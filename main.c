#include <stdio.h>
#include <stdlib.h>

/**
 * Binary Search tree
 * Oliver Tansley
 * began: 12/08/2021
 * finished: TBD
 */

//helper function returns length of an array of int's
int length(int *arr)
{
    return sizeof(arr) / sizeof(int);
}

/**
 * Tree struct is recursively defined, the left and right 
 * subtrees are pointers to other tree structs that all 
 * hold one item of data in this case 'int'.
 */
struct Tree
{
    int data;
    int length;
    struct Tree *left;
    struct Tree *right;
};

/**
 * @brief Tree Contstructor.
 * @param data the data that will be inserted to the tree.
 * @return a pointer to the newly created Tree struct.
 */
struct Tree *Tree(int data)
{
    struct Tree *T;
    T = malloc(sizeof(Tree));
    T->data = data;
    T->left = NULL;
    T->right = NULL;
    T->length = 1;
    return T;
}

/**
 * @brief This function adds data to the tree by declaring a new Tree struct.
 * @param data is the data to be added to the tree.
 * @param tree pointer to the tree that the data should be added to.
 * @return pointer to the updated tree.
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
    tree->length++;
    return tree;
}

/**
 * @brief adds all the contents of one tree to another.
 * @param toAdd the tree whos contents are added.
 * @param newTree the tree which the contents are added to.
 * @return A pointer to the new modified tree.
 */
struct Tree *addAll(struct Tree *toAdd, struct Tree *newTree)
{
    if (toAdd->left != NULL)
    {
        addAll(toAdd->left, newTree);
    }
    if (toAdd->data != 0)
    {
        newTree = addNode(toAdd->data, newTree);
    }
    if (toAdd->right != NULL)
    {
        addAll(toAdd->right, newTree);
    }
    return newTree;
}

/**
 * @brief removes data from the tree by redefining another tree struct.
 * @param toRemove the data which is removed from the tree.
 * @param tree the tree struct which data is removed from.
 * @return a pointer to the new updated tree.
 */
struct Tree *removeNode(int toRemove, struct Tree *tree)
{
    tree->length--;
    if (tree->data == toRemove)
    {
        if (tree->left == NULL && tree->right == NULL)
        {
            return NULL;
        }
        else if (tree->left != NULL && tree->right == NULL)
        {
            return tree->left;
        }
        else if (tree->left == NULL && tree->right != NULL)
        {
            return tree->right;
        }
        else
        {
            tree->right = addAll(tree->left, tree->right);
            return removeNode(toRemove, tree);
        }
    }
    else
    {
        if (toRemove < tree->data)
        {
            tree->left = removeNode(toRemove, tree->left);
        }
        else
        {
            tree->right = removeNode(toRemove, tree->right);
        }
    }
}

int main()
{
    struct Tree *t;
    t = Tree(3);
    t = addNode(5, t);
    t = addNode(4, t);

    printf("%d %d %d", t->data, t->right->data, t->right->left->data);

    t = removeNode(5, t);

    printf("\n");

    printf("%d %d ", t->data, t->right->data);
}