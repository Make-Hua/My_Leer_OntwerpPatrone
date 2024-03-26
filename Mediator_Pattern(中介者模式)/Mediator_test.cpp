// MediatorModel.h文件
#pragma once
#include <string>
#include <iostream>

// 中介者类
class Mediator {
public:
    virtual void send(std::string  msg, Colleague * p) = 0;
};

class Colleague {
protected:
    Mediator *m_mediator;
public:
    Colleague(Mediator * p) {
        m_mediator = p;
    }
    virtual void send(std::string msg) = 0;
    virtual void notify(std::string msg) = 0;
};

class ConcreteColleague_0 : public Colleague {
public:
    ConcreteColleague_0(Mediator * p) : Colleague(p) {}
    void send(std::string msg) {
        m_mediator->send(msg, this);
    }
    void notify(std::string msg) {
        std::cout << "Colleague_0 收到了消息：" << msg << std::endl;
    }
};

class ConcreteColleague_1 : public Colleague {
public:
    ConcreteColleague_1(Mediator * p) : Colleague(p) {}
    void send(std::string msg) {
        m_mediator->send(msg, this);
    }
    void notify(std::string msg) {
        std::cout << "Colleague_1 收到了消息：" << msg << std::endl;
    }
};

class ConcreteMediator : public Mediator {
private:
    // 这里也可以是一个列表
    Colleague * m_p1;
    Colleague * m_p2;
public:
    void addColleague(Colleague * p1, Colleague * p2) {
        m_p1 = p1;
        m_p2 = p2;
    }
    void send(std::string msg, Colleague * p) {
        // 这里接受来自一个同事发过来的消息，具体应该给谁要根据需求来
        // 这里知识一个很简单的应用。比如该类总可以是有两个队列。
        // 一个队列是客户，一个队列是客服
        if (p == m_p1)
            m_p2->notify(msg);
        else
            m_p1->notify(msg);
    }
};

int main() {
    using namespace std;
    // 中介者模式
    ConcreteMediator *p = new ConcreteMediator();
    Colleague *pCol1 = new ConcreteColleague_0(p);
    Colleague *pCol2 = new ConcreteColleague_1(p);
    p->addColleague(pCol1, pCol2);
    p->send("你下班了吗？", pCol1);
    p->send("没呢，你呢？", pCol2);
    delete pCol1;
    delete pCol2;
    delete p;

    getchar();
    return 0;
}

/*
    总结:
        要点总结

            ➢将多个对象间复杂的关联关系解耦，Mediator模式将多个对象间的
            控制逻辑进行集中管理，变“多个对象互相关联”为“多个对象和一个中
            介者关联”，简化了系统的维护，抵御了可能的变化。

            ➢随着控制逻辑的复杂化，Mediator具体对 象的实现可能相当复杂。
            这时候可以对Mediator对象进行分解处理。

            ➢Facade模式是解耦系统间(单向)的对象关联关系; 
            Mediator模式是解耦系统内各个对象之间(双向)的关联关系。
*/