
#include "main.h"

/**
 *  flag- gets flag
 *  @format: --
 */

char flag(const char **format)
{
	char flag = 0;
	while (**format == ' ' || **format == '+' || **format == '-' || **format == '0' || **format == '#')
	{
		if (**format == ' ')
			flag = ' ';
		else if (**format == '+')
			flag = '+';
		else if (**format == '-')
			flag = '-';
		else if (**format == '0')
			flag = '0';
		else if (**format == '#')
			flag = '#';
		(*format)++;
	}
	return flag;
}

/**
 *  width - gets width
 *  @format: --
 */

int width(const char **format)
{
	int width = 0;
	while (_isdigit(**format))
	{
		width = width * 10 + (**format - '0');
		(*format)++;
	}
	return width;
}

/**
 *  size - gets size
 *  @format: --
 */

int size(const char **format)
{
	int size = 0;
	if (**format == 'l' || **format == 'h') {
		size = **format;
		(*format)++;
	}
	return size;
}

/**
 *  specifier- gets specifiers
 *  @format: --
 */

char specifier(const char **format)
{
	return *(*format)++;
}

/**
 *  precison - gets precision
 *  @format: --
 */

int precision(const char **format)
{
	int precision = -1;
	if (**format == '.') {
		(*format)++;
		precision = 0;
		while (_isdigit(**format)) {
			precision = precision * 10 + (**format - '0');
			(*format)++;
		}
	}
	return precision;
}

