#include<stdio.h>
/*
 * https://www.cs.cornell.edu/~tomf/notes/cps104/floating.html
 * 
 * */

int main(){
	{
		int x = y = 3, y+1 
	printf("---------------\n");
	printf("signed  0xFFFFFFE2\n");
	int myInt = 0xFFFFFFE2;
	printf("signed   :   %d\n", myInt);
	printf("unsigned :   %u\n", myInt);
	printf("hex      :0X %X\n", myInt);
	}
	
	{
	printf("---------------\n");
	int myInt = 30;
	printf("signed  30\n");
	printf("signed   :   %d\n", myInt);
	printf("unsigned :   %u\n", myInt);
	printf("hex      :0X %X\n", myInt);
	}
	
	{
	printf("---------------\n");
	int myInt = -30;
	printf("signed  -30\n");
	printf("signed   :   %d\n", myInt);
	printf("unsigned :   %u\n", myInt);
	printf("hex      :0X %X\n", myInt);
	}

}