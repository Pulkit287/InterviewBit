/*Given a binary tree and a sum, find all root-to-leaf paths where each path’s sum equals the given sum.

For example:
Given the below binary tree and sum = 22,

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return

[
   [5,4,11,2],
   [5,8,4,5]
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
void solve(TreeNode *root,int sum,int B,vector<vector<int>> &vv,vector<int> &v)
{
    if(root==NULL)
    return;
    
    sum+=root->val;
    v.push_back(root->val);
    if(root->left==NULL && root->right==NULL && sum==B)
    {
        vv.push_back(v);
    }
    
    
    solve(root->left,sum,B,vv,v);
    solve(root->right,sum,B,vv,v);
    v.pop_back();
    
}
vector<vector<int> > Solution::pathSum(TreeNode* A, int B) {
    vector<int> v;
    vector<vector<int>> vv;
    solve(A,0,B,vv,v);
    return vv;
}
