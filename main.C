#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <DOS.h>
#include <time.h>

float maxx, maxy, midx, midy, s;

int k = 0, cli, clj;
int rn1, rn2, rn3, rn4, order[100][100];
float xa[100], ya[100], cxa[100], cya[100], sa[100], da[100], ba[100];
char msg[60];

void rotline(float x1, float y1, float x2, float y2, float theta, float cx, float cy)
{
	float r1, r2, d, initd1, initd2;
	d = theta*(3.142/180);
	initd1 = atan2((y1-cy),(x1-cx));
	initd2 = atan2((y2-cy),(x2-cx));
	r1 = sqrt((x1-cx)*(x1-cx)+(y1-cy)*(y1-cy));
	r2 = sqrt((x2-cx)*(x2-cx)+(y2-cy)*(y2-cy));
	x1 = r1*cos(d+initd1);
	y1 = r1*sin(d+initd1);
	x2 = r2*cos(d+initd2);
	y2 = r2*sin(d+initd2);
	line(cx+x1, cy+y1, cx+x2, cy+y2);
}

void rotcircle(float x, float y, float rad, float theta, float cx, float cy)
{
	float r, d, initd;
	d = theta*(3.142/180);
	initd = atan2((y-cy),(x-cx));
	r = sqrt((x-cx)*(x-cx)+(y-cy)*(y-cy));
	x = r*cos(d+initd);
	y = r*sin(d+initd);
	circle(cx+x, cy+y, rad);
}

void rotfloodfill(float x, float y, int color, float theta, float cx, float cy)
{
	float r, d, initd;
	d = theta*(3.142/180);
	initd = atan2((y-cy),(x-cx));
	r = sqrt((x-cx)*(x-cx)+(y-cy)*(y-cy));
	x = r*cos(d+initd);
	y = r*sin(d+initd);
	floodfill(cx+x, cy+y, color);
}

void car1(float x, float y, float cx, float cy, float s, float theta, int breaks)
{
	//Headlights
	rotline(x+3*s, y+0*s, x+9*s, y+0*s, theta, cx, cy);
	rotline(x+9*s, y+0*s, x+9*s, y+1*s, theta, cx, cy);
	rotline(x+9*s, y+1*s, x+3*s, y+1*s, theta, cx, cy);
	rotline(x+3*s, y+1*s, x+3*s, y+0*s, theta, cx, cy);
	rotline(x+33*s, y+0*s, x+39*s, y+0*s, theta, cx, cy);
	rotline(x+39*s, y+0*s, x+39*s, y+1*s, theta, cx, cy);
	rotline(x+39*s, y+1*s, x+33*s, y+1*s, theta, cx, cy);
	rotline(x+33*s, y+1*s, x+33*s, y+0*s, theta, cx, cy);
	rotline(x+1*s, y+3*s, x+3*s, y+1*s, theta, cx, cy);
	rotline(x+1*s, y+3*s, x+1*s, y+25*s, theta, cx, cy);
	rotline(x+1*s, y+25*s, x+3*s, y+27*s, theta, cx, cy);
	rotline(x+41*s, y+3*s, x+41*s, y+25*s, theta, cx, cy);
	rotline(x+39*s, y+1*s, x+41*s, y+3*s, theta, cx, cy);
	rotline(x+41*s, y+25*s, x+39*s, y+27*s, theta, cx, cy);
	rotline(x+9*s, y+1*s, x+11*s, y+3*s, theta, cx, cy);
	rotline(x+33*s, y+1*s, x+31*s, y+3*s, theta, cx, cy);

	//Rear bumpers
	rotline(x+3*s, y+59*s, x+1*s, y+61*s, theta, cx, cy);
	rotline(x+1*s, y+61*s, x+1*s, y+76*s, theta, cx, cy);
	rotline(x+1*s, y+76*s, x+6*s, y+81*s, theta, cx, cy);
	rotline(x+6*s, y+81*s, x+36*s, y+81*s, theta, cx, cy);
	rotline(x+36*s, y+81*s, x+41*s, y+76*s, theta, cx, cy);
	rotline(x+41*s, y+76*s, x+41*s, y+61*s, theta, cx, cy);
	rotline(x+41*s, y+61*s, x+39*s, y+59*s, theta, cx, cy);
	setcolor(4);
	rotcircle(x+6*s, y+76*s, 2*s, theta, cx, cy);
	rotcircle(x+36*s, y+76*s, 2*s, theta, cx, cy);
	setcolor(15);
	setfillstyle(SOLID_FILL, 4);
	if(breaks == 1)
	{
		rotfloodfill(x+6*s, y+76*s, 4, theta, cx, cy);
		rotfloodfill(x+36*s, y+76*s, 4, theta, cx, cy);
	}
	setfillstyle(SOLID_FILL, 15);

	//Body
	rotline(x+12*s, y+1*s, x+30*s, y+1*s, theta, cx, cy);
	rotline(x+30*s, y+1*s, x+31*s, y+3*s, theta, cx, cy);
	rotline(x+31*s, y+3*s, x+36*s, y+21*s, theta, cx, cy);
	rotline(x+36*s, y+21*s, x+41*s, y+31*s, theta, cx, cy);
	rotline(x+41*s, y+31*s, x+41*s, y+51*s, theta, cx, cy);
	rotline(x+41*s, y+51*s, x+36*s, y+71*s, theta, cx, cy);
	rotline(x+36*s, y+71*s, x+28*s, y+79*s, theta, cx, cy);
	rotline(x+28*s, y+79*s, x+14*s, y+79*s, theta, cx, cy);
	rotline(x+14*s, y+79*s, x+6*s, y+71*s, theta, cx, cy);
	rotline(x+6*s, y+71*s, x+1*s, y+51*s, theta, cx, cy);
	rotline(x+1*s, y+51*s, x+1*s, y+31*s, theta, cx, cy);
	rotline(x+1*s, y+31*s, x+6*s, y+21*s, theta, cx, cy);
	rotline(x+6*s, y+21*s, x+11*s, y+3*s, theta, cx, cy);
	rotline(x+11*s, y+3*s, x+12*s, y+1*s, theta, cx, cy);

	//Windows
	rotline(x+11*s, y+61*s, x+31*s, y+61*s, theta, cx, cy);
	rotline(x+31*s, y+61*s, x+31*s, y+71*s, theta, cx, cy);
	rotline(x+31*s, y+71*s, x+11*s, y+71*s, theta, cx, cy);
	rotline(x+11*s, y+71*s, x+11*s, y+61*s, theta, cx, cy);
	rotline(x+36*s, y+61*s, x+39*s, y+42*s, theta, cx, cy);
	rotline(x+39*s, y+42*s, x+36*s, y+42*s, theta, cx, cy);
	rotline(x+36*s, y+42*s, x+36*s, y+61*s, theta, cx, cy);
	rotline(x+36*s, y+26*s, x+39*s, y+40*s, theta, cx, cy);
	rotline(x+39*s, y+40*s, x+36*s, y+40*s, theta, cx, cy);
	rotline(x+36*s, y+40*s, x+36*s, y+26*s, theta, cx, cy);
	rotline(x+6*s, y+61*s, x+6*s, y+42*s, theta, cx, cy);
	rotline(x+6*s, y+42*s, x+3*s, y+42*s, theta, cx, cy);
	rotline(x+3*s, y+42*s, x+6*s, y+61*s, theta, cx, cy);
	rotline(x+6*s, y+26*s, x+6*s, y+40*s, theta, cx, cy);
	rotline(x+6*s, y+40*s, x+3*s, y+40*s, theta, cx, cy);
	rotline(x+3*s, y+40*s, x+6*s, y+26*s, theta, cx, cy);
	rotline(x+8*s, y+21*s, x+34*s, y+21*s, theta, cx, cy);
	rotline(x+34*s, y+21*s, x+32*s, y+23*s, theta, cx, cy);
	rotline(x+32*s, y+23*s, x+10*s, y+23*s, theta, cx, cy);
	rotline(x+10*s, y+23*s, x+8*s, y+21*s, theta, cx, cy);
	rotfloodfill(x+24*s, y+66*s, 15, theta, cx, cy);
	rotfloodfill(x+21*s, y+22*s, 15, theta, cx, cy);
	rotfloodfill(x+5*s, y+44*s, 15, theta, cx, cy);
	rotfloodfill(x+5*s, y+36*s, 15, theta, cx, cy);
	rotfloodfill(x+37*s, y+44*s, 15, theta, cx, cy);
	rotfloodfill(x+37*s, y+36*s, 15, theta, cx, cy);

	//Bonnet
	rotline(x+9*s, y+19*s, x+13*s, y+3*s, theta, cx, cy);
	rotline(x+13*s, y+3*s, x+19*s, y+3*s, theta, cx, cy);
	rotline(x+19*s, y+3*s, x+19*s, y+19*s, theta, cx, cy);
	rotline(x+19*s, y+19*s, x+9*s, y+19*s, theta, cx, cy);
	rotline(x+23*s, y+19*s, x+23*s, y+3*s, theta, cx, cy);
	rotline(x+23*s, y+3*s, x+29*s, y+3*s, theta, cx, cy);
	rotline(x+29*s, y+3*s, x+33*s, y+19*s, theta, cx, cy);
	rotline(x+33*s, y+19*s, x+23*s, y+19*s, theta, cx, cy);

}

