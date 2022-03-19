#include<iostream>

/*
 g++ decimal-char.cpp && ./a.exe
 */
int main(int argc, char *argv[]){

	char s[80];
	char *p;
	while(1){

		gets(s);
		p=s;
		while(*p) {
			printf("%d ",*p++);
		}
	}
}
