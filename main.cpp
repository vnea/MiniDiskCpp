#include <chrono>
#include <ctime>
#include <iostream>
#include <limits>
#include <vector>

#include "include/geom/Circle2D.h"
#include "include/utils/FilePointsLoader.h"
#include "include/algorithms/AlgorithmMinCircle.h"

int main()
{
    FilePointsLoader const FPL;
    std::vector<Point2D> points{FPL.loadPoints("samples/test-2.points")};

    AlgorithmMinCircle const AMC;
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();
    //std:: cout << AMC.naiveAlgorithm(points) << std::endl;
    std:: cout << AMC.minidisk(points) << std::endl;

    end = std::chrono::system_clock::now();


    std::chrono::duration<double, std::milli> elapsed_seconds = end - start;
    std::cout << "elapsed time: " << elapsed_seconds.count() << "ms\n";

    return 0;
}
