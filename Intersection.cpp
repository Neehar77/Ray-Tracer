// implementation code for Intersection class

// include this class include file FIRST to ensure that it has
// everything it needs for internal self-consistency
#include "Intersection.hpp"
#include "Sphere.hpp"
#include "Cone.hpp"
// other classes used directly in the implementation
#include "Object.hpp"
#include "World.hpp"
#include "Sphere.cpp"
#include "Cone.cpp"
#include "Object.cpp"




// new intersection with object and intersection location
Intersection::Intersection(const Object *_obj, float _t) {
    t = _t;
    d_obj = _obj;
}

// return color for one intersection
const Vec3 
Intersection::color(const World &w) const {

    if (d_obj) {
        return d_obj->color;
    }
    else
        // background color
        return w.background;
}

const Vec3 Intersection::normal(Ray& ray, Object& obj) 
{
    return obj.get_normal_at(ray);
}

