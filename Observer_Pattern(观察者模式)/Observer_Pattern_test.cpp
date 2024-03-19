// https://zhuanlan.zhihu.com/p/119308881
// https://blog.csdn.net/yhc166188/article/details/81587442
#include <iostream>
#include <vector>
#include<algorithm>

/*
        模式定义：
            定义对象间 一对多（变化）的依赖关系，以便当一个对象的状态发生改变时，
            所有依赖他的对象都得到通知并且自动更新。
*/



// 观察者接口
class ObserverInterface {
public:
    virtual void dosomething() = 0;

    /*       析构函数需要 virtual（防止内存泄漏）
    C++中基类采用virtual虚析构函数是为了防止内存泄漏。
    具体地说，如果派生类中申请了内存空间，并在其析构函数中对这些内存空间进行释放。
    假设基类中采用的是非虚析构函数，当删除基类指针指向的派生类对象时就不会触发动态绑定，
    因而只会调用基类的析构函数，而不会调用派生类的析构函数。那么在这种情况下，
    派生类中申请的空间就得不到释放从而产生内存泄漏。所以，为了防止这种情况的发生，
    C++中基类的析构函数应采用virtual虚析构函数。
    */

    virtual ~ObserverInterface() {}
};

// 被观察者接口
class SubjectInterface {
public:
    virtual void Add(ObserverInterface *obr) = 0;
    virtual void Remove(ObserverInterface *obr) = 0;
    virtual void Notify() = 0;

    virtual ~SubjectInterface() {}
};

class Me : public SubjectInterface {
public:
    void Add(ObserverInterface *obr) override {
        observers.emplace_back(obr);
    }

    void Remove(ObserverInterface *obr) override {
        auto pos = std::find(observers.begin(), observers.end(), obr);
        if (pos != observers.end()) {
            observers.erase(pos);
        }
    }

    void Notify() override {
        for (const auto &obs : observers) {
            obs->dosomething();
        }
    }

private:
    std::vector<ObserverInterface *> observers;
};

class Wife : public ObserverInterface {
public:
    void dosomething() override {
        std::cout << "老公快回来了，开始做饭" << std::endl;
    }
};

class Son : public ObserverInterface {
public:
    void dosomething() override {
        std::cout << "爸爸快回来了，不能玩游戏了" << std::endl;
    }
};

int main(){
    Me me;
    ObserverInterface* wife = new Wife;
    ObserverInterface* son = new Son;
    me.Add(wife);
    me.Add(son);

    //下班了 发消息
    me.Notify();

    delete wife;
    delete son;
}

/*
    要点总结：
        Observer_mode 保持了复用性
        ➢使用面向对象的抽象，Observer模式使得我们可以独立地改变目标与观察者，从而使二者之间的依赖关系达致松耦合。

        ➢目标发送通知时，无需指定观察者,通知(可以携带通知信息作为参数)会自动传播。

        ➢观察者自己决定是否需要订阅通知，目标对象对此一无所知。

        ➢Observer模式是基于事件的UI框架中非常常用的设计模式，也是MVC模式的一个重要组成部分。
*/