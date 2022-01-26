#include<iostream>
/* 
Merge two sorted lists
clear;g++ -std=c++2a merge.cpp && ./a.exe
*/

class Node {
    public:
        int key;
        Node *next;
};

void insert_after(Node *current, Node *temp){
    current->next = temp;
}

Node *merge(Node *h1, Node *h2){
    
    if(!h1){
        return h2;
    } else if(!h2){
        return h1;
    }

    Node *h3, *current;    
    if(h1->key < h2->key){
        h3 = h1;
        h1 = h1->next;
    }else {
        h3 = h2;
        h2 = h2->next;
    }
    current = h3;

    while(h1 && h2 ){
        if(h1->key < h2->key){
            current->next = h1;
            current = current->next;
            h1 = h1->next;
        } else {
            current->next = h2;
            current = current->next;
            h2 = h2->next;
        }
    }
    if(h1){
        current->next = h1;
    } else if(h2){
        current->next = h2;
    }

    return h3;
}

Node *new_node(int key){
    Node *temp = new Node;
    temp->key = key;
    temp->next = nullptr;
    return temp;
}

void print_list(Node *head){
    std::cout << "\n print : " ;
    while(head){
        std::cout << head->key << ", ";
        head = head->next;
    }
}

int main(int argc, char* argv[]) {

    std::cout << "hello" << std::endl;
    Node *h1, *h2, *h3;
    h1 = h2 = h3 = nullptr;
    //h1 = new_node(10) ;
    //h1->next = new_node(20);
    //h1->next->next = new_node(30);
    print_list(h1);   

    h2 = new_node(15) ;
    h2->next = new_node(50);
    h2->next->next = new_node(60);
    print_list(h2); 

    h3 = merge(h1, h2);
    std::cout << "merged list \n";
    print_list(h3); 

    return 0;
}
