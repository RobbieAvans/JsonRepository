//
// Created by robbie on 2-10-2016.
//

#ifndef JSONREPOSITORY_FOO_H
#define JSONREPOSITORY_FOO_H

#include<string>

class Foo {
public:
    void setName(std::string name);
    void setAge(int age);
    void setId(int id);
    std::string getName() const;
    int getAge() const;
    int getId() const;
private:
    std::string name;
    int age;
    int id;
};


#endif //JSONREPOSITORY_FOO_H
