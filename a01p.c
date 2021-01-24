// do not change this code except in the following ways:
//   * write code for the following functions:
//      * getNextHexInt()
//      * printNumberData()
//   * change studentName by changing "I. Forgot" to your actual name

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static char *studentName = "Devon Wilson";


// get next int (entered in hex) using scanf()
// returns true (success) or false (failure)
// if call succeeded, return int value via iPtr
bool getNextHexInt(unsigned int *iPtr)
{
	// replace this code with the call to scanf()
        int iHex;
        bool valid = scanf("%x", &iHex);
        if(valid)
        {
            *iPtr = iHex;
        }
        return valid;
}

// print requested data for the given number
void printNumberData(int i)
{
    unsigned signBit = ((i & 0x80000000) >> 0x1f);
    unsigned expBits = ((i & 0x7F800000) >> 0x17);
    unsigned fractBits = (i & 0x007fffff);
    printf("signBit %u, expBit %3u, fractBits %#010X", signBit, expBits, fractBits);
    int exp = expBits - 127;
    if(exp == -127)
    {
        exp++;
    }
    if(expBits == 0xff && !fractBits)
    {
        printf("%cinfinity\n", (signBit ? '-' : '+'));
    }
    else if (expBits == 0xff && fractBits)
    {
        (signBit == 1) ? printf("\nQNaN\n") : printf("\nSNaN\n");
    }
    else if (!(expBits || fractBits))
    {
        (signBit == 1) ? printf("\n-zero\n") : printf("\n+zero\n");
    }
    else
    {
        printf("\n%-13s %i\n", (expBits == 0 ? "denormalized:   exp = " : "normalized:   exp = "), exp);
    }
    printf("\n");
}

// do not change this function in any way
int main(int argc, char **argv)
{
	unsigned int	i;					// number currently being analyzed
	bool			validInput;			// was user input valid?

	printf("CS201 - A01p - %s\n\n", studentName);
	for (;;) {
		if (argc == 1)						// allow grading script to control ...
			printf("> ");					// ... whether prompt character is printed
		validInput = getNextHexInt(&i);
		printf("0x%08X\n", i);
		if (! validInput) {					// encountered bad input
			printf("bad input\n");
			while (getchar() != '\n') ;		// flush bad line from input buffer
			continue;
			}
		printNumberData(i);
		if (i == 0) {
			printf("bye...\n");
			break;
			}
		}
	printf("\n");
        short x, z;
        x = 32767;
        z = x + 2;
        printf("%d \n, z");
	return 0;
}
