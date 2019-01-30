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
    int maxDepth(TreeNode* root) {
        int deep=0 ;
        int sum =0;
        if(root){
            deep++;
            sum = deep;
            CDeep(root,deep,sum);
        }
        return sum;
    }
    void CDeep(TreeNode*root,int deep,int &sum){
            
        if(root){
            if(root->left!=NULL){
                deep++ ;
            }
            CDeep(root->left,deep,sum);
            if(root->right!=NULL&&root->left==NULL){
                deep++ ;
            }
            CDeep(root->right,deep,sum);
            if(sum<deep){
                sum=deep;
            }
        }
    }
};

