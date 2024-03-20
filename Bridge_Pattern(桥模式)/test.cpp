#include<iostream>
using namespace std;

class shape {

};

class RedCircle : public shape {

public:
    
};

class BuleCircle : public shape {

public:
    
};

class RedSquare : public shape {

public:
    
};

class BuleSquare : public shape {

public:
    
};

/*
    情景:
        此时如果想要加上第三个形状（目前有圆形和方形），
        则需要继续加上两个类（每种颜色一个）；
        此时如果还想要加上第三种颜色（目前有红色和蓝色），
        则需要继续加上3个类（每种类型一个）；

    解决方案：
        问题的根本原因是我们试图在两个独立的维度——形状与
        颜色——上扩展形状类。 这在处理类继承时是很常见的问题。
*/


int main() {
    return 0;
}