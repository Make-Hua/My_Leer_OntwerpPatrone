#include <bits/stdc++.h>

using namespace std;

class Image {
public:
	virtual void display() = 0;
};

class RealImage : public Image {
private:
	std::string filename;

public:
	RealImage(const std::string& filename) : filename(filename) {
		// Simulate loading the image (this can be a resource-intensive operation)
		std::cout << "Loading image: " << filename << std::endl;
	}

	void display() override {
		std::cout << "Displaying image: " << filename << std::endl;
	}
};

class ImageProxy : public Image {
private:
	RealImage* realImage; // Reference to the Real Object
	std::string filename;

public:
	ImageProxy(const std::string& filename) : filename(filename), realImage(nullptr) {}

	void display() override {
		// The Proxy checks if the Real Object is created and loads it if necessary
		if (realImage == nullptr) {
			realImage = new RealImage(filename);
		}
		realImage->display();
	}
};

int main() {
	// Create a proxy to an image
	Image* image = new ImageProxy("example.jpg");

	// Display the image (the Proxy will load the Real Object if necessary)
	image->display();

	// Displaying the image again (the Proxy won't reload it)
	image->display();

	delete image; // Clean up

	return 0;
}

/*
    代理模式在各种场景中特别有用：

延迟加载：当您有一个仅在需要时才加载的资源密集型对象时，
代理可以处理其创建。例如，按需加载大图像或数据库连接。
访问控制：代理可以通过添加身份验证和授权检查来控制对真实主体的访问。
这对于保护敏感资源特别有用。
缓存：代理可以缓存昂贵操作的结果，从而减少重复调用真实主体的需要。
记录和监控：代理可用于记录或监控对真实主体执行的操作，而无需修改
其代码。
*/

/*
    要点总结

➢“增加一层间接层”是软件系统中对许多复杂问题的一种常见解决方法。
在面向对象系统中，直接使用某些对象会带来很多问题，作为间接层的
proxy对象便是解决这一问题的常用手段。

➢具体proxy设计模式的实现方法、实现粒度都相差很大，有些可能对
单个对象做细粒度的控制，如copy-on-write技术， 有些可能对组件
模块提供抽象代理层,在架构层次对对象做proxy。

➢Proxy并不一定要求保持接口完整的一致性，只要能够实现间接控制，
有时候损及- -些透明性是可以接受的。
*/

