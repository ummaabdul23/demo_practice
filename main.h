#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>

#define UnUsed(i) (void)(i)
#define BUFFER 1024

typedef struct format
{
	char *id;
	int (*f)();
} convert_match;

int _printf(const char *format, ...);
char flag(const char **format);
int width(const char **format);
int size(const char **format);
char specifier(const char **format);
int precision(const char **format);
int _putchar(char c);
int print_mod(va_list param, char buffer[]; int flag, int width, int precision,int size);
int print_Dec(va_list param, char buffer[], int flag, int width, int precision, int size);
int print_str(va_list param, char buffer[], int flag, int width, int precision, int size);
int print_str(va_list param, char buffer[], int flag, int width, int precision, int size);
int _strlen(const char *s);
int print_Bin(va_list param,char buffer[], int flag, int width,int precision, int size);
int print_Hex(va_list param, char map_to, char buffer[], int flag, char f, int width, int precision, int size);
int print_Oct(va_list param, char buffer[], int flag, int width, int precision, int size);
int print_Unsig(va_list param, char buffer[], int flag, int width, int precision,int size);
/*int _isdigit(int c);*/
int print_Rot13(va_list param, char buffer[], int flag, int width, int precision, int size);
int print_Rev(va_list param, char buffer[], int flag, int width, int precision, int size);
int print_Ptr(va_list param, char buffer[], int flag, int width, int precision, int size);
int print_Str(va_list param, char buffer[], int flag, int width, int precision, int size);
int handle_char(char c, char buffer[], int flag, int width, int precision, int size);
int write_number(int neg, int index, char buffer[], int flag, int width, int precision, int size);
int write_num(int index, char buffer[], int flag, int width, int precision, int length, char padd, char extra_c);
int write_unsig(int neg, int index, char buffer[], int flag, int width, int precision, int size);
 long int convert_unsig(unsigned long int num, int size);

#endif

