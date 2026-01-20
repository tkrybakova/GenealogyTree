#pragma once
#include <vector>
#include <memory>
#include <string>
#include "Person.h"
#include "SearchCriteria.h"

class FamilyTree {
public:
    FamilyTree() = default;
    ~FamilyTree() = default;

    void addMember(const std::shared_ptr<Person>& person);

    std::vector<std::shared_ptr<Person>> searchInTree(const SearchCriteria& criteria);

    // Новые методы
    std::vector<std::shared_ptr<Person>> getMembers() const { return members; }
    std::shared_ptr<Person> findByName(const std::string& fullName) const;

private:
    std::vector<std::shared_ptr<Person>> members;
};

