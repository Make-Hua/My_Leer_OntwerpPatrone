#include <iostream>

// Subsystem 1
class Engine {
public:
	void Start() {
		std::cout << "Engine started" << std::endl;
	}

	void Stop() {
		std::cout << "Engine stopped" << std::endl;
	}
};

// Subsystem 2
class Lights {
public:
	void TurnOn() { std::cout << "Lights on" << std::endl; }

	void TurnOff() {
		std::cout << "Lights off" << std::endl;
	}
};

// Facade
class Car {
private:
	Engine engine;
	Lights lights;

public:
	void StartCar() {
		engine.Start();
		lights.TurnOn();
		std::cout << "Car is ready to drive" << std::endl;
	}

	void StopCar() {
		lights.TurnOff();
		engine.Stop();
		std::cout << "Car has stopped" << std::endl;
	}
};

/*
    我们有两个子系统，Engine和Lights，每个子系统都有自己的方法。
Car 类充当门面。它封装了与子系统的交互并向客户端提供简化的接口。
Car 类的StartCar和StopCar方法协调与子系统的交互以启动和停止汽车。
客户不需要知道引擎或灯光如何工作的细节，他们只需调用汽车外观上的方法即可。
*/

int main() {
	Car car;
	car.StartCar();
	car.StopCar();
	return 0;
}

/* 
    优点:
        简化的接口：客户只需要了解外观的方法，不需要了解底层子系统的复杂性。
        降低复杂性：该模式隐藏了子系统的复杂性，使系统更易于理解和管理。
        松耦合：客户端与子系统解耦，这允许更灵活和模块化的软件设计。
        易于维护：对子系统的更改可以在外观内隔离，从而最大限度地减少对客户端代码的影响。
        改进的测试：由于客户端与单个界面而不是多个子系统交互，因此测试变得更加容易。

*/

/*
    要点总结

➢从客户程序的角度来看，Fagade模式简化了整个组件系统的接口,
对于组件内部与外部客户程序来说，达到了一种“解耦”的效果一内部
子系统的任何变化不会影响到Fagade接口的变化。

➢Facade设计模式更注重从架构的层次去看整个系统，而不是单个类的层次。
Fagade很多时候更是一种架构设计模 式。

➢Fagade设计模式并非一个集装箱，可以任意地放进任何多个对象。
F agade模式中组件的内部应该是“相互耦合关系比较大的一系列组件”，
而不是一个简单的功能集合。
*/
