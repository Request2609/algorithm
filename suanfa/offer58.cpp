#include <iostream>
#include <vector>
using namespace std ;
struct TreeLinkNode
{
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;

    TreeLinkNode(int x = 0)
    :val(x), left(NULL), right(NULL), next(NULL)
    {

    }
};

class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode) {
        if(pNode == NULL) {
            return NULL ;
        }
        TreeLinkNode* pnext = NULL;
       if(pNode->right != NULL) {
            pnext = pNode->right ;
            while(pnext->left) {
                pnext = pnext ->left ;
            }
        }
       else if(pNode->right == NULL && pNode->next != NULL) {
            TreeLinkNode* pcur = pNode ;
            TreeLinkNode* pp = pNode->next ;
            while(pp != NULL && pcur == pp->right) {
                pcur = pp ;
                pp = pp->next ;
            }
            pnext = pp ;
       }
       return pnext ;
    }
} ;
int main() {
    return 0;
}

