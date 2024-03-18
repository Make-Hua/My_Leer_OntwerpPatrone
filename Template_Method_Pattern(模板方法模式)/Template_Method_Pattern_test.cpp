/*  引用
    https://blog.csdn.net/janeqi1987/article/details/104014906

*/
#include <iostream>
 
class Resume
{
protected:
    virtual void SetPersonalInfo() {}
    virtual void SetEducation() {}
    virtual void SetWorkExp() {}
public:
    void FillResume() {
        SetPersonalInfo();
        SetEducation();
        SetWorkExp();
    }
};
 
class ResumeA: public Resume
{
protected:
    void SetPersonalInfo() {
        std::cout << "A's PersonalInfo" << std::endl;
    }
    void SetEducation() {
        std::cout << "A's Education" << std::endl;
    }
    void SetWorkExp() {
        std::cout << "A's Work Experience" << std::endl;
    }
};
 
class ResumeB: public Resume
{
protected:
    void SetPersonalInfo() {
        std::cout << "B's PersonalInfo" << std::endl;
    }
    void SetEducation() {
        std::cout << "B's Education" << std::endl;
    }
    void SetWorkExp() {
        std::cout << "B's Work Experience" << std::endl;
    }
};
 
int main() {
    Resume* r1 = new ResumeA();
    Resume* r2 = new ResumeB();

    r1 -> FillResume();
    std::cout << "----------------------" << std::endl;
    r2 -> FillResume();
    return 0;
}

/*
    总结：
        具有良好的扩展性，封装不变部分，扩展可变部分，
        把认为是不变部分的算法封装到父类实现，而可变部分的则可以通过继承来继续扩展。
        例如增加一个新的功能很简单，只要再增加一个子类，实现父类的基本方法就可以了。
        提取公共部分代码，便于维护，减小维护升级成本，基本操作由父类定义，子类实现
        基本方法是由子类实现的，
        因此子类可以通过扩展的方式增加相应的功能，符合开闭原则
*/