#include<iostream>
using namespace std;

/*
    定义：
        桥接模式通过将继承改为组合的方式来解决这个问题。
        具体来说， 就是抽取其中一个维度并使之成为独立的类层次，
        这样就可以在初始类中引用这个新层次的对象，
        从而使得一个类不必拥有所有的状态和行为。

    核心：
        类似装饰模式，通过组合的多态特性，从而减低耦合，
        减少类数目。
*/
class Color {  // 颜色基类
public:
    virtual void getcolor() = 0;
    virtual ~Color() {}
};

class Shape {  // 形状类
protected:
    Color* color;
public:
    virtual void area() = 0;
    virtual void girth() = 0;
    virtual ~Shape() {}
    Shape(Color* Obj) : color(Obj) {}
};



class Circle : public Shape {
public:
    Circle(Color* Obj) : Shape(Obj) {}

    void area() override {
        color->getcolor();
        cout << "调用Circle-area" << '\n';
    }
    void girth() override {
        color->getcolor();
        cout << "调用Circle-girth" << '\n';
    }
};

class Square : public Shape {
public:
    Square(Color* Obj) : Shape(Obj) {}

    void area() override {
        color->getcolor();
        cout << "调用Square-area" << '\n';
    }
    void girth() override {
        color->getcolor();
        cout << "调用Square-girth" << '\n';
    }
};


class Red : public Color {
public:
    void getcolor() override {
        cout << "调用Red-gercolor" << '\n';
    }
};


class Bule : public Color {
public:
    void getcolor() override {
        cout << "调用Bule-gercolor" << '\n';
    }
};

int main() {
    Color* obj1 = new Red();
    Shape* obj2 = new Circle(obj1); // obj2 : 红色的圆形
    obj2->area();

    delete obj1; delete obj2;
    cout << "---------------------------------------" << '\n';

    obj1 = new Bule();
    obj2 = new Square(obj1);
    obj2->area();
    return 0;
}

/*
    总结：
        ➢Bridge模式使用“对象间的组合关系”>关键点是Color* color;<
        解耦了抽象和实现之间固有的绑定关系，
        使得抽象和实现可以沿着各自的维度来变化。
        所谓抽象和实现沿着各自纬度的变化，即"子类化"它们。

        ➢Bridge模式有时候类似于多继承方案，
        但是多继承方案往往违背单一职责原则(即一个类只有一个变化的原因)，
        复用性比较差。Bridge模式是比多继承方案更好的解决方法。

        ➢Bridge模式的应用一般在"两个非常强的变化维度”，
        有时一个类也有多于两个的变化维度，这时可以使用Bridge的扩展模式。
*/