void road(float s)
{
	int x, y, dash=20*s;
	line(midx-100*s, 0, midx-100*s, midy-100*s);
	line(midx-100*s, midy-100*s, 0, midy-100*s);
	line(0, midy+100*s, midx-100*s, midy+100*s);
	line(midx-100*s, midy+100*s, midx-100*s, maxy);
	line(midx+100*s, maxy, midx+100*s, midy+100*s);
	line(midx+100*s, midy+100*s, maxx, midy+100*s);
	line(maxx, midy-100*s, midx+100*s, midy-100*s);
	line(midx+100*s, midy-100*s, midx+100*s, 0);

	for(x=midx+100*s; x<=maxx; x+=2*dash)
	{
		line(x, midy, x+dash, midy);
	}

	for(x=midx-100*s; x>=0; x-=2*dash)
	{
		line(x, midy, x-dash, midy);
	}

	for(y=midy-100*s; y>=0; y-=2*dash)
	{
		line(midx, y, midx, y-dash);
	}

	for(y=midy+100*s; y<=maxy; y+=2*dash)
	{
		line(midx, y, midx, y+dash);
	}
}

void signals(float s, int signalNo, int red, int yellow, int green)
{
	int signalSize = 60;

	setcolor(15);
	rectangle(midx-110*s, midy-110*s, midx-110*s-s*signalSize, midy-110*s-s*signalSize/3);
	setcolor(4);
	setfillstyle(SOLID_FILL, 4);
	circle(midx-110*s-s*signalSize/6, midy-110*s-s*signalSize/6, s*signalSize/6-s*2);
	if(red == 1 && signalNo == 4)
	{
		floodfill(midx-110*s-s*signalSize/6, midy-110*s-s*signalSize/6, 4);
	}
	setcolor(14);
	setfillstyle(SOLID_FILL, 14);
	circle(midx-s*110-3*s*signalSize/6, midy-110*s-s*signalSize/6, s*signalSize/6-s*2);
	if(yellow == 1 && signalNo == 4)
	{
		floodfill(midx-s*110-3*s*signalSize/6, midy-110*s-s*signalSize/6, 14);
	}
	setcolor(2);
	setfillstyle(SOLID_FILL, 2);
	circle(midx-s*110-5*s*signalSize/6, midy-110*s-s*signalSize/6, s*signalSize/6-s*2);
	if(green == 1 && signalNo == 4)
	{
		floodfill(midx-s*110-5*s*signalSize/6, midy-110*s-s*signalSize/6, 2);
	}


	setcolor(15);
	rectangle(midx+s*110, midy-s*110, midx+s*110+s*signalSize/3, midy-s*110-s*signalSize);
	setcolor(4);
	setfillstyle(SOLID_FILL, 4);
	circle(midx+s*110+s*signalSize/6, midy-s*110-s*signalSize/6, s*signalSize/6-s*2);
	if(red == 1 && signalNo == 3)
	{
		floodfill(midx+s*110+s*signalSize/6, midy-s*110-s*signalSize/6, 4);
	}
	setcolor(14);
	setfillstyle(SOLID_FILL, 14);
	circle(midx+s*110+s*signalSize/6, midy-s*110-s*3*signalSize/6, s*signalSize/6-s*2);
	if(yellow == 1 && signalNo == 3)
	{
		floodfill(midx+s*110+s*signalSize/6, midy-s*110-s*3*signalSize/6, 14);
	}
	setcolor(2);
	setfillstyle(SOLID_FILL, 2);
	circle(midx+s*110+s*signalSize/6, midy-s*110-s*5*signalSize/6, s*signalSize/6-s*2);
	if(green == 1 && signalNo == 3)
	{
		floodfill(midx+s*110+s*signalSize/6, midy-s*110-s*5*signalSize/6, 2);
	}

	setcolor(15);
	rectangle(midx+s*110, midy+s*110, midx+s*110+s*signalSize, midy+s*110+s*signalSize/3);
	setcolor(4);
	setfillstyle(SOLID_FILL, 4);
	circle(midx+s*110+s*signalSize/6, midy+s*110+s*signalSize/6, s*signalSize/6-s*2);
	if(red == 1 && signalNo == 2)
	{
		floodfill(midx+s*110+s*signalSize/6, midy+s*110+s*signalSize/6, 4);
	}
	setcolor(14);
	setfillstyle(SOLID_FILL, 14);
	circle(midx+s*110+s*3*signalSize/6, midy+s*110+s*signalSize/6, s*signalSize/6-s*2);
	if(yellow == 1 && signalNo == 2)
	{
		floodfill(midx+s*110+s*3*signalSize/6, midy+s*110+s*signalSize/6, 14);
	}
	setcolor(2);
	setfillstyle(SOLID_FILL, 2);
	circle(midx+s*110+s*5*signalSize/6, midy+s*110+s*signalSize/6, s*signalSize/6-s*2);
	if(green == 1 && signalNo == 2)
	{
		floodfill(midx+s*110+s*5*signalSize/6, midy+s*110+s*signalSize/6, 2);
	}

	setcolor(15);
	rectangle(midx-s*110, midy+s*110, midx-s*110-s*signalSize/3, midy+s*110+s*signalSize);
	setcolor(4);
	setfillstyle(SOLID_FILL, 4);
	circle(midx-s*110-s*signalSize/6, midy+s*110+s*signalSize/6, s*signalSize/6-s*2);
	if(red == 1 && signalNo == 1)
	{
		floodfill(midx-s*110-s*signalSize/6, midy+s*110+s*signalSize/6, 4);
	}
	setcolor(14);
	setfillstyle(SOLID_FILL, 14);
	circle(midx-s*110-s*signalSize/6, midy+s*110+3*s*signalSize/6, s*signalSize/6-s*2);
	if(yellow == 1 && signalNo == 1)
	{
		floodfill(midx-s*110-s*signalSize/6, midy+s*110+3*s*signalSize/6, 14);
	}
	setcolor(2);
	setfillstyle(SOLID_FILL, 2);
	circle(midx-s*110-s*signalSize/6, midy+s*110+5*s*signalSize/6, s*signalSize/6-s*2);
	if(green == 1 && signalNo == 1)
	{
		floodfill(midx-s*110-s*signalSize/6, midy+s*110+5*s*signalSize/6, 2);
	}
	setcolor(15);
}

