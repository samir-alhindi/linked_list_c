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
void add_node(Node* node, Node* new_node, int index);
void append(LinkedList* list, int item);
int get(LinkedList list, int index);
void print_linked_list(LinkedList list);