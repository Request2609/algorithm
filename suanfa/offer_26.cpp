#include <iostream>
#include <vector>
//复杂链表的复制
using namespace std ;
struct LinkNode {
   int val ;
    LinkNode* next ;
    LinkNode* sibling ;
} ;


class ComplexLink {
public :
    //先将每个next连接的节点复制一份，并连接到链表中
    void cloneNode(LinkNode* head) {
        LinkNode* node = head ;
        while(node != NULL) {
            LinkNode* clone = new LinkNode() ;
            clone->val = node->val ;
            clone->next = node->next ;
            //设置sibling域为空
            clone->sibling = NULL ;
            //令node的下一个节点为clone节点
            node->next = clone ;
            //遍历到下一个节原始点
            node = clone->next ;
        }
    }
    //设置复制出来的节点的sibling域
    void setSibling(LinkNode* head) {
        LinkNode* tmp = head ;
        while(tmp != NULL) {
            LinkNode* cloned = head->next ;
            if(cloned->sibling != NULL) {
                cloned->sibling = tmp->sibling ;
            }
            tmp = cloned->next ;
        }
    }
    //把长链表拆分成两个链表，把奇数位置的节点使用nex连接起来，就是原始链表，偶数数值则是复制链表
    LinkNode* getLink(LinkNode* head) {
        LinkNode* tmp = head ;
        LinkNode* cloneHead = NULL ;
        LinkNode* cloneNode = NULL ;
        if(tmp != NULL) {
            cloneHead = cloneNode = tmp->next ;
            tmp->next = cloneNode->next ;
            tmp = tmp->next ;
        }
        while(tmp!=NULL) {
            //复制链表的连接
            cloneNode->next = tmp->next ;
            cloneNode = cloneNode->next ;
            //原始链表的连接
            tmp->next = cloneNode->next ;
            tmp = tmp->next ;
        }
        return cloneHead ;
    }
} ;

int main() {
    return 0;
}

