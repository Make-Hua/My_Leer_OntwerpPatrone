#include <iostream>
#include <string>

// 备忘录类
class EditorMemento {
private:
    std::string text;

public:
    EditorMemento(const std::string& t) : text(t) {}

    const std::string& getText() const {
        return text;
    }
};

// 文本编辑器类
class TextEditor {
private:
    std::string text;

public:
    void setText(const std::string& t) {
        text = t;
    }

    const std::string& getText() const {
        return text;
    }

    // 创建备忘录并保存当前状态
    EditorMemento createMemento() const {
        return EditorMemento(text);
    }

    // 从备忘录中恢复状态
    void restoreFromMemento(const EditorMemento& memento) {
        text = memento.getText();
    }
};

int main() {
    TextEditor editor;

    // 用户输入文本
    editor.setText("第一行文本\n第二行文本\n第三行文本");
    std::cout << "当前文本内容:\n" << editor.getText() << std::endl;

    // 创建备忘录并保存当前状态
    EditorMemento memento = editor.createMemento();

    // 用户继续编辑文本
    editor.setText("新的文本内容");

    std::cout << "修改后的文本内容:\n" << editor.getText() << std::endl;

    // 恢复到之前的状态
    editor.restoreFromMemento(memento);
    std::cout << "恢复后的文本内容:\n" << editor.getText() << std::endl;

    return 0;
}

/*
    要点总结

        ➢备忘录(Memento)存储原发器(Originator) 对象的内部状态，
        在需要时恢复原发器状态。

        ➢Memento模式的核心是信息隐藏，即Originator需 
        要向外接隐藏信息，保持其封装性。但同时又需要将
        状态保持到外界(Memento) 。

        ➢由于现代语言运行时(如C#、 Java等)都具有相当的对象序列
        化支持，因此往往采用效率较高、又较容易正确实现的序列化方
        案来实现Memento模式。
*/