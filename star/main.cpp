#include "graphics.h"
#include "control.h"
#include "task.h"
#include <time.h>


   
int main()
{
   int left = 0, top = 0, width = 800, height = 600;
   initwindow(width,height);
   
   create_control(BACKGROUND,0,0,"backg.bmp");
   create_control(RAD_PLUS,   0, height -100, "r+.bmp");
   create_control(RAD_MINUS,  100,height -100, "r-.bmp");
   create_control(NUMTOP_PLUS,  200, height -100, "t+.bmp");
   create_control(NUMTOP_MINUS,  300, height -100, "t-.bmp");
   create_control(SAVE,   400, height -100, "save.bmp");
   create_control(EXIT,    600, height -100, "exit.bmp");
   create_control(BAR,0,height - 150, "bar.bmp");
   
   
   srand(time(0));
   int col_rand[3];



   while (1)
   {
         col_rand[0] = rand()%COLOR_MAX;
         col_rand[1] = rand()%COLOR_MAX;
         col_rand[2] = rand()%COLOR_MAX;
         setfillstyle(SOLID_FILL,COLOR(col_rand[0],col_rand[1],col_rand[2]));
      
      while (mousebuttons() == 1) 
      {
         if (mousex()<=width && mousey()<=(height-150))
        {
         while (mousebuttons() == 1);
         Star(mousex(),mousey());
         }
      }


      while (mousebuttons() != 1);
      switch (select_control())
      {
      case NONE:break;
      case RAD_PLUS:Rad_plus(); show_Rad(height);break;
      case RAD_MINUS:Rad_minus(); show_Rad(height);break;
      case NUMTOP_PLUS:numTop_plus();show_nT(height);break;
      case NUMTOP_MINUS:numTop_minus();show_nT(height);break;
      case SAVE:save();break;
      case EXIT:closegraph(); return 0;
      }
   }
}