#include "SearchCriteria.h"
#include <iostream>

void SearchCriteria::addFilter(const std::string& key, const std::string& value) {
    filters[key] = value;
    std::cout << "Added filter: " << key << " = " << value << std::endl;
}

void SearchCriteria::clearFilters() {
    filters.clear();
    std::cout << "All filters cleared." << std::endl;
}
