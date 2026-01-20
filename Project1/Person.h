///////////////////////////////////////////////////////////
//  Person.h
//  Implementation of the Class Person
//  Created on:      19-???-2026
//  Original author: tkryb
///////////////////////////////////////////////////////////

#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <memory>
#include <ctime>
#include <vector>
#include "Gender.h"

class FamilyTree;
class Relationship;

class Person
{
public:
    Person();
    virtual ~Person();

    void create();                 // инициализация нового человека
    int getAge() const;            // расчёт возраста по birthDate
    std::string getFullName() const; // ФИО
    void remove();                 // логическое удаление
    void update();                 // обновление данных

    void setFirstName(const std::string& fn) { firstName = fn; }
    void setMiddleName(const std::string& mn) { middleName = mn; }
    void setLastName(const std::string& ln) { lastName = ln; }
    void setBirthDate(const std::tm& bd) { birthDate = bd; }
    void setDeathDate(const std::tm& dd) { deathDate = dd; }
    void setGender(Gender g) { gender = g; }
    void setBiography(const std::string& bio) { biography = bio; }

    std::string getFirstName() const { return firstName; }
    std::string getMiddleName() const { return middleName; }
    std::string getLastName() const { return lastName; }
    std::tm getBirthDate() const { return birthDate; }
    std::tm getDeathDate() const { return deathDate; }
    Gender getGender() const { return gender; }
    std::string getBiography() const { return biography; }

private:
    std::string id;          
    std::string firstName;
    std::string middleName;
    std::string lastName;
    Gender gender;
    std::tm birthDate{};
    std::tm deathDate{};
    std::string biography;

    std::weak_ptr<FamilyTree> familyTree;
    std::vector<std::shared_ptr<Relationship>> relations;
};

#endif 
