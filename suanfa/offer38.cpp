#include <iostream>
#include <stdio.h>
using namespace std ;
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
    int TreeDepth(TreeNode* pRoot)
    {
         if(pRoot == NULL) {
            return 0 ;
        }
        int r =TreeDepth(pRoot->right) ;
        int l = TreeDepth(pRoot->left) ;
        return ((r>l)?r:l)1 ;
    }
};
int main()
{
    
    return 0;
}

