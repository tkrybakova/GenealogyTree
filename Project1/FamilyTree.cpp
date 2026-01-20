#include "FamilyTree.h"
#include <algorithm>
#include <iostream>

void FamilyTree::addMember(const std::shared_ptr<Person>& person) {
    if (!person) return;
    members.push_back(person);
    std::cout << "Added member: " << person->getFullName() << std::endl;
}

std::vector<std::shared_ptr<Person>> FamilyTree::searchInTree(const SearchCriteria& criteria) {
    std::vector<std::shared_ptr<Person>> result;

    for (auto& person : members) {
        result.push_back(person);
    }

    return result;
}

std::shared_ptr<Person> FamilyTree::findByName(const std::string& fullName) const {
    auto it = std::find_if(members.begin(), members.end(),
        [&fullName](const std::shared_ptr<Person>& p) {
            return p->getFullName() == fullName;
        });

    if (it != members.end()) return *it;
    return nullptr;
}

