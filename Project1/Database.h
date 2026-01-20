#pragma once
#include <string>
#include <vector>
#include <memory>
#include "Person.h"
#include "sqlite3.h"

class Database {
public:
    Database(const std::string& filename);
    ~Database();

    bool open();
    void close();

    bool addPerson(const std::shared_ptr<Person>& person);
    std::vector<std::shared_ptr<Person>> getAllPersons();

private:
    std::string dbFilename;
    sqlite3* db = nullptr;

    bool execute(const std::string& sql);
};
