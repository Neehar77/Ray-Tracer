#include "Vec3.hpp"
#include <vector>
#include <iostream>

float scalar_distance(const Vec3 &v1, const Vec3 &v2)
{
        float s_distance;
        s_distance = sqrt(pow(v1[0] - v2[0], 2) + pow(v1[1] - v2[1], 2) + pow(v1[2] - v2[2], 2));
        return s_distance;
}

void Vec3::print()
{
    std::vector<char> path;

    for (std::vector<char>::const_iterator i = path.begin(); i != path.end(); ++i)
        std::cout << *i << ' ';
}
