#include <iostream>
using namespace std;

/*
    类似问题解决方案：
        工厂方法模式建议使用特殊的工厂方法代替对于
        对象构造函数的直接调用 （即使用 new运算符）。 
        不用担心， 对象仍将通过 new运算符创建， 
        只是该运算符改在工厂方法中调用罢了。 
        工厂方法返回的对象通常被称作 “产品”。
*/

class Animal {
public:
    virtual void Attack() = 0;
};

class Tiger : public Animal {
public:
    void Attack() override {
        std::cout << "Tiger Attack!" << std::endl;
    }
};

class Cat : public Animal {
public:
    void Attack() override {
        std::cout << "Cat Attack!" << std::endl;
    }
};

class AnimalFactory {
public:
    virtual Animal* CreateAnimal() = 0;
    virtual ~AnimalFactory();
};

class CatFactory : public AnimalFactory {
public:
    Animal* CreateAnimal() override {
        return new Cat;
    }
};

class TigerFactory : public AnimalFactory {
public:
    Animal* CreateAnimal() override {
        return new Tiger;
    }
};

int main() {
    AnimalFactory* animalFac1 = new TigerFactory();
    AnimalFactory* animalFac2 = new TigerFactory();
    Animal* Obj1 = animalFac1->CreateAnimal();
    Animal* Obj2 = animalFac2->CreateAnimal();
    Obj1->Attack();
    Obj2->Attack();
    delete Obj1;
    delete Obj2;
    delete animalFac1;
    delete animalFac2;

    return 0;
}

/*
    总结：
        ➢FactoryMethod模式用于隔离类对象的使用者和具体类型之间的耦合关系。
        面对一个经常变化的具体类型，紧耦合关系(new)会导致软件的脆弱。

        ➢FactoryMethod模式通过面向对象的手法，
        将所要创建的具体对象工作延迟到子类，
        从而实现一种 >扩展< (而非更改)的策略，较好地解决了这种紧耦合关系。

        ➢Factory Method模式解决“单个对象”的需求变化。
        缺点在于要求 创建方法/参数 相同。
*/