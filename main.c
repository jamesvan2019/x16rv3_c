//
//  main.c

#include <stdio.h>
#include <string.h>
//#include <malloc.h>
#include <stdlib.h>
#include "sph_types.h"


#include "x16rv3.h"

typedef unsigned int uint32_t;
typedef unsigned char uint8_t;



#define x16rv3_GOLDEN_COUNTER 3

static const uint32_t  x16rv3_hash_golden_data[x16rv3_GOLDEN_COUNTER][8] = {
{
0x11fd5a42,
0x9ef2b304,
0x28cac113,
0x63a52d3f,
0x1c7ebf8d,
0xcf462654,
0x6f1f7f9b,
0xdd0df41f,
},
{
0xb8639be5,
0x0aad3bb7,
0x064c5191,
0x8308de33,
0xeceb0a2b,
0x85f52eff,
0x83903b16,
0x949dcae5,
},
{
0x37a37b37,
0x5762b0b1,
0xe378405f,
0xeb0d3b9f,
0xd4d60d41,
0x368be1c6,
0xc79aa1ac,
0x5d70ef65,
},

};

uint32_t  x16rv3_endiandata[x16rv3_GOLDEN_COUNTER][32] = {
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


void x16rv3_test(void)
{
	uint32_t  hash32[8];
	int i;
	for (i = 0; i < x16rv3_GOLDEN_COUNTER; i++)
	{

		x16rv3_hash(hash32,x16rv3_endiandata[i]);

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
	uint32_t  hash32[8];
	char s[113] = "helloworldhelloworldhelloworldhelloworldhelloworldhelloworldhelloworldhelloworldhelloworldhelloworldhelloworldhel";
	x16rv3_hash(hash32,s);
	for(int j=0;j<8;j++)
    {
    	printf("%x",hash32[j]);
    }
    printf("\n");
	return 0;
}
