///////////////////////////////////////////////////////////
//  SearchService.h
//  Implementation of the Class SearchService
//  Created on:      19-???-2026 11:27:09
//  Original author: tkryb
///////////////////////////////////////////////////////////

#if !defined(EA_DDC95DCA_7331_49bc_BC55_D4B6A440CD2B__INCLUDED_)
#define EA_DDC95DCA_7331_49bc_BC55_D4B6A440CD2B__INCLUDED_
#include <vector>
#include <memory>
#include "SearchCriteria.h"

class Person;
class Relationship;
class FamilyTree;
/**
 * ===================== ?????? ?????? =====================
 */
#pragma once

#include <vector>
#include <memory>
#include "Person.h"
#include "Relationship.h"
#include "SearchCriteria.h"

class SearchService {
public:
    SearchService() = default;
    SearchService(std::shared_ptr<FamilyTree> tree) : familyTree(tree) {}
    ~SearchService() = default;

    std::vector<std::shared_ptr<Person>> findAncestors(const SearchCriteria& criteria);
    std::vector<std::shared_ptr<Person>> findDescendants(const SearchCriteria& criteria);
    std::vector<std::shared_ptr<Relationship>> findRelationships(const SearchCriteria& criteria);
    std::vector<std::shared_ptr<Person>> searchPerson(const SearchCriteria& criteria);

    void setFamilyTree(std::shared_ptr<FamilyTree> tree) { familyTree = tree; }

private:
    std::shared_ptr<FamilyTree> familyTree; 
};

#endif // !defined(EA_DDC95DCA_7331_49bc_BC55_D4B6A440CD2B__INCLUDED_)
