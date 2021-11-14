#include<iostream>
#include<malloc.h>

using namespace std;
/* 
 g++ bst.cpp && a.exe
 Binary Search Trees 

 in-order traversal gets the keys in the ascending sorted order of the keys.
 pre-order traversal gets the keys in topological sorted order of the keys.

*/
typedef struct node node;
struct node {
    int key;
    struct node *left;
    struct node *right;
};

node *new_node(int key) {
    //cout << "new_node" << endl;
    node * node_ptr = (node*) malloc(sizeof(node));
    if (node_ptr != NULL) {
        node_ptr->key = key;
        node_ptr->left = node_ptr->right = NULL;
        return node_ptr;      
    } else {
        return NULL;
    }    
}

/* insert a node in BST */
node *insert(node *root, int key) {
    if(root == NULL) {
        cout << "insert: " << key << endl;
        return new_node(key);
    }
    if(key < root->key){
        //cout << "left" << endl;
        root->left = insert(root->left, key);
    } else if(key > root->key) {
        //cout << "right" << endl;
        root->right = insert(root->right, key);
    }
    return root;
}

/* get min key in right subtree of given root */
int get_right_min_key(node *root) {        
    while(root->left != NULL){ 
        root = root->left;
    }
    return root->key;
}
/* 
https://www.log2base2.com/data-structures/tree/remove-an-element-from-binary-search-tree.html

Deletes a node containing give key
Returns the re-adjusted root (if it got re-adjusted) 
*/
node *delete_node (node *root, int key) {
    if(root == NULL) {
        return root;
    }
    if(key < root->key){
        root->left = delete_node(root->left, key);
        return root;
    } else if (key > root->key) {
        root->right = delete_node(root->right, key);
        return root;
    } else {
        if((root->left == NULL) && (root->right==NULL)){
            /*root has 0 children*/
            free(root);
            return NULL;
        } else if(root->left == NULL){
            /*root has only 1 child*/
            node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL){
            /*root has only 1 child*/
            node *temp = root->left;
            free(root);
            return temp;        
        } else {
            /* root has 2 children */
            int right_min_key = get_right_min_key(root->right);
            root->key = right_min_key;
            root->right = delete_node(root->right, right_min_key);
            return root;
        }
    }    
    //return root;
}


node *search(node *root, int key) {
    if((root == NULL) || (root->key == key)) {        
        return root;
    }
    if(key < root->key){
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }    
}

void pre_order(node *root) {
    if(root == NULL) {        
        return;
    }
    cout<<" " << root->key;
    pre_order(root->left);
    pre_order(root->right);
}

void in_order(node *root) {
    if(root == NULL){        
        return;
    }
    in_order(root->left);
    //cout<< " (" << root << ")" << root->key;
    cout<< " " << root->key;
    in_order(root->right);
}

void post_order(node *root) {
    if(root == NULL){        
        return;
    }
    post_order(root->left);
    post_order(root->right);
    cout << " " << root->key; 
}

int main() {
    node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    
    node *temp = search(root, 80);
    cout << "key 40 @ node " << temp << endl;
    
    cout<< "pre_oder: ";
    pre_order(root);
    cout<< endl;
    
    cout<< "in_oder: ";        
    in_order(root); 
    cout<< endl;

    cout<< "post_oder: " ;
    post_order(root);
    cout<< endl;

    root = delete_node(root, 30);
    cout<< "in_oder after 30 deleted:";    
    in_order(root);
    cout<< endl;
    
    cout << "Done";
}
