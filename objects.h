#ifndef objects_h
#define objects_h
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <math.h>
#include "vector.h"

class polygon 
{
public:
	Vec3D v1[20];
	polygon();
	polygon(Vec3D& v);
};
class cones 
{
public:
	Vec3D base, apex;
	float base_r, apex_r;
	cones();
	cones(Vec3D v1, float base_r, Vec3D v2, float apex_r);
};
class sphere {
public:
	Vec3D center, surface_color;
	float radius;
	sphere();
	sphere(Vec3D v, float radius);
};
class color 
{
public:
	float R, G, B;
	color();
	color(float r, float g, float b);
};
class Ray 
{
public:
	Vec3D Origin, direction;
	float tvalue;
	Ray();
	Ray(const Ray& r);
	Ray(const Vec3D& origin, const Vec3D& direction,
		float t);
};
class Intersection_sphere
{
public:
	Ray r1;
	bool intersection(Ray r, sphere s);
};
class Intersection_cone
{
public:
	Ray r1;
	bool intersection2(Ray r, cones c);
};
class Pixel
{
public:
	unsigned char r, g, b;
	Pixel() {}
	Pixel(color c) {
		r = (c.R < 0) ? 0 : (c.R > 1) ? 255 : (unsigned char)(c.R * 255);
		g = (c.G < 0) ? 0 : (c.G > 1) ? 255 : (unsigned char)(c.G * 255);
		b = (c.B < 0) ? 0 : (c.B > 1) ? 255 : (unsigned char)(c.B * 255);
	}
};
#endif

