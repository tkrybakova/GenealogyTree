#pragma once
#include <string>
#include <vector>
#include "Person.h"
#include <sqlite3.h>

class Database {
private:
    std::string filename;
    sqlite3* db = nullptr;

public:
    explicit Database(const std::string& dbFile);
    ~Database();

    bool open();
    void close();

    bool addPerson(const Person& p);
    std::vector<Person> getAllPersons() const;
};
