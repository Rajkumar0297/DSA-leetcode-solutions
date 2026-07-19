/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* build(
    int* preorder,
    int preStart,
    int preEnd,
    int* inorder,
    int inStart,
    int inEnd) {

    if (preStart > preEnd || inStart > inEnd)
        return NULL;

    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = preorder[preStart];
    root->left = NULL;
    root->right = NULL;

    int index = inStart;
    while (inorder[index] != root->val)
        index++;

    int leftSize = index - inStart;

    root->left = build(preorder,
                       preStart + 1,
                       preStart + leftSize,
                       inorder,
                       inStart,
                       index - 1);

    root->right = build(preorder,
                        preStart + leftSize + 1,
                        preEnd,
                        inorder,
                        index + 1,
                        inEnd);

    return root;
}

struct TreeNode* buildTree(int* preorder, int preorderSize,
                           int* inorder, int inorderSize) {
    return build(preorder, 0, preorderSize - 1,
                 inorder, 0, inorderSize - 1);
}