#include <iostream>
#include <vector>
using namespace std ;
//平衡二叉树的左子树和右子树的高度差不超过1

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
class Solution {
public:
    int depth(TreeNode*pRoot) {
        if(pRoot == NULL) 
            return 0 ;
        int l = depth(pRoot->left) ;
        int r = depth(pRoot->right) ;
        return ((l>r)?l:r)+1 ;
     }

    bool IsBalanced_Solution(TreeNode* pRoot) {
        if(pRoot == NULL) {
            return true ; 
        }
        int left = depth(pRoot->left) ;
        int right = depth(pRoot->right) ;
        if(fabs(left-right) <= 1) {
            return IsBalanced_Solution(pRoot->left)&&IsBalanced_Solution(pRoot->right) ;
        }
        else {
            return false ;
        }
    }
};

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

