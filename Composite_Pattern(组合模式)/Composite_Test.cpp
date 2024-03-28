#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Component {
public:
    virtual ~Component() { }
    virtual std::string getName() = 0;
    virtual void add(std::shared_ptr<Component> component) { }
    virtual void remove(std::shared_ptr<Component> component) { }
    virtual void operation() = 0;
};

class Leaf : public Component {
public:
    Leaf(std::string name) : _name(name) { }

    std::string getName() override {
        return _name;
    }

    void operation() override {
        std::cout << "Leaf: " << _name << std::endl;
    }

private:
    std::string _name;
};

class Composite : public Component {
public:
    Composite(std::string name) : _name(name) { }

    std::string getName() override {
        return _name;
    }

    void add(std::shared_ptr<Component> component) override {
        _children.push_back(component);
    }

    void remove(std::shared_ptr<Component> component) override {
        _children.erase(std::remove(_children.begin(), _children.end(), component), _children.end());
    }

    void operation() override {
        std::cout << "Composite: " << _name << std::endl;
        for (auto&& component : _children) {
            component->operation();
        }
    }

private:
    std::string _name;
    std::vector<std::shared_ptr<Component>> _children;
};

int main() {
    std::shared_ptr<Component> root = std::make_shared<Composite>("root");

    std::shared_ptr<Component> branchA = std::make_shared<Composite>("branchA");
    branchA->add(std::make_shared<Leaf>("leafA1"));
    branchA->add(std::make_shared<Leaf>("leafA2"));

    std::shared_ptr<Component> branchB = std::make_shared<Composite>("branchB");
    branchB->add(std::make_shared<Leaf>("leafB1"));
    branchB->add(std::make_shared<Leaf>("leafB2"));

    root->add(branchA);
    root->add(branchB);

    root->operation();

    return 0;
}