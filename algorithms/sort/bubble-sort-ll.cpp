/*
export PROG="bubble-sort-ll";clear; g++ $PROG.cpp -o $PROG.exe && ./$PROG.exe 
*/

#include<iostream>
using namespace std;

typedef struct node {
    int data;
    struct node *next;
} node;

node *a, *b, *c;

void print_ll(node *head){
	cout << __FUNCTION__ << ": ";
	while(head){		
		//cout << "[ "<<head <<"= d:"<< head->data << ", nx= "<< head->next<<" ], ";
		cout <<  head->data << ", ";
		head = head->next;
	}
	cout<< endl;
}

void print_lla(void){
	cout << __FUNCTION__ << endl;			
	cout << a <<"= d:"<< a->data << ", nx= " << a->next << endl;
	cout << b <<"= d:"<< b->data << ", nx= " << b->next << endl;
	cout << c <<"= d:"<< c->data << ", nx= " << c->next << endl;		
}

node *swap(node *p1, node *p2){	
	cout << "swap " << p1->data << " " << p2->data << endl;
	node *temp = p2->next;
	p2->next = p1;
	p1->next =  temp;	
	return p2;
}

void bubble_sort_non_dec(node **head_pp, int count){
	for(int i=0; i< count-1; i++){
		cout << "i = " << i << endl;
		print_ll(*head_pp);
		node **temp_head = head_pp;
		bool swaped = false;
		for(int j=0; j<count-1-i; j++){
			cout << "j = " << j << endl;
			node *p1 = *temp_head;
			node *p2 = (*temp_head)->next;
			cout << "j = " << j << ", p1 = " << p1 << ", p2= " << p2 << endl;
			if(p1->data > p2->data){
				//print_ll(*head_pp);
				print_lla();
				swap(p1, p2);
				//print_ll(*head_pp);
				print_lla();
				*temp_head = p2;
				print_lla();
				//print_ll(*head_pp);
				swaped = true;
			}
			temp_head = &((*temp_head)->next);
		}
	}
}

node * bubble_sort_non_dec_v1(node *head_pp, int count){	
	node *ret_head = head_pp;
	for(int i=0; i< count-1; i++){
		cout << "i = " << i << "ret_head: " << ret_head << endl;
		node *temp_head = ret_head;		
		node *prvs = NULL;
		bool swaped = false;
		//bool main_head_changed = false;
		for(int j=0; j < count-1-i; j++){			
			cout << "j = " << j << endl;
			node *p1 = temp_head;
			node *p2 = temp_head->next;
			if(p1->data > p2->data){
				swap(p1, p2);				
				temp_head = p2;
				if(prvs){
				 	prvs->next = p2;
				}
				if (!j) {
					//main_head_changed = true;
					ret_head = p2;
					cout << "ret_head changed = " << ret_head << endl;
					//print_ll(ret_head);					
				}				
			}
			prvs = temp_head;
			temp_head = temp_head->next;			
		}		
	}
	return ret_head;
}

int main(int argc, char *argv[]){	
	node *head = a = (node *)malloc(sizeof(node));
	cout << "node 5 = " << head << endl;
	head->data = 4;
	head->next = NULL;

	head->next = b =(node *)malloc(sizeof(node));
	cout << "node 1 = " << head->next << endl;
	head->next->data = 3;
	head->next->next = NULL;

	head->next->next = c = (node *)malloc(sizeof(node));
	cout << "node 4 = " << head->next->next << endl;
	head->next->next->data = 2;
	head->next->next->next = NULL;

	head->next->next->next= c = (node *)malloc(sizeof(node));
	cout << "node 2 = " << head->next->next->next << endl;
	head->next->next->next->data = 1;
	head->next->next->next->next = NULL;

	node *temp = head;
	int count = 0;
	while(temp){
		count++;
		temp = temp->next;
	}

	print_ll(head);
	cout << "head = " << head << endl;
#if 0
	bubble_sort_non_dec(&head, count);
#else
	head = bubble_sort_non_dec_v1(head, count);
#endif
	cout << "head = " << head << endl;
	//print_lla();
	print_ll(head);

	return 0;
}
