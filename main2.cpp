#include <iostream>
#include <stdio.h>
#include "file.h"
#include "vector.h"
#include "objects.h"
#include <math.h>
#define PI 3.14159265
using namespace std;


int main()
{
	sphere s1;
	cones c1;
	file f1;
	Pixel* image = new Pixel[f1.nx * f1.ny];
	Pixel* pixel = image;
	Ray r1;
	float d = 0, left, right, bottom, top, a, us, vs, t1, t2, delta;
	Vec3D ud, vd, wd, dis_or_cen, s, direction1, e_to_sphere, pixel1;
	int l1 = 0, no_of_spheres, no_of_cones, x, y;
	void file_read();
	x = f1.nx;
	y = f1.ny;
	no_of_spheres = sizeof(f1.s1) / sizeof(*f1.s1);
	no_of_cones = sizeof(f1.c1) / sizeof(*f1.c1);
	dis_or_cen = dis_or_cen.vector_distance(f1.eye, f1.center_of_plane);
	d = dis_or_cen.length();
	wd = dis_or_cen / d;
	l1 = cross(f1.up_vector, wd).length();
	ud = cross(f1.up_vector, wd) / l1;
	vd = cross(wd, ud);
	a = f1.angle / 2.0;
	top = d * tan(a * PI / 180);
	right = top;
	left = -1 * top;
	bottom = left;
	Vec3D v_cone, t, e_to_cone;
	float theta, height;
	for (int j = 0; j < y; ++j)
	{
		for (int i = 0; i < x; ++i, ++pixel)
		{
			us = left + (right - left) * (i + 0.5) / x;
			vs = top + (bottom - top) * (j + 0.5) / y;
			s = f1.eye + ud * us + vd * vs - wd * d;
			direction1 = s - f1.eye;
			
			for (int i = 0; i < no_of_spheres; i++)
			{
				e_to_sphere = f1.eye - f1.center_of_sphere[i];
				float a = direction1.length2();
				float b = 2 * dot(direction1, e_to_sphere);
				float c = e_to_sphere.length2() - sqr(s1.radius);
				float delta = sqr(b) - 4 * a * c;
				if (delta > 0)
				{
					t1 = (-b - sqrt(delta)) / (2 * a);
					t2 = (-b + sqrt(delta)) / (2 * a);
					if (t1 > t2)
					{
						std::swap(t1, t2);
						pixel1 = f1.eye + direction1 * t2;
					}
					else
					{
						pixel1 = f1.eye + direction1 * t1;
						*pixel = f1.fill_object;
					}

				}
				else if (delta == 0)
				{
					t1 = t2 = (-b) / (2 * a);
					pixel1 = f1.eye + direction1 * t1;
					*pixel = f1.fill_object;
				}
				else {
					f1.background;
				}
			}
			for (int j = 0; j < no_of_cones; j++)
			{
				height = t.scalar_distance(c1.base[j], c1.apex[j]);
				theta = atan(c1.base_r / height);
				v_cone = t.vector_distance(c1.base[j], c1.apex[j]);
				e_to_cone = f1.eye - c1.apex[j];
				float a1 = sqr(dot(direction1, v_cone)) - sqr(cos(theta));
				float b1 = 2 * (dot(direction1, v_cone) * dot(e_to_cone, v_cone)) - dot(direction1, e_to_cone * sqr(cos(theta)));
				float c1 = sqr(dot(e_to_cone, v_cone)) - dot(e_to_cone, e_to_cone * sqr(cos(theta)));
				float delta = sqr(b1) - 4 * a1 * c1;
				if (delta > 0)
				{
					t1 = (-b1 - sqrt(delta)) / (2 * a1);
					t2 = (-b1 + sqrt(delta)) / (2 * a1);
					if (t1 > t2)
					{
						std::swap(t1, t2);
						pixel1 = f1.eye + direction1 * t2;
					}
					else {
						pixel1 = f1.eye + direction1 * t1;
						*pixel = f1.fill_object;
					}
				}
				else if (delta == 0)
				{
					t1 = t2 = (-b1) / (2 * a1);
					pixel1 = f1.eye + direction1 * t1;
					*pixel = f1.fill_object;
				}
				else {
					f1.background;
				}
			}

		}
	}
	std::ofstream ofs("./trace.ppm", std::ios::out | std::ios::binary);
	ofs << "P6\n" << f1.nx << " " << f1.ny << "\n255\n";
	for (unsigned i = 0; i < f1.nx * f1.ny; ++i)
	{
		ofs << (unsigned char)(__min(float(1), image[i].r) * 255) <<
			(unsigned char)(__min(float(1), image[i].g) * 255) <<
			(unsigned char)(__min(float(1), image[i].b) * 255);
	}
}





