/*Given preorder and inorder traversal of a tree, construct the binary tree.

 Note: You may assume that duplicates do not exist in the tree. 
Example :

Input :
        Preorder : [1, 2, 3]
        Inorder  : [2, 1, 3]

Return :
            1
           / \
          2   3
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
 
map<int,int> mp;
int pre=0;
TreeNode* build(vector<int> &A,vector<int> &B,int s,int e)
{
    if(s>e)
    return NULL;
    
    TreeNode* temp=new TreeNode(A[pre++]);
    int ind=mp[temp->val];
    temp->left=build(A,B,s,ind-1);
    temp->right=build(A,B,ind+1,e);
    
    return temp;
    
}
 
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    
    for(int i=0;i<B.size();i++)
    {
        mp[B[i]]=i;
    }
    pre=0;
    return build(A,B,0,A.size()-1);
}