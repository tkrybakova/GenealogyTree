#pragma once
#include <string>

class Person {
    int id = 0;
    std::string firstName;
    std::string middleName;
    std::string lastName;
    std::string gender;
    std::string birthDate;
    std::string deathDate;
    std::string biography;

public:
    int getId() const { return id; }
    void setId(int v) { id = v; }

    const std::string& getFirstName() const { return firstName; }
    void setFirstName(const std::string& v) { firstName = v; }

    const std::string& getMiddleName() const { return middleName; }
    void setMiddleName(const std::string& v) { middleName = v; }

    const std::string& getLastName() const { return lastName; }
    void setLastName(const std::string& v) { lastName = v; }

    const std::string& getGender() const { return gender; }
    void setGender(const std::string& v) { gender = v; }

    const std::string& getBirthDate() const { return birthDate; }
    void setBirthDate(const std::string& v) { birthDate = v; }

    const std::string& getDeathDate() const { return deathDate; }
    void setDeathDate(const std::string& v) { deathDate = v; }

    const std::string& getBiography() const { return biography; }
    void setBiography(const std::string& v) { biography = v; }
};