void counters(float s)
{
	int counterSize = 100*s;
	setfillstyle(SOLID_FILL, 13);
	setcolor(13);
	rectangle(maxx-10, maxy-10, maxx-10-counterSize, maxy-10-counterSize);
	rectangle(maxx-10-counterSize/10, maxy-10-counterSize/10, maxx-10-counterSize+counterSize/10, maxy-10-counterSize+counterSize/10);
	floodfill(maxx-15, maxy-15, 13);
	setfillstyle(SOLID_FILL, 1);
	setcolor(1);
	rectangle(maxx-10, 10, maxx-10-counterSize, 10+counterSize);
	rectangle(maxx-10-counterSize/10, 10+counterSize/10, maxx-10-counterSize+counterSize/10, 10+counterSize-counterSize/10);
	floodfill(maxx-15, 15, 1);
	setfillstyle(SOLID_FILL, 10);
	setcolor(10);
	rectangle(10, maxy-10, 10+counterSize, maxy-10-counterSize);
	rectangle(10+counterSize/10, maxy-10-counterSize/10, 10+counterSize-counterSize/10, maxy-10-counterSize+counterSize/10);
	floodfill(15, maxy-15, 10);
	setfillstyle(SOLID_FILL, 11);
	setcolor(11);
	rectangle(10, 10, 10+counterSize, 10+counterSize);
	rectangle(10+counterSize/10, 10+counterSize/10, 10+counterSize-counterSize/10, 10+counterSize-counterSize/10);
	floodfill(15, 15, 11);
	setfillstyle(SOLID_FILL, 15);
	setcolor(15);
}

void printedcars(float x, float y, float cx, float cy, float s, float d, int b, int k)
{
	int i, addCar=-690;
	if(x != addCar && y != addCar && cx != addCar && cy != addCar && s != addCar && d != addCar && b != addCar)
	{
		xa[k-1] = x;
		ya[k-1] = y;
		cxa[k-1] = cx;
		cya[k-1] = cy;
		sa[k-1] = s;
		da[k-1] = d;
		ba[k-1] = b;
	}
	else
	{
		k--;
	}
	for(i=0; i<k; i++)
	{
		car1(xa[i], ya[i], cxa[i], cya[i], sa[i], da[i], ba[i]);
	}
}

void printcars(int rn, float degree)
{
	int rncar, i, j, b=0;
	float speed = 3;

	randomize();
	rncar = rand() % 1;

	for(i = 0; i<rn; i++)
	{
		k++;
		j = 100;
		while(j != -1000 && !kbhit())
		{
			//cleardevice();
			b = 0;
			if(j <= 5)
			{
				b = 1;
			}
			if(i%2 == 0)
			{
				car1(midx-95, j+midy+100+80*(i/2), midx, midy, 0.9, degree, b);
				printedcars(midx-95, j+midy+100+80*(i/2), midx, midy, 0.9, degree, b, k);
			}
			else
			{
				car1(midx-46, j+midy+100+80*(i/2), midx, midy, 0.9, degree, b);
				printedcars(midx-46, j+midy+100+80*(i/2), midx, midy, 0.9, degree, b, k);
			}
			j -= 1*speed;
			if(j == -2)
			{
				while(j != 0)
				{
					cleardevice();
					sprintf(msg, "%d", rn1);
					outtextxy(42, maxy-110, msg);
					delay(rn1*rn1);
					sprintf(msg, "%d", rn2);
					outtextxy(maxx-100+22, maxy-110, msg);
					delay(rn2*rn2);
					sprintf(msg, "%d", rn3);
					outtextxy(maxx-100+22, 10, msg);
					delay(rn3*rn3);
					sprintf(msg, "%d", rn4);
					outtextxy(42, 10, msg);
					signals(1, 1, 1, 0, 0);
					signals(1, 2, 1, 0, 0);
					signals(1, 3, 1, 0, 0);
					signals(1, 4, 1, 0, 0);
					counters(1);
					road(1);
					if(i%2 == 0)
					{
						car1(midx-95, j+midy+100+80*(i/2), midx, midy, 0.9, degree, b);
						printedcars(midx-95, j+midy+100+80*(i/2), midx, midy, 0.9, degree, b, k);
					}
					else
					{
						car1(midx-46, j+midy+100+80*(i/2), midx, midy, 0.9, degree, b);
						printedcars(midx-46, j+midy+100+80*(i/2), midx, midy, 0.9, degree, b, k);
					}
					j += 1;
					delay(50);
				}
				j = -1000;
			}
			delay(40);
			cleardevice();
			sprintf(msg, "%d", rn1);
			outtextxy(42, maxy-110, msg);
			delay(rn1*rn1);
			sprintf(msg, "%d", rn2);
			outtextxy(maxx-100+22, maxy-110, msg);
			delay(rn2*rn2);
			sprintf(msg, "%d", rn3);
			outtextxy(maxx-100+22, 10, msg);
			delay(rn3*rn3);
			sprintf(msg, "%d", rn4);
			outtextxy(42, 10, msg);
			signals(1, 1, 1, 0, 0);
			signals(1, 2, 1, 0, 0);
			signals(1, 3, 1, 0, 0);
			signals(1, 4, 1, 0, 0);
			counters(1);
			road(1);
			b = 1;
		}
		if(i%2 == 0)
		{
			printedcars(midx-95, midy+100+80*(i/2), midx, midy, 0.9, degree, b, k);
		}
		else
		{
			printedcars(midx-46, midy+100+80*(i/2), midx, midy, 0.9, degree, b, k);
		}
	}
}

void printLanes(int numCars, int laneNum)
{
	int i;
	for(i = 0; i<numCars; i++)
	{
		if(i%2 == 0)
		{
			car1(midx-96, midy+100+80*(i/2), midx, midy, 0.9, 90-90*laneNum, 1);
		}
		else
		{
			car1(midx-46, midy+100+80*(i/2), midx, midy, 0.9, 90-90*laneNum, 1);
		}
	}
}

void SJF(int rn1, int rn2, int rn3, int rn4)
{
	int i, j, temp;
	order[0][0] = rn1;
	order[0][1] = rn2;
	order[0][2] = rn3;
	order[0][3] = rn4;
	for(i=0; i<4; i++)
	{
		order[1][i] = i+1;
	}
	for(j=0; j<4; j++)
	{
		for(i=0; i<3; i++)
		{
			if(order[0][i] >= order[0][i+1])
			{
				temp = order[0][i];
				order[0][i] = order[0][i+1];
				order[0][i+1] = temp;
				temp = order[1][i];
				order[1][i] = order[1][i+1];
				order[1][i+1] = temp;
			}
		}
	}
}

