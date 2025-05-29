#include "shell.h"

#include "kernel.h"
#include "std_lib.h"

void shell() {
    char buf[128];
    char cmd[64];
    char arg[2][64];
    char user[64];

    printLogo();
    strcpy(user, "user");

    while (true) {
        prompt(user, buf);
        parseCommand(buf, cmd, arg);

        if (strcmp(cmd, "clear")) {
            clearScreen();
            continue;
        }
        if (strcmp(cmd, "yo") || strcmp(cmd, "gurt")) {
            yogurt(buf);
            continue;
        }

        if (strcmp(cmd, "yogurt")) {
            realyogurt();
            continue;
        }

        if (strcmp(cmd, "user")) {
            changeUser(user, arg[0]);
            continue;
        }

        if (strcmp(cmd, "grandcompany")) {
            grandCompany(gc, colorCode, arg[0]);
            continue;
        } 

        if (strcmp(cmd, "add") || strcmp(cmd, "sub") || strcmp(cmd, "mul") || strcmp(cmd, "div")) {
            calc(cmd, arg[0], arg[1]);
            continue;
        }

        printString(buf);
        printString("\n");
    }
}

void prompt(char *user, char *buf) {
    printString(user);
    printString("> ");
    readString(buf);
}

void printLogo() {
    printString(" ____ ___ ____   ___  ____  \n");
    printString("/ ___|_ _/ ___| / _ \\|  _ \\ \n");
    printString("\\___ \\| |\\___ \\| | | | |_) |\n");
    printString(" ___) | | ___) | |_| |  __/ \n");
    printString("|____/___|____/ \\___/|_|    \n\n");
    printString(" ___ _____   _  ___  \n");
    printString("|_ _|_   _| | |/ _ \\ \n");
    printString(" | |  | |   | | | | |\n");
    printString(" | |  | |   | | |_| |\n");
    printString("|___| |_|   |_|\\___/ \n\n");
    printString("Welcome to our very lite OS!\n\n");
}

void parseCommand(char *buf, char *cmd, char arg[2][64]) {
    int i = 0, j = 0, k = 0;
    int argIndex = -1;

    cmd[0] = '\0';
    arg[0][0] = '\0';
    arg[1][0] = '\0';

    while (buf[i] == ' ' || buf[i] == '\t') i++;

    while (buf[i] != '\0' && buf[i] != '\n') {
        if (buf[i] == ' ' || buf[i] == '\t') {
            if (argIndex == -1) {
                cmd[j] = '\0';
                argIndex = 0;
            } else if (argIndex < 2) {
                arg[argIndex][k] = '\0';
                argIndex++;
                k = 0;
            }
            while (buf[i] == ' ' || buf[i] == '\t') i++;
            continue;
        }

        if (argIndex == -1) {
            cmd[j++] = buf[i++];
        } else if (argIndex < 2) {
            arg[argIndex][k++] = buf[i++];
        } else {
            i++;
        }
    }

    if (argIndex == -1) {
        cmd[j] = '\0';
    } else if (argIndex < 2) {
        arg[argIndex][k] = '\0';
    }
}

void yogurt(char *buf) {
    if (strcmp(buf, "yo")) {
        printString("gurt\n");
    } else if (strcmp(buf, "gurt")) {
        printString("yo\n");
    }
}

void realyogurt(void) {
    static int seed = 0;
    static char *strings[] = {"yo", "ts unami gng </3", "sygau"};
    int random_index;

    if (seed == 0) {
        seed = interrupt(0x1A, 0, 0, 0, 0);
    }

    seed = seed * 17 + 7;  // LCG
    random_index = mod(mod(seed, 3) + 3, 3);

    printString("gurt> ");
    printString(strings[random_index]);
    printString("\n");
}

void changeUser(char *user, char *to) {
    printString("Username changed to: ");
    if (to[0] == '\0') {
        strcpy(user, "user");
        printString("user\n");
    } else {
        strcpy(user, to);
        printString(user);
        printString("\n");
    }
}

void grandCompany(char *gc, char *colorCode, char *arg) {
    if (strcmp(arg[0], "maelstorm")) {
        strcpy(gc, "@Storm");
        strcpy(colorCode, "\033[1;31m");
    } else if (strcmp(arg[0], "twinadder")) {
        strcpy(gc, "@Serpent");
        strcpy(colorCode, "\033[1;33m");
    }  else if (strcmp(arg[0], "immortalflames")) {
        strcpy(gc, "@Flame");
        strcpy(colorCode, "\033[1;34m");
    }  else {
        printString("Error: invalid grand companmy\n");
        return;
    }

    clearScreen();
}

void calc(char *op, char *a, char *b) {
    int num1 = 0, num2 = 0, result = 0;
    char *out;

    if (a[0] == '\0' || b[0] == '\0') {
        printString("Error: arguments missing\n");
        return;
    }

    atoi(a, &num1);
    atoi(b, &num2);

    if (strcmp(op, "add")) {
        result = num1 + num2;
    } else if (strcmp(op, "sub")) {
        result = num1 - num2;
    } else if (strcmp(op, "mul")) {
        result = num1 * num2;
    } else if (strcmp(op, "div")) {
        if (num2 == 0) {
            printString("Error: division by zero\n");
            return;
        }

        result = num1 / num2;
    }

    itoa(result, out);

    printString(out);
    printString("\n");
}
