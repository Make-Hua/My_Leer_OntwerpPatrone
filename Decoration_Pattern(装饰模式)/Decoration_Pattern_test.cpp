#include <iostream>
using namespace std;

/* 
    模式定义：
        动态(组各)地给一个对象增加一些额外的职责。
        就增加功能而言，Decorator模式比生成子类(继承)更为灵活(消除重复代码&减少子类个数)。

        通过 组合 去 替代继承，从而减少子类个数，增加灵活性
*/

//业务操作
class Stream {

public:
    virtual void Read(int number) = 0;
    virtual void Seek(int position) = 0;
    virtual void Write(char data) = 0;

    virtual ~Stream() {}
};

//主体类
class FileStream : public Stream {
public:
    void Read(int number) override {
        //读文件流
        cout << "读文件流" << endl;
    }
    void Seek(int position) override {
        //定位文件流
    }
    void Write(char data) override {
        //写文件流
    }

};

class NetworkStream :public Stream {
public:
    void Read(int number) override {
        //读网络流
        cout << "读网络流" << endl;
    }
    void Seek(int position) override {
        //定位网络流
    }
    void Write(char data) override {
        //写网络流
    }

};

class MemoryStream :public Stream {
public:
    void Read(int number) override {
        //读内存流
    }
    void Seek(int position) override {
        //定位内存流
    }
    void Write(char data) override {
        //写内存流
    }

};

//扩展操作

class DecoratorStream : public Stream {
protected:
    Stream* stream;//...

    DecoratorStream(Stream* stm) : stream(stm) {}

};

class CryptoStream : public DecoratorStream {
public:
    CryptoStream(Stream* stm) : DecoratorStream(stm) {}

    void Read(int number) override {

        //额外的加密操作...
        stream->Read(number);//读文件流
    }
    void Seek(int position) override {
        //额外的加密操作...
        stream->Seek(position);//定位文件流
        //额外的加密操作...
    }
    void Write(char data) override {
        //额外的加密操作...
        stream->Write(data);//写文件流
        //额外的加密操作...
    }
};



class BufferedStream : public DecoratorStream {
public:
    BufferedStream(Stream* stm) :DecoratorStream(stm) {}
    //...
    void Read(int number) override {

        //额外的加密操作...
        stream->Read(number);//读文件流
    }
    void Seek(int position) override {
        //额外的加密操作...
        stream->Seek(position);//定位文件流
        //额外的加密操作...
    }
    void Write(char data) override {
        //额外的加密操作...
        stream->Write(data);//写文件流
        //额外的加密操作...
    }
};




int main() {

    //运行时装配
    FileStream* s1 = new FileStream();
    s1->Read(123);
    CryptoStream* s2 = new CryptoStream(s1);
    s2->Read(123);
    BufferedStream* s5 = new BufferedStream(s1);
    s5->Read(123);

    NetworkStream* s3 = new NetworkStream();
    s3->Read(456);
    BufferedStream* s4 = new BufferedStream(s3);
    s4->Read(456);


    return 0;

}

/*
    总结：
        要点总结

            ➢通过采用组合而非继承的手法，Decorator模式实现了在 >运行时< 动态扩展对象功能的能力，
              而且可以根据需要扩展多个功能。避免了使用继承带来的“灵活性差’'和“多子类衍生问题”。

            ➢Decorator类在接口.上表现为is-a Component的继承关系，即
              Decorator类继承了Component类所具有的接口。但在实现.
              上又表现为has-a Component的组合关系，即Decorator类又使用了另外一个Component类。

            ➢Decorator模式的目的并非解决“多子类衍生的多继承"问题,
              Decorator模式应用的要点在于解决“主体类在多个方向上的扩展功能”是为“装饰”的含义。
*/