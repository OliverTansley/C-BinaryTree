#include <stdio.h>
#include <stdlib.h>

struct Tree
{
    int data;
    struct Tree *left;  //pointer to another tree struct
    struct Tree *right; //pointer to another tree struct
};

//Tree struct constructor function
struct Tree *Tree(int data)
{
    struct Tree *T;
    T = malloc(sizeof(struct Tree));

    T->data = data;
    T->left = NULL;
    T->right = NULL;

    return T;
}

/**
 * @brief This function adds data to the tree by declaring a new Tree struct
 * @param data is the data to be added to the tree
 * @param tree pointer to the tree that the data should be added to
 * @return pointer to the updated tree 
 */
struct Tree *addNode(int newData, struct Tree *tree)
{
    if (tree->data == 0)
    {
        tree->data = newData;
    }
    else
    {
        if (newData < tree->data)
        {
            if (tree->left == NULL)
            {
                tree->left = Tree(newData);
            }
            else
            {
                addNode(newData, tree->left);
            }
        }
        else
        {
            if (tree->right == NULL)
            {
                tree->right = Tree(newData);
            }
            else
            {
                addNode(newData, tree->right);
            }
        }
    }
    return tree;
}

int main()
{
    struct Tree *T;
    T = malloc(sizeof(struct Tree));
    T = addNode(4, T);
    T = addNode(1, T);
    printf("%d\n", T->data);
    printf("%d", T->left->data);
}