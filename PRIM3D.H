
class vec3d {
public:
	float x;
	float y;
	float z;

	void operator +=(const vec3d& a);
	void operator -=(const vec3d& a);

	float dot(const vec3d& a);
	float cross(const vec3d& a);

	static float cross(const vec3d& a, const vec3d& b);

};

vec3d operator +(const vec3d& a, const vec3d& b);
vec3d operator -(const vec3d& a, const vec3d& b);
float operator *(const vec3d& a, const vec3d& b);

class vertex {
public:
	float x;
	float y;
	float z;
};

class vertex_N {
public:
	float x;
	float y;
	float z;
	
	vec3d _normal;
};

class matrix3x4 {
public:
	float m_data[4][3];	
}

vec3d operator *(const vec3d& v, const matrix3x4 &m);
vec3d operator *(const matrix3x4 &m, const vec3d &v);
matrix3x4 operator *(const matrix3x4 &m1, const matrix3x4 &m2);

class mesh3d {
private:
	vertex *m_pData;

public:
	mesh3d(vector *m_pData);
	~mesh3d();
	
	vertex const * const Get() const;
	mesh3d Clone() const;
	void Transform(const matrix3x4 &m);
};

class mesh_n3d {
private:
	vertex_N *m_pData;
	
public:
	mesh_n3d(vertex_N *pData);
	~mesh_n3d();
	
	vertex_N const * const Get() const;
	mesh_n3d Clone() const;
	void Transform(const matrix_n3d);
};
