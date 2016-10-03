//
// Created by robbie on 2-10-2016.
//

#include "FooJsonRepository.h"

using json = nlohmann::json;

std::string FooJsonRepository::jsonFileLocation() const
{
    /** TODO: Create relative path?? */
    return "C:\\Users\\robbie\\Documents\\JsonRepository\\src\\Resources/foo.json";
}

std::string FooJsonRepository::toJson(const Foo foo) const
{
    json j;
    j["id"] = foo.getId();
    j["name"] = foo.getName();
    j["age"] = foo.getAge();

    return j.dump();
}

Foo FooJsonRepository::createFromJson(const std::string jsonString) const
{
    json j = json::parse(jsonString);

    Foo foo;

    foo.setId(j["id"]);
    foo.setName(j["name"]);
    foo.setAge(j["age"]);

    return foo;
}

int FooJsonRepository::getIdentifier(const Foo foo) const
{
    return foo.getId();
}