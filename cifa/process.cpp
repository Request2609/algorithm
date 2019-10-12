#include "process.h"
using namespace std ;

int main() {
    string file ;   
    cin >> file ;
    int fd = open(file.data(), O_RDWR) ;
    if(fd < 0) {
        cout << __FILE__ << "     " << __LINE__ << endl ;
        cout << "文件可能不存在!" << endl;
        return -1 ;
    }
    struct stat st ;
    int ret = fstat(fd, &st) ; 
    int size = st.st_size ;
    char* p = (char*)mmap(NULL, size, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0) ;  
    if(p == NULL) {
        cout << __LINE__ << "       " << __FILE__ << endl ;
        return -1 ;
    }
    close(fd) ;
    //读取到要分析程序中的所有内容
    string tmp = p ;
    ret = munmap(p, size) ;
    if(ret < 0) {
        cout << __LINE__ << "     " << __FILE__ << endl ;
        return -1 ;
    }  
   cout << "分析结束" << endl ;
}
