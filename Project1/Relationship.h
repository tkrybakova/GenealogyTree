#pragma once
#include <string>
#include <memory>
#include <ctime>
#include "RelationshipType.h"

class Person;

class Relationship {
public:
    Relationship() = default;
    virtual ~Relationship() = default;

    // Создание связи между двумя людьми
    void createRelationship(const std::shared_ptr<Person>& a,
        const std::shared_ptr<Person>& b,
        RelationshipType type,
        const std::tm& start = std::tm{},
        const std::tm& end = std::tm{},
        const std::string& notes_ = "");

    void deleteRelationship();
    bool validateRelationship() const; 

    // Геттеры
    std::shared_ptr<Person> getPersonA() const { return personA; }
    std::shared_ptr<Person> getPersonB() const { return personB; }
    RelationshipType getType() const { return relationshipType; }
    std::tm getStartDate() const { return startDate; }
    std::tm getEndDate() const { return endDate; }
    std::string getNotes() const { return notes; }

private:
    std::shared_ptr<Person> personA;
    std::shared_ptr<Person> personB;
    RelationshipType relationshipType;
    std::tm startDate{};
    std::tm endDate{};
    std::string notes;
};
