#include "main.h"

void print_Unsig(unsigned int num) {
    char buffer[20];
    int i;

    do {
        buffer[i++] = (num % 10) + '0';
        num /= 10;
    } while (num);

    while (i > 0) {
        _putchar(buffer[--i]);
    }
}

void print_Oct(unsigned int num) {
    char buffer[20];
    int i;

    do {
        buffer[i++] = (num % 8) + '0';
        num /= 8;
    } while (num);

    while (i > 0) {
        _putchar(buffer[--i]);
    }
}

void print_Hex(unsigned int num, int upper, int width, char flags) {
    char buffer[20];
    int i = 0;
    char hex_chars[] = "0123456789abcdef";

    if (num >= 0) {
        if (upper) {
            for (i = 7; i >= 0; i--) {
                int digit = (num >> (4 * i)) & 0xf;
                buffer[i] = toupper(hex_chars[digit]);
            }
        } else {
            for (i = 7; i >= 0; i--) {
                int digit = (num >> (4 * i)) & 0xf;
                buffer[i] = hex_chars[digit];
            }
        }

        int firstNonZeroIndex = 0;
        while (firstNonZeroIndex < 8 && buffer[firstNonZeroIndex] == '0') {
            firstNonZeroIndex++;
        }

        if (width > 8 - firstNonZeroIndex) {
            int padding = width - 8 + firstNonZeroIndex;
            char padChar = ' ';
            if (flags == '0') {
                padChar = '0';
            }
            for (i = 0; i < padding; i++) {
                _putchar(padChar);
            }
        }

        for (i = firstNonZeroIndex; i < 8; i++) {
            _putchar(buffer[i]);
        }
    }
}

void print_Bin(unsigned int num, int width, char flags) {
    char buffer[32];
    int j, i = 0;

    for (j = 31; j >= 0; j--) {
        buffer[i++] = '0' + ((num >> j) & 1);
    }

    int firstNonZeroIndex;
    while (firstNonZeroIndex < 32 && buffer[firstNonZeroIndex] == '0') {
        firstNonZeroIndex++;
    }

    if (width > 32 - firstNonZeroIndex) {
        int padding = width - 32 + firstNonZeroIndex;
        char padChar = ' ';
        if (flags == '0') {
            padChar = '0';
        }
        for (i = 0; i < padding; i++) {
            _putchar(padChar);
        }
    }

    for (i = firstNonZeroIndex; i < 32; i++) {
        _putchar(buffer[i]);
    }
}

/**
 * _strlen - calculate the length of a given string
 * @s: the given string
 *
 * Return: the length of the string
 */

int _strlen(const char *s)
{
	int counter = 0;

	while (*s != '\0')
	{
		counter++;
		s++;
	}
	return (counter);
}

