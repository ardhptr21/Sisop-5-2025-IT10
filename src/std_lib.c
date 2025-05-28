#include "std_lib.h"

int div(int a, int b) {
    int quotient = 0;
    int isNegative = 0;
    int absA = a, absB = b;

    if (b == 0) return 0;

    if (a < 0) {
        isNegative = !isNegative;
        absA = -a;
    }
    if (b < 0) {
        isNegative = !isNegative;
        absB = -b;
    }

    while (absA >= absB) {
        absA -= absB;
        quotient++;
    }

    return isNegative ? -quotient : quotient;
}

int mod(int a, int b) {
    int absA = a < 0 ? -a : a;
    int absB = b < 0 ? -b : b;

    if (b == 0) return 0;

    while (absA >= absB) {
        absA -= absB;
    }

    return a < 0 ? -absA : absA;
}
bool strcmp(char *str1, char *str2) {
    int i = 0, flag = 0;

    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            flag = 1;
            break;
        }
        i++;
    }

    if (flag == 0 && str1[i] == '\0' && str2[i] == '\0') return 1;
    return 0;
}

void strcpy(char *dst, char *src) {
    int i = 0;
    while (src[i] != '\0') {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
}

void clear(byte *buf, unsigned int size) {
    int i = 0;
    while (i < size) {
        buf[i] = 0x0;
        i++;
    }
}

void atoi(char *str, int *num) {
    int i = 0;
    int result = 0;
    int sign = 1;

    while (str[i] == ' ' || str[i] == '\t') i++;

    if (str[i] == '-') {
        sign = -1;
        i++;
    } else if (str[i] == '+') {
        i++;
    }

    while (str[i] >= '0' && str[i] <= '9') {
        result = result * 10 + (str[i] - '0');
        i++;
    }

    *num = sign * result;
}

void itoa(int num, char *str) {
    int i = 0;
    int isNegative = 0;
    int start, end;
    char temp;

    if (num == 0) {
        str[i++] = '0';
        str[i] = '\0';
        return;
    }

    if (num < 0) {
        isNegative = 1;
        num = -num;
    }

    while (num > 0) {
        str[i++] = mod(num, 10) + '0';
        num = div(num, 10);
    }

    if (isNegative) {
        str[i++] = '-';
    }

    str[i] = '\0';

    start = 0;
    end = i - 1;
    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}