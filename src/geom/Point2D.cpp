#include <cmath>

#include "../../include/geom/Point2D.h"
#include "../../include/utils/Tools.h"

Point2D::Point2D()
    : x{0.0}, y{0.0}
{}

Point2D::Point2D(double x, double y)
    : x{x}, y{y}
{}


Point2D::~Point2D()
{}

double Point2D::distanceSquaredTo(Point2D const &p) const
{
    double const DX = x - p.x;
    double const DY = y - p.y;

    return DX * DX + DY * DY;
}


double Point2D::distanceTo(Point2D const &p) const
{
    return std::sqrt(distanceSquaredTo(p));
}

bool Point2D::areColinear(Point2D const &p1, Point2D const &p2, Point2D const &p3)
{
    // We compute a fake area (we normally should divide by 2.0 but not needed here)
    return doubleAlmostEqualToZero(std::abs(p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y)));
}

std::ostream& operator<<(std::ostream &os, Point2D const &p)
{
    return os << "X: " << p.x << ", Y: " << p.y;
}

