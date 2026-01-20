#pragma once
#include <string>
#include <memory>

class FamilyTree;

class Actor {
public:
    Actor();
    ~Actor();

    std::shared_ptr<FamilyTree> createTree(const std::string& name);
    bool login(const std::string& password);
    void logout();
    void registerActor();

    void setName(const std::string& n) { name = n; }
    std::string getName() const { return name; }

private:
    std::string id; 
    std::string name;
    std::string password; 
    std::shared_ptr<FamilyTree> myTree;
};

