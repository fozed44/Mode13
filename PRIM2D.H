
#ifndef __PRIM2D__
#define __PRIM2D__

class vec2d {
public:
	float x;
	float y;	

	void operator +=(const vec2d &a);
	void operator -=(const vec2d &a);

	float Length() const;

	void Normalize();
};

vec2d operator +(const vec2d &a, const vec2d &b);
vec2d operator -(const vec2d &a, const vec2d &b);
float operator *(const vec2d &a, const vec2d &b);

/*
class matrix3x3 {
public:
	float _data[3][3];

	static matrix3x3& operator +(const matrix3x3 &a, const matrix3x3 &b);
	static matrix3x3& operator *(const matrix3x3 &a, const matrix3x3 &b);

	matrix3x3& operator *=(const matrix3x3 &a);
};
*/

#endif