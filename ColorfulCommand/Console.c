
// File Encoding: UTF-8

#include <conio.h>
#include <direct.h>
#include <process.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <winuser.h>

#include "com.rmdust.Console.h"
#include "com.rmdust.Color.h"

#define ERROR_COLOR_NOT_IN_RANGE "Color not in range"
#define ERROR_NUMS_IS_TOO_SMALL "The number is too small"
#define ERROR_NUMS_IS_TOO_BIG "The number is too big"

static const char* FILENAME = "Console.c";
static int WindowWidth;
static int WindowHeight;
static color WindowBackground;
static color WindowFrontground;

// The symbol can only be used for functions whose names begin with __
#define private static

// This symbol is used to mark the variable is located in this file
#define this_

extern struct CONSOLE Console() {

  __Init_Console();

  struct CONSOLE Copy = {
    .SetBackground = &SetBackground,
    .SetFrontground = &SetFrontground,
    .SetSize = &SetSize,
    .SetConsolePos = &SetPosition,
    .Scanf = &Scanf,
    .Clear = &Clear,
  };

  return Copy;
}



private void __Init_Console() {
  this_ WindowWidth = 100;
  this_ WindowHeight = 100;
  this_ WindowBackground = COLOR_BLACK;
  this_ WindowFrontground = COLOR_WHITE;
}

static void SetFrontground(int Frontground) {
  
  if ((Frontground < 48 || Frontground > 57) && (Frontground < 65 && Frontground > 70)) {
    printf(
      "%s: %s: %d",
      this_ FILENAME, 
      ERROR_COLOR_NOT_IN_RANGE,
      Frontground
    );
    return;
  }

  this_ WindowFrontground = Frontground;

  __Update_Color();
}
static void SetBackground(int Background) {
  
  if ((Background < 48 || Background > 57) && (Background < 65 && Background > 70)) {
    printf(
      "%s: %s :%d",
      this_ FILENAME, 
      ERROR_COLOR_NOT_IN_RANGE,
      Background
    );
    return;
  }

  this_ WindowBackground = Background;

  __Update_Color();
}

private void __Update_Color() {
  char ColorCode[9];

  sprintf_s(
    ColorCode,
    9,
    "%s%c%c",
    "color ",
    this_ (char)WindowBackground,
    this_ (char)WindowFrontground
  );
  system(ColorCode);
}

static void SetSize(int Width, int Height) {
  
  if (Width < 0 || Height < 0) {
    printf(
      "%s: %s :%d & %d", 
      this_ FILENAME, 
      ERROR_NUMS_IS_TOO_SMALL,
      Width, 
      Height
    );
    return;
  }
  if (Width > 1024 || Height > 800) {
    printf(
      "%s: %s :%d & %d", 
      this_ FILENAME, 
      ERROR_NUMS_IS_TOO_BIG,
      Width,
      Height
    );
    return;
  }

  this_ WindowWidth = Width;
  this_ WindowHeight = Height;

  char stCmd[32];
  sprintf_s(
    stCmd,
    32,
    "mode con cols=%d lines=%d",
    Width,
    Height
  );
  system(stCmd);
}

static void SetPosition(SHORT X, SHORT Y) {

  if(X < 0 || Y < 0){
    printf(
      "%s: %s :%d & %d", 
      this_ FILENAME, 
      ERROR_NUMS_IS_TOO_SMALL, 
      X,
      Y
    );
    return;
  }

  if (X > WindowWidth || Y > WindowHeight) {
    printf(
      "%s: %s :%d & %d\nThe Window size:%d & %d",
      this_ FILENAME,
      ERROR_NUMS_IS_TOO_BIG,
      X,
      Y,
      this_ WindowWidth, 
      this_ WindowHeight
    );
    return;
  }

  COORD point = {
    point.X = X,
    point.Y = Y,
  };

  HANDLE HOutput = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleCursorPosition(HOutput, point);
}

static char* Scanf(char refSource[], int Size) {
  
  for (int Index = 0; Index < Size; Index += 1) {
    char ch = (char)getchar();

    if (ch == '\n') {
      break;
    }

    refSource[Index] = ch;
  }

  return refSource;
}

static void Clear(void) {
  system("cls");
}

static void SetTitle(LPCSTR Title) {
  //SetConsoleTite(Title);
}

static void SetWindowPosition() {
  //SetWindowPos(GetConsoleWindow(), , 20,20,20,20);
}

