/*Given a binary tree, return the postorder traversal of its nodes’ values.

Example :

Given binary tree

   1
    \
     2
    /
   3
return [3,2,1].

Using recursion is not allowed.
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
vector<int> Solution::postorderTraversal(TreeNode* A) {
    
    vector<int> ans;
    if(A==NULL)
    return ans;
    stack<TreeNode*> s1,s2;
    s1.push(A);
    while(!s1.empty())
    {
        TreeNode* temp=s1.top();
        s2.push(temp);
        s1.pop();
        if(temp->left)
        s1.push(temp->left);
        if(temp->right)
        s1.push(temp->right);
    }
    while(!s2.empty())
    {
        TreeNode* node=s2.top();
        ans.push_back(node->val);
        s2.pop();
    }
    return ans;
}
