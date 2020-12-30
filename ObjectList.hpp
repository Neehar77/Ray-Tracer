// lists of objects in scene
#ifndef OBJECTLIST_HPP
#define OBJECTLIST_HPP

// other classes we use DIRECTLY in our interface
#include "Intersection.hpp"
#include "Ray.hpp"

// system includes
#include <list>

// classes we only use by pointer or reference
class Object;
class Light;

class ObjectList {
private: // private types
    // list of objects
    typedef std::list<Object*> t_List;
    t_List d_list;
    // list of lights
    

public: // constructor & destructor
    ObjectList() {}
    ~ObjectList();

public:
    // Add an object to the list. Objects should be allocated with
    // new. Objects will be deleted when this ObjectList is destroyed
    void addObject(Object *obj) { d_list.push_back(obj);}
    // Add a light to the list. lights should be allocated with new
    // Lights will be deleted when ObjectList is destroyed
   
public: // computational members
    // trace ray r through all objects, returning first intersection
    const Intersection trace(Ray r) const;
    const int diffuse(Vec3 normal, Vec3 light_to_point);
    const int specular(Vec3 direction, Vec3 light_to_point);
};

#endif
