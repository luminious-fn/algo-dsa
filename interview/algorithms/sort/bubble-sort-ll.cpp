/*
export PROG="bubble-sort-ll";clear; g++ $PROG.cpp -o $PROG.exe && ./$PROG.exe 
*/

#include<iostream>
using namespace std;

typedef struct node {
    int data;
    struct node *next;
} node;

void bubble_sort_non_dec(node **head, int count){
	int i, j;
	node *p1, *p2;
	for(i=0;i<count-1; i++){
		swapped = false;
		p1 = *head;
		p2 = p1->next;
		for(j=0;j<count-1-i;j++){			
			if(p1->data > p2->data){
				swap(p1, p2);
				swapped = true;
			}
			new_head = 			
		}
		if(!swapped) {
			break;
		}
	}
}

int main(int argc, char *argv[]){	
	node *head = (node *)malloc(sizeof(node));
	head->data = 3;

	head->next = (node *)malloc(sizeof(node));
	head->next->data = 2;

	head->next->next = (node *)malloc(sizeof(node));	
	head->next->next->data = 1;

	bubble_sort_non_dec(&head, 3);

	return 0;
}
