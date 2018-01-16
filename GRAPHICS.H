
#ifndef __GRAPHICS__
#define __GRAPHICS__

#include "intrface.h"

class Mode13Graphics  : IGraphicsDevice {
public:
	virtual ~Mode13Graphics(){}

	void SetGraphicsMode() const;
	void SetTextMode() const;
	void WaitForVSync() const;

	int GetDeviceWidth() const;
	int GetDeviceHeight() const;

	virtual void PutPixel(int x, int y, unsigned char color);
	virtual void PutLine(int x1, int y1, int x2, int y2, unsigned char color) ;
	virtual void PutRect(int x1, int y1, int width, int height, unsigned char color);
	virtual void PutFilledRect(int x1, int y1, int width, int height, unsigned char color);
	

	virtual void ClearScreen(unsigned char color);

//	virtual void SetPalletteColor(unsigned char r, unsigned char g, unsigned char b, unsigned char index) const;
};

class RenderTarget2D : IRenderTarget2D {
public:
	RenderTarget2D(IGraphicsDevice *pDevice, float width, float height);
	virtual ~RenderTarget2D(){}

	virtual float GetTargetWidth() const;
	virtual float GetTargetHeight() const;

	virtual void Put(const vec2d& a, unsigned char color);
	virtual void PutLine(const vec2d& a, const vec2d& b, unsigned char color);
	//virtual void PutRect(const vec2d& a, const vec2d& b, unsigned char color);
	//virtual void PutFilledRect(const vec2d& a, const vec2d& b, unsigned char color);
private:
	int vRenderSpaceToDeviceSpace(float renderSpace) const;
	int hRenderSpaceToDeviceSpace(float renderSpace) const;
	IGraphicsDevice *m_pDevice;
	float m_height;
	float m_width;
	float m_deviceWidth;
	float m_deviceHeight;
};


#endif