#include<iostream>
#include<malloc.h>

using namespace std;
/* 
 g++ bst.cpp && ./a.exe
 Binary Search Trees 

 in-order traversal gets the keys in the ascending sorted order of the keys.
 pre-order traversal gets the keys in topological sorted order of the keys.

*/

/*
https://www.codingeek.com/data-structure/tree-traversal-bfs-and-dfs-introduction-explanation-and-implementation/#1_breadth_first_traversalbft_breadth_forst_searchbfs
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

/* get min key in right subtree of given root 
This assumes, root is never null!
*/
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
https://www.javatpoint.com/deletion-in-binary-search-tree

*/

node *delete_node (node *root, int key) {
    if(!root) {
        return root;
    }
    if(key < root->key){
        root->left = delete_node(root->left, key);
        return root;
    } else if (key > root->key) {
        root->right = delete_node(root->right, key);
        return root;
    } else {
        if((root->left == NULL) && (root->right == NULL)){
            /*root has 0 children*/
            free(root);
            return NULL; // new root
        } else if(root->left == NULL){
            /*root has only 1 child*/
            node *new_root = root->right;
            free(root);
            return new_root;// new root
        } else if (root->right == NULL){
            /* root has only 1 child */
            node *new_root = root->left;
            free(root);
            return new_root;// new root
        } else {
            /* root has 2 children 
            get the smallest number in right sub tree (OR biggest in left subtree)
            This smallest __always__ the last child without any leaves.
            */            
            int right_min_key = get_right_min_key(root->right);
            root->key = right_min_key;
            root->right = delete_node(root->right, right_min_key);
            return root;// new root
        }
    }
    //return root;
}

node *dfs_search(node *root, int key) {
    if((root == NULL) || (root->key == key)) {
        return root;
    }
    if(key < root->key){
        return dfs_search(root->left, key);
    } else {
        return dfs_search(root->right, key);
    }
}

int get_max_level(node *root){
    if (!root){
        return 0;
    }
    int left_level = get_max_level(root->left);
    int right_level = get_max_level(root->right);
    if (left > right) {
        return left_level + 1;
    } else {
        return right_level + 1;
    }
}

void bfs(node *root, int level){
    if(!root) {
        return;
    }

    if(level == 1) {
        std::cout << root->key << ", ";
        return;
    } else {
        bfs(root->left,  level - 1);
        bfs(root->right, level - 1);
    }
}

void dfs_pre_order(node *root) {
    if(root == NULL) {        
        return;
    }
    cout<<" " << root->key;
    dfs_pre_order(root->left);
    dfs_pre_order(root->right);
}

void dfs_in_order(node *root) {
    if(root == NULL){        
        return;
    }
    dfs_in_order(root->left);
    //cout<< " (" << root << ")" << root->key;
    cout<< " " << root->key;
    dfs_in_order(root->right);
}

void dfs_in_order_descending(node *root) {
    if(root == NULL){        
        return;
    }
    dfs_in_order_descending(root->right);    
    //cout<< " (" << root << ")" << root->key;
    cout<< " " << root->key;
    dfs_in_order_descending(root->left);    
}


void dfs_post_order(node *root) {
    if(root == NULL){        
        return;
    }
    dfs_post_order(root->left);
    dfs_post_order(root->right);
    cout << " " << root->key; 
}

int total_nodes(node *root){
    if(!root){
        return 0;        
    }

    int left = total_nodes(root->left);
    int right = total_nodes(root->right);
    std::cout << " left: right = " << left << ", " << right << std::endl;
    return 1 + left + right;
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
    int count = total_nodes(root);
    std::cout << "count: " << count << std::endl;


    std::cout << "BFS: " ;
    int level = get_max_level(root);
    std::cout << "level : " << level << std::endl;
    bfs(root, level);
    std::cout << std::endl;
    
    std::cout << " DFS " << std::endl;
    node *temp = dfs_search(root, 80);
    cout << "key 40 @ node" << temp << endl;
    
    cout<< "pre_oder: ";
    dfs_pre_order(root);
    cout<< endl;
    
    cout<< "in_oder: ";        
    dfs_in_order(root);    
    cout<< endl;

    cout<< "in_oder: descedning";        
    dfs_in_order_descending(root);
    cout<< endl;

    cout<< "post_oder: " ;
    dfs_post_order(root);
    cout<< endl;

    root = delete_node(root, 30);
    cout<< "in_oder after 30 deleted:";    
    dfs_in_order(root);
    std::cout<< endl;
   
    std::cout << "Done";
}
