#include <iostream>
#include<stack>
using namespace std;
struct TreeNode{
    int val ;
    TreeNode* left ;
    TreeNode* right ;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};
class Solution {
public:
    void recoverTree(TreeNode* root) {
        stack<TreeNode*>_stk;
        _stk.push(root);
        while(!_stk.empty()){
            auto cur=_stk.top();
            auto l=left(cur,cur->left);
            if(!l)
                continue;
            auto r=right(cur,cur->right);
            if(!r)
                continue;
            _stk.pop();
            if(cur->left!=NULL)
                _stk.push(cur->left);
            if(cur->right!=NULL)
                _stk.push(cur->right);
        }
    }
    
    bool left(TreeNode* root,TreeNode *next){
        if(next==NULL)
            return true;
        if(root->val>next->val){
            auto l=left(root,next->left);
            if(!l)
                return false;
            auto r=left(root,next->right);
            if(!r)
                return false;
            return true;
        }
        else{
            swap(root->val,next->val);
            return false;
        }
    }
    
    bool right(TreeNode* root,TreeNode *next){
        if(next==NULL)
            return true;
        if(root->val<next->val){
            auto l=right(root,next->left);
            if(!l)
                return false;;
            auto r=right(root,next->right);
            if(!r)
                return false;
        }

        return true;    
    }
};
int main(){

}
