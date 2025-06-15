#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

LinkedList* new_linked_list(){
    LinkedList* list = (LinkedList*) malloc(sizeof(LinkedList));
    if(list == NULL)
        printf("Memory allocation failed.");
    list->head = NULL;
    list->length = 0;
    return list;
}

void add_node(Node* node, Node* new_node, int index){
    if(node->next == NULL){
        node->next = new_node;
        new_node->index = index;
    } 
    else add_node(node->next, new_node, index + 1);
}

void append(LinkedList* list, int item){

    list->length++;

    if(list->head == NULL){
        Node* p_head_node = malloc(sizeof(Node));
        if(p_head_node == NULL)
            printf("Memory allocation failed.");
        p_head_node->data = item;
        p_head_node->index = 0;
        p_head_node->next = NULL;
        list->head = p_head_node;
    }
    else{
        Node* p_node = malloc(sizeof(Node));
        if(p_node == NULL)
            printf("Memory allocation failed.");
        p_node->data = item;
        p_node->next = NULL;
        add_node(list->head, p_node, 1);
    }

}

int get(LinkedList list, int index){
    if(index >= list.length){
        printf("Error: index %d is out of bounds for LinkedList of size %d", index, list.length);
        exit(1);
    }

    Node cur = *list.head;
    while(cur.index != index)
        cur = *cur.next;
    return cur.data;

    
}

void print_linked_list(LinkedList list){
    printf("{");
    if(list.length == 0){
        printf("}\n");
        return;
    }
    Node current = *list.head;
    while(current.next != NULL){
        printf("%d, ", current.data);
        current = *current.next;
    }
    printf("%d}\n", current.data);

}