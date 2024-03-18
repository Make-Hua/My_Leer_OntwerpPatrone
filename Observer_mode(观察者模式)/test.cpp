// https://zhuanlan.zhihu.com/p/119308881
#include <iostream>

class Son{
public:
    void DoSomething(){
        std::cout<<"爸爸回来了，赶紧去写作业"<<std::endl;
    }
};

class Wife{
public:
    void DoSomething(){
        std::cout<<"老公回来了，去做饭"<<std::endl;
    }
};

class Me{
public:
    void Gohome(){
        wife.DoSomething();
        son.DoSomething();
    }
private:
    Wife wife;
    Son son;
};

//     当观察者变多时，需要不断的修改我们类中的代码
//     在正常的工程中均会遇到类似的问题，且不断更新
//     不可能更新一次改一次代码，所以为了降低错误的
//     发生，我们需要降低耦合，而在该题的例子中，就
//     可以通过 Observer_mode 降低耦合
 
int main(){
    Me me;
    me.Gohome();
    return 0;
}