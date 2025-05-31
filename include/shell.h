#ifndef __SHELL_H__
#define __SHELL_H__

#include "std_type.h"

void shell();
void prompt(char *user, char *top, char *buf);
void printLogo();
void parseCommand(char *buf, char *cmd, char arg[2][64]);

void yogurt(char *buf);
void realyogurt();
void changeUser(char *user, char *to);
void grandCompany(char *top, char *arg);
void calc(char *op, char *a, char *b);

#endif  // __SHELL_H__
