#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

int main(){

    LinkedList* list = new_linked_list();
    append(&list, 5);
    append(&list, 7);
    append(&list, -2);

    print_linked_list(*list);
    printf("%d", get(*list, 0));

    free(list);

    return 0;
}