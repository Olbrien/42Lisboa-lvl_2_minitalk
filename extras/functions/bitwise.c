#include <stdio.h>

int main()
{
	{
		// Z in binary is: 01011010
		// Z << 2

		// Adds 2 zeros on the right, removes first 2 bits.
		// 01011010 becomes 01101000

		// 01101000 = 104
		// Decimal 104 is the character 'h'.

		char Z = 'Z';

		Z = Z << 2;
		printf("Z << 2 = %c\n", Z);
	}
	{
		// Z in binary is: 01011010
		// Z >> 1

		// Adds 1 zeros on the right, removes first 1 bits.
		// 01011010 becomes 00101101

		// 01101000 = 45
		// Decimal 45 is the character '-'.

		char Z = 'Z';

		Z = Z >> 1;
		printf("Z >> 1 = %c\n", Z);
	}
	{
		// Z in binary is: 01011010
		// x in binary is: 01111000
		// Z & x

		// Returns a 1 in each bit position for which the corresponding bits of
		// both operands are 1's.

		//   01011010
		//   01111000
		// ------------
		//   01011000

		// 01011000 = 88
		// Decimal 88 is the character 'X'.

		char Z = 'Z';
		char x = 'x';
		char result;

		result = Z & x;
		printf("Z & x = %c\n", result);
	}
	{
		// Z in binary is: 01011010
		// x in binary is: 01111000
		// Z | x

		// Returns a 1 in each bit position for which the corresponding bits of
		// either or both operands are 1s.

		//   01011010
		//   01111000
		// ------------
		//   01111010

		// 01111010 = 122
		// Decimal 122 is the character 'z'.

		char Z = 'Z';
		char x = 'x';
		char result;

		result = Z | x;
		printf("Z | x = %c\n", result);
	}
	{
		// Z in binary is: 01011010
		// x in binary is: 01111000
		// Z ^ x

		// Returns a 1 in each bit position for which the corresponding bits
		// of either but not both operands are 1s.

		//   01011010
		//   01111000
		// ------------
		//   00100010

		// 01111010 = 34
		// Decimal 34 is the character '"'.

		char Z = 'Z';
		char x = 'x';
		char result;

		result = Z ^ x;
		printf("Z ^ x = %c\n", result);
	}
	{
		// Z in binary is: 01011010
		// ~Z

		// Invert all bits in an integer variable. All 1's become zero and all
		// 0's become ones.

		//   01011010
		// ------------
		//   10100101

		// 10100101 = 165
		// Decimal 165 is the character 'Â¥'.

		char Z = 'Z';

		Z = ~Z;
		printf("~Z = %c\n", Z);
	}
}
