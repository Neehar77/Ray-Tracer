#include "objects.h"
#include "vector.h"
#include <math.h>
#include <iostream>
#define PI 3.14159265
using namespace std;


color::color() {
	this->R = 0.0f;
	this->G = 0.0f;
	this->B = 0.0f;
}
color::color(float r, float g, float b) {
	this->R = r;
	this->G = g;
	this->B = b;
}
Ray::Ray() : Origin(0.0f, 0.0f, 0.0f),
direction(),
tvalue(0.0f)
{
}
Ray::Ray(const Ray& r)
	: Origin(r.Origin),
	direction(r.direction),
	tvalue(r.tvalue)
{
}
Ray::Ray(const Vec3D& origin, const Vec3D& direction, float t)
	: Origin(origin),
	direction(direction),
	tvalue(t)
{
}
