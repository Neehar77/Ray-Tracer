// sphere objects
#ifndef SPHERE_HPP
#define SPHERE_HPP

// other classes we use DIRECTLY in the interface
#include "Object.hpp"
#include "Vec3.hpp"

// classes we only use by pointer or reference
class World;
class Ray;

// sphere objects
class Sphere : public Object {
public:
    Vec3 d_center;
    float d_radius;

public: // constructors
    Sphere() {
        d_center[0] = 0;
        d_center[1] = 0;
        d_center[2] = 0;
        d_radius = 0;
    }
    Sphere(const Vec3 &_color, const Vec3 &_center, float _radius)
        : Object(_color) 
    {
        d_center = _center;
        d_radius = _radius;
    }

public: // object functions
    const Intersection intersect(const Ray &ray) const;
    Vec3 get_normal_at(Ray& ray);
};

#endif
