#include "graphics.h"
#include "task.h"
#include <iostream>
#include <math.h>
using namespace std;

int R = 40,numTop = 5;


void draw_line(int x1,int y1,int x2, int y2) 
{
   int color=getcolor();
   int sx,sy,x,y,p;
   x = abs(x2 - x1);
   y = abs(y2 - y1);
   
   sx = x1<=x2?1:-1;
   sy = y1<=y2?1:-1;
   
   int i;
   if(x >= y)
   {
      p = 2*y - x;
      i = x1;
      while (i!= x2)
      {
         putpixel(i,y1,color);
         i += sx;
         y1+=p>0? sy: 0;
         p+=p>0? 2*(y-x): 2*y;
      }
   }
   else if (x < y)
   {
      p = 2*x-y;
      i = y1;
      while(i!=y2)
      {
         putpixel(x1,i,color);
         i += sy;
         x1+=p>0? sx: 0;
         p+=p>0? 2*(x-y): 2*x;
      }
   }
   putpixel(x2,y2,color);
}

void Star(int x0, int y0)
{
   int r,x1,y1;
   int n = numTop;
   double theta = PI/n;
   r=cos(theta *2)/cos(theta)*R;;
   for(int i=0;i<n;i++)
   {
      moveto(x0+R*cos((2*theta)*i),
             y0+R*sin((2*theta)*i));
      x1=getx();
      y1=gety();
      draw_line(x1,y1,x0+r*cos(2*theta*i+theta),
                      y0+r*sin(2*theta*i+theta));
      
      moveto(x0+r*cos(2*theta*i+theta),
             y0+r*sin(2*theta*i+theta));
      x1=getx();
      y1=gety();
      draw_line(x1,y1,x0+R*cos(2*theta*(i+1)),
                      y0+R*sin(2*theta*(i+1)));
   }
   floodfill(x0,y0, getcolor());
}

void Rad_plus()
{
    R+=5;
    if(R>90)
    R=90;
}

void Rad_minus() 
{
    R-=5;
    if(R<20)
    R=20;
}

void show_Rad(int height)
{
    int show=R;
    settextstyle(GOTHIC_FONT,0,5);
    outtextxy(150,height-150,to_string(show).c_str());
}

void show_nT(int height)
{
    int show=numTop;
    settextstyle(GOTHIC_FONT,0,5);
    outtextxy(520,height-150,to_string(show).c_str());
}

void numTop_plus() 
{
   numTop++;
   if(numTop > 20)
   numTop = 20;

}

void numTop_minus() 
{
    numTop--;
    if(numTop<5)
    numTop=5;
}

void save()
{
   int width, height;
   IMAGE *output;

   width  = getmaxx() + 1;
   height = getmaxy() + 1;
   output = createimage(width, height);

   getimage(0, 0, width - 1, height - 1, output);
   saveBMP("output.bmp", output);
   freeimage(output);
}

