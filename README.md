# C-BinaryTree

## Overview

A binary search tree implemented using recursive struct defenition. With the following methods:

- Tree(int data)
- addNode(int newData,struct Tree *tree)
- removeNode(int toRemove,struct Tree *tree)
- addAll(struct Tree *toAdd,Struct Tree *newTree)

## Tree(int data)

```C
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
```

The purpose of this function is to act like a constructor method, the function returns a pointer to the newly constructed Tree, which can then be assigned to a Tree pointer in another method scope.

## addNode(int newData,struct Tree *tree)

```C
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
```