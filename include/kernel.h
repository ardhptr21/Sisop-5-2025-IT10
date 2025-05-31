#ifndef __KERNEL_H__
#define __KERNEL_H__

#include "std_type.h"

#define WHITE_COLOR 0x000F
#define RED_COLOR 0x000C
#define YELLOW_COLOR 0x000E
#define BLUE_COLOR 0x0001

extern void putInMemory(int segment, int address, char character);
extern int interrupt(int number, int AX, int BX, int CX, int DX);
extern int getRawCursorPos();
unsigned int getBiosTick();

void setColor(int color);
void printString(char* str);
void readString(char* buf);
void clearScreen();

#endif  // __KERNEL_H__
