#include <iostream>
#include "Domain/Foo.h"
#include "Repository/JsonRepository/FooJsonRepository.h"


int main() {
    // Create foo object
    Foo foo;
    foo.setId(2);
    foo.setName("Robbie2");
    foo.setAge(21);

    // Init the repository (repository factory in the future??)
    FooJsonRepository repository;

    // Save the foo object
    repository.save(foo);

    // Retrieve all the foo objects
    std::vector<Foo> savedFoos = repository.all();

    // Loop through the results
    for(Foo const& savedFoo: savedFoos) {
        std::cout << savedFoo.getName() << " is " << savedFoo.getAge() << " jaar oud";
        std::cout << std::endl;
    }

    return 0;
}