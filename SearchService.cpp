#include "SearchService.h"
#include "FamilyTree.h"
#include "Person.h"
#include <iostream>

std::vector<std::shared_ptr<Person>> SearchService::searchPerson(const SearchCriteria& criteria) {
    std::vector<std::shared_ptr<Person>> result;

    if (!familyTree) {
        std::cout << "No family tree linked to SearchService." << std::endl;
        return result;
    }

    auto filters = criteria.getFilters();

    // Перебираем всех членов дерева
    for (auto& person : familyTree->searchInTree(criteria)) {
        bool match = true;

        // Фильтр по имени
        if (filters.count("firstName") &&
            person->getFirstName() != filters.at("firstName"))
            match = false;

        if (filters.count("lastName") &&
            person->getLastName() != filters.at("lastName"))
            match = false;

        if (match)
            result.push_back(person);
    }

    return result;
}

// Простейшие заглушки для предков и потомков
std::vector<std::shared_ptr<Person>> SearchService::findAncestors(const SearchCriteria& criteria) {
    // TODO: можно добавить рекурсивный поиск по связям parent-child
    return searchPerson(criteria);
}

std::vector<std::shared_ptr<Person>> SearchService::findDescendants(const SearchCriteria& criteria) {
    // TODO: аналогично findAncestors
    return searchPerson(criteria);
}

std::vector<std::shared_ptr<Relationship>> SearchService::findRelationships(const SearchCriteria& criteria) {
    std::vector<std::shared_ptr<Relationship>> result;
    // TODO: добавить фильтр по типу, дате и участникам
    return result;
}
