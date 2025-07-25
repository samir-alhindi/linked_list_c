typedef struct Node {
    struct Node* next;
    int data;
    int index;
} Node;

typedef struct LinkedList {
    Node* head;
    int length;
} LinkedList;

LinkedList* new_linked_list();
void _add_node(Node* node, Node* new_node, int index);
void append(LinkedList* list, int item);
int get(LinkedList* list, int index);
void set(LinkedList* list, int at, int item);
void print_linked_list(LinkedList* list);
int check_valid_index(LinkedList* list, int index);
void free_linked_list(LinkedList* list);
void sort(LinkedList* list);
int pop(LinkedList* list);