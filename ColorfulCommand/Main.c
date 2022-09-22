
#define public extern
#define private static

#include <stdio.h>

#include "com.rmdust.Console.h"
#include "com.rmdust.Graphics.h"
#include "com.rmdust.Color.h"

typedef struct CONSOLE CONSOLE;
typedef struct LINE LINE;

CONSOLE setConsole;


int main(void) {

  setConsole = Console();

  // set size for frame
  setConsole.SetSize(200,200);

  // set background for frame
  setConsole.SetBackground(COLOR_WHITE);
  setConsole.SetFrontground(COLOR_BLACK);

  // create a new graphics
  LINE a = Line();
  a.Background = HEX_COLOR_GREEN;
  a.Frountground = HEX_COLOR_BLACK;

  // it is update block
  int LocationX[] = {
    4,3,5,2,6,1,7,1,2,3,4,5,6,7,9
  };
  int LocationY[] = {
    1,2,2,3,3,4,4,5,5,5,5,5,5,5,9
  };

  a.LocationListSize = (int)sizeof (LocationX) / sizeof (LocationX[0]) - 1;
  a.setPath(&a, LocationX, LocationY);

  a.Paint(a);

  printf("\n");

  return 0;
}

