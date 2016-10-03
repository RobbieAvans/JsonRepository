//
// Created by robbie on 2-10-2016.
//

#ifndef JSONREPOSITORY_REPOSITORY_H
#define JSONREPOSITORY_REPOSITORY_H

#include <vector>

template<typename T>
class Repository {
public:
    virtual void save(const T obj) const = 0;
    virtual void remove(T obj) const = 0;
    virtual T *getById(const int id) const = 0;
    virtual std::vector<T> all() const = 0;
};

#endif //JSONREPOSITORY_REPOSITORY_H
