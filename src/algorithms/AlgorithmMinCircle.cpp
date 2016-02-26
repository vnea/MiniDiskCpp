#include <algorithm>
#include <limits>

#include "../include/algorithms/AlgorithmMinCircle.h"

AlgorithmMinCircle::~AlgorithmMinCircle()
{}

Circle2D AlgorithmMinCircle::naiveAlgorithm(std::vector<Point2D> const &points) const
{
    // General case
    //std::cout << "General case\n";
    Circle2D minimumCircle;
    for (auto p = begin(points); p != end(points); ++p)
    {
        for (auto q = begin(points); q != end(points); ++q)
        {
            if (p != q)
            {
                minimumCircle.center.x = (p->x + q->x) * 0.5,
                minimumCircle.center.y = (p->y + q->y) * 0.5,
                minimumCircle.radius = p->distanceTo(*q) * 0.5;

                if (minimumCircle.containsAllPoints(begin(points), end(points)))
                {
                    //std::cout << "OK\n";
                    return minimumCircle;
                }
            }
        }
    }

    //std::cout << "Triangle case\n";

    // Triangle case
    minimumCircle.radius = std::numeric_limits<double>::max();
    for (auto p = begin(points); p != end(points); ++p)
    {
        for (auto q = begin(points); q != end(points); ++q)
        {
            for (auto r = begin(points); r != end(points); ++r)
            {
                if (p != q && q != r && p != r && !Point2D::areColinear(*p, *q, *r))
                {
                    Circle2D const CIRCUMSCRIBED_CIRCLE{*p, *q, *r};
                    if (CIRCUMSCRIBED_CIRCLE.radius < minimumCircle.radius && CIRCUMSCRIBED_CIRCLE.containsAllPoints(begin(points), end(points))) {
                        minimumCircle.center.x = CIRCUMSCRIBED_CIRCLE.center.x;
                        minimumCircle.center.y = CIRCUMSCRIBED_CIRCLE.center.y;
                        minimumCircle.radius = CIRCUMSCRIBED_CIRCLE.radius;
                    }
                }
            }
        }
    }

    return minimumCircle;
}

Circle2D AlgorithmMinCircle::minidisk(std::vector<Point2D> &points) const
{
    std::vector<Point2D> boundary;
    boundary.reserve(3);

    return bMinidisk(points, boundary);
}

Circle2D AlgorithmMinCircle::bMinidisk(std::vector<Point2D> &points, std::vector<Point2D> &boundary) const
{
    Circle2D minimumCircle;
    if (boundary.size() == 3)
    {
        minimumCircle = Circle2D{boundary[0], boundary[1], boundary[2]};
    }
    else if (points.empty() && boundary.size() == 2)
    {
        minimumCircle = Circle2D{boundary[0], boundary[1]};
    }
    else if (points.size() == 1 && boundary.empty())
    {
        minimumCircle = Circle2D{points[0].x, points[0].y, 0.0};
    }
    else if (points.size() == 1 && boundary.size() == 1)
    {
        minimumCircle = Circle2D{points[0], boundary[0]};
    }
    else
    {
        Point2D p = *points.erase(points.end() - 1);
        minimumCircle = bMinidisk(points, boundary);

        if (minimumCircle.containsPoint(p))
        {
            boundary.push_back(p);
            minimumCircle = bMinidisk(points, boundary);

            boundary.erase(points.end() - 1);
            points.push_back(p);
        }
    }

    return minimumCircle;
}
