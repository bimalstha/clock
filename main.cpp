#include <graphics.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include<math.h>
#include<dos.h>
#include<string.h>
#include<iostream>
#include<ctime>



#define S_N_L (radius-10)        // Second Needle Length
#define S_N_C RED                   // Second needle Color
#define M_N_L (radius-20)           // Minute Needle Length
#define M_N_C LIGHTRED              // Minute Needle Color
#define H_N_L (radius-(radius/2))       // Hour Needle Length
#define H_N_C CYAN                     // Hour Needle Color

float cx,cy;
float radius=100;

void get_time(int &h,int &m,int &s);
void second_needle(int s);
void minute_needle(int m,int s);
void hour_needle(int h,int m,int s);

int main(void)
{
/* request auto detection */
int gdriver = DETECT, gmode, errorcode;
initgraph(&gdriver,&gmode,"d:\\tc\\bgi");
/***********************************/
cx=getmaxx()/2.0; // cx is center x value.
cy=getmaxy()/2.0; // cy is center y value.
/** Now the point (cx,cy) is the center of your screen. **/

float x,y;
int hour,minute,second;
circle(cx,cy,radius);
setcolor(2);
circle(cx,cy,radius+10);
setcolor(3);
while(!kbhit())
{
get_time(hour,minute,second);
second_needle(second);
minute_needle(minute,second);
hour_needle(hour,minute,second);
circle(cx,cy,2);
delay(100);
}


getch();
closegraph();
return 0;

}

/** Function to get the current time. **/
void get_time(int &h,int &m,int &s)
{
time_t rawtime;
struct tm *t;
time(&rawtime);
t = gmtime(&rawtime);
h=t->tm_hour;
m=t->tm_min;
s=t->tm_sec;
}
//=================
/** Function to draw Second needle. **/
void second_needle(int s)
{

float angle=-90;
float sx,sy;
setcolor(0);
sx=cx+S_N_L*cos((angle+s*6-6)*M_PI/180);
sy=cy+S_N_L*sin((angle+s*6-6)*M_PI/180);
line(cx,cy,sx,sy);
setcolor(S_N_C);
sx=cx+S_N_L*cos((angle+s*6)*M_PI/180);
sy=cy+S_N_L*sin((angle+s*6)*M_PI/180);
line(cx,cy,sx,sy);
}
/** Function to draw Minute needle. **/
void minute_needle(int m,int s)
{
float angle=-90;
float sx,sy;
setcolor(0);
sx=cx+M_N_L*cos((angle+m*6-6)*M_PI/180);
sy=cy+M_N_L*sin((angle+m*6-6)*M_PI/180);
line(cx,cy,sx,sy);
setcolor(M_N_C);
sx=cx+M_N_L*cos((angle+m*6/*+(s*6/60)*/)*M_PI/180);
sy=cy+M_N_L*sin((angle+m*6/*+(s*6/60)*/)*M_PI/180);
line(cx,cy,sx,sy);
}
/** Function to draw Hour needle. **/
void hour_needle(int h,int m,int s)
{
float angle=-90;
float sx,sy;
setcolor(0);
sx=cx+H_N_L*cos((angle+h*30-(m*30/60))*M_PI/180);
sy=cy+H_N_L*sin((angle+h*30-(m*30/60))*M_PI/180);
line(cx,cy,sx,sy);
setcolor(H_N_C);
sx=cx+H_N_L*cos((angle+h*30+(m*30/60))*M_PI/180);
sy=cy+H_N_L*sin((angle+h*30+(m*30/60))*M_PI/180);
line(cx,cy,sx,sy);
}
