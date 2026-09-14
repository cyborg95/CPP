#include "Point.hpp"

bool bsp(const Point& a, const Point& b,
         const Point& c, const Point& point)
{
    Fixed abp =
        (b.getX() - a.getX()) * (point.getY() - a.getY())
        - (b.getY() - a.getY()) * (point.getX() - a.getX());

    Fixed bcp =
        (c.getX() - b.getX()) * (point.getY() - b.getY())
        - (c.getY() - b.getY()) * (point.getX() - b.getX());

    Fixed cap =
        (a.getX() - c.getX()) * (point.getY() - c.getY())
        - (a.getY() - c.getY()) * (point.getX() - c.getX());

    if (abp == 0 || bcp == 0 || cap == 0)
        return false;

    return (abp > 0 && bcp > 0 && cap > 0)
        || (abp < 0 && bcp < 0 && cap < 0);
}