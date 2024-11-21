#include <string>
#include <iostream>

class Text {
public:
    virtual void render(const std::string& data) const {
        std::cout << data;
    }
};

class DecoratedText : public Text {
public:
    explicit DecoratedText(std::shared_ptr<Text> text) : text_(text) {}
    std::shared_ptr<Text> text_;
};

class ItalicText : public DecoratedText {
public:
    explicit ItalicText(std::shared_ptr<Text> text) : DecoratedText(text) {}
    void render(const std::string& data)  const {
        std::cout << "<i>";
        text_->render(data);
        std::cout << "</i>";
    }
};

class BoldText : public DecoratedText {
public:
    explicit BoldText(std::shared_ptr<Text> text) : DecoratedText(text) {}
    void render(const std::string& data) const {
        std::cout << "<b>";
        text_->render(data);
        std::cout << "</b>";
    }
};

class Paragraph : public DecoratedText {
public:
    explicit Paragraph(std::shared_ptr<Text> text) : DecoratedText(text) {};
    void render(const std::string& data) const {
        std::cout << "<p>";
        text_->render(data);
        std::cout << "</p>";
    }
};

class Reversed : public DecoratedText {
public:
    explicit Reversed(std::shared_ptr<Text> text) : DecoratedText(text) {};
    void render(const std::string& data) const {
        std::string _data = data;
        std::reverse(_data.begin(), _data.end());
         text_->render(_data);
    }
};

class Link : public DecoratedText {
public: 
    explicit Link(std::shared_ptr<Text> text) : DecoratedText(text) {};
    void render(const std::string& link, const std::string& data) const {
        std::cout << "<a href=";
        text_->render(link);
        std::cout << ">";
        text_->render(data);
        std::cout << "</a>";
    }
};

int main() {
    auto text_block_1 = std::make_shared<Paragraph>(std::make_shared<Text>());
    text_block_1->render("Hello world");
    std::cout << std::endl;
    auto text_block_2 = std::make_shared<Reversed>(std::make_shared<Text>());
    text_block_2->render("Hello world");
    std::cout << std::endl;
    auto text_block_3 = std::make_shared<Link>(std::make_shared<Text>());
    text_block_3->render("netology.ru", "Hello world");
    std::cout << std::endl;

    return 0;
}