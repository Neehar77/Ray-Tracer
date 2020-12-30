#ifndef vector_manipulation_h
#define vector_manipulation_h
#include <stdio.h>
#include <math.h>

#ifndef PI
#define PI 3.1415926f
#endif

inline float sqr(float n)
{
	return n * n;
}
struct Vec3D {
	float x, y, z;
	Vec3D();
	Vec3D(float x, float y, float z);
	float length();
	Vec3D vector_distance(Vec3D v1, Vec3D v2);
	float scalar_distance(Vec3D v1, Vec3D v2);
	inline float length2();
	Vec3D& operator =(const Vec3D& v);
	Vec3D& operator +=(const Vec3D& v);
	Vec3D& operator -=(const Vec3D& v);
	Vec3D& operator *=(const Vec3D& v);
	Vec3D& operator /=(const Vec3D& v);
	Vec3D& operator *=(float f);
	Vec3D& operator /=(float f);
	Vec3D normalized();
	float normalize();
};

float dot(Vec3D v1, Vec3D v2);
Vec3D cross(Vec3D v1, Vec3D v2);


inline Vec3D operator +(const Vec3D& v1, const Vec3D& v2)
{
	return Vec3D(v1.x + v2.x,
		v1.y + v2.y,
		v1.z + v2.z);
	// TODO: insert return statement here
}

inline Vec3D operator -(const Vec3D& v1, const Vec3D& v2)
{
	return Vec3D(v1.x - v2.x,
		v1.y - v2.y,
		v1.z - v2.z);
	// TODO: insert return statement here
}

inline Vec3D operator *(const Vec3D& v1, const Vec3D& v2)
{
	return Vec3D(v1.x * v2.x,
		v1.y * v2.y,
		v1.z * v2.z);
	// TODO: insert return statement here
}
inline Vec3D operator *(const Vec3D& v, float f)
{
	return Vec3D(v.x * f,
		v.y * f,
		v.z * f);
}
inline Vec3D operator *(float f, const Vec3D& v)
{
	return Vec3D(f * v.x,
		f * v.y,
		f * v.z);
}
inline Vec3D operator /(const Vec3D& v1, const Vec3D& v2)
{
	return Vec3D(v1.x / v2.x,
		v1.y / v2.y,
		v1.z / v2.z);
	// TODO: insert return statement here
}
inline Vec3D operator /(const Vec3D& v, float f)
{
	return Vec3D(v.x / f,
		v.y / f,
		v.z / f);
}
#endif
