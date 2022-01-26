#include<iostream>
/* 
g++ rev-list.cpp && ./a.out
*/

class node {    
    public:
        int key;
        node *next;        
};

node *reverse(node *head){
    node *temp;

    if(!head){
        return head;
    }

    node *prev, *curr, *next;
    prev = nullptr;
    curr = head;

    while(curr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr =  next;
    }
    return prev;
}

node *new_node(int key){
    node *ptr = new node;
    ptr->key = key;
    ptr->next = nullptr;
    return ptr;
}

void print_list(node *head){
    std::cout << "\n print : " ;
    while(head){
        std::cout << head->key << ", ";
        head = head->next;
    }
}

int main(int argc, char* argv[]) {

    std::cout << "hello" << std::endl;
    node *head { nullptr };
    head = new_node(10) ;
    head->next = new_node(20);
    head->next->next = new_node(30);
    print_list(head);

    head = reverse(head);
    print_list(head);

    return 0;

}
