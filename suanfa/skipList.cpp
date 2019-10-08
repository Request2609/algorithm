#include "skipList.h"

int main() {
    shared_ptr<skipList<int, int>> sl = make_shared<skipList<int, int>>() ;
    //创建skiplist
    sl = sl->createSkipList() ;
    sl->insert(sl, 1, 1) ;
    sl->insert(sl, 2, 3) ;
    sl->insert(sl, 5, 3) ;
    sl->insert(sl, 7, 3) ;
    sl->insert(sl, 9, 3) ;
    sl->insert(sl, 10, 3) ;
    cout << "获取键为1的值:"<< *sl->search(sl, 1) << endl ;
    cout << "获取键为2的值:" << *sl->search(sl, 2) << endl ;
    cout << "删除键为：1" << "         删除结果"<< sl->erase(sl, 1)  << endl ;
    cout << "找键为1的值-------->" << endl ;
    if(sl->search(sl, 1) == nullptr) {
        cout << "没找到节点" << endl ;
        return 1 ;
    } else 
    cout << "找到了节点！" << endl ;

}
