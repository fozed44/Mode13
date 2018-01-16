#include <DOS.H>
#include <MATH.H>
#include "graphics.h"

#define __DEBUG_GRAPHICS__

#ifdef __DEBUG_GRAPHICS__
#include <assert.h>
#endif

int Mode13Graphics::GetDeviceWidth() const
{
	return 319;
}

int Mode13Graphics::GetDeviceHeight() const
{
	return 199;
}

void Mode13Graphics::SetGraphicsMode() const
{
	asm {
		mov ax, 0x13
		int 0x10
	}
}

void Mode13Graphics::SetTextMode() const
{
	asm {
		mov ax, 0x03
		int 0x10
	}
}

void Mode13Graphics::WaitForVSync() const
{
	// Wait until any previous retrace has ended
	do{
	} while (inportb(0x3da) & 8);

	// Wait until a new retrace has just begun
	do{
	} while (!(inportb(0x3da) & 8));
}

void Mode13Graphics::PutPixel(int x, int y, unsigned char color) 
{
	#ifdef __DEBUG_GRAPHICS__
	assert(x < 320);
	assert(y < 200);
	#endif

	asm {
		mov di, 0xA000
		mov es, di
		mov ax, 320
		mul [y]
		mov di, ax
		add di, [x]
		mov al, [color]
		stosb
	}
}

void Mode13Graphics::PutLine(int x1, int y1, int x2, int y2, unsigned char color) 
{
	int dx,dy,sdx,sdy,px,py,dxabs,dyabs,i;
	float slope;

	dx=x2-x1;      /* the horizontal distance of the line */
	dy=y2-y1;      /* the vertical distance of the line */
	dxabs=abs(dx);
	dyabs=abs(dy);
	sdx= dx > 0 ? 1 : -1;
	sdy= dy > 0 ? 1 : -1;
	if (dxabs>=dyabs) /* the line is more horizontal than vertical */
	{
		slope=(float)dy / (float)dx;
		for(i=0;i!=dx;i+=sdx)
		{
			px=i+x1;
			py=slope*i+y1;
			PutPixel(px, py,color);
		}
	}
	else /* the line is more vertical than horizontal */
	{
		slope=(float)dx / (float)dy;
		for(i=0;i!=dy;i+=sdy)
		{
			px=slope*i+x1;
			py=i+y1;
			PutPixel(px, py,color);
		}
	}
	PutPixel(x2, y2, color);
}

void Mode13Graphics::PutRect(int x, int y, int width, int height, unsigned char color) 
{

	// Top edge
	PutLine(x, y, x + width, y, color);

	// Right edge
	PutLine(x + width, y, x + width, y + height, color);

	// Left edge
	PutLine(x, y, x, y + height, color);

	// Bottom edge
	PutLine(x, y + height, x + width, y + height, color);
}

void Mode13Graphics::PutFilledRect(int x1, int y1, int width, int height, unsigned char color)
{
	for(int i = 0; i < height; ++i)
	{
		PutLine(x1, y1 + i, x1 + width, y1 + i, color);
	}
}

void Mode13Graphics::ClearScreen(unsigned char color) 
{
	asm {
		mov al, [color]
		mov di, 0xA000
		mov es, di
		mov di, 0x0000
		cld
		mov cx, 0xFA00
		rep stosb
	}
}