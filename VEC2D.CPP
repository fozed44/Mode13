
#include "PRIM2D.H"
#include "MATH.H"


vec2d operator +(const vec2d &a, const vec2d &b)
{
	vec2d result;

	result.x = a.x + b.x;
	result.y = a.y + b.y;

	return result;
}

vec2d operator -(const vec2d &a, const vec2d &b)
{
    vec2d result;

    result.x = a.x - b.x;
    result.y = a.y - b.y;

    return result;
}

float operator *(const vec2d &a, const vec2d &b)
{
    return a.x*b.x+a.y*b.y;
}

void vec2d::operator +=(const vec2d &a)
{
    x += a.x;
	y += a.y;
}

void vec2d::operator -=(const vec2d &a){
    x -= a.x;
    y -= a.y;
}

float vec2d::Length() const
{
    return sqrt(x*x + y*y);
}

void vec2d::Normalize()
{
    float length = Length();
    x /= length;
    y /= length;
}
