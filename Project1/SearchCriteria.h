#pragma once
#include <string>
#include <memory>
#include <map>
#include "DateRange.h"

class FamilyTree;

class SearchCriteria {
public:
    SearchCriteria() = default;
    virtual ~SearchCriteria() = default;

    void addFilter(const std::string& key, const std::string& value);
    void clearFilters();

    // Геттеры
    std::map<std::string, std::string> getFilters() const { return filters; }
    DateRange getBirthDateRange() const { return birthDateRange; }
    DateRange getDeathDateRange() const { return deathDateRange; }

private:
    DateRange birthDateRange;
    DateRange deathDateRange;

    std::shared_ptr<FamilyTree> tree;

    std::map<std::string, std::string> filters; // ключ: поле, значение: фильтр
};