void bottom(int numCars)
{
	int a=3, d1, d2, flag=0, rndm;
	float iniy=midy+100, iniyTurn, iniy1, iniy2, iniy3;
	iniy1=iniy;
	iniy2=iniy+80;
	iniy3 = midy-40;
	if(numCars == 0)
	{
		flag = 1;
		goto bot;
	}
	while(iniy >= midy+100-40 && !kbhit())
	{
		cleardevice();
		sprintf(msg, "%d", rn1);
		outtextxy(42, maxy-110, msg);
		sprintf(msg, "%d", rn2);
		outtextxy(maxx-100+22, maxy-110, msg);
		sprintf(msg, "%d", rn3);
		outtextxy(maxx-100+22, 10, msg);
		sprintf(msg, "%d", rn4);
		outtextxy(42, 10, msg);
		counters(1);
		for(clj=cli+1; clj<4; clj++)
		{
			printLanes(order[0][clj], order[1][clj]);
		}
		road(1);
		signals(1, 1, 0, 0, 1);
		signals(1, 2, 1, 0, 0);
		signals(1, 3, 1, 0, 0);
		signals(1, 4, 1, 0, 0);
		if(numCars >= 1)
		{
			car1(midx-96, iniy, midx, midy, 0.9, 90+90*a, 0);
		}
		if(iniy1-5 >= iniy)
		{
			if(numCars >= 3)
			{
				car1(midx-96, iniy+80+5, midx, midy, 0.9, 90+90*a, 0);
			}
			if(numCars >= 4)
			{
				car1(midx-46, iniy+80+5, midx, midy, 0.9, 90+90*a, 0);
			}
		}
		else
		{
			if(numCars >= 3)
			{
				car1(midx-96, iniy1+80, midx, midy, 0.9, 90+90*a, 1);
			}
			if(numCars >= 4)
			{
				car1(midx-46, iniy1+80, midx, midy, 0.9, 90+90*a, 1);
			}
		}
		if(numCars >= 2)
		{
			car1(midx-46, iniy, midx, midy, 0.9, 90+90*a, 0);
		}
		delay(25);
		iniy--;
	}
	d1 = 0;
	iniy2 = iniy;
	while(d1 >= -90 && !kbhit())
	{
		cleardevice();
		sprintf(msg, "%d", rn1);
		outtextxy(42, maxy-110, msg);
		sprintf(msg, "%d", rn2);
		outtextxy(maxx-100+22, maxy-110, msg);
		sprintf(msg, "%d", rn3);
		outtextxy(maxx-100+22, 10, msg);
		sprintf(msg, "%d", rn4);
		outtextxy(42, 10, msg);
		counters(1);
		for(clj=cli+1; clj<4; clj++)
		{
			printLanes(order[0][clj], order[1][clj]);
		}
		road(1);
		signals(1, 1, 0, 0, 1);
		signals(1, 2, 1, 0, 0);
		signals(1, 3, 1, 0, 0);
		signals(1, 4, 1, 0, 0);
		if(numCars >= 1)
		{
			car1(midx-96, midy+100-40, midx-100, midy+100, 0.9, d1, 1);
		}
		if(numCars >= 3)
		{
			car1(midx-96, iniy+80+5, midx, midy, 0.9, 90+90*a, 1);
		}
		if(numCars >= 2)
		{
			car1(midx-46, iniy2, midx, midy, 0.9, 90+90*a, 0);
		}
		if(numCars >= 4)
		{
			car1(midx-46, iniy2+80+5, midx, midy, 0.9, 90+90*a, 0);
		}
		iniy2--;
		d1--;
		delay(10);
	}
	iniyTurn = midy-100-40;
	d1 = d2 = 0;
	while(flag != 1 >= -160 && !kbhit())
	{
		cleardevice();
		sprintf(msg, "%d", rn1);
		outtextxy(42, maxy-110, msg);
		sprintf(msg, "%d", rn2);
		outtextxy(maxx-100+22, maxy-110, msg);
		sprintf(msg, "%d", rn3);
		outtextxy(maxx-100+22, 10, msg);
		sprintf(msg, "%d", rn4);
		outtextxy(42, 10, msg);
		counters(1);
		for(clj=cli+1; clj<4; clj++)
		{
			printLanes(order[0][clj], order[1][clj]);
		}
		road(1);
		signals(1, 1, 0, 0, 1);
		signals(1, 2, 1, 0, 0);
		signals(1, 3, 1, 0, 0);
		signals(1, 4, 1, 0, 0);
		if(numCars >= 1)
		{
			car1(midx-96, iniyTurn, midx, midy, 0.9, 90*a, 0);
		}
		if(iniy+80+5 >= midy+100-40 && numCars >= 3)
		{
			iniy--;
			car1(midx-96, iniy+80+5, midx, midy, 0.9, 90+90*a, 0);
		}
		else
		{
			if(d1 >= -90 && numCars >= 3)
			{
				car1(midx-96, midy+100-40, midx-100, midy+100, 0.9, d1, 1);
				d1--;
				iniy = midy-100-40;
			}
			else
			{
				if(numCars >= 3)
				{
					car1(midx-96, iniy, midx, midy, 0.9, 90*a, 0);
				}
				iniy--;
			}
		}
		if(iniy2 >= midy-40)
		{
			if(numCars >= 2)
			{
				car1(midx-46, iniy2, midx, midy, 0.9, 90+90*a, 0);
			}
			if(numCars >= 4)
			{
				car1(midx-46, iniy2+80+5, midx, midy, 0.9, 90+90*a, 0);
			}
			iniy2--;
		}
		else
		{
			randomize();
			rndm = rand()%2;
			if(d2 <= 90 && numCars >= 2)
			{
				car1(midx-47, iniy2, midx, midy, 0.9, 0+d2, 1);
				if(numCars >= 4)
				{
					car1(midx-46, iniy2+80+5, midx, midy, 0.9, 90+90*a, 1);
				}
				d2++;
			}
			else
			{

				if(numCars >= 2)
				{
					car1(midx-47, iniy2, midx, midy, 0.9, 180+90*a, 0);
				}
				if(iniy2+80+5 >= midy-40 && numCars >= 4)
				{
					car1(midx-46, iniy2+80+5, midx, midy, 0.9, 90+90*a, 0);
					d2 = 360;
				}
				else
				{
					if(d2 <= 450 && numCars >= 4)
					{
						car1(midx-47, iniy3, midx, midy, 0.9, 0+d2, 1);
						d2++;
					}
					else
					{
						if(numCars >= 4)
						{
							car1(midx-47, iniy3, midx, midy, 0.9, 90, 0);
						}
						iniy3--;
					}
					if(numCars == 4 && iniy3 <= -160)
					{
						flag = 1;
						goto bot;
					}
				}
				if((numCars == 2 || numCars == 3) && iniy2 <= -160)
				{
					flag = 1;
					goto bot;
				}
				iniy2--;
			}
		}
		if(numCars == 1 && iniyTurn <= -160)
		{
			flag = 1;
			goto bot;
		}
		iniyTurn--;
		delay(10);
	}
	bot:numCars = 0;
	while(!kbhit() && numCars <= 50)
	{
		cleardevice();
		sprintf(msg, "%d", rn1);
		outtextxy(42, maxy-110, msg);
		sprintf(msg, "%d", rn2);
		outtextxy(maxx-100+22, maxy-110, msg);
		sprintf(msg, "%d", rn3);
		outtextxy(maxx-100+22, 10, msg);
		sprintf(msg, "%d", rn4);
		outtextxy(42, 10, msg);
		counters(1);
		for(clj=cli+1; clj<4; clj++)
		{
			printLanes(order[0][clj], order[1][clj]);
		}
		road(1);
		if(numCars < 10)
		{
		signals(1, 1, 0, 1, 0);
		}
		else
		{
		signals(1, 1, 1, 0, 0);
		}
		signals(1, 2, 1, 0, 0);
		signals(1, 3, 1, 0, 0);
		signals(1, 4, 1, 0, 0);
		numCars++;
		delay(100);
	}
}
void top(int numCars)
{
	int a=1, d1, d2, flag=0;
	float iniy=midy+100, iniyTurn, iniy1, iniy2, iniy3;
	iniy1=iniy;
	iniy2=iniy+80;
	iniy3 = midy-40;
	if(numCars == 0)
	{
		flag = 1;
		goto top;
	}
	while(iniy >= midy+100-40 && !kbhit())
	{
		cleardevice();
		sprintf(msg, "%d", rn1);
		outtextxy(42, maxy-110, msg);
		sprintf(msg, "%d", rn2);
		outtextxy(maxx-100+22, maxy-110, msg);
		sprintf(msg, "%d", rn3);
		outtextxy(maxx-100+22, 10, msg);
		sprintf(msg, "%d", rn4);
		outtextxy(42, 10, msg);
		counters(1);
		for(clj=cli+1; clj<4; clj++)
		{
			printLanes(order[0][clj], order[1][clj]);
		}
		road(1);
		signals(1, 1, 1, 0, 0);
		signals(1, 2, 1, 0, 0);
		signals(1, 3, 0, 0, 1);
		signals(1, 4, 1, 0, 0);
		if(numCars >= 1)
		{
			car1(midx-96, iniy, midx, midy, 0.9, 90+90*a, 0);
		}
		if(iniy1-5 >= iniy)
		{
			if(numCars >= 3)
			{
				car1(midx-96, iniy+80+5, midx, midy, 0.9, 90+90*a, 0);
			}
			if(numCars >= 4)
			{
				car1(midx-46, iniy+80+5, midx, midy, 0.9, 90+90*a, 0);
			}
		}
		else
		{
			if(numCars >= 3)
			{
				car1(midx-96, iniy1+80, midx, midy, 0.9, 90+90*a, 1);
			}
			if(numCars >= 4)
			{
				car1(midx-46, iniy1+80, midx, midy, 0.9, 90+90*a, 1);
			}
		}
		if(numCars >= 2)
		{
			car1(midx-46, iniy, midx, midy, 0.9, 90+90*a, 0);
		}
		delay(25);
		iniy--;
	}
	d1 = 180;
	iniy2 = iniy;
	while(d1 >= 90 && !kbhit())
	{
		cleardevice();
		sprintf(msg, "%d", rn1);
		outtextxy(42, maxy-110, msg);
		sprintf(msg, "%d", rn2);
		outtextxy(maxx-100+22, maxy-110, msg);
		sprintf(msg, "%d", rn3);
		outtextxy(maxx-100+22, 10, msg);
		sprintf(msg, "%d", rn4);
		outtextxy(42, 10, msg);
		counters(1);
		for(clj=cli+1; clj<4; clj++)
		{
			printLanes(order[0][clj], order[1][clj]);
		}
		road(1);
		signals(1, 1, 1, 0, 0);
		signals(1, 2, 1, 0, 0);
		signals(1, 3, 0, 0, 1);
		signals(1, 4, 1, 0, 0);
		if(numCars >= 1)
		{
			car1(midx-96+200, midy-100-40, midx+100, midy-100, 0.9, d1, 1);
		}
		if(numCars >= 3)
		{
			car1(midx-96, iniy+80+5, midx, midy, 0.9, 90+90*a, 1);
		}
		if(numCars >= 2)
		{
			car1(midx-46, iniy2, midx, midy, 0.9, 90+90*a, 0);
		}
		if(numCars >= 4)
		{
			car1(midx-46, iniy2+80+5, midx, midy, 0.9, 90+90*a, 0);
		}
		iniy2--;
		d1--;
		delay(10);
	}
	iniyTurn = midy-100-40;
	d1 = d2 = 180;
	while(flag != 1 >= -160 && !kbhit())
	{
		cleardevice();
		sprintf(msg, "%d", rn1);
		outtextxy(42, maxy-110, msg);
		sprintf(msg, "%d", rn2);
		outtextxy(maxx-100+22, maxy-110, msg);
		sprintf(msg, "%d", rn3);
		outtextxy(maxx-100+22, 10, msg);
		sprintf(msg, "%d", rn4);
		outtextxy(42, 10, msg);
		counters(1);
		for(clj=cli+1; clj<4; clj++)
		{
			printLanes(order[0][clj], order[1][clj]);
		}
		road(1);
		signals(1, 1, 1, 0, 0);
		signals(1, 2, 1, 0, 0);
		signals(1, 3, 0, 0, 1);
		signals(1, 4, 1, 0, 0);
		if(numCars >= 1)
		{
			car1(midx-96, iniyTurn, midx, midy, 0.9, 90*a, 0);
		}
		if(iniy+80+5 >= midy+100-40 && numCars >= 3)
		{
			iniy--;
			car1(midx-96, iniy+80+5, midx, midy, 0.9, 90+90*a, 0);
		}
		else
		{
			if(d1 >= 90 && numCars >= 3)
			{
				car1(midx-96+200, midy-100-40, midx+100, midy-100, 0.9, d1, 1);
				d1--;
				iniy = midy-100-40;
			}
			else
			{
				if(numCars >= 3)
				{
					car1(midx-96, iniy, midx, midy, 0.9, 90*a, 0);
				}
				iniy--;
			}
		}
		if(iniy2 >= midy-40)
		{
			if(numCars >= 2)
			{
				car1(midx-46, iniy2, midx, midy, 0.9, 90+90*a, 0);
			}
			if(numCars >= 4)
			{
				car1(midx-46, iniy2+80+5, midx, midy, 0.9, 90+90*a, 0);
			}
			iniy2--;
		}
		else
		{
			if(d2 <= 270 && numCars >= 2)
			{
				car1(midx-47, iniy2, midx, midy, 0.9, 0+d2, 1);
				if(numCars >= 4)
				{
					car1(midx-46, iniy2+80+5, midx, midy, 0.9, 90+90*a, 1);
				}
				d2++;
			}
			else
			{

				if(numCars >= 2)
				{
					car1(midx-47, iniy2, midx, midy, 0.9, 180+90*a, 0);
				}
				if(iniy2+80+5 >= midy-40 && numCars >= 4)
				{
					car1(midx-46, iniy2+80+5, midx, midy, 0.9, 90+90*a, 0);
					d2 = 540;
				}
				else
				{
					if(d2 <= 630 && numCars >= 4)
					{
						car1(midx-47, iniy3, midx, midy, 0.9, 0+d2, 1);
						d2++;
					}
					else
					{
						if(numCars >= 4)
						{
							car1(midx-47, iniy3, midx, midy, 0.9, 180+90*a, 0);
						}
						iniy3--;
					}
					if(numCars == 4 && iniy3 <= -160)
					{
						flag = 1;
						goto top;
					}
				}
				if((numCars == 2 || numCars == 3) && iniy2 <= -160)
				{
					flag = 1;
					goto top;
				}
				iniy2--;
			}
		}
		if(numCars == 1 && iniyTurn <= -160)
		{
			flag = 1;
			goto top;
		}
		iniyTurn--;
		delay(10);
	}
	top:numCars = 0;
	while(!kbhit() && numCars <= 50)
	{
		cleardevice();
		sprintf(msg, "%d", rn1);
		outtextxy(42, maxy-110, msg);
		sprintf(msg, "%d", rn2);
		outtextxy(maxx-100+22, maxy-110, msg);
		sprintf(msg, "%d", rn3);
		outtextxy(maxx-100+22, 10, msg);
		sprintf(msg, "%d", rn4);
		outtextxy(42, 10, msg);
		counters(1);
		for(clj=cli+1; clj<4; clj++)
		{
			printLanes(order[0][clj], order[1][clj]);
		}
		road(1);
		if(numCars < 10)
		{
			signals(1, 3, 0, 1, 0);
		}
		else
		{
			signals(1, 3, 1, 0, 0);
		}
		signals(1, 1, 1, 0, 0);
		signals(1, 2, 1, 0, 0);
		signals(1, 4, 1, 0, 0);
		numCars++;
		delay(100);
	}
}

