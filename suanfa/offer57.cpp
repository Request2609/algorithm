#include <iostream>
#include <map>
#include <stdio.h>
using namespace std ;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead) {
       /* ListNode* tmp = pHead ;
        ListNode* pre = pHead ;
        ListNode* cur = pre ->next ;
        while(cur) {
            if(pre->val == cur->val) {
                if(pre == pHead) {
                    pHead = cur->next ;
                    free(pre) ;
                    free(cur) ;
                    tmp = pHead ;
                    pre = pHead ;
                    cur = pHead->next ;
                }
                else {
                    tmp->next = cur->next ;
                    free(pre) ;
                    pre = cur->next ;
                    free(cur) ;
                    cur = pre->next ;
                }
            }
            else {
                tmp = pre ;               
                pre = cur ;
                cur = pre->next ;
            }
        }*/
        ListNode* first = new ListNode(-1) ;
        first->next = pHead ;
        ListNode*p = pHead ;
        ListNode* last = first ;
        while(p != NULL && p->next != NULL) {
            //是重复的元素
            if(p->val == p->next->val) {
                int val = p->val ;
                while(p!=NULL && p->val == val) {
                    p = p->next ;
                }
                last->next = p ;
            }
            else {
                last = p ;
                p = p->next ;
            }
        }   
        return first->next ;
    }
};
int main()
{
    return 0;
}

