#include "vector.h"
#include <cmath>
#include <math.h>

Vec3D::Vec3D()
{
	this->x = 0;
	this->y = 0;
	this->z = 0;
}
Vec3D::Vec3D(float x1, float y1, float z1)
{
	this->x = x1;
	this->y = y1;
	this->z = z1;
}
float Vec3D::normalize()
{
	float l = std::sqrt(x*x + y*y + z*z);
	*this /= l;
	return l;
}
Vec3D Vec3D::normalized()
{
	Vec3D v(*this);
	v.normalize();
	return v;
}
float dot(Vec3D v1, Vec3D v2) 
{
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}
Vec3D cross(Vec3D v1, Vec3D v2)
{
	return Vec3D(v1.y * v2.z - v1.z * v2.y,
		v1.z * v2.x - v1.x * v2.z,
		v1.x * v2.y - v1.y * v2.x);
}
Vec3D& Vec3D::operator =(const Vec3D& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	return *this;
}
Vec3D& Vec3D::operator +=(const Vec3D& v)
{
	x += v.x;
	y += v.y;
	z += v.z;
	return *this;
}
Vec3D& Vec3D::operator -=(const Vec3D& v)
{
	x -= v.x;
	y -= v.y;
	z -= v.z;
	return *this;
}
Vec3D& Vec3D::operator *=(float f)
{
	x *= f;
	y *= f;
	z *= f;
	return *this;
}

Vec3D& Vec3D::operator /=(float f)
{
	x /= f;
	y /= f;
	z /= f;
	return *this;
}
Vec3D& Vec3D::operator *=(const Vec3D& v)
{
	x *= v.x;
	y *= v.y;
	z *= v.z;
	return *this;
}
Vec3D& Vec3D::operator /=(const Vec3D& v)
{
	x /= v.x;
	y /= v.y;
	z /= v.z;
	return *this;
}
Vec3D Vec3D::vector_distance(Vec3D v1, Vec3D v2)
{
	Vec3D distance;
	distance.x = v1.x - v2.x;
	distance.y = v1.y - v2.y;
	distance.z = v1.z - v2.z;
	return distance;
}
float Vec3D::scalar_distance(Vec3D v1, Vec3D v2)
{
	float s_distance;
	s_distance = sqrt(pow(v1.x - v2.x, 2) + pow(v1.y - v2.y, 2) + pow(v1.z - v2.z, 2));
	return s_distance;
}
float Vec3D::length() 
{
	return std::sqrt(x * x + y * y + z * z);
}
inline float Vec3D::length2()
{
	return sqr(x) + sqr(y) + sqr(z);
}