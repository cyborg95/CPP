#include <iostream>
#include "iter.hpp"

void printString(std::string &str)
{
    std::cout << str << std::endl;
}

void printInt(int &number)
{
    std::cout << number << std::endl;
}

void doubleInt(int &number)
{
    number *= 2;
    std::cout << number << std::endl;
}

int main()
{
    int numbers[] = {1, 2, 3, 4, 5};

    std::cout << "Original:" << std::endl;
    iter(numbers, 5, printInt);

    std::cout << "\nAfter doubling:" << std::endl;
    iter(numbers, 5, doubleInt);

    std::cout << std::endl;

    std::string words[] = {"Hello", "42", "CPP07"};
    iter(words, 3, printString);

    return 0;
}