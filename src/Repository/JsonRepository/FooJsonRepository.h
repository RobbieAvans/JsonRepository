//
// Created by robbie on 2-10-2016.
//

#ifndef JSONREPOSITORY_FOOJSONREPOSITORY_H
#define JSONREPOSITORY_FOOJSONREPOSITORY_H


#include "../../Domain/Foo.h"
#include "../Repository.h"
#include "JsonRepository.hpp"

class FooJsonRepository: public JsonRepository<Foo> {
    std::string toJson(const Foo foo) const;
    Foo createFromJson(const std::string jsonString) const;
    int getIdentifier(const Foo foo) const;
    std::string jsonFileLocation() const;
};


#endif //JSONREPOSITORY_FOOJSONREPOSITORY_H
