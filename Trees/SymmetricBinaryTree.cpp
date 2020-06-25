/*Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

Example :

    1
   / \
  2   2
 / \ / \
3  4 4  3
The above binary tree is symmetric.
But the following is not:

    1
   / \
  2   2
   \   \
   3    3
Return 0 / 1 ( 0 for false, 1 for true ) for this problem
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int check(TreeNode* A,TreeNode *B)
{
    if(A==NULL && B==NULL)
    return 1;
    if(A==NULL || B==NULL)
    return 0;
    if(A->val==B->val && check(A->left,B->right) && check(A->right,B->left))
    return 1;
    else
    return 0;
}
int Solution::isSymmetric(TreeNode* A) {
    
    if(A==NULL)
    return 1;
    else
    return check(A->left,A->right);
    
    
}

