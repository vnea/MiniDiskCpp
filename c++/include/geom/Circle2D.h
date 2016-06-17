#ifndef CIRCLE2D_H
#define CIRCLE2D_H

#include <iostream>
#include <vector>

#include "Point2D.h"

class Circle2D
{
    public:
        Circle2D();
        Circle2D(Circle2D const &c) = default;
        Circle2D(Circle2D &&) = default;

        Circle2D(double xCenter, double yCenter, double radius);
        Circle2D(Point2D const &center, double radius);
        Circle2D(Point2D const &p1, Point2D const &p2);
        Circle2D(Point2D const &p1, Point2D const &p2, Point2D const &p3);
        ~Circle2D();

        Circle2D& operator=(Circle2D const &) = default;
        Circle2D& operator=(Circle2D &&) = default;


        bool containsPoint(Point2D const &p) const;
        bool containsAllPoints(std::vector<Point2D>::const_iterator begin, std::vector<Point2D>::const_iterator end) const;

        friend std::ostream& operator<<(std::ostream &os, Circle2D const &c);

    public:
        // No need to make them private
        Point2D center;
        double radius;
};

#endif // CIRCLE2D_H
