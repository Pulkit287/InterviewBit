/*Given an inorder traversal of a cartesian tree, construct the tree.

 Cartesian tree : is a heap ordered binary tree, where the root is greater than all the elements in the subtree. 
 Note: You may assume that duplicates do not exist in the tree. 
Example :

Input : [1 2 3]

Return :   
          3
         /
        2
       /
      1
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
int maxx(vector<int> A,int st,int end)
{
    int m=INT_MIN;
    int ind=-1;
    for(int i=st;i<=end;i++)
    {
        if(A[i]>m)
        {
            ind=i;
            m=A[i];
        }
    }
    return ind;
}
TreeNode* build(vector<int> A,int st,int end)
{
    if(st>end)
    return NULL;
    
    int mi=maxx(A,st,end);
    TreeNode* temp=new TreeNode(A[mi]);
    temp->left=build(A,st,mi-1);
    temp->right=build(A,mi+1,end);
    
    return temp;
}
TreeNode* Solution::buildTree(vector<int> &A) {
    
    return build(A,0,A.size()-1);
    
}
