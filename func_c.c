#include "main.h"
/**
 *  print_str - print string
 *  @param: --
 *  @buffer: --
 *  @flag: --
 *  @width: --
 *  @precision: --
 *  @size
 *  Return: int
 */

int print_Str(va_list param, char buffer[], int flag, int width, int precision, int size)
{
	int count = 0;
	int i;
	char *str = va_arg(param, char*);

	while (str[count] != '\0') {
		count++;
	}

	if (precision < 0) {
		precision = count;
	} else if (precision > count) {
		precision = count;
	}

	if (width > count && (flag & 1) == 0)
	{
		int padding = width - count;
		char padChar = ' ';
		if (flag & 4){
			padChar = '0';
		for (i = 0; i < padding; i++)
			_putchar(padChar);
	}
	int printedChar = 0;

	for (i = 0; i < precision; i++)
	{
		if (str[i] >= 32 && str[i] < 127)
		{
			_putchar(str[i]);
			printedChar++;
		} else {
			_putchar('\\');
			_putchar('x');
			_putchar("0123456789ABCDEF"[((unsigned char)str[i]) >> 4]);
			_putchar("0123456789ABCDEF"[((unsigned char)str[i]) & 15]);
			printedChar += 4;
		}
	}

	if ((flags & 1) != 0 && width > count) {
		int padding = width - count;
		for (i = 0; i < padding; i++) {
			_putchar(' ');
		}
	}
	return (printedChar);
}
/**
 *  print_str - print pointer
 *  @param: --
 *  @buffer: --
 *  @flag: --
 *  @width: --
 *  @precision: --
 *  @size: --
 *  Return: int
 */

int print_Ptr(va_list param, char buffer[], int flag, int width, int precision, int size)
{
	unsigned long int num = (unsigned long int)va_arg(param, void*);
	int i = 0;
	char hex_char[] = "0123456789abcdef";
	memset(buffer, 0, BUFFER);
	buffer[i++] = '0';
	buffer[i++] = 'x';

	do {
		buffer[i++] = hex_char[num % 16];
		num /= 16;
	} while (num);
	int printedChar = 0;

	if (i < width)
	{
		int padding = width - i;
		char padChar = ' ';
		if (flag == 4)
			padChar = '0';
		if ((flag & 1) == 0)
		{
			for (int j = 0; j < padding; j++)
			{
				_putchar(padChar);
				printedChar++;
			}
		}
	}
	for (int j = i - 1; j >= 0; J--)
	{
		_putchar(buffer[j]);
		printedChar++;
	}
	if((flag & 1 != 0 && width > i)
			{
			int padding = width - i;
			for (int j = 0; j < padding; j++)
			{
			_putchar(' ');
			printedChar++;
			}
			}
			return (printedChar);
			}
			/**
			 *  print_str - print reverse string
			 *  @param: --
			 *  @buffer: --
			 *  @flag: --
			 *  @width: --
			 *  @precision: --
			 *  @size: --
			 *  Return: int
			 */

int print_Rev(va_list param, char buffer[], int flag, int width, int precision, int size)
{
	char *str;
	int count = _strlen(str);
	int i;

	str = va_arg(param, char *);

	for (i = count - 1; i >= 0; i--)
	{
		_putchar(str[i]);
		count++;
	}
	return (count);
}
/**
 *  print_str - print Rot13
 *  @param: --
 *  @buffer: --
 *  @flag: --
 *  @width: --
 *  @precision: --
 *  @size: --
 *  Return: int
 */

int print_Rot13(va_list param, char buffer[], int flag, int width, int precision, int size)
{
	char *str;
	str = va_arg(param, char *);

	while (*str) {
		char c = *str;
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
			char base = (c >= 'a' && c <= 'z') ? 'a' : 'A';
			_putchar((c - base + 13) % 26 + base);
		} else {
			_putchar(c);
		}
		str++;
	}
}
/**
 * _isdigit - checks for digit
 * @c: character to be checked
 *
 * Return: 1 or 0
 */
int _isdigit(int c)
{
	if (c >= 48 && c <= 57)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

