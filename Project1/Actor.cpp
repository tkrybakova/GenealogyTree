#include "Actor.h"
#include "FamilyTree.h"
#include <memory>
#include <iostream>

Actor::Actor() {
    std::time_t now = std::time(nullptr);
    id = std::to_string(static_cast<long long>(now));
}

Actor::~Actor() {
    logout();
}

std::shared_ptr<FamilyTree> Actor::createTree(const std::string& treeName) {
    myTree = std::make_shared<FamilyTree>();
    std::cout << "Created new FamilyTree: " << treeName << std::endl;
    return myTree;
}

bool Actor::login(const std::string& pwd) {
    if (pwd == password) {
        std::cout << name << " logged in successfully" << std::endl;
        return true;
    }
    std::cout << name << " login failed" << std::endl;
    return false;
}

void Actor::logout() {
    if (myTree) {
        myTree.reset();
    }
    std::cout << name << " logged out" << std::endl;
}

void Actor::registerActor() {
    std::cout << "Registering actor: " << name << std::endl;
    password = "1234"; 
}
