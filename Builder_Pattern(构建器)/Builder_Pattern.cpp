#include <string>
#include <iostream>

// 产品类 车
class Car {
 public:
    Car() {}
    void set_car_tire(std::string t) {
        tire_ = t;
        std::cout << "set tire: " << tire_ << std::endl;
    }
    void set_car_steering_wheel(std::string sw) {
        steering_wheel_ = sw;
        std::cout << "set steering wheel: " << steering_wheel_ << std::endl;
    }
    void set_car_engine(std::string e) {
        engine_ = e;
        std::cout << "set engine: " << engine_ << std::endl;
    }

 private:
    std::string tire_;            // 轮胎
    std::string steering_wheel_;  // 方向盘
    std::string engine_;          // 发动机

};

// 抽象建造者
class CarBuilder {
 public:
    Car getCar() {
        return car_;
    }

    // 抽象方法
    virtual void buildTire() = 0;
    virtual void buildSteeringWheel() = 0;
    virtual void buildEngine() = 0;

 protected:
    Car car_;
};

// 具体建造者 奔驰
class BenzBuilder : public CarBuilder {
 public:
    // 具体实现方法
    void buildTire() override {
        car_.set_car_tire("benz_tire");
    }
    void buildSteeringWheel() override {
        car_.set_car_steering_wheel("benz_steering_wheel");
    }
    void buildEngine() override {
        car_.set_car_engine("benz_engine");
    }
};

// 具体建造者 奥迪
class AudiBuilder : public CarBuilder {
 public:
    // 具体实现方法
    void buildTire() override {
        car_.set_car_tire("audi_tire");
    }
    void buildSteeringWheel() override {
        car_.set_car_steering_wheel("audi_steering_wheel");
    }
    void buildEngine() override {
        car_.set_car_engine("audi_engine");
    }
};

class Director {
 public:
    Director() : builder_(nullptr) {}

    void set_builder(CarBuilder *cb) {
        builder_ = cb;
    }

    // 组装汽车
    Car ConstructCar() {
        builder_->buildTire();
        builder_->buildSteeringWheel();
        builder_->buildEngine();
        return builder_->getCar();
    }

 private:
    CarBuilder* builder_;
};


int main() {
    // 抽象建造者(一般是动态确定的)
    CarBuilder* builder;
    // 指挥者
    Director* director = new Director();
    // 产品
    Car car;

    // 建造奔驰
    std::cout << "==========construct benz car==========" << std::endl;
    builder = new BenzBuilder();
    director->set_builder(builder);
    car = director->ConstructCar();
    delete builder;

    // 建造奥迪
    std::cout << "==========construct audi car==========" << std::endl;
    builder = new AudiBuilder();
    director->set_builder(builder);
    car = director->ConstructCar();
    delete builder;

    std::cout << "==========done==========" << std::endl;
    delete director;
    return 0;
}