void left(int numCars)
{
	int a=0, d1, d2, d3=180, d4, flag=0;
	float iniy = midy+100, iniyTurn, iniy1, iniy2, iniy3, iniy4, iniy5;
	iniy1=iniy;
	iniy2=iniy+80;
	iniy3 = midy-40;
	if(numCars == 0)
	{
		flag = 1;
		goto lef;
	}
	while(iniy >= midy+100-40 && !kbhit())
	{
		cleardevice();
		sprintf(msg, "%d", rn1);
		outtextxy(42, maxy-110, msg);
		sprintf(msg, "%d", rn2);
		outtextxy(maxx-100+22, maxy-110, msg);
		sprintf(msg, "%d", rn3);
		outtextxy(maxx-100+22, 10, msg);
		sprintf(msg, "%d", rn4);
		outtextxy(42, 10, msg);
		counters(1);
		for(clj=cli+1; clj<4; clj++)
		{
			printLanes(order[0][clj], order[1][clj]);
		}
		road(1);
		signals(1, 1, 1, 0, 0);
		signals(1, 2, 1, 0, 0);
		signals(1, 3, 1, 0, 0);
		signals(1, 4, 0, 0, 1);
		if(numCars >= 1)
		{
			car1(midx-96, iniy, midx, midy, 0.9, 90+90*a, 0);
		}
		if(iniy1-5 >= iniy)
		{
			if(numCars >= 3)
			{
				car1(midx-96, iniy+80+5, midx, midy, 0.9, 90+90*a, 0);
			}
			if(numCars >= 4)
			{
				car1(midx-46, iniy+80+5, midx, midy, 0.9, 90+90*a, 0);
			}
		}
		else
		{
			if(numCars >= 3)
			{
				car1(midx-96, iniy1+80, midx, midy, 0.9, 90+90*a, 1);
			}
			if(numCars >= 4)
			{
				car1(midx-46, iniy1+80, midx, midy, 0.9, 90+90*a, 1);
			}
		}
		if(iniy1-10 >= iniy)
		{
			if(numCars >= 5)
			{
				car1(midx-96, iniy+160+10, midx, midy, 0.9, 90+90*a, 0);
			}
			if(numCars >= 6)
			{
				car1(midx-46, iniy+160+10, midx, midy, 0.9, 90+90*a, 0);
			}
		}
		else
		{
			if(numCars >= 5)
			{
				car1(midx-96, iniy1+160, midx, midy, 0.9, 90+90*a, 1);
			}
			if(numCars >= 6)
			{
				car1(midx-46, iniy1+160, midx, midy, 0.9, 90+90*a, 1);
			}
		}
		if(numCars >= 2)
		{
			car1(midx-46, iniy, midx, midy, 0.9, 90+90*a, 0);
		}
		delay(25);
		iniy--;
	}
	d1 = 180;
	iniy2 = iniy;
	while(d1 >= 90 && !kbhit())
	{
		cleardevice();
		sprintf(msg, "%d", rn1);
		outtextxy(42, maxy-110, msg);
		sprintf(msg, "%d", rn2);
		outtextxy(maxx-100+22, maxy-110, msg);
		sprintf(msg, "%d", rn3);
		outtextxy(maxx-100+22, 10, msg);
		sprintf(msg, "%d", rn4);
		outtextxy(42, 10, msg);
		counters(1);
		for(clj=cli+1; clj<4; clj++)
		{
			printLanes(order[0][clj], order[1][clj]);
		}
		road(1);
		signals(1, 1, 1, 0, 0);
		signals(1, 2, 1, 0, 0);
		signals(1, 3, 1, 0, 0);
		signals(1, 4, 0, 0, 1);
		if(numCars >= 1)
		{
			car1(midx-96, midy-100-40, midx-100, midy-100, 0.9, d1-90, 1);
		}
		if(numCars >= 3)
		{
			car1(midx-96, iniy+80+5, midx, midy, 0.9, 90+90*a, 1);
		}
		if(numCars >= 5)
		{
			car1(midx-96, iniy+160+10, midx, midy, 0.9, 90+90*a, 1);
		}
		if(numCars >= 2)
		{
			car1(midx-46, iniy2, midx, midy, 0.9, 90+90*a, 0);
		}
		if(numCars >= 4)
		{
			car1(midx-46, iniy2+80+5, midx, midy, 0.9, 90+90*a, 0);
		}
		if(numCars >= 6)
		{
			car1(midx-46, iniy2+160+10, midx, midy, 0.9, 90+90*a, 0);
		}
		iniy2--;
		d1--;
		delay(10);
	}
	iniyTurn = midy-100-40;
	d1 = d2 = 180;
	while(flag != 1 >= -160 && !kbhit())
	{
		cleardevice();
		sprintf(msg, "%d", rn1);
		outtextxy(42, maxy-110, msg);
		sprintf(msg, "%d", rn2);
		outtextxy(maxx-100+22, maxy-110, msg);
		sprintf(msg, "%d", rn3);
		outtextxy(maxx-100+22, 10, msg);
		sprintf(msg, "%d", rn4);
		outtextxy(42, 10, msg);
		counters(1);
		for(clj=cli+1; clj<4; clj++)
		{
			printLanes(order[0][clj], order[1][clj]);
		}
		road(1);
		signals(1, 1, 1, 0, 0);
		signals(1, 2, 1, 0, 0);
		signals(1, 3, 1, 0, 0);
		signals(1, 4, 0, 0, 1);
		if(numCars >= 1)
		{
			car1(midx-96, iniyTurn, midx, midy, 0.9, 90*a, 0);
		}
		if(iniy+80+5 >= midy+100-40 && numCars >= 3)
		{
			iniy--;
			car1(midx-96, iniy+80+5, midx, midy, 0.9, 90+90*a, 0);
			if(numCars >= 5)
			{
				car1(midx-96, iniy+160+10, midx, midy, 0.9, 90+90*a, 0);
			}
			iniy4 = iniy;
		}
		else
		{
			if(d1 >= 90 && numCars >= 3)
			{
				car1(midx-96, midy-100-40, midx-100, midy-100, 0.9, d1-90, 1);
				d1--;
				iniy = midy-100-40;
				if(numCars >= 5)
				{
					car1(midx-96, iniy4+160+10, midx, midy, 0.9, 90+90*a, 1);
				}
			}
			else
			{
				if(numCars >= 3)
				{
					car1(midx-96, iniy, midx, midy, 0.9, 90*a, 0);
				}
				iniy--;
				if(numCars >= 5 && iniy4+160+10 >= midy+100-40)
				{
					iniy4--;
					car1(midx-96, iniy4+160+10, midx, midy, 0.9, 90+90*a, 0);
				}
				else
				{
					if(d3 >= 90 && numCars >= 5)
					{
						car1(midx-96, midy-100-40, midx-100, midy-100, 0.9, d3-90, 1);
						d3--;
					}
					else
					{
						iniy4--;
						if(numCars >= 5)
						{
							car1(midx-96, iniy4+160+10-200, midx, midy, 0.9, 90*a, 0);
						}
					}
				}
			}
		}
		if(iniy2 >= midy-40)
		{
			if(numCars >= 2)
			{
				car1(midx-46, iniy2, midx, midy, 0.9, 90+90*a, 0);
			}
			if(numCars >= 4)
			{
				car1(midx-46, iniy2+80+5, midx, midy, 0.9, 90+90*a, 0);
			}
			if(numCars >= 6)
			{
				car1(midx-46, iniy2+160+10, midx, midy, 0.9, 90+90*a, 0);
			}
			iniy2--;
		}
		else
		{
			if(d2 <= 270 && numCars >= 2)
			{
				car1(midx-47, iniy2, midx, midy, 0.9, 0+d2-90, 1);
				if(numCars >= 4)
				{
					car1(midx-46, iniy2+80+5, midx, midy, 0.9, 90+90*a, 1);
				}
				if(numCars >= 6)
				{
					car1(midx-46, iniy2+160+10, midx, midy, 0.9, 90+90*a, 1);
				}
				d2++;
			}
			else
			{

				if(numCars >= 2)
				{
					car1(midx-47, iniy2, midx, midy, 0.9, 180+90*a, 0);
				}
				if(iniy2+80+5 >= midy-40 && numCars >= 4)
				{
					car1(midx-46, iniy2+80+5, midx, midy, 0.9, 90+90*a, 0);
					if(numCars >= 6)
					{
						car1(midx-46, iniy2+160+10, midx, midy, 0.9, 90+90*a, 0);
					}
					iniy5 = iniy2;
					d2 = 540;
				}
				else
				{
					if(d2 <= 630 && numCars >= 4)
					{
						car1(midx-47, iniy3, midx, midy, 0.9, d2-90, 1);
						if(numCars >= 6)
						{
							car1(midx-46, iniy5+160+10, midx, midy, 0.9, 90+90*a, 1);
						}
						d2++;
					}
					else
					{
						if(numCars >= 4)
						{
							car1(midx-47, iniy3, midx, midy, 0.9, 180+90*a, 0);
						}
						iniy3--;
						if(iniy5+160+10 > midy-40 && numCars >= 6)
						{
							car1(midx-46, iniy5+160+10, midx, midy, 0.9, 90+90*a, 0);
							iniy5--;
							d4 = 0;
						}
						else
						{
							if(d4 <= 90 && numCars >= 6)
							{
								car1(midx-47, iniy5+160+10, midx, midy, 0.9, 90+d4, 1);
								d4++;

							}
							else
							{
								if(numCars >= 6 && iniy5+160+10+80 >= 0)
								{
									car1(midx-47, iniy5+160+10, midx, midy, 0.9, 180+90*a, 0);
									iniy5--;
								}
								if(numCars >= 6 && iniy5+160+10+80 < 0)
								{
									flag = 1;
									goto lef;
								}
							}
						}
					}
					if((numCars == 4 || numCars == 5) && iniy3 <= -160)
					{
						flag = 1;
						goto lef;
					}
				}
				if((numCars == 2 || numCars == 3) && iniy2 <= -160)
				{
					flag = 1;
					goto lef;
				}
				iniy2--;
			}
		}
		if(numCars == 1 && iniyTurn <= -160)
		{
			flag = 1;
			goto lef;
		}
		iniyTurn--;
		delay(10);
	}
	lef:numCars = 0;
	while(!kbhit() && numCars <= 50)
	{
		cleardevice();
		sprintf(msg, "%d", rn1);
		outtextxy(42, maxy-110, msg);
		sprintf(msg, "%d", rn2);
		outtextxy(maxx-100+22, maxy-110, msg);
		sprintf(msg, "%d", rn3);
		outtextxy(maxx-100+22, 10, msg);
		sprintf(msg, "%d", rn4);
		outtextxy(42, 10, msg);
		counters(1);
		for(clj=cli+1; clj<4; clj++)
		{
			printLanes(order[0][clj], order[1][clj]);
		}
		road(1);
		if(numCars < 10)
		{
			signals(1, 4, 0, 1, 0);
		}
		else
		{
			signals(1, 4, 1, 0, 0);
		}
		signals(1, 1, 1, 0, 0);
		signals(1, 2, 1, 0, 0);
		signals(1, 3, 1, 0, 0);
		numCars++;
		delay(100);
	}
}

