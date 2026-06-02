#include <stdio.h>
#include <stdlib.h>

// Узел дерева
typedef struct TreeNode {
    int data;                                                              // значение узла
    struct TreeNode* left;                                                 // указатель на левого потомка
    struct TreeNode* right;                                                // указатель на правого потомка
} TreeNode;

// Создание нового узла
TreeNode* create_node(int value) {
    TreeNode* new_node = (TreeNode*)malloc(sizeof(TreeNode));              // Выделение памяти под новый узел
    if (new_node == NULL) return NULL;
    
    new_node->data = value;                                                // Заполнение data
    new_node->left = NULL;                                                 // Обнуляет указатели на потомков
    new_node->right = NULL;
    
    return new_node;
}

// Вставка узла в дерево
TreeNode* insert(TreeNode* root, int value) { 
    if (root == NULL) {                                                    // Если дерево пусто, создаём корень
        return create_node(value);
    }
    
    if (value < root->data) {                                              // Идём влево или вправо
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);                          // Если value == root->data, ничего не делаем (дубликаты не добавляем)
    }
                                                                      
    return root;
}


// Поиск значения в дереве
TreeNode* search(TreeNode* root, int value) {
    if (root == NULL || root->data == value) {                             // Базовый случай: дерево пусто или нашли значение
        return root;
    }
    
    if (value < root->data) {                                              // Если искомое значение меньше корня - ищем в левом поддереве
        return search(root->left, value);
    }

    return search(root->right, value);                                     // Иначе ищем в правом поддереве
}


// Поиск минимального значения
TreeNode* find_min(TreeNode* root) {
    if (root == NULL) return NULL;

    while (root->left != NULL) {                                           // Идём всё время влево, пока можем
        root = root->left;
    }
    return root;
}



// Поиск максимального значения
TreeNode* find_max(TreeNode* root) {
    if (root == NULL) return NULL;
    
    while (root->right != NULL) {                                          // Идём всё время вправо, пока можем
        root = root->right;
    }
    return root;
}


// Удаление узла из дерева
TreeNode* delete_node(TreeNode* root, int value) {
    if (root == NULL) return NULL;
    
    if (value < root->data) {                                              // Ищем удаляемый узел
        root->left = delete_node(root->left, value);
    } else if (value > root->data) {
        root->right = delete_node(root->right, value);
    } else {                                                               // Нашли узел для удаления
        if (root->left == NULL) {                                          // Случай 1: нет левого потомка
            TreeNode* temp = root->right;
            free(root);
            return temp;
        }
        if (root->right == NULL) {                                         // Случай 2: нет правого потомка
            TreeNode* temp = root->left;
            free(root);
            return temp;
        }
        TreeNode* min = find_min(root->right);                             // Случай 3: есть оба потомка. Находим минимальный элемент в правом поддереве
        root->data = min->data;                                            // копируем значение
        root->right = delete_node(root->right, min->data);                 // Удаляем узел-дубликат
    }
    
    return root;
}


// Обход в порядке возрастания
void inorder(TreeNode* root) {
    if (root == NULL) return;
    
    inorder(root->left);                                                   // сначала все меньшие (левое поддерево)
    printf("%d ", root->data);                                             // потом текущий (корень)
    inorder(root->right);                                                  // потом все большие (правое поддерево)
}

// Освобождение памяти
void free_tree(TreeNode* root) {
    if (root == NULL) return;
    
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}
