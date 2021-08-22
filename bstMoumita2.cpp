#include<iostream>

using namespace std;


struct node
{
    int value;
    node* left;
    node* right;
    node* parent;
};

node* root= NULL;

node* create_node(int value)
{
    node* newnode = new node;
    newnode->value = value;
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->parent = NULL;

    return newnode;
}

bool search_value(node* current_node, int given_value)
{
    if(current_node==NULL) {
        return false;
    }
    if(current_node->value == given_value) {
        return true;
    }
    else if(current_node->value > given_value) {
        return search_value(current_node->left, given_value);
    }
    else {
        return search_value(current_node->right, given_value);
    }
}

void postorder(node* current_node)
{
    if(current_node!=NULL) {
        postorder(current_node->left);
        postorder(current_node->right);
        cout<<current_node->value<<endl;
    }
}

void inorder(node* current_node)
{
    if(current_node!=NULL) {
        inorder(current_node->left);
        cout<<current_node->value<<endl;
        inorder(current_node->right);
    }
}

void inorder_search(node* current_node, int given_value)
{
    if(current_node!=NULL) {
        inorder_search(current_node->left,given_value);
        if(current_node->value==given_value) {
            cout<<"match found\n";
        }
        inorder_search(current_node->right,given_value);
    }
}

void preorder(node* current_node)
{
    if(current_node!=NULL) {
        cout<<current_node->value<<endl;
        preorder(current_node->left);
        preorder(current_node->right);
    }
}


node* insert_value(node* current_node, int new_value)
{
    if(current_node==NULL) {
        return create_node(new_value);
    }
    if(current_node->value > new_value) {
        current_node->left = insert_value(current_node->left, new_value);
        current_node->left->parent = current_node;
    }
    else {
        current_node->right = insert_value(current_node->right, new_value);
        current_node->right->parent = current_node;
    }
    return current_node;
}

int find_minimum(node* current_node)
{
    if(current_node->left!=NULL) {
        return find_minimum(current_node->left);
    }
    return current_node->value;
}

int main()
{
    root = insert_value(root,5);
    insert_value(root,20);
    insert_value(root,25);
    insert_value(root,1);
    insert_value(root,3);
    cout<<search_value(root,4)<<endl;
    cout<<endl;
    postorder(root);
    cout<<endl;
    cout<<endl;
    inorder(root);

    cout<<endl;
    cout<<find_minimum(root)<<endl;
}
