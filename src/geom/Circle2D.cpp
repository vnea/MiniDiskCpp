#include<cmath>

#include "../../include/geom/Circle2D.h"
#include "../../include/utils/Tools.h"

Circle2D::Circle2D()
    : center{0.0, 0.0}, radius{0.0}
{}

Circle2D::Circle2D(double xCenter, double yCenter, double radius)
    : center{xCenter, yCenter}, radius{radius}
{}

Circle2D::Circle2D(Point2D const &center, double radius)
    : center{center}, radius{radius}
{}

Circle2D::Circle2D(Point2D const &p1, Point2D const &p2)
    : center{(p1.x + p2.x) * 0.5, (p1.y + p2.y) * 0.5}, radius{p1.distanceTo(center)}
{}

Circle2D::Circle2D(Point2D const &p1, Point2D const &p2, Point2D const &p3)
{
    double const P2_MINUS_P1Y = p2.y - p1.y;
    double const P3_MINUS_P2Y =  p3.y - p2.y;

    if (!doubleAlmostEqualToZero(P2_MINUS_P1Y, 0.0) && !doubleAlmostEqualToZero(P3_MINUS_P2Y, 0.0))
    {
        double const A = -(p2.x - p1.x) / P2_MINUS_P1Y;
        double const A_PRIME = -(p3.x - p2.x) / P3_MINUS_P2Y;
        double const A_PRIME_MINUS_A = A_PRIME - A;

        if (!doubleAlmostEqualToZero(A_PRIME_MINUS_A, 0.0))
        {
            double const P2_SQUARED_X = p2.x * p2.x;
            double const P2_SQUARED_Y = p2.y * p2.y;

            double const B = (P2_SQUARED_X - p1.x * p1.x + P2_SQUARED_Y - p1.y * p1.y) /
                             (2.0 * P2_MINUS_P1Y);
            double const B_PRIME = (p3.x * p3.x - P2_SQUARED_X + p3.y * p3.y - P2_SQUARED_Y) /
                                   (2.0 * P3_MINUS_P2Y);


            // Center coordinates
            center.x = (B - B_PRIME) / A_PRIME_MINUS_A;
            center.y = A * center.x + B;

            double const DXC = p1.x - center.x;
            double const DYC = p1.y - center.y;

            // Radius
            radius = std::sqrt(DXC * DXC + DYC * DYC);
        }
    }
}

Circle2D::~Circle2D()
{}

bool Circle2D::containsPoint(Point2D const &p) const
{
    double const DIST_SQUARED = p.distanceSquaredTo(center);
    double const RADIUS_SQUARED = radius * radius;

    return DIST_SQUARED < RADIUS_SQUARED || doubleAlmostEqual(DIST_SQUARED, RADIUS_SQUARED);
}

bool Circle2D::containsAllPoints(std::vector<Point2D>::const_iterator begin, std::vector<Point2D>::const_iterator end) const
{
    for (auto it = begin; it != end; ++it)
    {
        if (!containsPoint(*it))
        {
            return false;
        }
    }

    return true;
}

std::ostream& operator<<(std::ostream &os, Circle2D const &c)
{
    return os << c.center << ", Radius: " << c.radius;
}
