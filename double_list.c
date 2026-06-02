#include <stdio.h>
#include <stdlib.h>

// Узел двусвязного списка
typedef struct Node {
    int data;                                                 // данные (целое число)
    struct Node* prev;                                        // указатель на предыдущий узел
    struct Node* next;                                        // указатель на следующий узел
} Node;

// Добавление в начало списка
Node* push_front(Node* head, int value) {
    Node* new_node = (Node*)malloc(sizeof(Node));             // Создаём новый узел
    if (new_node == NULL) return head;                        // если память не выделилась - выходим
                                                              
    new_node->data = value;                                   // Заполняем данные
    new_node->prev = NULL;                                    // перед новым узлом никого нет
    new_node->next = head;                                    // следующий за новым - старый head
    
    if (head != NULL) {                                       // Если список не пуст, у старого head'а меняем prev на новый узел
        head->prev = new_node;
    }
    
    return new_node;                                          // Новый узел становится головой списка
}

// Добавление в конец списка
Node* push_back(Node* head, int value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) return head;
    
    new_node->data = value;
    new_node->next = NULL;                                    // новый узел будет последним в списке
                                                                 
    if (head == NULL) {                                       // Если список пуст, новый узел становится головой
        new_node->prev = NULL;
        return new_node;
    }
    
    Node* current = head;                                     // Идём в конец списка
    while (current->next != NULL) {
        current = current->next;
    }
    
    current->next = new_node;                                 // Привязываем новый узел в конец
    new_node->prev = current;
    
    return head;                                              // голова не меняется
}



// Удаление первого элемента
Node* pop_front(Node* head) {
    if (head == NULL) return NULL;                            // список пуст

    Node* new_head = head->next;                              // сохраняем второй узел
    
    if (new_head != NULL) {
        new_head->prev = NULL;                                // новый первый элемент теперь без предыдущего
    }
    
    free(head);                                               // удаляем старую голову
    return new_head;
}


// Удаление последнего элемента
Node* pop_back(Node* head) {
    if (head == NULL) return NULL;                            // список пуст
                                                  
    if (head->next == NULL) {                                 // Если в списке один элемент
        free(head);
        return NULL;
    }
      
    Node* current = head;                                     // Идём в конец списка
    while (current->next != NULL) {
        current = current->next;
    }
    
    Node* prev_node = current->prev;                         // current теперь указывает на последний узел. предпоследний узел                                     
    prev_node->next = NULL;                                  // теперь он последний
    
    free(current);                                           // удаляем последний
    return head;                                             // голова не меняется
}


// Разворот списка
Node* reverse(Node* head) {
    if (head == NULL) return NULL;                           // пустой список
    
    Node* current = head;
    Node* temp = NULL;
                                          
    while (current != NULL) {                                // Меняем местами prev и next для каждого узла
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        
        current = current->prev;                             // переходим к следующему (бывшему next)
    }
    
    if (temp != NULL) {                                      // После цикла temp указывает на новую голову
        return temp->prev;
    }
    
    return head;
}


// Проходит по списку от головы до конца (пока current != NULL) и печатает данные каждого узла
void print_list(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Освобождает память всех узлов
void free_list(Node* head) {
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;                                // Сохраняет temp, чтобы не потерять ссылку на следующий узел
        current = current->next;
        free(temp);
    }
}
