#pragma once
#include <vector>
#include <iostream>
#include <memory>
#define TYPE template <typename keyType, typename valType>
#define CLASS Node<keyType, valType>
#define SKIPCLASS skipList<keyType, valType> 

using namespace std ;


TYPE
class Node {
public :
    Node() {}
    ~Node() {} 
private :
    keyType key ;
    valType value ;
    //后继指针数组
    vector<shared_ptr<CLASS>>next ;
};

TYPE
class skipList {
public:
    skipList():maxL(1), level(1) {}
    ~skipList() {}
    shared_ptr<SKIPCLASS> createSkipList() ;
    void createNode(int level, keyType key, valType val) ;
    bool insert(shared_ptr<SKIPCLASS>sl, keyType key, valType val) ;
    valType search(shared_ptr<SKIPCLASS>sl, keyType key) ;
    bool erase(shared_ptr<SKIPCLASS>sl, keyType key) ;
    int getLevel() ;
public :
    int level ; //层数
    shared_ptr<CLASS>  head ;
    //最大层数
    int maxL ;
};

//随机产生当前跳表的层数
TYPE 
int SKIPCLASS :: getLevel() {
    int level = 1 ;
    while(rand()%2) {
        level ++ ;
    }
    level = (maxL>level)?level:maxL ;
    return level ;
}

//创建一个新的跳表节点
TYPE 
void SKIPCLASS :: createNode(int level, keyType key, valType val) {
    //创建节点
    shared_ptr<CLASS> p = make_shared<CLASS>() ;
    //跳表的层空间
    p->next.reserve(level) ;
    //申请层数
    //设置键值
    p->key = key ;
    p->value = val ;
    return p ;
}

//创建跳表
TYPE
shared_ptr<SKIPCLASS> SKIPCLASS :: createSkipList() {
    //创建新的跳表
    shared_ptr<SKIPCLASS> sl = make_shared<SKIPCLASS>() ;
    //预设跳表层数为0
    sl->level = 0 ;
    //获取层数
    //创建跳表节点
    int level = getLevel() ;
    //设置高度
    sl->level = level ;
    shared_ptr<CLASS> h = createNode(level, 0, 0) ;
    sl -> head = h ;
    //将head的next数组清空
    for(int i=0; i<level; i++) {
        h->next[i] = nullptr ;
    }
    srand(time(0)) ;
}

//跳表的插入操作
TYPE
bool SKIPCLASS :: insert(shared_ptr<SKIPCLASS>sl, keyType key, valType val) {
    vector<shared_ptr<CLASS>>update ;
    update.reserve(maxL) ;
    shared_ptr<CLASS> q, p = sl->head ;
    int i=sl->level-1; 
    for(;i>=0;i--) {
        //q->next[i]不为空并且p->next[i]中的key小于插入的key
        while((q=p->next[i])&&q->key<key) {
            p=q ;
        }
        //记录遍历过的节点
        update[i] = p ;
    }
    //key等于插入的key，只修改相应的值
    if(q && q->key == key) {
        q->value = val ;
        return true ;
    }
    
    int level = getLevel() ;
    //产生的随机数比跳表的层数大，则在update中将新添加的层指向header
    if(level > sl->level) {
        //给update申请更大的空间
        for(int i=sl->level; i<level; i++) {
            update[i] = sl->head ;
        }   
        //设置跳表的层数为level
        sl->level = level ;
    }   
    //创建一个节点
    q = createNode(level, key, val) ;
    //新建一个待插入节点，一层层插入
    for(int i=level-1; i>=0; --i) {
        q->next[i] = update[i]->next[i] ;
        update[i]->next[i] = q ;
    }
    return true ;
}

//调表删除节点操作
TYPE 
bool SKIPCLASS :: erase(shared_ptr<SKIPCLASS> sl, keyType key) {
    vector<shared_ptr<CLASS>> update ;
    shared_ptr<CLASS>q = nullptr, p = sl->head ;
    update.reserve(maxL) ;
    int i = sl->level -1 ;
    for(; i>=0; --i) {
        while((q = p->next[i]) && q->key < key) {
            p = q ;
        }
        update[i] = p ;
    }
    //判断是否为待删除的键
    if(!q || (q&&q->key != key)) {
        return false ;
    }
    //逐层删除
    for(i=sl->level-1; i>=0; --i) {
        if(update[i]->next[i] == q) {
            update[i]->next[i] = q->next[i] ;
        }
        if(sl->head->next[i] == nullptr) {
            sl->level -- ;
        }
    }
    q = nullptr ;
    return true ;
}

//跳表的查找
TYPE
valType SKIPCLASS :: search(shared_ptr<SKIPCLASS>sl, keyType key) {
    shared_ptr<CLASS> q, p = sl->head ;
    q = nullptr ;
    int i = sl->level-1 ;   
    for(; i>=0; --i) {
        while((q = p->next[i]) && q->key < key) {
            p = q ;
        }

        if(p && (key == q->key)) {
            return &q->value  ;
        }
    }
    return nullptr ;
}
