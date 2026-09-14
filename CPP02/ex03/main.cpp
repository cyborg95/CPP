#include <iostream>
#include "Point.hpp"

bool bsp(const Point& a, const Point& b, const Point& c, const Point& point);

int main(void)
{
    Point a(0, 0);
    Point b(10, 0);
    Point c(0, 10);

    // Inside
    Point inside1(2, 2);
    Point inside2(1, 5);
    Point inside3(5, 1);

    // Outside
    Point outside1(10, 10);
    Point outside2(-1, 2);
    Point outside3(5, 6);

    // On edges
    Point edgeAB(5, 0);
    Point edgeAC(0, 5);
    Point edgeBC(5, 5);

    // Vertices
    Point vertexA(0, 0);
    Point vertexB(10, 0);
    Point vertexC(0, 10);

    std::cout << "Inside 1: " << bsp(a, b, c, inside1) << std::endl;
    std::cout << "Inside 2: " << bsp(a, b, c, inside2) << std::endl;
    std::cout << "Inside 3: " << bsp(a, b, c, inside3) << std::endl;

    std::cout << "Outside 1: " << bsp(a, b, c, outside1) << std::endl;
    std::cout << "Outside 2: " << bsp(a, b, c, outside2) << std::endl;
    std::cout << "Outside 3: " << bsp(a, b, c, outside3) << std::endl;

    std::cout << "Edge AB: " << bsp(a, b, c, edgeAB) << std::endl;
    std::cout << "Edge AC: " << bsp(a, b, c, edgeAC) << std::endl;
    std::cout << "Edge BC: " << bsp(a, b, c, edgeBC) << std::endl;

    std::cout << "Vertex A: " << bsp(a, b, c, vertexA) << std::endl;
    std::cout << "Vertex B: " << bsp(a, b, c, vertexB) << std::endl;
    std::cout << "Vertex C: " << bsp(a, b, c, vertexC) << std::endl;

    return 0;
}