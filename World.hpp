// Everything we know about the world
#ifndef World_hpp
#define World_hpp

// other classes we use DIRECTLY in our interface
#include "Vec3.hpp"
#include "ObjectList.hpp"
#include "LightList.hpp"


class World {
public: // public data
    //exponent
    int exponent;
    // image size
    int width, height;
    // background color
    Vec3 background, current_color;
    // co-efficients 
    int diffuse_coeff, reflection_coeff, exponent;
    // near clipping plane distance
    float hither;
    // view origin and basis parameters
    Vec3 eye, w, u, v;
    float dist, left, right, bottom, top;
    // Intensity
    float light_intensity;
    //ray point and direction 
    Vec3 point, ray_direction, normal, total_color;
    //recursion limit
    int recursion_limit = 5;
    // list of objects in the scene
    ObjectList objects;
    LightList lights;

public:                                 
    // read world data from a file
    World(FILE *f); 
};

#endif
