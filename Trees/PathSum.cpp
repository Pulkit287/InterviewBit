/*Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

Example :

Given the below binary tree and sum = 22,

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.

Return 0 / 1 ( 0 for false, 1 for true ) for this problem
 */
int solve(TreeNode* root,int sum,int B)
{
    if(root==NULL)
    return 0;
    
    if(root->left==NULL && root->right==NULL && sum+root->val==B)
    return 1;
    
    return solve(root->left,sum+root->val,B)||
    solve(root->right,sum+root->val,B);
}
 
int Solution::hasPathSum(TreeNode* A, int B) {
    return solve(A,0,B);
}
