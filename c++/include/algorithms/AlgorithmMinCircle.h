#ifndef ALGORITHHMMINCIRCLE_H
#define ALGORITHHMMINCIRCLE_H

#include "AlgorithmMinCircle.h"
#include "../geom/Circle2D.h"

class AlgorithmMinCircle
{
    public:
        AlgorithmMinCircle() = default;
        AlgorithmMinCircle(AlgorithmMinCircle const &) = delete;
        AlgorithmMinCircle(AlgorithmMinCircle &&) = delete;
        ~AlgorithmMinCircle();

        AlgorithmMinCircle& operator=(AlgorithmMinCircle const &) = delete;
        AlgorithmMinCircle& operator=(AlgorithmMinCircle &&) = delete;

        Circle2D naiveAlgorithm(std::vector<Point2D> const &points) const;
        Circle2D minidisk(std::vector<Point2D> &points) const;

    private:
        Circle2D bMinidisk(std::vector<Point2D> &points, std::vector<Point2D> &boundary) const;
};

#endif // ALGORITHHMMINCIRCLE_H
