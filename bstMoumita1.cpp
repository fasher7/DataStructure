#include <iostream>

using namespace std;

struct node
{
    int value;
    node *left;
    node *right;
};

node *root = NULL;

node *create_node(int value)
{
    node *newnode = new node;
    newnode->value = value;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
}

bool search_value(node *current_node, int given_value)
{
    if (current_node == NULL)
    {
        return false;
    }
    if (current_node->value == given_value)
    {
        return true;
    }
    else if (current_node->value > given_value)
    {
        return search_value(current_node->left, given_value);
    }
    else
    {
        return search_value(current_node->right, given_value);
    }
}

void postorder(node *current_node)
{
    if (current_node != NULL)
    {
        postorder(current_node->left);
        postorder(current_node->right);
        cout << current_node->value << endl;
    }
}

void inorder(node *current_node)
{
    if (current_node != NULL)
    {
        inorder(current_node->left);
        cout << current_node->value << endl;
        inorder(current_node->right);
    }
}

void preorder(node *current_node)
{
    if (current_node != NULL)
    {
        cout << current_node->value << endl;
        preorder(current_node->left);
        preorder(current_node->right);
    }
}

node *insert_value(node *current_node, int new_value)
{
    if (current_node == NULL)
    {
        return create_node(new_value);
    }
    if (current_node->value > new_value)
    {
        current_node->left = insert_value(current_node->left, new_value);
    }
    else
    {
        current_node->right = insert_value(current_node->right, new_value);
    }
    return current_node;
}

int main()
{
    root = insert_value(root, 5);
    insert_value(root, 2);
    root = insert_value(root, 9);
    root = insert_value(root, 7);
    //cout<<search_value(root,4)<<endl;
    preorder(root);
    
}
