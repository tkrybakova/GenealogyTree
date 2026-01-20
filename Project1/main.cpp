#include "crow.h"
#include <vector>
#include <fstream>
#include <crow/mustache.h>
#include <sstream>
#include <string>



int main()
{
    crow::SimpleApp app;

    // Указываем папку с html шаблонами
    crow::mustache::set_base("web");

    CROW_ROUTE(app, "/")
        ([] {
        auto page = crow::mustache::load("index.html");
        return page.render();
            });

    app.port(18080).multithreaded().run();
}
