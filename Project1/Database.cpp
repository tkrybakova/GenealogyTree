#include "Database.h"
#include <iostream>
#include <sstream>

Database::Database(const std::string& filename) : dbFilename(filename) {}

Database::~Database() {
    close();
}

bool Database::open() {
    if (sqlite3_open(dbFilename.c_str(), &db) != SQLITE_OK) {
        std::cerr << "Cannot open DB: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }

    // Создаём таблицу, если её нет
    std::string sql = R"(CREATE TABLE IF NOT EXISTS Person (
        id TEXT PRIMARY KEY,
        firstName TEXT,
        middleName TEXT,
        lastName TEXT,
        gender INTEGER,
        birthYear INTEGER,
        birthMonth INTEGER,
        birthDay INTEGER
    );)";
    return execute(sql);
}

void Database::close() {
    if (db) {
        sqlite3_close(db);
        db = nullptr;
    }
}

bool Database::execute(const std::string& sql) {
    char* errMsg = nullptr;
    if (sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errMsg) != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
        return false;
    }
    return true;
}

bool Database::addPerson(const std::shared_ptr<Person>& person) {
    if (!db) return false;

    std::ostringstream ss;
    auto bd = person->getBirthDate();
    ss << "INSERT INTO Person (id, firstName, middleName, lastName, gender, birthYear, birthMonth, birthDay) VALUES ("
        << "'" << person->getFullName() << "', "
        << "'" << person->getFirstName() << "', "
        << "'" << person->getMiddleName() << "', "
        << "'" << person->getLastName() << "', "
        << static_cast<int>(person->getGender()) << ", "
        << bd.tm_year + 1900 << ", "
        << bd.tm_mon + 1 << ", "
        << bd.tm_mday
        << ");";

    return execute(ss.str());
}

std::vector<std::shared_ptr<Person>> Database::getAllPersons() {
    std::vector<std::shared_ptr<Person>> persons;
    if (!db) return persons;

    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db, "SELECT * FROM Person;", -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Failed to prepare statement\n";
        return persons;
    }

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        auto p = std::make_shared<Person>();
        // Здесь можно распарсить данные из stmt и заполнить поля p
        // Например: firstName = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        persons.push_back(p);
    }

    sqlite3_finalize(stmt);
    return persons;
}
