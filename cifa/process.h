#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <memory>
#include "key.h"
using namespace std ;

//c语言的关键字
namespace keys {
vector<string>key{"auto","break","case","char","const","continue","default","do","double",
    "else","enum","extern","float","for","goto","if","int","long","register",
    "return","short","signed","sizeof","static","struct","switch","typedef",
    "union","unsigned","void","volatile","while"
};
}

class bianLiang ;
class errorNode ;
class zuJian ;
class process ;
class tipNode ;

class process {
public:
    process():index(0) {}
    ~process() {}
    void start(string info) ;
private:    
    int index ;
    vector<shared_ptr<zuJian>>zjList ;
    vector<shared_ptr<errorNode>>errList ;
    vector<shared_ptr<tipNode>>tpList;
};

class zuJian {
public :
    zuJian() {
    }
    ~zuJian() {
    }
public :
    //left little 左小括号
    static int ll ;
    //右小括号
    static int rl;
    //左中括号
    //left middle 
    static int lm ;
    static int rm ;
    //做大括号
    //left big
    static int lb ;
    static int rb ;       
} ;


class bianLiang {
public :
    bianLiang() :content(""), desc(""), type(0), line(0){}
    ~bianLiang() {}
public :
    string content ;
    string desc ;
    int type ;
    int line ;
} ;

class errorNode {
public :
    errorNode():content(""), desc(""), type(0), line(0) {}
    ~errorNode() {}
public :
    //错误内容
    string content ;
    //错误描述
    string desc ;
    //种类
    int type ;
    //行号
    int line ;
} ;

//标识符节点
class tipNode { 
public :
    tipNode() :content(""), desc(""), type(0), line(0){}
    ~tipNode() {
    }
public :
    string content ;
    string desc ;
    int type ;
    int line ;
};

//left little 左小括号
int zuJian :: ll = 0 ;
int zuJian :: rl = 0 ;
int zuJian :: lm = 0 ;
int zuJian :: rm = 0 ;
int zuJian :: lb = 0 ;
int zuJian :: rb = 0 ;

void process :: start(string info) {
    long len = info.size() ;
    //单词
    string word ;
    while(index < len) {
        char ch = info[index] ;
        //字母，下划线开头
        if((ch >= 'A'&& ch<='Z')||(ch>='a'&&ch<='z')||ch=='_') {
            
            word += ch ;
            index ++ ;
        }
        
    }
}
