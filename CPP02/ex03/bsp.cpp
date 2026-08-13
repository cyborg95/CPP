#include "Point.hpp"

bool bsp(const Point& a, const Point& b, const Point& c, const Point& point) {
    Fixed area_abc = (b.getX() - a.getX()) * (c.getY() - a.getY()) - (c.getX() - a.getX()) * (b.getY() - a.getY());
    Fixed area_abp = (b.getX() - a.getX()) * (point.getY() - a.getY()) - (point.getX() - a.getX()) * (b.getY() - a.getY());
    Fixed area_acp = (c.getX() - a.getX()) * (point.getY() - a.getY()) - (point.getX() - a.getX()) * (c.getY() - a.getY());
    Fixed area_bcp = (c.getX() - b.getX()) * (point.getY() - b.getY()) - (point.getX() - b.getX()) * (c.getY() - b.getY());

    return ((area_abc > 0 && area_abp > 0 && area_acp > 0 && area_bcp > 0) ||
            (area_abc < 0 && area_abp < 0 && area_acp < 0 && area_bcp < 0));
}