// 示例代码 ： https://blog.csdn.net/janeqi1987/article/details/104027525

#include <iostream>
 
class Context;
 
//state
class LiftState {
protected:
    Context* context;
public:
    virtual ~LiftState() = default;
    void setContext(Context* context) {
        this->context = context;
    }
    //开电梯门
    virtual void open() = 0;
    //关电梯门
    virtual void close() = 0;
    //电梯运行
    virtual void run() = 0;
    //电梯停止
    virtual void stop() = 0;
};
 
//context
class Context {
public:
    static LiftState* openningState;
    static LiftState* closingState;
    static LiftState* runningState;
    static LiftState* stoppingState;
 
    LiftState& getLiftState() {
        return *liftState;
    }
 
    void setLiftState(LiftState* liftState) {
        this->liftState = liftState;
        //把当前的环境通知到各个实现类中
        this->liftState->setContext(this);
    }
 
    void open() { liftState->open(); }
    void close() { liftState->close(); }
    void run() { liftState->run(); }
    void stop() { liftState->stop(); }
 
private:
    LiftState* liftState;
};
 
//ConcreteState
class OpenningState : public LiftState
{
public:
    //打开电梯门
    void open()
    {
        std::cout << "门开启电梯..." << std::endl;
    }
 
    //开门状态下，可以按下“关门”按钮
    void close()
    {
        //将当前状态修改为关门状态
        context->setLiftState(Context::closingState);
        //关门
        context->getLiftState().close();
    }
 
    //开门状态下不能运行！
    void run()
    {
        //do nothing;
    }
 
    //开门状态下，按停止没效果
    void stop()
    {
        //do nothing
    }
};
 
//关门状态
class ClosingState : public LiftState
{
public:
    //打开电梯门
    void open()
    {
        //将当前状态修改为开门状态
        context->setLiftState(Context::openningState);
        context->getLiftState().open();
    }
 
    //关门状态
    void close()
    {
        std::cout << "电梯门关闭..." << std::endl;
    }
 
    //关门状态，可以按“运行”按钮
    void run()
    {
        //将当前状态修改为运行状态
        context->setLiftState(Context::runningState);
        context->getLiftState().run();
    }
 
    //关门状态下，可以切换到停止状态
    void stop() {
        //将当前状态修改为停止状态
        context->setLiftState(Context::stoppingState);
        context->getLiftState().stop();
    }
};
 
//运行状态
class RunningState : public LiftState
{
public:
    //运行状态，按“开门”按钮没效课
    void open()
    {
        //do nothing
    }
 
    //运行状态按“关门”按钮没效果
    void close()
    {
        //do nothing;
    }
 
    //运行状态
    void run()
    {
        std::cout << "电梯上下运行..." << std::endl;
    }
 
    //运行状态下，可按“停止”
    void stop()
    {
        //将当前状态修改为停止状态
        context->setLiftState(Context::stoppingState);
        context->getLiftState().stop();
    }
};
 
//停止状态
class StoppingState : public LiftState
{
public:
    //停止状态，可以打开电梯门
    void open()
    {
        //将当前状态修改为开门状态
        context->setLiftState(Context::openningState);
        context->getLiftState().open();
    }
 
    //停止状态下，可以按下“关门”按钮没效果
    void close()
    {
        //do nothing
    }
 
    //关门状态，可以按“运行”按钮！
    void run()
    {
        //将当前状态修改为运行状态
        context->setLiftState(Context::runningState);
        context->getLiftState().run();
    }
 
    //开门状态下，按停止没效果
    void stop()
    {
        std::cout << "电梯停止了..." << std::endl;
    }
};
 
LiftState* Context::openningState = new OpenningState();
LiftState* Context::closingState  = new ClosingState();
LiftState* Context::runningState  = new RunningState();
LiftState* Context::stoppingState = new StoppingState();
 
int main()
{
    Context context;
    context.setLiftState(Context::closingState);
 
    context.open();
    context.close();
    context.run();
    context.stop();
 
    delete Context::openningState;
    delete Context::closingState;
    delete Context::runningState;
    delete Context::stoppingState;
 
    return 0;
}