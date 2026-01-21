#include "crow.h"
#include "Database.h"
#include "Person.h"
#include <fstream>
#include <sstream>

std::string loadFile(const std::string& path) {
    std::ifstream file("web/" + path, std::ios::binary);
    if (!file.is_open()) return "";
    std::ostringstream ss;
    ss << file.rdbuf();
    return ss.str();
}

int main() {
    Database db("genealogy.db");
    if (!db.open()) return 1;

    crow::SimpleApp app;

    // === Статика ===
    CROW_ROUTE(app, "/")([]() {
        auto body = loadFile("index.html");
        if (body.empty()) return crow::response(404);
        crow::response res(body);
        res.set_header("Content-Type", "text/html; charset=utf-8");
        return res;
        });

    CROW_ROUTE(app, "/style.css")([]() {
        auto body = loadFile("style.css");
        if (body.empty()) return crow::response(404);
        crow::response res(body);
        res.set_header("Content-Type", "text/css");
        return res;
        });

    CROW_ROUTE(app, "/app.js")([]() {
        auto body = loadFile("app.js");
        if (body.empty()) return crow::response(404);
        crow::response res(body);
        res.set_header("Content-Type", "application/javascript");
        return res;
        });

    // === API: Персоны ===
    CROW_ROUTE(app, "/api/persons").methods("GET"_method)([&db]() {
        auto persons = db.getAllPersons();
        crow::json::wvalue result;
        result["persons"] = crow::json::wvalue::list();

        for (size_t i = 0; i < persons.size(); ++i) {
            const Person& p = persons[i];
            crow::json::wvalue personJson;
            personJson["id"] = p.getId();
            personJson["first_name"] = p.getFirstName();
            personJson["middle_name"] = p.getMiddleName();
            personJson["last_name"] = p.getLastName();
            personJson["gender"] = p.getGender();
            personJson["birth_date"] = p.getBirthDate();
            personJson["death_date"] = p.getDeathDate();
            personJson["biography"] = p.getBiography();

            result["persons"][i] = personJson;

        }
        return crow::response(result);
        });

    CROW_ROUTE(app, "/api/persons").methods("POST"_method)([&db](const crow::request& req) {
        auto body = crow::json::load(req.body);
        if (!body) return crow::response(400, "Invalid JSON");

        Person p;
        p.setFirstName(body["first_name"].s());
        p.setMiddleName(body.has("middle_name") ? body["middle_name"].s() : "");
        p.setLastName(body["last_name"].s());
        p.setGender(body["gender"].s());
        p.setBirthDate(body.has("birth_date") ? body["birth_date"].s() : "");
        p.setDeathDate(body.has("death_date") ? body["death_date"].s() : "");
        p.setBiography(body.has("biography") ? body["biography"].s() : "");

        if (p.getFirstName().empty() || p.getLastName().empty() || p.getGender().empty())
            return crow::response(400, "Missing required fields");

        if (db.addPerson(p)) {
            return crow::response(201, "Person added");
        }
        else {
            return crow::response(500, "Database error");
        }
        });

    // PUT - обновление
    CROW_ROUTE(app, "/api/persons/<int>").methods("PUT"_method)([&db](const crow::request& req, int id) {
        auto body = crow::json::load(req.body);
        if (!body) return crow::response(400, "Invalid JSON");

        Person p;
        p.setId(id);
        p.setFirstName(body["first_name"].s());
        p.setMiddleName(body.has("middle_name") ? body["middle_name"].s() : "");
        p.setLastName(body["last_name"].s());
        p.setGender(body["gender"].s());
        p.setBirthDate(body.has("birth_date") ? body["birth_date"].s() : "");
        p.setDeathDate(body.has("death_date") ? body["death_date"].s() : "");
        p.setBiography(body.has("biography") ? body["biography"].s() : "");

        if (db.updatePerson(p))
            return crow::response(200, "Updated");
        else
            return crow::response(500, "Update error");
        });

    // DELETE - удаление
    CROW_ROUTE(app, "/api/persons/<int>").methods("DELETE"_method)([&db](int id) {
        if (db.deletePerson(id))
            return crow::response(200, "Deleted");
        else
            return crow::response(500, "Delete error");
        });

    // === API: Дерево ===
    CROW_ROUTE(app, "/api/tree").methods("GET"_method)([&db]() {
        auto tree = db.getTree(); // возвращает JSON-подобную структуру
        crow::json::wvalue result = tree;
        return crow::response(result);
        });

    // === API: Загрузка / выгрузка дерева ===
    CROW_ROUTE(app, "/api/tree/load").methods("POST"_method)([&db](const crow::request& req) {
        auto body = crow::json::load(req.body);
        if (!body) return crow::response(400, "Invalid JSON");
        if (db.loadTreeFromJson(body))
            return crow::response(200, "Tree loaded");
        else
            return crow::response(500, "Load error");
        });

    CROW_ROUTE(app, "/api/tree/save").methods("GET"_method)([&db]() {
        auto tree = db.getTree();
        crow::json::wvalue result = tree;
        return crow::response(result);
        });

    std::cout << "Server running on http://localhost:18080\n";
    app.port(18080).multithreaded().run();
}
