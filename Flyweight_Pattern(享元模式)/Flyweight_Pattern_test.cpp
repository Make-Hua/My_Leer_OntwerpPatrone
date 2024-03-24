#include <iostream>
#include <map>
#include <string>
using namespace std;

class Flyweight {
public:
    virtual void Operation(int extrinsicstate) = 0;
    virtual ~Flyweight() {}
};

class ConcreteFlyweight : public Flyweight {
public:
    void Operation(int extrinsicstate) override {
        cout << "ConcreteFlyweight: " << extrinsicstate << endl;
    }
};

class UnsharedConcreteFlyweight : public Flyweight { // 不强制共享对象，但也可以共享
public:
    void Operation(int extrinsicstate) override {
        cout << "UnsharedConcreteFlyweight: " << extrinsicstate << endl;
    }
};

class FlyweightFactory {
private:
    map<string, Flyweight*> flyweights;
public:
    Flyweight* GetFlyweight(string key) {
        if (flyweights[key] == NULL) flyweights[key] = new ConcreteFlyweight();
        return (Flyweight*)flyweights[key];
    }
};

int main() {
    int extrinsicstate = 22;   // 外部状态

    FlyweightFactory* f = new FlyweightFactory();
    Flyweight* fx = f->GetFlyweight("X");   // X、Y、Z为内部状态
    fx->Operation(--extrinsicstate);    // ConcreteFlyweight: 21

    Flyweight* fy = f->GetFlyweight("Y");
    fy->Operation(--extrinsicstate);    // ConcreteFlyweight: 20

    Flyweight* fz = f->GetFlyweight("Z"); // ConcreteFlyweight: 19
    fz->Operation(--extrinsicstate);    

    UnsharedConcreteFlyweight* uf = new UnsharedConcreteFlyweight();
    uf->Operation(--extrinsicstate);    // UnsharedConcreteFlyweight: 18

    delete fx;
    delete fy;
    delete fz;
    delete f;
    delete uf;

    return 0;
}