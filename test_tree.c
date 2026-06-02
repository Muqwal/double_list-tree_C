#include <stdio.h>
#include <stdlib.h>
#include "library/tree.h"


int main() {
    TreeNode* tree = NULL;
    
    tree = insert(tree, 50);                                               // Дерево:
    tree = insert(tree, 30);                                               //        50                                                
    tree = insert(tree, 70);                                               //       |  |
    tree = insert(tree, 20);                                               //     30   70              
    tree = insert(tree, 40);                                               //     | |  | |             
    tree = insert(tree, 60);                                               //    20 40 60 80            
    tree = insert(tree, 80);                                                               
    
    printf("Original tree: ");
    inorder(tree);                                                         // 20 30 40 50 60 70 80
    printf("\n");
    
    tree = insert(tree, 100); 
    printf("Tree after insert 100: ");
    inorder(tree);                                                         // 20 30 40 50 60 70 80 100
    printf("\n");


    TreeNode* found = search(tree, 100); 
    if (found != NULL) {
        printf("Node found: %d\n", found->data);                           // 100
    } else {
        printf("Node 100 not found\n");
    }

    TreeNode* found_2 = search(tree, 200); 
    if (found_2 != NULL) {
        printf("Node found: %d\n", found_2->data);                           
    } else {
        printf("Node 200 not found\n");                                    // Not found
    }
    
    TreeNode* min = find_min(tree);
    printf("Tree minimum: %d\n", min->data);                               // 20

    TreeNode* max = find_max(tree);
    printf("Tree maximum: %d\n", max->data);                               // 100


    tree = delete_node(tree, 50);                                          // удаляем корень
    printf("Tree after delete 50: ");
    inorder(tree);                                                         // 20 30 40 60 70 80 100
    printf("\n");

    tree = delete_node(tree, 70);                                          // удаляем корень
    printf("Tree after delete 70: ");
    inorder(tree);                                                         // 20 30 40 60 70 80 100
    printf("\n");

    free_tree(tree);                                                            
    return 0;
}