//
// Created by robbie on 2-10-2016.
//

#ifndef JSONREPOSITORY_JSONREPOSITORY_H
#define JSONREPOSITORY_JSONREPOSITORY_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "../Repository.h"

#include "../../Libraries/json.hpp"
using json = nlohmann::json;

template<typename T>
class JsonRepository: public Repository<T> {
public:
    virtual std::string jsonFileLocation() const = 0;
    virtual std::string toJson(const T obj) const = 0;
    virtual T createFromJson(const std::string jsonString) const = 0;
    virtual int getIdentifier(const T obj) const = 0;

    void save(const T obj) const
    {
        std::vector<T> toSave = this->all();

        // Check if the obj already exists
        if (this->getById(this->getIdentifier(obj)) != NULL) {
            // Update the new object
            for(T &o: toSave) {
                if (this->getIdentifier(obj) == this->getIdentifier(o))
                {
                    o = obj;
                }
            }
        } else {
            // Save the new object
            toSave.push_back(obj);
        }

        // Write the json string
        this->writeToFile(toSave);
    }

    std::vector<T> all() const
    {
        // Read the json file
        std::ifstream file(this->jsonFileLocation());
        std::string jsonString((std::istreambuf_iterator<char>(file)), (std::istreambuf_iterator<char>()));

        // Parse the string
        json j = json::parse(jsonString);

        // Loop through each json object, and add it to the vector
        std::vector<T> all;
        for (json::iterator it = j.begin(); it != j.end(); ++it) {
            all.push_back(createFromJson(it.value().dump()));
        }

        return all;
    }

    T *getById(const int id) const
    {
        // Read all
        std::vector<T> all = this->all();

        // Find the id
        for(T &obj: all) {
            if (this->getIdentifier(obj) == id) {
                return &obj;
            }
        }

        return nullptr;
    }

    void remove(T obj) const
    {
        // Check if the object is saved
        if (this->getById(this->getIdentifier(obj)) != NULL)
        {
            // Find it and remove it from the json string
            std::vector<T> all = this->all();
            for(typename std::vector<T>::iterator it = all.begin(); it != all.end(); ++it) {
                if (this->getIdentifier(obj) == this->getIdentifier(*it))
                {
                    all.erase(it);
                    break;
                }
            }

            // Update the file
            this->writeToFile(all);
        }
    }
private:
    void writeToFile(const std::vector<T> objects) const
    {
        // Create the json array with all the values
        json j = json::array({});
        for(T const& obj: objects) {
            j.push_back(json::parse(this->toJson(obj)));
        }

        // Open the file
        std::ofstream file;
        file.open (this->jsonFileLocation());

        // Write to the file
        file << j.dump();

        // Close the file
        file.close();
    }
};


#endif //JSONREPOSITORY_JSONREPOSITORY_H
