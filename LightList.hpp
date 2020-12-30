#pragma once
#ifndef  LightList_h
#define  LightList_h
#include "Ray.hpp"
#include "Vec3.hpp"
#include "World.hpp"
#include <list>

class Light;

class LightList {
public:
	typedef std::list<Light*> l_list;
	l_list light_list;
public: // constructor & destructor
	LightList() {}
	~LightList();
public:
	void addObject(Light* obj) { light_list.push_back(obj); }
	const Vec3 ray_color(Ray &ray, World &w);

};
#endif // ! LightList_h
