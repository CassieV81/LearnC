#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int number;
    struct node *next;
} node;

int linked_list(int num, node **list);
int sorted_linked_list(int num, node **sorted_list);
void free_list(node *list);

int main(int argc, char *argv[]) {

    node *list = NULL;
    node *sorted_list = NULL;
    
    for (int i = 1; i < argc; i++) {
        int number = atoi(argv[i]);

        linked_list(number, &list);
        sorted_linked_list(number, &sorted_list);

    }

    node *ptr = list;
    node *ptr2 = sorted_list;
    printf("Unsorted list: ");
    while (ptr != NULL) {
        printf("%i ", ptr->number);
        ptr = ptr->next;
    }
    printf("\n");
    printf("Sorted list: ");
    while (ptr2 != NULL) {
        printf("%i ", ptr2->number);
        ptr2 = ptr2->next;
    }
    printf("\n");

    free_list(list);
    free_list(sorted_list);

}

int linked_list(int num, node **list) {

    node *n = malloc(sizeof(node));
    if (n == NULL) {
        return 1;
    }
    n->number = num;
    n->next = *list;

    *list = n;
    
    return 0;
}

int sorted_linked_list(int num, node **sorted_list) {

    node *n = malloc(sizeof(node));
    if (n == NULL) {
        return 1;
    } 
    n->number = num;
    n->next = NULL;

    if (*sorted_list == NULL) {
        *sorted_list = n;
    } else if (n->number < (*sorted_list)->number) {
        n->next = *sorted_list;
        *sorted_list = n;
    } else {
        for (node *ptr = *sorted_list; ptr !=NULL; ptr = ptr->next) {
            if (ptr->next == NULL) {
                ptr->next = n;
                break;
            } else if (n->number < ptr->next->number) {
                n->next = ptr->next;
                ptr->next = n;
                break;
            }
        }
    }

    return 0;
}

void free_list(node *list) {
    node *tmp;
    while (list != NULL) {
        tmp = list;
        list = list->next;
        free(tmp);
    }
}