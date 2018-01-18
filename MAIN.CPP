
#include "conio.h"
#include "graphics.h"
#include "stdlib.h"
#include "stdio.h"
#include <iostream.h>
#include "PRIM2D.H"

#define VEC_RAND_MIN_X 100
#define VEC_RAND_MAX_X 400

#define VEC_RAND_MIN_Y 100
#define VEC_RAND_MAX_Y 400

#define MIN_VELOCITY 0.001
#define MAX_VELOCITY 0.005

#define VEC_COLOR 20

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

void RandomizeVectors(vec2d *pVecs, int count) {
	for(int x = 0; x < count; x++) {
		pVecs[x].x = VEC_RAND_MIN_X + rand() % (int)(VEC_RAND_MAX_X - VEC_RAND_MIN_X);
		pVecs[x].y = VEC_RAND_MIN_Y + rand() % (int)(VEC_RAND_MAX_Y - VEC_RAND_MIN_Y);
	}
}

void RandomizeVelocity(vec2d *pVol, int count) {
	for(int x = 0; x < count; x++) {
		pVol[x].x = MIN_VELOCITY + ((float)rand() / (float)(RAND_MAX)) * (MAX_VELOCITY - MIN_VELOCITY);
		pVol[x].y = MIN_VELOCITY + ((float)rand() / (float)(RAND_MAX)) * (MAX_VELOCITY - MIN_VELOCITY);
	}
}

vec2d calcCenter(vec2d *pVecs, int count)
{
	vec2d r;

	r.x = 0;
	r.y = 0;

	for(int x = 0; x < count; x++)
	{
		r += pVecs[x];
	}

	r.x /= (float)count;
	r.y /= (float)count;

	return r;
}

void UpdateVel(vec2d *pVecs, vec2d *pCenter, int count){
	float w = 0.01;
	for(int x = 0; x < count; x++){
		vec2d d = *pCenter - pVecs[x];
		float length = d.Length();
		float ls = (length*length);
		ls = ls < 10000 ? 10000 : ls;
		d.Normalize();
		pVecs[x] += ( d * (1000/(ls)));
	}
}

void UpdateVectors(vec2d *pVecs, vec2d *pVels, int count){
	vec2d center = calcCenter(pVecs, count);
	UpdateVel(pVecs, &center, count);
	for(int x = 0; x < count; x++)
	{
		pVecs[x] += pVels[x];
	}
}

void RenderVectors(vec2d *pVecs, vec2d *pVels, int count, IRenderTarget2D *pRt, Mode13Graphics *g) {
	while(!kbhit()){
		g->WaitForVSync();
		g->ClearScreen(0);
		UpdateVectors(pVecs, pVels, count);
		for(int x = 0; x < count; ++x)
			pRt->Put(pVecs[x], VEC_COLOR);


	}
}

void main() {

	int vecCount = 100;
	vec2d *pVecs = new vec2d[vecCount];
	vec2d *pVels = new vec2d[vecCount];

	RandomizeVectors(pVecs, vecCount);
	RandomizeVelocity(pVels, vecCount);


	Mode13Graphics g;
	IRenderTarget2D *pRt = (IRenderTarget2D*)new RenderTarget2D((IGraphicsDevice*)&g, 500, 500);

	g.SetGraphicsMode();

	RenderVectors(pVecs, pVels, vecCount, pRt,&g);

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