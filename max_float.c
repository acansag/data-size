#include <stdio.h>
#include <float.h>

//assumes little endian
void printBits(size_t const size, void const * const ptr)
{
    unsigned char *b = (unsigned char*) ptr;
    unsigned char byte;
    int i, j;

    for (i=size-1;i>=0;i--)
    {
        for (j=7;j>=0;j--)
        {
            byte = b[i] & (1<<j);
            byte >>= j;
            printf("%u", byte);
        }
    }
    puts("");
}


int main()
{	
	int a=3;
	float b = 5.25;
	float f = FLT_MAX;
	
	printf("%d is -> ",a);
	printBits(sizeof(a), &a);
	printf("%f is -> ",b);
	printBits(sizeof(b), &b);
	printf("%f is -> ",f);
	printBits(sizeof(f), &f);
	f = FLT_MIN;
	printf("%f is -> ",f);
	printBits(sizeof(f), &f);

	return 0;
}

/*
	additional info:

	http://stackoverflow.com/questions/2053843/min-and-max-value-of-data-type-in-c
	http://stackoverflow.com/questions/111928/is-there-a-printf-converter-to-print-in-binary-format
	http://en.cppreference.com/w/c/types/limits

*/

