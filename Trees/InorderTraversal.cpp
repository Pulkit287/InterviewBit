/*Given a binary tree, return the inorder traversal of its nodes’ values.

Example :
Given binary tree

   1
    \
     2
    /
   3
return [1,3,2].

Using recursion is not allowed.*/


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

vector<int> Solution::inorderTraversal(TreeNode* A) {
    vector<int> ans;
     stack<TreeNode *> s;
   TreeNode* current=A;
   while(s.empty()==false || current!=NULL)
   {
       while(current!=NULL)
       {
            s.push(current);
            current=current->left;
       }
           
           current=s.top();
           s.pop();
           ans.push_back(current->val);
           current=current->right;
      
   }
    
    return ans;
}
