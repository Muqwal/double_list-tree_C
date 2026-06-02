#include <stdio.h>
#include <stdlib.h>
#include "library/double_list.h"

int main() {
    Node* list = NULL;
    
    list = push_front(list, 10);                             // список: 10
    printf("Original list: ");
    print_list(list); 

    printf("After push_front: ");
    list = push_front(list, 20);                             // список: 20 -> 10
    print_list(list);

    printf("After reverse: ");
    list = reverse(list);                                    // список: 10 -> 20
    print_list(list);

    printf("After push_back: ");
    list = push_back(list, 30);                              // список: 10 -> 20 -> 30
    print_list(list);                                         
    
    printf("After pop_front: ");
    list = pop_front(list);                                  // список: 20 -> 30
    print_list(list);  

    printf("After pop_back: ");
    list = pop_back(list);                                   // список: 20
    print_list(list);  

    free_list(list);                                         // очистка памяти
    return 0;
}