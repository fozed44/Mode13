
#ifndef __INTERFACES__
#define __INTERFACES__

#include "PRIM2D.H"
#include "PRIM3D.H"

class IGraphicsDevice {
public:
	virtual int GetDeviceWidth() const = 0;
	virtual int GetDeviceHeight() const = 0;
	virtual void PutPixel(int x, int y, unsigned char color) = 0;
	virtual void PutLine(int x1, int y1, int x2, int y2, unsigned char color) = 0;
	virtual void PutRect(int x1, int y1, int width, int height, unsigned char color) = 0;
	virtual void PutFilledRect(int x1, int y1, int width, int height, unsigned char color) = 0;
	virtual ~IGraphicsDevice(){}
};

class IRenderTarget2D {
public:
	virtual ~IRenderTarget2D(){}

	virtual float GetTargetWidth()  const = 0;
	virtual float GetTargetHeight() const = 0;

	virtual void Put(const vec2d& a, unsigned char color) = 0;
	virtual void PutLine(const vec2d& a, const vec2d& b, unsigned char color) = 0;
	//virtual void PutRect(const vec2d& a, const vec2d& b, unsigned char color) = 0;
	//virtual void PutFilledRect(const vec2d& a, const vec2d& b, unsigned char color) = 0;
};

class IRenderTarget3D {
	virtual ~IRenderTarget3D(){}

	virtual void Render(const vertex& v) = 0;
	virtual void Render(const mesh& v) = 0;
};

class IDrawable {
public:
	virtual void Draw(const IRenderTarget2D &target) const = 0;
	virtual ~IDrawable(){}
};

class IAnimatable {
public:
	virtual void Tick(int time) = 0;
	virtual ~IAnimatable(){}
};

#endif