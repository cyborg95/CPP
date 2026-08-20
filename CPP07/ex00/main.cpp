#include <iostream>
#include "whatever.hpp"

int main()
{
    int a = 10;
    int b = 20;

    std::cout << "Before swap:" << std::endl;
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;

    swap(a, b);

    std::cout << "\nAfter swap:" << std::endl;
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;

    std::cout << "\nMin: " << min(a, b) << std::endl;
    std::cout << "Max: " << max(a, b) << std::endl;

    return 0;
}