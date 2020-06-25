/*Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers % 1003.

Example :

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = (12 + 13) % 1003 = 25 % 1003 = 25.
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
void solve(TreeNode* root,int &sum,int x)
{
    if(root==NULL)
    return;
    
    x=((x*10)%1003+root->val%1003)%1003;
    if(root->left==NULL && root->right==NULL)
    {
        sum=(sum%1003+x%1003)%1003;
        return;
    }
    solve(root->left,sum,x);
    solve(root->right,sum,x);
}
int Solution::sumNumbers(TreeNode* A) {
    int sum=0;
    solve(A,sum,0);
    return sum%1003;
}
