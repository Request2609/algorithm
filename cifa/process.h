#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <memory>
#include <algorithm>
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
using namespace keys ;
class bianLiang ;
class errorNode ;
class zuJian ;
class process ;
class tipNode ;
class fuHao ;
class changLiang ;

class process {
public:
    process():index(0) {}
    ~process() {}
    //开始解析
    int isNum(char c) { return c >='0'&& c<='9' ; }
    void start(string info) ;
    //获取变量名称
    void getBianLiang(string info) ;
    void getKey(string info) ;
    //获取数字
    void getNum(string info) ;
    //获取其他
    void getOther(string info) ;
    //或缺各种对象的只能指针
    shared_ptr<fuHao> getFuHao(string con, int line) ;
    shared_ptr<errorNode> getErr(string con, int line) ;
    shared_ptr<zuJian> getZujian(string con, int line) ;
    shared_ptr<tipNode>getTipNode(string con, int line) ;
    shared_ptr<changLiang>getNum(string con, int line) ;
private:    
    int index ;
    //括号之类的
    vector<shared_ptr<zuJian>>zjList ;
    //错误列表
    vector<shared_ptr<errorNode>>errList ;
    //标识符号
    vector<shared_ptr<tipNode>>tpList;
    //运算符号
    vector<shared_ptr<fuHao>> fhList ;
    //数字列表
    vector<shared_ptr<changLiang>> cList ;
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

class changLiang {
public :
    changLiang() {}
    ~changLiang() {}
public :
    string content ;
    string desc ;
    int line ;
    int type ;
} ;

class fuHao {
public :
    fuHao():content(""), desc(""), line(0) {}
    ~fuHao() {
    }
public :
    string content ;
    string desc ;
    int line ;
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
    //单
    //以字母下划线开头，处理关键字或者表示符
    while(index < len) {
        char ch = info[index] ; 
        if((ch >= 'A'&& ch<='Z')||(ch>='a'&&ch<='z')||ch=='_') {
            //数字开头
            getBianLiang(info) ;
            ch = info[index] ;
        }
        else if(ch >= '0' && ch <= '9') {   
            getNum(info) ;      
        }
    }
}

//获取数字
void process :: getNum(string info) {
    char ch = info[index] ;
    string num = "";
    int flag = 0 ;
    while((ch >= '0' && ch <= '9') || ch == '.') {
        //判断是否为数组
        if(ch == '.' && isNum(num[index+1])&& flag == 0) {
            flag = 0 ;
        }
        num += ch ;
        ch = info[++index] ;
    }
    //要是解析出来最后不是空格
    if(ch == 'E' || ch == 'e') {
        num += ch ;
        ch = info[++index] ;
    }
    if(ch == '+' || ch == '-') {
        num+=ch ;
        ch = info[++index] ;
    }
    while((ch >= '0' && ch <= '9')) {
        num += ch ;
        ch = info[++index] ;
    }
}


void process :: getKey(string info) {
    char ch = info[index] ;
    //字母，下划线开头
    string word = "";
    //判断只要是字母下划线,就往关键字信息里面放
    while((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0'&& ch <= '9')||ch == '_') {
        word += ch ;
        ch = info[++index] ;
    }
    //判断是关键字还是其他标识符号
    auto res = find(keys::key.begin(), keys::key.end(), word) ;
    //找到了相应的关键字，则创建智能指针对象
    if(res != keys::key.end()) {
        shared_ptr<tipNode> tp = make_shared<tipNode>() ;
        tp->content = word ;
        tp->desc = KEY_DESC ;
        tp->line = __LINE__ ;
        tpList.push_back(tp) ;
    }
    else {
        //一个标识符接收完成
        shared_ptr<bianLiang>tmp = make_shared<bianLiang>(make_shared<bianLiang>()) ;
        //设置标志
        tmp->desc = IDENTIFER_DESC ;
        tmp -> line = __LINE__ ;
        tmp->content = word ;
        cL.push_back(tmp) ;
    }
}

void process :: getOther(string info) {
    char ch = info[index] ;
    string other = "";
    int len = info.size() ;
    //以/开
    if(ch == '/') {
        int flag = 0 ;
        //判断是 /= 除法符号
        if(info[index+1] == '=') {
            flag = 1 ;
            other += ch ;
            ch = info[++index] ;
            other += ch ;
            shared_ptr<fuHao>fh = make_shared<fuHao>() ;
            fh->content = other ;
            fh->line = __LINE__ ;
            fh->desc = to_string(COMPLETE_MOD) ;
            ch = info[++index] ;
            fhList.push_back(fh) ;
            other.clear() ;
        } 
        //注释符号
        else if(flag != 1 && ch == '*') {
            int t = index ;
            char c = ch ;
            while(1) {      
                if(c != '*') {
                    t++ ;
                    c = info[t] ;
                }
                if(t == len) {
                    
                }
            }
            shared_ptr<errorNode>er = make_shared<errorNode>() ;
            er->content += "*" ;
            er->line = __LINE__  ;
            er->desc = CHAR_ERROR ;
            errList.push_back(er) ;
            ch = info[++index] ;
        }
    }
}


shared_ptr<fuHao> process :: getFuHao(string con, int line) {
    shared_ptr<fuHao> fh = make_shared<fuHao>() ;
    fh->content = con ;
    fh->desc = OPE_DESC ;
    fh->line = line ;
    return fh ;
}

shared_ptr<errorNode> process :: getErr(string con, int line) {
    shared_ptr<errorNode> en = make_shared<errorNode>() ;
    en->content = con ;
    en->desc = CHAR_ERROR ;
    en->line = line ;
    return en ;
}

shared_ptr<zuJian> process :: getZujian(string con, int line) {
    shared_ptr<zuJian> en = make_shared<zuJian>() ;
    return en ;
}

shared_ptr<tipNode> process :: getTipNode(string con, int line) {
    shared_ptr<tipNode> en = make_shared<tipNode>() ;
    en->content = con ;
    en->desc = IDENTIFER_DESC ;
    en->line = line ;
    return en ;
}

shared_ptr<changLiang> process :: getNum(string con, int line) {
    shared_ptr<changLiang> en = make_shared<changLiang>() ;
    en->content = con ;
    en->desc = CONSTANT_DESC ;
    en->line = line ;
    if(con[0] >= '0' && con[0] <= '9') {
        en->type = STRING_VAL ;
    }
    else 
        en->type = INT_VAL ;
    return en ;
}

