
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

class mesh3d {
private:
	vector<vertex> m_data;

public:
	void Add(const vertex& v);
	void Add(float x, float y, float z);
	void Add(float vX, float vY, float vZ, float nX, float nY, float nZ);
};

class mesh_n3d {
private:
	vector<vertex_N> m_data;
	
public:
	void Add(const vertex_N& v);
	void Add(const vertex& v);
	void Add(float x, float y, float z);
	void Add(float vX, float vY, float vZ, float nX, float nY, float nZ);
};