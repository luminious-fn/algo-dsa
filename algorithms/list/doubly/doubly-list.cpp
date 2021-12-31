/*
I have given due credits using reference links.
Ref: https://www.geeksforgeeks.org/doubly-linked-list/
g++ doubly-list.cpp  && ./a.exe
*/

#include<iostream>
#include <stdlib.h>
#include<unordered_set>

using namespace std;

typedef struct node {
    int data;
    struct node *prev;
    struct node *next;
} node;


/*
append to the list
*/

void append(node **head_ref, int data) {

    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = new_node->prev = nullptr;

    if(head_ref == nullptr) {
        return;
    }

    if(*head_ref == nullptr){
        *head_ref = new_node;
        return;
    }
    
    node *last_node = *head_ref;
    while(last_node->next) {
        last_node = last_node->next;
    }
    last_node->next = new_node;
    new_node->prev = last_node;
    return;
}

/* insert at front. i.e, we get new head! */
void push(node **head_ref, int data){
    cout << __FUNCTION__ << endl;
    if((head_ref == nullptr) || (*head_ref == nullptr)){
        cout << "return : null err" << endl;
        return;
    }
    node *new_node = (node *)malloc(sizeof(node));    
    if(new_node == nullptr) { 
        return;
    }
    new_node->data = data;
    (*head_ref)->prev = new_node;
    new_node->next = *head_ref;
    new_node->prev= nullptr;
    *head_ref = new_node;

    return;
}
/*
ref: https://www.geeksforgeeks.org/doubly-linked-list/
*/
void insert_after(struct node* prev_node, int new_data) {
    if(prev_node == nullptr){
        return;
    }
    node *new_node = (node *)malloc(sizeof(node));
    if(new_node == nullptr){
        return;
    }
    new_node->data = new_data;
    new_node->prev = prev_node;
    new_node->next = prev_node->next;

    if(prev_node->next != nullptr){
        prev_node->next->prev = new_node;
        prev_node->next = new_node;
    } else {
        prev_node->next = new_node;        
    }
}

void print_list(node *head){
    cout << "__FUNCTION__" << endl;
    cout << "Forward print:" << endl;
    
    node *last = nullptr;
    node *node = head;

    while(node) {
        cout << " " << node->data;        
        last = node;
        node = node->next;        
    }

    cout << endl << "Reverse print:" << endl;
    node = last; 
    while(node) {
        cout << " " << node->data;      
        node = node->prev;
    }

}

int main(int argc, char *argv[]) {
    node *head = nullptr;   
    append(&head, 100);
    append(&head, 200);
    append(&head, 300);
    push(&head, 99);
    push(&head, 98);
    print_list(head);
    cout << endl << "calling insert_after" << endl;
    insert_after(head->next->next, 8);
    print_list(head);
    cout << endl << "return from main " << endl;
}
