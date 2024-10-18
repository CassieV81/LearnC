#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int number;
    struct node *left;
    struct node *right;
} node;

int binary_tree(int num, node **tree);
bool search_tree(int num, node *tree);
int tree_depth(node *tree, int rdepth, int ldepth);
void depth_first(node *tree);
void print_tree(node *tree);

int main(int argc, char *argv[]) {

    node *tree = NULL;

    for (int i = 1; i < argc; i++) {
        int number = atoi(argv[i]);

        binary_tree(number, &tree);
       
    }

    // bool check = search_tree(40, tree);
    // printf("%i\n", check);

    int depth = tree_depth(tree, 0, 0);
    printf("%i\n", depth);
    
    // print_tree(tree);
    depth_first(tree);
    printf("\n");
}

int binary_tree(int num, node **tree) {
    
    node *n = malloc(sizeof(node));
    if (n == NULL) {
        return 1;
    }
    n->number = num;
    n->left = NULL;
    n->right = NULL;

    if (*tree == NULL) {
        *tree = n;
    } else if (n->number < (*tree)->number) {
        binary_tree(n->number, &(*tree)->left);
    } else {
        binary_tree(n->number, &(*tree)->right);
    }

    return 0;
}

int tree_depth(node *tree, int rdepth, int ldepth) {
    
    // printf("Left: %i\n", ldepth);
    // printf("Right: %i\n", rdepth);
    if (tree == NULL) {
        if (rdepth > ldepth){
            return rdepth;
        } else {
            return ldepth;
        }
    } 
    if (tree->left != NULL) {
        ldepth++;
        ldepth = tree_depth(tree->left, rdepth, ldepth);
        ldepth = tree_depth(tree->left->right, rdepth, ldepth);
    } 
    if (tree->right != NULL) {
        rdepth++;
        rdepth = tree_depth(tree->right, rdepth, ldepth);
        rdepth = tree_depth(tree->right->left, rdepth, ldepth);
    }
    if (rdepth > ldepth){
        return rdepth;
    } else {
        return ldepth;
    }
}

int balance_tree(node *tree) {
    
}

bool search_tree(int num, node *tree) {

    if (tree == NULL) {
        return false;
    } else if (num < tree->number) {
        return search_tree(num, tree->left);
    } else if (num > tree->number) {
        return search_tree(num, tree->right);
    } else {
        return true;
    }
    
}

void depth_first(node *tree) {
    if (tree != NULL) {
        if ( tree->left != NULL) {
            depth_first(tree->left);
        } 
        printf("%i ", tree->number);
        if ( tree->right != NULL) {
            depth_first(tree->right);
        } 
    }
}

void print_tree(node *tree) {
    if (tree != NULL) {
        printf("%i\n", tree->number);
        
        if (tree->left != NULL) {
            printf("/ ");
            print_tree(tree->left);
        }
        if (tree->right != NULL) {
            printf("\\ ");
            print_tree(tree->right);
        }
    }
}