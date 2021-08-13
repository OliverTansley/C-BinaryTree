#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

/**
 * Binary Search tree
 * Oliver Tansley
 * began: 12/08/2021
 * finished: TBD
 */

/**
 * Tree struct is recursively defined, the left and right 
 * subtrees are pointers to other tree structs that all 
 * hold one item of data in this case 'int'.
 */
struct Tree
{
    int data;
    int size;
    struct Tree *left;
    struct Tree *right;
};

/**
 * Helper function returns the larges of two integers
*/
int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

/**
 * @brief treeHeight returns the height of a particular tree.
 * @param tree pointer to the tree whos height is calculated.
 * @return the number of data nodes stored below the tree.
*/
int treeHeight(struct Tree *tree)
{
    if (tree == NULL)
    {
        return 0;
    }
    else
    {
        return max(treeHeight(tree->left), treeHeight(tree->right)) + 1;
    }
}

/**
 * @brief showTree function recursively displays a tree provided that ncurses mode is established 
 * @param x the x position that the tree will be displayed
 * @param y the y position that the tree will be displayed
*/
void showTree(struct Tree *tree, int x, int y)
{
    if (tree->data != 0)
    {
        mvprintw(y, x, "%d", tree->data);
    }
    if (tree->left != NULL)
    {
        for (int i = 0; i < treeHeight(tree); i++)
        {
            mvprintw(y + 1 + i, x - 1 - i, "/");
        }
        showTree(tree->left, x - treeHeight(tree), y + treeHeight(tree));
    }
    if (tree->right != NULL)
    {
        for (int i = 0; i < treeHeight(tree); i++)
        {
            mvprintw(y + 1 + i, x + 1 + i, "\\");
        }
        showTree(tree->right, x + treeHeight(tree), y + treeHeight(tree));
    }
}

/**
 * @brief initialises ncurses mode and calls the showTree function
 * @param tree pointer to the tree that will be displayed to the screen 
*/
void display(struct Tree *tree)
{
    int row, col;
    initscr();
    getmaxyx(stdscr, row, col);
    mvprintw(0, 0, "Your Binary Search Tree:");
    showTree(tree, col / 2, 2);
    mvprintw(row - 1, col - 1, "");
    refresh();
    getch();
    endwin();
}

/**
 * @brief inOrderTraversal will either write all nodes to a file or print to stdout if a file is not passed
 * @param f pointer to file for traversal to be written to, if equal to NULL traversal will be printed using printf
 * @param tree pointer to tree that will be traversed
*/
void inOrderTraversal(struct Tree *tree, FILE *f)
{
    if (tree->left != NULL)
    {
        inOrderTraversal(tree->left, f);
    }
    if (f == NULL)
    {
        printf("%d,", tree->data);
    }
    else
    {
        fprintf(f, "%d,", tree->data);
    }
    if (tree->right != NULL)
    {
        inOrderTraversal(tree->right, f);
    }
}

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
    T->size = 1;
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
    tree->size++;
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
    tree->size--;
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
            return tree->right;
        }
    }
    else
    {
        if (toRemove < tree->data)
        {
            tree->left = removeNode(toRemove, tree->left);
            return tree;
        }
        else
        {
            tree->right = removeNode(toRemove, tree->right);
            return tree;
        }
    }
}

int main()
{
}