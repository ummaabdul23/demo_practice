#include "main.h"

/**
 *  print_Unsig - print unsigned integers
 *  @param: --
 *  @buffer: --
 *  @flag: --
 *  @width: --
 *  @precision: --
 *  @size: --
 *  Return: int
 */

int print_Unsig(va_list param, char buffer[], int flag, int width, int precision,int size)
{
	int i = BUFFER - 2;
	unsigned long int n = va_arg(param, unsigned long int);

	n = convert_unsig(n, size);

	if (n == 0)
		buffer[i--] = '0';
	buffer[BUFFER - 1] = '\0';

	while (n > 0)
	{
		buffer[i--] = (n % 10) + '0';
		n /= 10;
	}
	i++;
	return (write_unsig(0, i, buffer,flag, width, precision, size));
}
/**
 *  print_Oct - print octal
 *  @param: --
 *  @buffer: --
 *  @flag: --
 *  @width: --
 *  @precision: --
 *  @size: --
 *  Return: int
 */

int print_Oct(va_list param, char buffer[], int flag, int width, int precision, int size)
{
	int i = BUFFER - 2;
	unsigned long int n = va_arg(param, unsigned long int);
	unsigned long int a = n;

	UNUSED(width);

	if (n == 0)
		buffer[i--] = '0';
	buffer[BUFFER - 1] = '\0';

	while (n > 0)
	{
		buffer[i--] = (n % 8) + '0';
		n /= 8;
	}
	if (flag == '#' && a != 0)
		buffer[i--] = '0';
	i++;
	return (write_unsig(0, i, buffer, flag, width, precision, size);
			}
			/**
			 *  print_Hex - print hexadecimal
			 *  @param: --
			 *  @map_to: --
			 *  @buffer: --
			 *  @flag: --
			 *  @f: --
			 *  @width: --
			 *  @precision: --
			 *  @size: --
			 *  Return: int
			 */

			int print_Hex(va_list param, char map_to, char buffer[], int flag, char f, int width, int precision, int size)
			{
			int i = BUFFER - 2;
			unsigned long int n = va_arg(param, unsigned long int);
			unsigned long int a = n;

			UNUSED(width);
			n = convert_unsig(n, size);

			if (n)
				buffer[i--] = '0';
			buffer[BUFFER - 1] = '\0';

			while (n > 0)
			{
				if (f == 'X')
					buffer[i--] = map_to[n % 16];
				else if (f == 'x')
					buffer[i--] = map_to[n % 16] -32
						n /= 16;
			}
			if (flag == '#' && a != 0)
			{
				buffer[i--] = f;
				buffer[i--] = '0';
			}
			i++;
			return (write_unsig(0, i, buffer, flag, width, precision, size));
			}
/**
 *  print_Bin - print binary
 *  @param: --
 *  @buffer: --
 *  @flag: --
 *  @width: --
 *  @precision: --
 *  @size: --
 *  Return: int
 */

int print_Bin(va_list param,char buffer[], int flag, int width,int precision, int size)
{
	unsigned int i, x, y, sum;
	unsigned int arr[32];
	int count;

	UNUSED(buffer);
	UNUSED(flag);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	x = va_arg(param, unsigned int);
	y = 2147483648 // 2^31
		arr[0] = x / y;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		arr[i] = (x / y) % 2;
	}
	i = 0;
	count = 0;
	sum = 0;

	while (i < 32)
	{
		sum += arr[i];
		if (sum || i == 31)
		{
			char z = '0' + arr[i];
			_putchar(z);
			count++;
			i++;
		}
	}
	return (count);
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

