#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

int main(){

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
    

    return 0;
}