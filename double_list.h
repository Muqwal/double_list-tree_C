// Узел двусвязного списка
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* push_front(Node* head, int value);
Node* push_back(Node* head, int value);
Node* pop_front(Node* head);
Node* pop_back(Node* head);
Node* reverse(Node* head);
void print_list(Node* head);
void free_list(Node* head);