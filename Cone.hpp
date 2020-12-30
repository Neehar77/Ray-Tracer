// cone objects
#ifndef CONE_HPP
#define CONE_HPP

// other classes we use DIRECTLY in the interface
#include "Object.hpp"
#include "Vec3.hpp"

// classes we only use by pointer or reference
class Appearance;
class Ray;

// cone objects
class Cone : public Object {
    Vec3 d_base, d_axis, d_apex;        // base point and axis vector
    float d_rBase, d_rDiff;     // radius at base and difference to apex
    Vec3 d_scaledAxis;          // axis divided by squared length

public: // constructors
    Cone(const Vec3& color,
        const Vec3& base, float base_radius,
        const Vec3& apex, float apex_radius);

public: // object functions
    const Intersection intersect(const Ray &ray) const;
    Vec3 get_normal_at(Ray& ray);
};

#endif
