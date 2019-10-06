#include <iostream>
#include <vector>
#include <stack>
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
    vector<int> printListFromTailToHead(ListNode* head) {
        ListNode* tmp = head;
        stack<ListNode*>ls ;
        while(tmp != NULL) {
            ls.push(tmp)  ;  
        }

        vector<int>ss(ls.size()) ;
        while(!ls.empty()) {
            ss.push_back(ls.top()->val) ;
            ls.pop() ;
        }
        return ss ;
    }
};
int main() {
    
    return 0;
}

