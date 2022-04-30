#include <unistd.h>
#include <stdio.h>

int main()
{
	// Convert to Binary

	char binary[8];
	char Z = 'x';

	int bits = 7;
	int i = 0;
	while (bits >= 0)
	{
		char bit = (Z >> bits & 1) + 48;
		binary[i] = bit;
		bits--;
		i++;
	}
	binary[8] = '\0';

	write(1, binary, 8);
	write(1, "\n", 1);


	// Convert to char

	int binary_table[8] = {128, 64, 32, 16, 8, 4, 2, 1};
	int converted = 0;

	i = 0;
	while (i < 8)
	{
		if (binary[i] == '1')
			converted += binary_table[i];
		i++;
	}
	write(1, &converted, 1);
	write(1, "\n", 1);
}
