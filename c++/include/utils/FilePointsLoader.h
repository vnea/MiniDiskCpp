#ifndef FILEPOINTSLOADER_H
#define FILEPOINTSLOADER_H

#include <string>
#include <vector>

#include "../geom/Point2D.h"

class FilePointsLoader
{
    public:
        FilePointsLoader() = default;
        FilePointsLoader(FilePointsLoader const &) = delete;
        FilePointsLoader(FilePointsLoader &&) = delete;
        ~FilePointsLoader();

        FilePointsLoader& operator=(FilePointsLoader const &) = delete;
        FilePointsLoader& operator=(FilePointsLoader &&) = delete;

       std::vector<Point2D> loadPoints(std::string const &filePath) const;
};

#endif // FILEPOINTSLOADER_H
