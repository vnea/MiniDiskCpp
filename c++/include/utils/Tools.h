#ifndef TOOLS_H_INCLUDED
#define TOOLS_H_INCLUDED

#include <cmath>

inline bool doubleAlmostEqual(double a, double b, double epsilon = 1E-6)
{
    return std::fabs(a - b) < epsilon;
}

inline bool doubleAlmostEqualToZero(double a, double epsilon = 1E-6)
{
    return a < epsilon;
}

#endif // TOOLS_H_INCLUDED
