#include "Span.hpp"

Span::Span() : _maxSize(0)
{
}

Span::Span(unsigned int N) : _maxSize(N)
{
}

Span::Span(const Span& other)
    : _maxSize(other._maxSize), _numbers(other._numbers)
{
}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        _maxSize = other._maxSize;
        _numbers = other._numbers;
    }

    return *this;
}

Span::~Span()
{
}

void Span::addNumber(int number)
{
    if (_numbers.size() >= _maxSize)
        throw std::exception();

    _numbers.push_back(number);
}

void Span::addNumbers(std::vector<int>::iterator begin,
                      std::vector<int>::iterator end)
{
    while (begin != end)
    {
        addNumber(*begin);
        ++begin;
    }
}

unsigned int Span::shortestSpan() const
{
    if (_numbers.size() < 2)
        throw std::exception();

    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());

    unsigned int shortest = static_cast<unsigned int>(
        sorted[1] - sorted[0]
    );

    for (unsigned int i = 1; i < sorted.size(); i++)
    {
        unsigned int distance = static_cast<unsigned int>(
            sorted[i] - sorted[i - 1]
        );

        if (distance < shortest)
            shortest = distance;
    }

    return shortest;
}

unsigned int Span::longestSpan() const
{
    if (_numbers.size() < 2)
        throw std::exception();

    int min = *std::min_element(_numbers.begin(), _numbers.end());
    int max = *std::max_element(_numbers.begin(), _numbers.end());

    return static_cast<unsigned int>(max - min);
}