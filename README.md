# C-BinaryTree

## Overview

This project is a binary search tree written in C to help me learn more about structs and pointers. The tree is implemented using a recursive struct defenition where the struct has the following properties:

```C
struct Tree
{
    int data;
    int size;
    struct Tree *left;
    struct Tree *right;
};
```
- data is the value stored at that particular node in the tree
- left is a pointer to another Tree struct representing the left subtree
- right is a pointer to another Tree struct representing the right subtree
- size is an integer value representing the total elements stored in the tree including subtrees.

The following functions have also been implented to act as methods for the binary search tree:

[Tree](# Tree)
- addNode(int newData,struct Tree *tree)
- removeNode(int toRemove,struct Tree *tree)
- addAll(struct Tree *toAdd,Struct Tree *newTree)

## Tree(int data)

The purpose of this function is to act like a constructor method, the function returns a pointer to the newly constructed Tree, which can then be assigned to a Tree pointer in another method scope.

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