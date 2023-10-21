#include "main.h"
/**
 *  handle_char - handles char
 *  @c: --
 *  @buffer: --
 *  @flag: --
 *  @width: --
 *  @precision: --
 *  @size: --
 *  Return: int
 */

int handle_char(char c, char buffer[],
		int flag, int width, int precision, int size)
{
	int i = 0;
	char padd = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flag & '0')
		padd = '0';

	buffer[i++] = c;
	buffer[i] = '\0';

	if (width > 1)
	{
		buffer[BUFFER - 1] = '\0';
		for (i = 0; i < width - 1; i++)
			buffer[BUFFER - i - 2] = padd;

		if (flag & 1)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFFER - i - 1], width - 1));
		else
			return (write(1, &buffer[BUFFER - i - 1], width - 1) +
					write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}


/**
 * write_number - Prints a string
 * @neg: Lista of arguments
 * @index: char types.
 * @buffer: Buffer array to handle print
 * @flag:  Calculates active flags
 * @width: get width.
 * @precision: precision specifier
 * @size: Size specifier
 *
 * Return: Number of chars printed.
 */
int write_number(int neg, int index, char buffer[],
		int flag, int width, int precision, int size)
{
	int length = BUFFER - index - 1;
	char padd = ' ', extra_ch = 0;

	UNUSED(size);

	if ((flag & 4) && (!flag & 1))
		padd = '0';
	if (neg)
		extra_ch = '-';
	else if (flag & 2)
		extra_ch = '+';
	else if (flag & 16)
		extra_ch = ' ';

	return (write_num(index, buffer, flag, width, precision,
				length, padd, extra_ch));
}

/**
 * write_num - Write a number using a bufffer
 * @ind: Index at which the number starts on the buffer
 * @buffer: Buffer
 * @flag: Flags
 * @width: width
 * @precision: Precision specifier
 * @length: Number length
 * @padd: Pading char
 * @extra_c: Extra char
 *
 * Return: Number of printed chars.
 */
int write_num(int index, char buffer[],
		int flag, int width, int precision,
		int length, char padd, char extra_c)
{
	int i, padd_start = 1;

	if (precision == 0 && ind = BUFFER - 2 && buffer[index] == '0' && width == 0)
		return (0);
	if (precision == 0 && index == BUFFER - 2 && buffer[index] == '0')
		buffer[index] = padd = ' ';
	if (precision > 0 && precision < length)
		padd = ' ';
	while (precision > length)
		buffer[--index] = '0', length++;
	if (extra_c != 0)
		length++;
	if (width > length)
	{
		for (i = 1; i < width - length + 1; i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (flag & 1 && padd == 16)
		{
			if (extra_c)
				buffer[--index] = extra_c;
			return (write(1, &buffer[index], length) + write(1, &buffer[1], i - 1));
		}
		else if (!(flag & 1) && padd == ' ')
		{
			if (extra_c)
				buffer[--index] = extra_c;
			return (write(1, &buffer[1], i - 1) + write(1, &buffer[index], length));
		}
		else if (!(flag & 1) && padd == '0')
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			return (write(1, &buffer[padd_start], i - padd_start) +
					write(1, &buffer[index], length - (1 - padd_start)));
		}
	}
	if (extra_c)
		buffer[--index] = extra_c;
	return (write(1, &buffer[index], length));
}

/**
 * write_unsgnd - Writes an unsigned number
 * @is_negative: Number indicating if the num is negative
 * @ind: Index at which the number starts in the buffer
 * @buffer: Array of chars
 * @flags: Flags specifiers
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 *
 * Return: Number of written chars.
 */

int write_unsig(int neg, int index,
		char buffer[],
		int flag, int width, int precision, int size)
{
	int length = BUFFER - index - 1, i = 0;
	char padd = ' ';

	UNUSED(neg);
	UNUSED(size);

	if (precision == 0 && index == BUFFER - 2 && buffer[index] == '0')
		return (0);

	if (precision > 0 && precision < length)
		padd = ' ';

	while (precision > length)
	{
		buffer[--index] = '0';
		length++;
	}

	if ((flag & 4) && !(flag & 1))
		padd = '0';

	if (width > length)
	{
		for (i = 0; i < width - length; i++)
			buffer[i] = padd;

		buffer[i] = '\0';

		if (flag & 1)
		{
			return (write(1, &buffer[index], length) + write(1, &buffer[0], i));
		}
		else
		{
			return (write(1, &buffer[0], i) + write(1, &buffer[index], length));
		}
	}

	return (write(1, &buffer[index], length));
}
/**
 *  convert_unsig - convert numbers
 *  @num: --
 *  @size: --
 * Return: int
 */

long int convert_unsig(unsigned long int num, int size)
{
	if (size == 2)
		return (num);
	else if (size == 1)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
