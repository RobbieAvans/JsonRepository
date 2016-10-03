//
// Created by robbie on 2-10-2016.
//

#include "Foo.h"

void Foo::setAge(int age)
{
    this->age = age;
}

void Foo::setName(std::string name)
{
    this->name = name;
}

void Foo::setId(int id)
{
    this->id = id;
}

int Foo::getAge() const
{
    return this->age;
}

std::string Foo::getName() const
{
    return this->name;
}

int Foo::getId() const
{
    return this->id;
}