void right(int numCars)
{
	int a=2, d1, d2, d3=180, d4, flag=0;
	float iniy = midy+100, iniyTurn, iniy1, iniy2, iniy3, iniy4, iniy5;
	iniy1=iniy;
	iniy2=iniy+80;
	iniy3 = midy-40;
	if(numCars == 0)
	{
		flag = 1;
		goto rig;
	}
	while(iniy >= midy+100-40 && !kbhit())
	{
		cleardevice();
		sprintf(msg, "%d", rn1);
		outtextxy(42, maxy-110, msg);
		sprintf(msg, "%d", rn2);
		outtextxy(maxx-100+22, maxy-110, msg);
		sprintf(msg, "%d", rn3);
		outtextxy(maxx-100+22, 10, msg);
		sprintf(msg, "%d", rn4);
		outtextxy(42, 10, msg);
		counters(1);
		for(clj=cli+1; clj<4; clj++)
		{
			printLanes(order[0][clj], order[1][clj]);
		}
		road(1);
		signals(1, 1, 1, 0, 0);
		signals(1, 2, 0, 0, 1);
		signals(1, 3, 1, 0, 0);
		signals(1, 4, 1, 0, 0);
		if(numCars >= 1)
		{
			car1(midx-96, iniy, midx, midy, 0.9, 90+90*a, 0);
		}
		if(iniy1-5 >= iniy)
		{
			if(numCars >= 3)
			{
				car1(midx-96, iniy+80+5, midx, midy, 0.9, 90+90*a, 0);
			}
			if(numCars >= 4)
			{
				car1(midx-46, iniy+80+5, midx, midy, 0.9, 90+90*a, 0);
			}
		}
		else
		{
			if(numCars >= 3)
			{
				car1(midx-96, iniy1+80, midx, midy, 0.9, 90+90*a, 1);
			}
			if(numCars >= 4)
			{
				car1(midx-46, iniy1+80, midx, midy, 0.9, 90+90*a, 1);
			}
		}
		if(iniy1-10 >= iniy)
		{
			if(numCars >= 5)
			{
				car1(midx-96, iniy+160+10, midx, midy, 0.9, 90+90*a, 0);
			}
			if(numCars >= 6)
			{
				car1(midx-46, iniy+160+10, midx, midy, 0.9, 90+90*a, 0);
			}
		}
		else
		{
			if(numCars >= 5)
			{
				car1(midx-96, iniy1+160, midx, midy, 0.9, 90+90*a, 1);
			}
			if(numCars >= 6)
			{
				car1(midx-46, iniy1+160, midx, midy, 0.9, 90+90*a, 1);
			}
		}
		if(numCars >= 2)
		{
			car1(midx-46, iniy, midx, midy, 0.9, 90+90*a, 0);
		}
		delay(25);
		iniy--;
	}
	d1 = 180;
	iniy2 = iniy;
	while(d1 >= 90 && !kbhit())
	{
		cleardevice();
		sprintf(msg, "%d", rn1);
		outtextxy(42, maxy-110, msg);
		sprintf(msg, "%d", rn2);
		outtextxy(maxx-100+22, maxy-110, msg);
		sprintf(msg, "%d", rn3);
		outtextxy(maxx-100+22, 10, msg);
		sprintf(msg, "%d", rn4);
		outtextxy(42, 10, msg);
		counters(1);
		for(clj=cli+1; clj<4; clj++)
		{
			printLanes(order[0][clj], order[1][clj]);
		}
		road(1);
		signals(1, 1, 1, 0, 0);
		signals(1, 2, 0, 0, 1);
		signals(1, 3, 1, 0, 0);
		signals(1, 4, 1, 0, 0);
		if(numCars >= 1)
		{
			car1(midx-96+200, midy+100-40, midx+100, midy+100, 0.9, d1+90, 1);
		}
		if(numCars >= 3)
		{
			car1(midx-96, iniy+80+5, midx, midy, 0.9, 90+90*a, 1);
		}
		if(numCars >= 5)
		{
			car1(midx-96, iniy+160+10, midx, midy, 0.9, 90+90*a, 1);
		}
		if(numCars >= 2)
		{
			car1(midx-46, iniy2, midx, midy, 0.9, 90+90*a, 0);
		}
		if(numCars >= 4)
		{
			car1(midx-46, iniy2+80+5, midx, midy, 0.9, 90+90*a, 0);
		}
		if(numCars >= 6)
		{
			car1(midx-46, iniy2+160+10, midx, midy, 0.9, 90+90*a, 0);
		}
		iniy2--;
		d1--;
		delay(10);
	}
	iniyTurn = midy-100-40;
	d1 = d2 = 180;
	while(flag != 1 >= -160 && !kbhit())
	{
		cleardevice();
		sprintf(msg, "%d", rn1);
		outtextxy(42, maxy-110, msg);
		sprintf(msg, "%d", rn2);
		outtextxy(maxx-100+22, maxy-110, msg);
		sprintf(msg, "%d", rn3);
		outtextxy(maxx-100+22, 10, msg);
		sprintf(msg, "%d", rn4);
		outtextxy(42, 10, msg);
		counters(1);
		for(clj=cli+1; clj<4; clj++)
		{
			printLanes(order[0][clj], order[1][clj]);
		}
		road(1);
		signals(1, 1, 1, 0, 0);
		signals(1, 2, 0, 0, 1);
		signals(1, 3, 1, 0, 0);
		signals(1, 4, 1, 0, 0);
		if(numCars >= 1)
		{
			car1(midx-96, iniyTurn, midx, midy, 0.9, 90*a, 0);
		}
		if(iniy+80+5 >= midy+100-40 && numCars >= 3)
		{
			iniy--;
			car1(midx-96, iniy+80+5, midx, midy, 0.9, 90+90*a, 0);
			if(numCars >= 5)
			{
				car1(midx-96, iniy+160+10, midx, midy, 0.9, 90+90*a, 0);
			}
			iniy4 = iniy;
		}
		else
		{
			if(d1 >= 90 && numCars >= 3)
			{
				car1(midx-96+200, midy+100-40, midx+100, midy+100, 0.9, d1+90, 1);
				d1--;
				iniy = midy-100-40;
				if(numCars >= 5)
				{
					car1(midx-96, iniy4+160+10, midx, midy, 0.9, 90+90*a, 1);
				}
			}
			else
			{
				if(numCars >= 3)
				{
					car1(midx-96, iniy, midx, midy, 0.9, 90*a, 0);
				}
				iniy--;
				if(numCars >= 5 && iniy4+160+10 >= midy+100-40)
				{
					iniy4--;
					car1(midx-96, iniy4+160+10, midx, midy, 0.9, 90+90*a, 0);
				}
				else
				{
					if(d3 >= 90 && numCars >= 5)
					{
						car1(midx-96+200, midy+100-40, midx+100, midy+100, 0.9, d3+90, 1);
						d3--;
					}
					else
					{
						iniy4--;
						if(numCars >= 5)
						{
							car1(midx-96, iniy4+160+10-200, midx, midy, 0.9, 90*a, 0);
						}
					}
				}
			}
		}
		if(iniy2 >= midy-40)
		{
			if(numCars >= 2)
			{
				car1(midx-46, iniy2, midx, midy, 0.9, 90+90*a, 0);
			}
			if(numCars >= 4)
			{
				car1(midx-46, iniy2+80+5, midx, midy, 0.9, 90+90*a, 0);
			}
			if(numCars >= 6)
			{
				car1(midx-46, iniy2+160+10, midx, midy, 0.9, 90+90*a, 0);
			}
			iniy2--;
		}
		else
		{
			if(d2 <= 270 && numCars >= 2)
			{
				car1(midx-47, iniy2, midx, midy, 0.9, 0+d2+90, 1);
				if(numCars >= 4)
				{
					car1(midx-46, iniy2+80+5, midx, midy, 0.9, 90+90*a, 1);
				}
				if(numCars >= 6)
				{
					car1(midx-46, iniy2+160+10, midx, midy, 0.9, 90+90*a, 1);
				}
				d2++;
			}
			else
			{

				if(numCars >= 2)
				{
					car1(midx-47, iniy2, midx, midy, 0.9, 180+90*a, 0);
				}
				if(iniy2+80+5 >= midy-40 && numCars >= 4)
				{
					car1(midx-46, iniy2+80+5, midx, midy, 0.9, 90+90*a, 0);
					if(numCars >= 6)
					{
						car1(midx-46, iniy2+160+10, midx, midy, 0.9, 90+90*a, 0);
					}
					iniy5 = iniy2;
					d2 = 540;
				}
				else
				{
					if(d2 <= 630 && numCars >= 4)
					{
						car1(midx-47, iniy3, midx, midy, 0.9, d2+90, 1);
						if(numCars >= 6)
						{
							car1(midx-46, iniy5+160+10, midx, midy, 0.9, 90+90*a, 1);
						}
						d2++;
					}
					else
					{
						if(numCars >= 4)
						{
							car1(midx-47, iniy3, midx, midy, 0.9, 180+90*a, 0);
						}
						iniy3--;
						if(iniy5+160+10 > midy-40 && numCars >= 6)
						{
							car1(midx-46, iniy5+160+10, midx, midy, 0.9, 90+90*a, 0);
							iniy5--;
							d4 = 0;
						}
						else
						{
							if(d4 <= 90 && numCars >= 6)
							{
								car1(midx-47, iniy5+160+10, midx, midy, 0.9, d4-90, 1);
								d4++;
							}
							else
							{
								if(numCars >= 6 && iniy5+160+10+80 >= 0)
								{
									car1(midx-47, iniy5+160+10, midx, midy, 0.9, 180+90*a, 0);
									iniy5--;
								}
								if(numCars >= 6 && iniy5+160+10+80 < 0)
								{
									flag = 1;
									goto rig;
								}
							}
						}
					}
					if((numCars == 4 || numCars == 5) && iniy3 <= -160)
					{
						flag = 1;
						goto rig;
					}
				}
				if((numCars == 2 || numCars == 3) && iniy2 <= -160)
				{
					flag = 1;
					goto rig;
				}
				iniy2--;
			}
		}
		if(numCars == 1 && iniyTurn <= -160)
		{
			flag = 1;
			goto rig;
		}
		iniyTurn--;
		delay(10);
	}
	rig:numCars = 0;
	while(!kbhit() && numCars <= 50)
	{
		cleardevice();
		sprintf(msg, "%d", rn1);
		outtextxy(42, maxy-110, msg);
		sprintf(msg, "%d", rn2);
		outtextxy(maxx-100+22, maxy-110, msg);
		sprintf(msg, "%d", rn3);
		outtextxy(maxx-100+22, 10, msg);
		sprintf(msg, "%d", rn4);
		outtextxy(42, 10, msg);
		counters(1);
		for(clj=cli+1; clj<4; clj++)
		{
			printLanes(order[0][clj], order[1][clj]);
		}
		road(1);
		if(numCars < 10)
		{
			signals(1, 2, 0, 1, 0);
		}
		else
		{
			signals(1, 2, 1, 0, 0);
		}
		signals(1, 1, 1, 0, 0);
		signals(1, 3, 1, 0, 0);
		signals(1, 4, 1, 0, 0);
		numCars++;
		delay(100);
	}
}

