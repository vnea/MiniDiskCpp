#include <iostream>
#include <fstream>
#include <string>

#include "../../include/utils/FilePointsLoader.h"

FilePointsLoader::~FilePointsLoader()
{}

std::vector<Point2D> FilePointsLoader::loadPoints(std::string const &filePath) const
{
    std::ifstream pointsFile{filePath};
    std::vector<Point2D> points;

    if (pointsFile.is_open())
    {
        // Get the number of points to reserve memory for points
        std::vector<Point2D>::size_type nbPoints = 0;
        std::string line;
        while (getline(pointsFile, line))
        {
            ++nbPoints;
        }

        points.reserve(nbPoints);

        // Set file cursor at the beginning
        pointsFile.clear();
        pointsFile.seekg(0, std::ios::beg);

        // Load points in the vector
        double x, y;
        nbPoints = 0;
        while (nbPoints < points.capacity())
        {
            pointsFile >> x >> y;
            points.push_back(Point2D {x, y});
            ++nbPoints;
        }
    }

    return points;
}
