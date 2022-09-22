
// File Encoding: UTF-8

#include <conio.h>
#include <direct.h>
#include <process.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "com.rmdust.Graphics.h"
#include "com.rmdust.Color.h"


typedef int color;

extern struct LINE Line() {
  struct LINE Copy = {
    .setSize = &setSizeOO,
    .Width = 0,
    .Height = 0,
    .setBackground = &SetBackgroundOO,
    .Frountground = &setFrontgroundOO,
    .Background = COLOR_BLACK,
    .Frountground = COLOR_WHITE,
    .setLocation = &setLocationOO,
    .X = 0,
    .Y = 0,
    .LocationX = {0},
    .LocationY = {0},
    .LocationListSize = 0,
    .setPath = &setPathOO,
    .Paint = &PaintOO,
  };

  return Copy;
}


void setSizeOO(struct LINE * ref_ Source, int Width, int Height) {
  Source->Width = Width;
  Source->Height = Height;
}

void setFrontgroundOO(struct LINE * ref_ Source, color Frontground) {
  Source->Frountground = Frontground;
}

void SetBackgroundOO(struct LINE * ref_ Source, color Background) {
  Source->Background = Background;
}

void setLocationOO(struct LINE * ref_ Source, int X, int Y) {
  Source->X = X;
  Source->Y = Y;
}

void setPathOO(struct LINE* ref_ Source, int LocationX[], int LocationY[]) {
  __Copy_Location(Source, LocationX, LocationY);
}

private void __Copy_Location(struct LINE* ref_ Source, int LocationX[], int LocationY[]) {  
  for (int Index = 0; Index <= Source->LocationListSize; Index++) {
    Source->LocationX[Index] = LocationX[Index];
    Source->LocationY[Index] = LocationY[Index];
  }

}

private void __Set_Position(int X, int Y) {
  COORD point = {
    point.X = X,
    point.Y = Y,
  };

  HANDLE HOutput = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleCursorPosition(HOutput, point);
}

private void __Set_Console_Text_Attribute(UINT uFore, UINT uBack) {
  HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(handle, uFore+uBack*0x10);
}

static void PaintOO(struct LINE Source) {
  for (int Index = 0; Index <= Source.LocationListSize; Index ++) {
    __Set_Position(Source.LocationX[Index], Source.LocationY[Index]);
    __Set_Console_Text_Attribute(Source.Frountground, Source.Background);
    
    // need
    printf("%c", ' ');
  }
}

void PrintAll(struct LINE Source) {
  for (int Index = 0; Index <= Source.LocationListSize; Index ++) {
    printf("%d - ", Source.LocationX[Index]);
  }

  printf("\n%d",Source.LocationListSize);
}