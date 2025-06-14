#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    struct Node* next;
    int data;
    int index;
} Node;

typedef struct LinkedList {
    Node* head;
    int length;
} LinkedList;

LinkedList new_linked_list(){
    LinkedList* list = (LinkedList*) malloc(sizeof(LinkedList));
    if(list == NULL)
        printf("Memory allocation failed.");
    list->head = NULL;
    list->length = 0;
    return *list;
}

void add_node(Node* node, Node* new_node, int index){
    if(node->next == NULL) node->next = new_node;
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
        add_node(list->head, p_node, 0);
    }

}

void print_linked_list(LinkedList list){
    printf("{");
    Node current = *list.head;
    while(current.next != NULL){
        printf("%d, ", current.data);
        current = *current.next;
    }
    printf("%d}", current.data);

}

int main(){

    LinkedList list = new_linked_list();
    append(&list, 5);
    append(&list, 7);
    append(&list, -2);

    print_linked_list(list);

    return 0;
}