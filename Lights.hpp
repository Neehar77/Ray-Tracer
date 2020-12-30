#pragma once
#ifndef  light_h
#define light_h
#include "World.hpp"
#include "Object.hpp"


class Light 
{
public:
	Vec3 position, color;
	Light();
	Light(Vec3 p, Vec3 c);
	virtual Vec3 light_position() { return position; }
	virtual Vec3 light_color() { return color; }
};

Light::Light() 
{
	position = Vec3(0, 0, 0);
	color = Vec3(color.r(), color.g(), color.b());
}
Light::Light(Vec3 p, Vec3 c) 
{
	position = p;
	color = c;
}
#endif // ! light_h
