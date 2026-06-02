// Узел дерева
typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Объявления функций
TreeNode* create_node(int value);
TreeNode* insert(TreeNode* root, int value);
TreeNode* search(TreeNode* root, int value);
TreeNode* find_min(TreeNode* root);
TreeNode* find_max(TreeNode* root);
TreeNode* delete_node(TreeNode* root, int value);
void inorder(TreeNode* root);
void free_tree(TreeNode* root);