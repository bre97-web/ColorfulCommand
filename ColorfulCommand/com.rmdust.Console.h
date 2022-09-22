
// File Encoding: UTF-8

#pragma once

#include <windows.h>

#ifndef _INC_COM_RMDUST_CONSOLE
#define _INC_COM_RMDUST_CONSOLE

#define WINSIZE_128 128

typedef int color;

struct CONSOLE {
  /// <summary>
  /// 设置控制台窗口颜色。具体颜色请参考com.rmdust.Console.h的宏定义。
  /// </summary>
  /// <param name="Background">背景色</param>
  /// <param name="Frontground">前景色</param>
  void (*SetBackground)(color);
  /// <summary>
  /// 设置控制台窗口颜色。具体颜色请参考com.rmdust.Console.h的宏定义。
  /// </summary>
  /// <param name="Background">背景色</param>
  /// <param name="Frontground">前景色</param>
  void (*SetFrontground)(color);



  /// <summary>
  /// 设置控制台窗口大小。具体大小请参考com.rmdust.Console.h的宏定义。
  /// </summary>
  /// <param name="Width">宽度</param>
  /// <param name="Height">高度</param>
  void (*SetSize)(int, int);

  /// <summary>
  /// 设置控制台窗口的光标的位置。
  /// </summary>
  /// <param name="X">X 坐标</param>
  /// <param name="Y">Y 坐标</param>
  void (*SetConsolePos)(SHORT, SHORT);

  /// <summary>
  /// 用于控制台窗口的输入函数，当遇到回车符时结束输入。不包含回车符。
  /// </summary>
  /// <param name="refSource">目标对象</param>
  /// <param name="Size">目标限制大小</param>
  /// <returns>字符串</returns>
  char* (*Scanf)(char*, int);

  void (*Clear)(void);

  void(*SetTitle)(LPCSTR);
};

enum COLORINFO {
  Black = 48,
  Blue,
  Green,
  Aqua,
  Red,
  Purple,
  Yellow,
  White,
  Gray,
  LightBlue,
  LightGreen = 65,
  LightAqua,
  LightRed,
  LightPurple,
  LightYellow,
  BrightWhite
};

/// <summary>
/// 初始化struct CONSOLE类型的变量。
/// </summary>
extern struct CONSOLE Console();


static void SetBackground(color Background);
static void SetFrontground(color Frontground);
static void SetSize(int Width, int Height);
static void SetPosition(SHORT X, SHORT Y);
static char* Scanf(char refSource[], int Size);
static void Clear(void);
static void SetTitle(LPCSTR Title);

static void __Init_Console();
static void __Update_Color();

#endif