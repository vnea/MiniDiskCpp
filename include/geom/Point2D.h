#ifndef POINT2D_H
#define POINT2D_H

#include <iostream>
#include <cmath>

class Point2D
{
    public:
        Point2D();
        Point2D(Point2D const &) = default;
        Point2D(Point2D &&) = default;

        Point2D(double x, double y);
        ~Point2D();


        Point2D& operator=(Point2D const &) = default;
        Point2D& operator=(Point2D &&) = default;

        double distanceSquaredTo(Point2D const &p) const;
        double distanceTo(Point2D const &p) const;
        static bool areColinear(Point2D const &p1, Point2D const &p2, Point2D const &p3);

        friend std::ostream& operator<<(std::ostream &os, Point2D const &p);

    public:
        // No need to make them private
        double x;
        double y;
};

#endif // POINT2D_H
