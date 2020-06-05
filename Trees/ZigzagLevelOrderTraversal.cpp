/*Given a binary tree, return the zigzag level order traversal of its nodes’ values. (ie, from left to right, then right to left for the next level and alternate between).

Example :
Given binary tree

    3
   / \
  9  20
    /  \
   15   7
return

[
         [3],
         [20, 9],
         [15, 7]
]
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
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    
    vector<vector<int>> ans;
    if(A==NULL)
    return ans;
    
    stack<TreeNode*> s1,s2;
    s2.push(A);
    while(!s1.empty()||!s2.empty())
    {
        vector<int> v;
       
        while(!s2.empty())//left to right
        {
            TreeNode* temp=s2.top();
            //cout<<temp->val;
            v.push_back(temp->val);
            s2.pop();
            if(temp->left)
            s1.push(temp->left);
            if(temp->right)
            s1.push(temp->right);
        }
        if(v.size()>0)
        ans.push_back(v);
        v.clear();
         while(!s1.empty())//right to left
        {
            TreeNode* temp=s1.top();
            //cout<<temp->val;
            v.push_back(temp->val);
            s1.pop();
            if(temp->right)
            s2.push(temp->right);
            if(temp->left)
            s2.push(temp->left);
        }
        if(v.size()>0)
        ans.push_back(v);
        v.clear();
    }
    
    return ans;
    
    
}
