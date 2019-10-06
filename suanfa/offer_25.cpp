#include <iostream>
//二叉树中和为某一值的路径
#include <vector>
using namespace std ;
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class solution {
public :
    vector<vector<int>> result ;
    vector<int>elem ;
    void dfs(TreeNode* root, int expectNumber) {
        if(root)
            elem.push_back(root->val) ;
        else {
            return ;
        }
        //当前节点的值和要比较的值相等，并且已经到达了叶子节点，elem为符合条件的集合之一
        if(root->val == expectNumber && root->left == NULL&& root->right == NULL) {
            result.push_back(elem) ;
        }
        else {
            if(root->left) {
                //不是叶子节点，继续dfs
                dfs(root->left, expectNumber-root->val) ;
            }
            if(root->right) {
                //继续dfs
                dfs(root->right, expectNumber-root->val) ;
            }
        }
        //如果从叶子节点到根节点的和不等于expectNumber，则元素退栈
        //进行另一路径的判断
        elem.pop_back() ;
    }
    
    vector<vector<int>> FindPath(TreeNode* root, int expectNumber) {
        if(root) {
            dfs(root, expectNumber) ;
        }
        return result ;
    }
} ;

int main() {
    
    return 0;
}

