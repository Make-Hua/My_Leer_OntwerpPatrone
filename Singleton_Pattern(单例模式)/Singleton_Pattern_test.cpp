// https://light-city.github.io/design_pattern/singleton/singleton/

#include<iostream>
#include<thread>
#include<mutex>

using namespace std;

class singleton {
private:
    //  防止其他类外 new 该类对象
    singleton() {}
    static singleton *p;
public:
    static singleton* instance();
};

singleton *singleton::p = nullptr;


// 该方法单线程安全  // 懒汉单例（第一次用到采取实例化）
singleton* singleton::instance() {
    if (p == nullptr)
        p = new singleton();
    return p;
}

/*

// 饿汉单例（定义了就直接初始化）
// 饿汉单例是线程安全的

class singleton {
private:
    singleton() {}
    static singleton *p;
public:
    static singleton *instance();
};

singleton *singleton::p = new singleton();
singleton* singleton::instance() {
    return p;
}
*/


/*
    该写法实现了 懒汉单例模式的线程安全
    但是由于每一次调用 instance() 函数
    都需要使用 Lock，但是我们只需要new
    一次，这会导致性能问题
*/
class singleton1 {
private:
    singleton1() {}
    static singleton1 *p1;
    static mutex lock_;
public:
    static singleton1 *instance();
};

singleton1 *singleton1::p1 = nullptr;

singleton1* singleton1::instance() {
    lock_guard<mutex> guard(lock_);
    if (p1 == nullptr)
        p1 = new singleton1();
    return p1;
}

/*
// 所以提出了 double check Lock 模式
singleton* singleton::instance() {
    if(p == nullptr) {  // 第一次检查
        Lock lock;
        if(p == nullptr){ // 第二次检查
            p = new singleton;
        }
    }
    return p;
}

// 但是该模式内存读写时存在问题
  > p = new singleton; <
这条语句会导致三个事情的发生：

1 分配能够存储singleton对象的内存；
2 在被分配的内存中构造一个singleton对象；
3 让p指向这块被分配的内存。
可能会认为这三个步骤是按顺序执行的，
但实际上只能确定步骤1是最先执行的，
步骤2，3却不一定。问题就出现在这。
（
因为编译器会进行代码优化，当中有reoder优化
该优化会现执行步骤3，在执行步骤2，这就导致
在多线程模式下存在：
    某一个线程读取对象时，该对象仅分配了内存
    并没有构造具体对象
）
*/


// Scott Meyer在《Effective C++》中提出了一种简洁的singleton写法

/*
singleton *singleton::instance() {
    static singleton p;
    return &p;
}


注：
    上述方法
    单线程下正确；  
    c++11以及之后的版本正确；
    c++11 之前版本，不一定正确；

    不正确的具体原因：
        原因在于在C++11之前的标准中并没有规定local static变量的内存模型。
        于是乎它就是不是线程安全的了。但是在C++11却是线程安全的，
        这是因为新的C++标准规定了当一个线程正在初始化一个变量的时候，
        其他线程必须得等到该初始化完成以后才能访问它。


*/
int main() {
    /*
        Test
    */
    return 0;
}