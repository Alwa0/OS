#include <stdio.h>
#include <stdlib.h>

struct node{
    int val;
    struct node* next;

};

void print_list(struct node* n){
    struct node* t = n;
    while (t!=NULL){
        printf("%d ", t->val);
        t = t->next;
    }
}

void insert_node(struct node* n, int data){
    struct node* t = n;
    while (t->next!=NULL){
        t = t->next;
    }
    struct node* new = (struct node *) malloc(sizeof(struct node));
    new->next = NULL;
    new->val = data;
    t->next = new;
}

void delete_node(struct node* head, struct node* n){
    if(n==head){
        *head = *head->next;
    }
    else{
        struct node* t = head;
        while(t->next!=n){
            t = t->next;
        }
        t->next = t->next->next;
    }

}

int main() {
    struct node *n;
    n = malloc(sizeof(struct node));
    n->val=8;
    n->next = NULL;
    insert_node(n, 5);
    insert_node(n, 6);
    return 0;
}