//s = 1;
//road(scale);
//signals(scale, signalNo, red, yellow, green);
//counters(scale);
//car1(xcoordinate, ycoordinate, rotcentrex, rotcentrey, scale, degree);
//settextstyle(TRIPLEX_FONT, HORIZ_DIR, 8);
//rn = rand() % 6;
//sprintf(msg, "%d", rn);
//outtextxy(42, maxy-110, msg);

int main(void)
{
	/* request auto detection */
	int gdriver = DETECT, gmode, errorcode, keee;
	float theta;
	int signalNo;

	initgraph(&gdriver, &gmode, "C://TC//BGI");

	maxx = getmaxx();
	maxy = getmaxy();
	midx = maxx/2;
	midy = maxy/2;

	cleardevice();
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 5);
	settextjustify(CENTER_TEXT, CENTER_TEXT);
	sprintf(msg, "Title: Traffic signal using SJF");
	outtextxy(midx, midy-40, msg);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
	sprintf(msg, "Roll No: 4 - Neil Albuquerque");
	outtextxy(midx, midy, msg);
	sprintf(msg, "Roll No: 22 - Ansel Dsouza");
	outtextxy(midx, midy+20, msg);
	sprintf(msg, "Roll No: 23 - Arnold Dsouza");
	outtextxy(midx, midy+40, msg);
	sprintf(msg, "Class: SE CMPN A");
	outtextxy(midx, midy+60, msg);
	settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
	sprintf(msg, "(Press any key to start)");
	outtextxy(midx, midy+150, msg);
	getch();

	//rn1 is bottom left, then going anti-clockwise
	randomize();
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 8);
	settextjustify(LEFT_TEXT, RIGHT_TEXT);
	rn1 = rand() % 5;
	sprintf(msg, "%d", rn1);
	outtextxy(42, maxy-110, msg);
	delay(rn1*rn1);
	rn2 = rand() % 7;
	sprintf(msg, "%d", rn2);
	outtextxy(maxx-100+22, maxy-110, msg);
	delay(rn2*rn2);
	rn3 = rand() % 5;
	sprintf(msg, "%d", rn3);
	outtextxy(maxx-100+22, 10, msg);
	delay(rn3*rn3);
	rn4 = rand() % 7;
	sprintf(msg, "%d", rn4);
	outtextxy(42, 10, msg);

	signals(1, 0, 0, 0, 0);
	counters(1);
	road(1);
	printcars(rn1, 0*90);
	printcars(rn2, -1*90);
	printcars(rn3, -2*90);
	printcars(rn4, -3*90);

	SJF(rn1, rn2, rn3, rn4);

	for(cli=0; cli<4; cli++)
	{
		cleardevice();
		sprintf(msg, "%d", rn1);
		outtextxy(42, maxy-110, msg);
		sprintf(msg, "%d", rn2);
		outtextxy(maxx-100+22, maxy-110, msg);
		sprintf(msg, "%d", rn3);
		outtextxy(maxx-100+22, 10, msg);
		sprintf(msg, "%d", rn4);
		outtextxy(42, 10, msg);
		counters(1);
		road(1);
		for(clj=cli; clj<4; clj++)
		{
			printLanes(order[0][clj], order[1][clj]);
		}
		if(order[1][cli] == 1)
		{
			signals(1, 1, 0, 0, 1);
			signals(1, 2, 1, 0, 0);
			signals(1, 3, 1, 0, 0);
			signals(1, 4, 1, 0, 0);
			delay(1000);
			bottom(order[0][cli]);
		}
		if(order[1][cli] == 2)
		{
			signals(1, 1, 1, 0, 0);
			signals(1, 2, 0, 0, 1);
			signals(1, 3, 1, 0, 0);
			signals(1, 4, 1, 0, 0);
			delay(1000);
			right(order[0][cli]);
		}
		if(order[1][cli] == 3)
		{
			signals(1, 1, 1, 0, 0);
			signals(1, 2, 1, 0, 0);
			signals(1, 3, 0, 0, 1);
			signals(1, 4, 1, 0, 0);
			delay(1000);
			top(order[0][cli]);
		}
		if(order[1][cli] == 4)
		{
			signals(1, 1, 1, 0, 0);
			signals(1, 2, 1, 0, 0);
			signals(1, 3, 1, 0, 0);
			signals(1, 4, 0, 0, 1);
			delay(1000);
			left(order[0][cli]);
		}
	}
	getch();
	cleardevice();
	settextjustify(CENTER_TEXT, CENTER_TEXT);
	sprintf(msg, "Thank You");
	outtextxy(midx, midy, msg);
	settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
	sprintf(msg, "(Press any key to exit)");
	outtextxy(midx, midy+150, msg);

	getch();
	closegraph();
	return 0;
}