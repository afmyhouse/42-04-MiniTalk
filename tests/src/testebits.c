#include <stdio.h>
#include	<stdlib.h>

int main(void)
{
	int i = 0;
	unsigned char d = 0;
	unsigned char c = '1';

	i = 8;
	while (i > 0)
	{
		d = d >> 1;
		if (c & 0b00000001)
		{
			printf("1");
			d = (d | 128) ;
		}
		else
		{
			d = (d | 0) ;
			printf("0");
		}
		c = c >> 1;
		i--;
		//usleep(100);
	}
	printf("\nd = %u\n", d);
	printf("%u %u %u %u %u %u %u %u\n", (d & 128)/128, (d & 64)/64, (d & 32)/32, (d & 16)/16, (d & 8)/8, (d & 4)/4, (d & 2)/2, (d & 1));
	printf("\n");

	c = 0;
	c |= (1 << 0);
	c |= (1 << 4);
	c |= (1 << 5);
	printf("\nc2 = %u\n", (unsigned char)c);

	c = 0;
	c = c | (1 << 0);
	printf("\nc3 = %u\n", (unsigned char)c);
	c = c | (1 << 4);
	printf("\nc3 = %u\n", (unsigned char)c);
	c = c | (1 << 5);
	printf("\nc3 = %u\n", (unsigned char)c);
	return (0);
}