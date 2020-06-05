/*Given inorder and postorder traversal of a tree, construct the binary tree.

 Note: You may assume that duplicates do not exist in the tree. 
Example :

Input : 
        Inorder : [2, 1, 3]
        Postorder : [2, 3, 1]

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
TreeNode* build(vector<int> &A,vector<int> &B,int s,int e,int &pos)
{
    if(s>e)
    return NULL;
    
    TreeNode* temp=new TreeNode(B[pos--]);
    int ind=mp[temp->val];
     temp->right=build(A,B,ind+1,e,pos);
    temp->left=build(A,B,s,ind-1,pos);
   
    return temp;
    
}
 
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    
    for(int i=0;i<A.size();i++)
    {
        mp[A[i]]=i;
    }
    int pos=B.size()-1;
    return build(A,B,0,A.size()-1,pos);
}