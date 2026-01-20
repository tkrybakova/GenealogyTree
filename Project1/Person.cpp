#include "Person.h"
#include <ctime>
#include <sstream>

Person::Person() {
}

Person::~Person() {
}

void Person::create() {
    std::time_t now = std::time(nullptr);
    id = std::to_string(static_cast<long long>(now));
}

int Person::getAge() const {
    if (birthDate.tm_year == 0) {
        return 0;
    }

    std::time_t t = std::time(nullptr);
    std::tm now{};
    localtime_s(&now, &t);

    int age = now.tm_year - birthDate.tm_year;

    if (now.tm_mon < birthDate.tm_mon ||
        (now.tm_mon == birthDate.tm_mon && now.tm_mday < birthDate.tm_mday)) {
        age--;
    }

    return age;
}

std::string Person::getFullName() const {
    std::ostringstream fullName;

    if (!lastName.empty())
        fullName << lastName << " ";
    if (!firstName.empty())
        fullName << firstName << " ";
    if (!middleName.empty())
        fullName << middleName;

    return fullName.str();
}

void Person::remove() {
    biography.clear();
    relations.clear();
}

void Person::update() {
   
}
