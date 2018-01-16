#include "conio.h"
#include "graphics.h"
#include "stdlib.h"
#include "stdio.h"
#include <iostream.h>
#include "PRIM2D.H"

void PutRandPixel(IRenderTarget2D *pRt) {
	float width = pRt->GetTargetWidth();
	float height = pRt->GetTargetHeight();

	while(!kbhit()){
		vec2d v;
		v.x = rand() % (int)width;
		v.y = rand() % (int)height;

		pRt->Put(v, rand() % 200);
	}

}

void RandClear(IRenderTarget2D *pRt) {
	float width = pRt->GetTargetWidth();
	float height = pRt->GetTargetHeight();

	while(!kbhit()) {
		vec2d v;
		v.x = rand() % (int)width;
		v.y = rand() % (int)height;

		pRt->Put(v, 0);
	}
}

void main() {

	Mode13Graphics g;
	IRenderTarget2D *pRt = (IRenderTarget2D*)new RenderTarget2D((IGraphicsDevice*)&g, 500, 500);

	g.SetGraphicsMode();

	PutRandPixel(pRt);

	getch();

	RandClear(pRt);

	g.SetTextMode();
	
	delete pRt;
}
/*
#define RANDX (rand() % 320)
#define RANDY (rand() % 200)
#define RAND_COLOR (rand() % 255)

void RandLines(Mode13Graphics& graphics)
{
	while(!kbhit())
	{
		graphics.WaitForVSync();
		graphics.PutLine(
			RANDX,
			RANDY,
			RANDX,
			RANDY,
			RAND_COLOR
		);
	}
};

void RandPixels(Mode13Graphics& graphics){
	while(!kbhit()){
		graphics.PutPixel(
			RANDX,
			RANDY,
			RAND_COLOR
		);
	}
};


void RandRects(Mode13Graphics& graphics){
	while(!kbhit())
	{
		graphics.WaitForVSync();
		int x = RANDX;
		int y = RANDY;
		int width = rand() % (320 - x);
		int height = rand() % (200 - y);
		graphics.PutRect(
			x,y,
			width, height,
			RAND_COLOR
		);
	}
}


void RandFilledRects(Mode13Graphics& graphics){
	while(!kbhit())
	{
		graphics.WaitForVSync();
		int x = RANDX;
		int y = RANDY;
		int width = rand() % (320 - x);
		int height = rand() % (200 - y);
		graphics.PutFilledRect(
			x,y,
			width, height,
			RAND_COLOR
		);
	}

}

void RandClearScreen(Mode13Graphics& graphics) {
	while(!kbhit())
	{
		graphics.WaitForVSync();
		graphics.ClearScreen(RAND_COLOR);
	}
}

void LineTest(Mode13Graphics& g)
{

	for(int x = 0; x != 320; x++)
	{
		g.ClearScreen(0);
		g.PutLine(0, 10, x, 10, 1);
		g.PutPixel(0,11,1);
		g.PutPixel(x,11,1);

		int y = x;
		if(y > 199) y = 199;

		g.PutLine(10, 0, 10, y, 1);
		g.PutPixel(11,0, 1);
		g.PutPixel(11,y, 1);

		getch();

	}
}

int main(){
	
	cout << "testing";

	return 0;
}

*/