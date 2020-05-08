//
//  main.c

//
//  main.c

#include <stdio.h>
#include <string.h>
//#include <malloc.h>
#include <stdlib.h>
#include "sph_types.h"


#include "x16rv3.h"
#include "x8r16.h"

typedef unsigned int uint32_t;
typedef unsigned char uint8_t;



#define GOLDEN_COUNTER 3

uint32_t  endiandata[GOLDEN_COUNTER][32] = {
{
0x00000000,
0x465d4f58,
0x15b0ed40,
0xee2c3b35,
0x7203cfa6,
0x391e224f,
0xee85549c,
0x00040811,
0x00000000,
0x00000000,
0x5ce9c0f4,
0x8fb801ed,
0x7fc3fb9c,
0xa70c3cd8,
0x34eaeb75,
0x095586b5,
0x9d38e171,
0x026b6d6c,
0x01d02306,
0x9eb8fd6a,
0x8fb801ed,
0x7fc3fb9c,
0xa70c3cd8,
0x34eaeb75,
0x095586b5,
0x9d38e171,
0x026b6d6c,
0x01d02306,
0x0000006a,
0x026b6d6c,
0x01d02306,
0x0000006a,
},
{
0x00000000,
0x171ca33e,
0x2dc99729,
0x8dafe8f6,
0x240c88d1,
0x3bbeba0d,
0xa40b2d81,
0x000a3dc0,
0x00000000,
0x00000000,
0xe3f0cfe4,
0xd3be8b82,
0xb4e9bc9f,
0x9361c989,
0x8b925281,
0xce3eddd0,
0xf7855220,
0xb3bd3d5e,
0x00579a05,
0x3e2d2500,
0x8fb801ed,
0x7fc3fb9c,
0xa70c3cd8,
0x34eaeb75,
0x095586b5,
0x9d38e171,
0x026b6d6c,
0x01d02306,
0x0000006a,
0x026b6d6c,
0x01d02306,
0x0000006a,
},
{
0x00000000,
0xbe73de56,
0x060d16f1,
0x8fce6a9e,
0x232a3dce,
0xdbda7fe4,
0x5108126e,
0x0009d379,
0x00000000,
0x00000000,
0x270d9ace,
0xf3ffb7f8,
0x72d625bc,
0xe9273aa9,
0xd45d895c,
0xd20d6586,
0x377e7e2a,
0x8b70b492,
0x00579a05,
0x7d246c00,
0x8fb801ed,
0x7fc3fb9c,
0xa70c3cd8,
0x34eaeb75,
0x095586b5,
0x9d38e171,
0x026b6d6c,
0x01d02306,
0x0000006a,
}
};


static const uint32_t  x8r16_hash_golden_data[GOLDEN_COUNTER][8] = {
{
0x2104ef01,
0xcb540bbf,
0x8c0db8c6,
0xc35bcb19,
0x7660c836,
0x04ac8f89,
0xecc77124,
0x74952c3a,
},
{
0xbe7f13f9,
0xe022489b,
0xf5c26c62,
0xe6d44a96,
0xfeca4e40,
0x6758938a,
0xaaa34028,
0xed08a790,
},
{
0xd33a1abb,
0x44525c6d,
0xc3bfb38b,
0x249b8bdc,
0xb0aca007,
0x1a5a94d4,
0x4ea336d1,
0x98f8559b,
},

};


static const uint32_t  x16rv3_hash_golden_data[GOLDEN_COUNTER][8] = {
{
0xa245aa9e,
0x7210bd2b,
0xf0474e87,
0x23e20a4c,
0xe8586fca,
0x92b0980b,
0x28bb4aaf,
0x0f0481b9,
},
{
0xf48c9d7d,
0x81175959,
0x4ed522c4,
0x471e579b,
0x3891ad25,
0xe45a21c5,
0x0c65e46c,
0x6fd50428,
},
{
0xfdcc9427,
0x6d4b3aee,
0x3be58a1c,
0x93a0bef5,
0x43ae16be,
0xedce5c02,
0xf5b58bd8,
0xe3acee95,
},

};

void x8r16_test(void)
{
	uint32_t  hash32[8];
	int i;
	for (i = 0; i < GOLDEN_COUNTER; i++)
	{

		x8r16_hash(hash32,endiandata[i]);

		if (memcmp(hash32, x8r16_hash_golden_data[i], 32) != 0)
		{
			printf("x8r16 output data check failed!\n");
			for(int j=0;j<8;j++)
			{
				printf("0x%08x,\n",hash32[j]);
			}
		}
		else
		{
			printf("x8r16 output data check success!\n");
		}
	}
}

void x16rv3_test(void)
{
	uint32_t  hash32[8];
	int i;
	for (i = 0; i < GOLDEN_COUNTER; i++)
	{

		x16rv3_hash(hash32,endiandata[i]);

		if (memcmp(hash32, x16rv3_hash_golden_data[i], 32) != 0)
		{
			printf("x16rv3 output data check failed!\n");
			for(int j=0;j<8;j++)
			{
				printf("0x%08x,\n",hash32[j]);
			}
		}
		else
		{
			printf("x16rv3 output data check success!\n");
		}
	}
}


int main(int argc, const char * argv[])
{
	x8r16_test();
	uint8_t  hash32[32];
	char s[113] = "helloworldhelloworldhelloworldhelloworldhelloworldhelloworldhelloworldhelloworldhelloworldhelloworldhelloworldhel";
	x8r16_hash(hash32,s);
	printf("\n");
	for(int j=0;j<32;j++)
    {
    	printf("%02x",hash32[j]);
    }
    printf("\n");
	return 0;
}
