#include <iostream>
#include <string.h>
#include <string>
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
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
        ListNode* p1 = pHead ;
        ListNode* p2 = pHead ;
        while(p1 != NULL && p2 != NULL) {
            p1 = p1->next ;
            p2 = p2->next->next ;
            if(p1 == p2) {
                break ;
            }
        }
        p2 = p2->next ;
        int count = 1 ;
        while(p1 != p2) {
            p2 = p2->next ;
            count ++ ;
        }
        return p2 ;
    }
};
int main() {
    std::cout << "Hello world" << std::endl;
    return 0;
}

