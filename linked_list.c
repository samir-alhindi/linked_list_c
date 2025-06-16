#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "linked_list.h"

LinkedList* new_linked_list(){
    LinkedList* list = (LinkedList*) malloc(sizeof(LinkedList));
    if(list == NULL)
        printf("Memory allocation failed.");
    list->head = NULL;
    list->length = 0;
    return list;
}

void _add_node(Node* node, Node* new_node, int index){
    if(node->next == NULL){
        node->next = new_node;
        new_node->index = index;
    } 
    else _add_node(node->next, new_node, index + 1);
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
        _add_node(list->head, p_node, 1);
    }

}

int get(LinkedList* list, int index){
    index = check_valid_index(list, index);

    Node cur = *list->head;
    while(cur.index != index)
        cur = *cur.next;
    return cur.data;

}

void set(LinkedList* list, int at, int item){
    int index = check_valid_index(list, at);

    Node* cur = list->head;
    while(cur->index != index)
        cur = cur->next;
    
    cur->data = item;

}

void sort(LinkedList* list){
    for(int i = 0; i < list->length; i++){
        for(int j = 0; j < list->length - 1; j++){
            if( get(list, j) > get(list, j + 1) ){
                int temp = get(list, j);
                set(list, j, get(list, j + 1) );
                set(list, j + 1, temp);
            }
        }
    }
}

int check_valid_index(LinkedList* list, int index){

    // Negative index:
    if(index < 0)
        index = list->length + index;
    
    if(index >= list->length || index < 0){
        printf("Error: index %d is out of bounds for LinkedList of size %d\n", index, list->length);
        exit(1);
    }
    
    return index;
}

int pop(LinkedList* list){

    if(list->length == 0){
        printf("Can't pop from an empty list\n");
        exit(1);
    }

    else if(list->length == 1){
        list->length--;
        int value = list->head->data;
        list->head = NULL;
        free(list->head);
        return value;
    }

    // Get node right before tail of linked list:
    Node* current = list->head;
    while(current->index < (list->length - 2) )
        current = current->next;
    
    int value = current->next->data;
    
    // Free the tail:
    free(current->next);
    current->next = NULL;
    list->length--;
    return value;

}

void print_linked_list(LinkedList* list){
    
    printf("{");
    if(list->length == 0){
        printf("}\n");
        return;
    }
    Node current = *list->head;
    while(current.next != NULL){
        printf("%d, ", current.data);
        current = *current.next;
    }
    printf("%d}\n", current.data);

}

void free_linked_list(LinkedList* list){

    Node* current = list->head;
    while(current->index < list->length){
        Node* node_to_be_freed = current;
        free(node_to_be_freed);
        current = current->next;
    }
    
    free(list);

}