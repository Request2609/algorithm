/*
给定一个二叉树，判断其是否是一个有效的二叉搜索树。

假设一个二叉搜索树具有如下特征：

    节点的左子树只包含小于当前节点的数。
    节点的右子树只包含大于当前节点的数。
    所有左子树和右子树自身必须也是二叉搜索树。

示例 1:

输入:
    2
   / \
  1   3
输出: true

示例 2:

输入:
    5
   / \
  1   4
     / \
    3   6
输出: false
解释: 输入为: [5,1,4,null,null,3,6]。
     根节点的值为 5 ，但是其右子节点值为 4 。


*/
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<queue>
#include<memory>
using namespace std;

class Tree{
public:
    int val ;
    Tree*l,*r;
    Tree(){

    }
    ~Tree(){}
    static Tree* create();
    void print(Tree*root);
};

void Tree::print(Tree*root){
    
    queue<Tree*>q ;
    q.push(root);
    while(!q.empty()){

        Tree* t = q.front();
        cout<<t->val<<"  ";
        if(t->l!=NULL){
            q.push(t->l);
        }
        if(t->r!=NULL){
            q.push(t->r);
        }
        q.pop();
    }
    cout<<endl;
}

Tree* Tree::create(){
    
    Tree*h =new Tree();
    cin>>h->val ;
    queue<Tree*>q ;
    q.push(h);
    while(!q.empty()){
        
        Tree*t = q.front();
        int a ;
        cin>>a;
        if(a==-1){
            t->l =NULL;
        }
        else{
            Tree * tt = new Tree();
            tt->val=a;
            t->l = tt;
            q.push(tt);
        }
        cin>>a ;
        if(a==-1){
            t->r = NULL;
        }
        else{
            Tree* tt = new Tree();
            tt->val = a;
            t->r = tt;
            q.push(tt);
        }
        q.pop();
    }

    return h ;
}

class Solution {
public:
    bool isValidBST(Tree* root) {
        bool flag = true;
        helper(root, NULL, NULL, flag);
        return flag;
    }

    void helper(Tree* root, Tree* min, Tree* max, bool& flag)
    {
        if (root == NULL)
            return;
        //将不满足的条件全部列出,即左子树即不为空,且其值大于根节点或者右子树不为空其值小于根节点
        if ((min != NULL && root->val <= min->val) || (max != NULL && root->val >= max->val))
        {
            flag = false;
            return;
        }

        helper(root->l, min, root, flag);
        helper(root->r, root, max, flag);
    }
};

int main(){
    Tree* tt =Tree::create();
    tt->print(tt);
    Solution ss ;
    cout<<ss.isValidBST(tt);
}

