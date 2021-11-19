/*
clear; g++ matrix-multiplication.cpp  && ./a.exe
*/

#include<iostream>
using namespace std;

typedef struct node {
    int data;
    struct node *next;
} node;

void print_list(node *nd) {
    cout << endl;
    while(nd != NULL){
        cout << " " << nd->data;
        nd = nd->next;
    }
}

node *create_node(int data) {
    node *nd = (node *)malloc(sizeof(node));
    if(nd == NULL) {
        cout<< "create_node() failed" << endl;
    } else {
        nd->data = data;
        nd->next = NULL;
    }
    return nd;
}

node *insert_before_head(node *head, int data) {
    node *new_node = create_node(data);
    if(new_node == NULL) {
        cout << "node allocation failed" << endl;
        return head;
    }

    cout << "new head created" << endl;
    new_node->next = head;
    return new_node;

}

int insert_after_a_node(node *after_node, int data) {
    node *new_node = create_node(data);
    if(new_node == NULL) {
        cout << "node allocation failed" << endl;
        return 1;
    }

    cout << "new head created" << endl;
    new_node->next = after_node->next;
    after_node->next = new_node;    
    return 0;    

}

node *append(node *head, int data) {
    node *new_node = create_node(data);
    if(new_node == NULL) {
        cout << "node allocation failed" << endl;
        return head;
    }

    if(head == NULL){
        return new_node;
    }
    node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = new_node;
    return head;   

}

/*
Ref: https://www.geeksforgeeks.org/reverse-a-linked-list/?ref=lbp
Reverse the given linked list
*/
node *reverse(node *head) {
    
    node *current = head;
    node *prev = NULL;
    node *next = NULL;
    while(current) {        
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;        
    }
    return prev;
}

/* 
Ref:
https://www.geeksforgeeks.org/detect-loop-in-a-linked-list/?ref=leftbar-rightbar
*/
/* loop detect: by storing the each node address in a
set, but by checking if it already exists.
returns true if it finds the loop.
returns false otherwise.
*/
bool detect_loop(node *h) {    
    unordered_set<node*> s;
    while(h) {
        if(s.find(h) == s.end()) {
            s.insert(h);
            h = h->next;
        } else {
            cout << "detect_loop(): found loop" << endl;
            return true;
        }
    }
    cout << "no loop exists" << endl; 
    return false; // no loop
}

/* detect loop using Floyed's cycle finding algo */
bool detect_loop_floyed(node *h) {
    node *slow_p = h;
    node *fast_p = h;

    while(slow_p && fast_p && fast_p->next) {
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;
        if (slow_p == fast_p) {
            cout << "detect_loop_floyed(): loop found" << endl;
            return true;
        }
    }
    cout << "detect_loop_floyed(): false: no loop" << endl;
    return false;
}

/* 

The function removes duplicates from a sorted list 
https://www.geeksforgeeks.org/remove-duplicates-from-a-sorted-linked-list/

*/
void remove_duplicates(struct node* head) {
    if(!head){
        return;        
    }

    node *current = head;
    while(current->next) {
        if(current->data == current->next->data){
            // remove current->next
            node *next_to_next;
            next_to_next = current->next->next;
            free(current->next);
            current->next = next_to_next;
        } else {
            current = current->next;
        }
    }
}

int main(int argc, char *argv[]) {

    node *head = NULL;    
    #if 0
    head = insert_before_head(head, 400);
    head = insert_before_head(head, 500);
    insert_after_a_node(head, 300);
    #endif
    
    head = append(head, 100);
    head = append(head, 100);
    head = append(head, 200);
    head = append(head, 200);
    head = append(head, 400);
    head = append(head, 400);
    #if 0
    head->next->next->next = head; // create loop.
    detect_loop(head);
    detect_loop_floyed(head);
    #endif

    #if 1
    print_list(head);
    remove_duplicates(head);
    print_list(head);

    head = reverse(head);
    print_list(head);
    #endif

}
