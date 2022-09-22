
// File Encoding: UTF-8

#pragma once

#include <windows.h>

#ifndef _INC_COM_RMDUST_GRAPHICS
#define _INC_COM_RMDUST_GRAPHICS

// The symbol can only be used for functions whose names begin with __
#define private static

// This symbol is used to mark the variable is located in this file
#define this_

#define ref_ 

typedef int color;

struct LINE {
  void(*setSize)(struct LINE* ref_, int, int);

  int Width;
  int Height;

  void(*setBackground)(struct LINE* ref_, color);
  void(*setFrontground)(struct LINE* ref_, color);

  color Background;
  color Frountground;

  void(*setLocation)(struct LINE* ref_, int, int);

  int X;
  int Y;
  int LocationX[512];
  int LocationY[512];
  int LocationListSize;

  void(*setPath)(struct LINE* ref_ Source, int[], int[]);

  void(*Paint)(struct LINE Source);
};

extern struct LINE Line();

void setSizeOO(struct LINE* ref_ Source, int Width, int Height);
void setFrontgroundOO(struct LINE* ref_ Source, color Frontground);
void SetBackgroundOO(struct LINE* ref_ Source, color Background);
void setLocationOO(struct LINE* ref_ Source, int X, int Y);
void setPathOO(struct LINE* ref_ Source, int LocationX[], int LocationY[]);
static void PaintOO(struct LINE Source);

void PrintAll(struct LINE Source);

private void __Copy_Location(struct LINE* ref_ Source, int LocationX[], int LocationY[]);
private void __Set_Position(int X, int Y);
private void __Set_Console_Text_Attribute(UINT uFore, UINT uBack);


#endif
