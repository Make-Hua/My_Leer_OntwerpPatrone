#include <iostream>
#include <string>

// 老 Printer (Adaptee)
class LegacyPrinter {
public:
	void printInUppercase(const std::string& text) {
		std::cout << "Printing: " << text << std::endl;
	}
};

// 新 Computer (Client)
class ModernComputer {
public:
	void sendCommand(const std::string& command) {
		std::cout << "Sending command: " << command << std::endl;
	}
};

/*
    假设老类无法适配我们现有程序，则可以通过适配器解决，
    让无法适配的类完成衔接
*/

// Adapter class
class PrinterAdapter {
private:
	LegacyPrinter legacyPrinter;

public:
	void sendCommand(const std::string& command) {
		std::string uppercaseCommand = command;
		for (char& c : uppercaseCommand) {
			c = std::toupper(c);
		}
		legacyPrinter.printInUppercase(uppercaseCommand);
	}
};

int main()
{
	ModernComputer computer;
	PrinterAdapter adapter;

	computer.sendCommand("Print this in lowercase");
	adapter.sendCommand("Print this in lowercase (adapted)");

	return 0;
}

/*
	总结：
		➢Adapter模式主要应用于“希望复用-些现存的类，但是接口又与复用环境要求不
		一致的情况”， 在遗留代码复用、类库迁移等方面非常有用。

		➢GoF 23定义了两种Adapter模式的实现结构:对象适配器和类适配器。但类适配
		器采用“多继承”的实现方式，一般不推荐使用。对象适配器采用“对象组合”的方
		式，更符合松耦合精神。

		-Adapter模式可以实现的非常灵活，不必拘泥于Gof23中定义的两种结构。例如，
		完全可以将Adapter模式 中的“现存对象”作为新的接口方法参数，来达到适配的目的。
*/
