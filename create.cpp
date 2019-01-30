#include <iostream>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <malloc.h>
#include <queue>
#include <math.h>
#include <map>
using namespace std;
 
typedef struct Node
{
    char data;
    struct Node *left, *right;
}sn,*ssn;
queue<ssn> que;
int n;
ssn create_tree()
{
    int tn = n;
    char ch, ch1, ch2;  ///根节点字符，左右字符
    ssn t, p, q;    ///链表
    ch = getchar();
    if (ch != '0')
    {
        p = (ssn)malloc(sizeof(sn));
        p -> data = ch;
        que.push(p);
        tn--;
    }
    else
    return NULL; ///根就是0还扯啥
    while (!que.empty()) ///开始按成次建树
    {
        t = que.front();
        que.pop();
        if (tn == 0) break;
        getchar();
        ch1 = getchar(); 
        if (ch1 != '0')
        {
            q = (ssn)malloc(sizeof(sn));
            q -> data = ch1;
            t -> left = q;  ///也就是根的左子树是q
 
            que.push(q);
            tn--;
        }
        else t->left = NULL; ///否则跟的左子树空
        getchar();
        ch2 = getchar();
        if (ch2 != '0')
        {
            q = (ssn)malloc(sizeof(sn));
            q -> data = ch2;
            t -> right = q;
            que.push(q);
            tn--;
        }
        else t->right = NULL;
    }
    return p;
}
 
void query(ssn tt, int tn)
{
    ssn t, q;
    while(que.size())
    que.pop();
 
    que.push(tt);
    t = que.front();
    printf("%2c", t->data);
    tn--;
   while (!que.empty())
    {
        t = que.front();
        que.pop();
        if (tn == 0) break;
        if (t -> left)
        {
            q = (ssn)malloc(sizeof(sn));
            q = t -> left;
            printf("%2c", q->data);
            que.push(q);
            tn--;
        }
        else printf(" NULL");       ///有的题问你有多少叶子
        if (t -> right)
        {
            q = (ssn)malloc(sizeof(sn));
            q = t -> right;
            printf("%2c", q->data);
            que.push(q);
            tn--;
        }
        else printf(" NULL");   ///如果上边那个和这个都是NULL，那他们的父亲就是叶子呗
        ///最后计算总的叶子时候别忘了加上最后一层的不为NULL值的节点（为什么：因为是最后一层）
        ///判断是否是最后一层就在“tn--；”的上边判断tn是不是1就行了
    }
}
 
int main()
{
    ssn t;
    while (scanf("%d", &n) == 1)
    {
        getchar();
        t = create_tree();
        query(t, n);
    }
    return 0;
}

