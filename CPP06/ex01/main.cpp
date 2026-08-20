#include "Serializer.hpp"
#include <iostream>

int main()
{
    Data data;

    data.name = "Otis";
    data.age = 26;

    Data* original = &data;

    std::cout << "Original pointer: " << original << std::endl;
    std::cout << "Name: " << original->name << std::endl;
    std::cout << "Age: " << original->age << std::endl;

    uintptr_t raw = Serializer::serialize(original);

    std::cout << "\nSerialized value: " << raw << std::endl;

    Data* result = Serializer::deserialize(raw);

    std::cout << "\nDeserialized pointer: " << result << std::endl;
    std::cout << "Name: " << result->name << std::endl;
    std::cout << "Age: " << result->age << std::endl;

    if (result == original)
        std::cout << "\nPointers are the same!" << std::endl;
    else
        std::cout << "\nPointers are different!" << std::endl;

    return 0;
}