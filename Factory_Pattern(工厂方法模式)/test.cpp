#include<iostream>

class Animal {
public:
    virtual void Attack() = 0;
};

class Tiger : public Animal {
public:
    virtual void Attack() {
        std::cout << "Tiger Attack!" << std::endl;
    }
};

class Cat : public Animal {
public:
    virtual void Attack() {
        std::cout << "Cat Attack!" << std::endl;
    }
};

void Attack(Animal* pAnimal) {
    pAnimal->Attack();
}

int main() {
    Animal* animal1 = new Tiger;
    Animal* animal2 = new Cat;
    Attack(animal1);
    Attack(animal2);
    delete animal1;
    delete animal2;
    return 0;
}