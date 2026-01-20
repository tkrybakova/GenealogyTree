#include "Relationship.h"
#include "Person.h"  
#include <iostream>

void Relationship::createRelationship(const std::shared_ptr<Person>& a,
    const std::shared_ptr<Person>& b,
    RelationshipType type,
    const std::tm& start,
    const std::tm& end,
    const std::string& notes_)
{
    personA = a;
    personB = b;
    relationshipType = type;
    startDate = start;
    endDate = end;
    notes = notes_;

    if (!validateRelationship()) {
        std::cerr << "Invalid relationship!" << std::endl;
        // Можно очистить данные
        personA = nullptr;
        personB = nullptr;
    }
    else {
        std::cout << "Relationship created between "
            << a->getFullName() << " and " << b->getFullName() << std::endl;
    }
}

void Relationship::deleteRelationship() {
    personA = nullptr;
    personB = nullptr;
    notes.clear();
    std::cout << "Relationship deleted." << std::endl;
}

bool Relationship::validateRelationship() const {
    // Простейшая проверка: нельзя сделать связь с самим собой
    if (!personA || !personB) return false;
    if (personA == personB) return false;

    // Можно добавить дополнительные правила:
    // например, нельзя быть родителем самому себе, проверка даты и типа
    return true;
}
