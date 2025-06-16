#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

void grades_average();

int main(){

    grades_average();

    LinkedList* list = new_linked_list();

    append(list, 3);
    append(list, 2);
    append(list, 1);
    append(list, -1);
    append(list, -2);
    
    
    sort(list);

    print_linked_list(list);
    int Tail = pop(list);

    print_linked_list(list);
    printf("Tail: %d", Tail);

    free_linked_list(list);

    return 0;
}

void grades_average(){
    int count;
    printf("How many grades will you enter: ");
    scanf("%d", &count);

    LinkedList* list = new_linked_list();

    for(int i = 0; i < count; i++){
        int num;
        printf("\nPlease enter grade #%d: ", i + 1);
        scanf("%d", &num);
        append(list, num);
    }

    printf("\nYou entered: ");
    int sum = 0;
    for(int i = 0; i < list->length; i++){
        printf("\n#%d- %d", i + 1, get(list, i));
        sum += get(list, i);
    }
    
    float average = (float) sum / count;
    printf("\nThe average is: %.2f", average);
    
    free_linked_list(list);
}