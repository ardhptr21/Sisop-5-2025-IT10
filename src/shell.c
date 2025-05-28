#include "shell.h"

#include "kernel.h"
#include "std_lib.h"

void shell() {
    char buf[128];

    printLogo();

    while (true) {
        printString("> ");
        readString(buf);
        printString(buf);
        printString("\n");
    }
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
    // TODO: Implementasi fungsi untuk mem-parsing perintah
}

// Tambahkan fungsi bila perlu