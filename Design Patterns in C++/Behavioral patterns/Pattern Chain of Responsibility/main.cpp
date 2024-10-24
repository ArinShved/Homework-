#include <iostream>
#include <fstream>

enum class Type {
     warning,
     error,
     fatal_error,
     unknown_error
};

class LogMessage {
protected:
    Type mes_type;
    std::string mes = "";
public:
    Type type() const {
        return mes_type;
    };
    const std::string& message() {
        return mes;
    };
    
    virtual void processing(Type _type, const std::string& _message) = 0;
    virtual void next_handler(LogMessage* next) = 0;
};

class FatalError : public LogMessage {
private:
    LogMessage* next = nullptr;
public:
    void processing(Type _type, const std::string& _message) override {
        mes_type = _type;
        mes = _message;
        if (type() == Type::fatal_error) {
            throw mes;
        }
        else if (next != nullptr) {
            next->processing(_type, _message);
        }
        else {
            throw std::string("Запрещенная команда. Проверьте цепочку обработки");
        }
    }
    void next_handler(LogMessage* _next) override{
        next = _next;
    }
};

class Error : public LogMessage {
private:
    LogMessage* next = nullptr;
    const std::string path = "text.txt";
public:
    void processing(Type _type, const std::string& _message) override {
        mes_type = _type;
        mes = _message;
        if (type() == Type::error) {
            std::ofstream out;
            out.open(path);
            if (out.is_open()) {
                out << mes << std::endl;
            }
            out.close();
        }
        else if (next != nullptr) {
            next->processing(_type, _message);
        }
         else {
             throw std::string("Запрещенная команда. Проверьте цепочку обработки");
        }
    }
    void next_handler(LogMessage* _next) override {
        next = _next;
    }
};


class Warning : public LogMessage {
private:
    LogMessage* next = nullptr;
public:
    void processing(Type _type, const std::string& _message) override {
        mes_type = _type;
        mes = _message;
        if (type() == Type::warning) {
            std::cout << mes << std::endl;
        }
        else if (next != nullptr) {
            next->processing(_type, _message);
        }
        else {
            throw std::string("Запрещенная команда. Проверьте цепочку обработки");
        }
    }
    void next_handler(LogMessage* _next) override {
        next = _next;
    }
};

class UnknownError : public LogMessage {
private:
    LogMessage* next = nullptr;
public:
    void processing(Type _type, const std::string& _message) override {
        mes_type = _type;
        mes = _message;
        throw std::string("Необработанное исключение");
    }
    void next_handler(LogMessage* _next) override {
        next = nullptr;
    }
};

int main()
{
    setlocale(LC_ALL, "rus");
    try {
        LogMessage* first = new FatalError;
        LogMessage* second = new Error;
        LogMessage* third = new Warning;
        LogMessage* fourth = new UnknownError;
        first->next_handler(second);
        second->next_handler(third);
        third->next_handler(fourth);
   

        first->processing(Type::error, "Невозможно открыть");
        first->processing(Type::warning, "Проверьте файл");
        first->processing(Type::fatal_error, "Отсутствие данных");
        first->processing(Type::unknown_error, "Неизвестная ошибка");
    }
    catch (const std::string& e) {
        std::cout << e << std::endl;
    }

	return 0;
}