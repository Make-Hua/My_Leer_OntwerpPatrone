#include<iostream>
#include<string>

using namespace std;

// 猴子
class Monkey {
public:
    Monkey(){}
    virtual ~Monkey(){}
    virtual Monkey* Clone() = 0;  // 克隆
    virtual void Play() = 0;  // 玩耍
};

class SunWuKong : public Monkey {
public:
    SunWuKong(string name) {
        m_strName = name;
    }
    ~SunWuKong(){}

    // 拷贝构造函数
    SunWuKong(const SunWuKong &other) {
        m_strName = other.m_strName;
    }
    Monkey* Clone() override {
        // 调用拷贝构造函数
        return new SunWuKong(*this);
    }
    void Play() override {
        cout << m_strName << " play Golden-Hoop-Stick" << endl;
    }

private:
    string m_strName;
};



int main() {
    // 孙悟空
    Monkey *pSWK = new SunWuKong("Qi Tian Da Sheng");

    // 克隆猴子猴孙
    Monkey *pSWK1 = pSWK -> Clone();
    Monkey *pSWK2 = pSWK1 -> Clone();

    pSWK1 -> Play();
    pSWK2 -> Play();

    delete pSWK; delete pSWK2; delete pSWK1; 

    return 0;
}

/*

    要点总结：
        ➢Prototype模式同样用于隔离类对象的使用者和
        具体类型(易变类)之间的耦合关系，它同样要求这些
        “易变类"拥有“稳定的接口”。

        ➢Prototype模式对于“如何创建易变类的实体对象
        '采用“原型克隆’的方法来做，它使得我们可以非常
        灵活地动态创建拥有某些稳定接口”的新对象一一所 
        需工作仅仅是注册一个新类的对象(即原型)，
        然后在任何需要的地方Clone。

        ➢Prototype模式中的Clone方法可以利用某些框架
        中的序列化来实现深拷贝。

*/