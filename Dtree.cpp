#include <iostream>
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
     bool isSymmetric(TreeNode* root){
            
         bool same = true ;
         if(root)
         DTree(root->left,root->right,same);
        return same ;
    }
    void DTree(TreeNode* l,TreeNode* r,bool &same){
        
        if((l==NULL&&r!=NULL)||(r==NULL&&l!=NULL)){
            same=false;
        }
        if(l&&r){
            if(r->val!=l->val){
                same = false ;
            }
            
            DTree(l->left,r->right,same);
            DTree(l->right,r->left,same);
        }
    }
};

