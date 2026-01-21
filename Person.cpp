#include "Person.h"
#include <ctime>

int Person::getId() const {
    return id;
}

void Person::setId(int value) {
    id = value;
}

std::string Person::getFirstName() const {
    return firstName;
}

void Person::setFirstName(const std::string& value) {
    firstName = value;
}

std::string Person::getLastName() const {
    return lastName;
}

void Person::setLastName(const std::string& value) {
    lastName = value;
}

std::string Person::getFullName() const {
    return lastName + " " + firstName;
}

int Person::getBirthYear() const {
    return birthYear;
}

void Person::setBirthYear(int value) {
    birthYear = value;
}

int Person::getAge() const {
    if (birthYear == 0) return 0;

    std::time_t t = std::time(nullptr);
    std::tm tm{};
    localtime_s(&tm, &t);

    int currentYear = tm.tm_year + 1900;
    return currentYear - birthYear;
}
