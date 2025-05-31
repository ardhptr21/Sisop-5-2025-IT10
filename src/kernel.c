#include "kernel.h"

#include "shell.h"

static int currentColor = WHITE_COLOR;

int main() {
    clearScreen();
    shell();
    return 0;
}

void setColor(int color) {
    currentColor = color;
}

void printString(char *str) {
    char *p = str;
    while (*p != 0) {
        if (*p == '\n') {
            interrupt(0x10, 0x0e0d, 0x0000, 0x0001, 0);
            interrupt(0x10, 0x0e0a, 0x0000, 0x0001, 0);
        } else {
            interrupt(0x10, 0x0900 | *p, currentColor, 0x0001, 0);
            interrupt(0x10, 0x0e00 | *p, 0x0000, 0x0001, 0);
        }
        p++;
    }
}

void readString(char *buf) {
    char c;
    int i = 0;

    while (1) {
        c = interrupt(0x16, 0, 0, 0, 0);

        if (c == '\r') {
            interrupt(0x10, 0x0e0d, 0x0000, 0x0001, 0);
            interrupt(0x10, 0x0e0a, 0x0000, 0x0001, 0);
            break;
        } else if (c == '\b') {
            if (i > 0) {
                i--;
                interrupt(0x10, 0x0e08, 0x0000, 0x0001, 0);
                interrupt(0x10, 0x0e20, 0x0000, 0x0001, 0);
                interrupt(0x10, 0x0e08, 0x0000, 0x0001, 0);
            }
        } else {
            interrupt(0x10, 0x0900 | c, currentColor, 0x0001, 0);
            interrupt(0x10, 0x0e00 | c, 0x0000, 0x0001, 0);
            buf[i++] = c;
        }
    }
    buf[i] = 0;
}

void clearScreen() {
    interrupt(0x10, 0x0003, 0x0007, 0, 0);
    interrupt(0x10, 0x0200, 0x0000, 0, 0);
}