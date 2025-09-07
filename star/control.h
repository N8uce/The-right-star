#ifndef CONTROL_H
#define CONTROL_H

enum control_values { NONE = -1, EXIT, SAVE,
                      RAD_PLUS, RAD_MINUS, NUMTOP_PLUS,NUMTOP_MINUS, BAR,
                      BACKGROUND, 
                      N_CONTROLS };

struct Control
{
   int left;
   int top;
   int right;
   int bottom;
};

void create_control(int, int, int, const char*);
int select_control();

#endif