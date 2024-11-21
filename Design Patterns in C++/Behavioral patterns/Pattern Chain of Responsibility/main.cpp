#include <iostream>
#include <fstream>

enum class Type {
     warning,
     error,
     fatal_error,
     unknown_error
};

class LogMessage {
public:
    LogMessage(Type _type, const std::string& str) : mes_type(_type), mes(str) {};
    Type type() const {
        return mes_type;

    };
    const std::string& message() const {
        return mes;
    };
private:
    Type mes_type;
    std::string mes;
};

class LogHandler {
public:
     void receiveMessage(const LogMessage& _message) {
        if (canHadle() == _message.type()) {
            processing(_message);
        }
        else if (next != nullptr) {
            next->receiveMessage(_message);
        }
        else {
            throw( std::runtime_error("Запрещенная команда. Проверьте цепочку обработки"));
        }
    }
     void next_handler(LogHandler* _next) {
         next = _next;
     }
    
private:
    LogHandler* next = nullptr;

protected:
    virtual void processing(const LogMessage& _message) = 0;
    virtual Type canHadle() const = 0;
 
};

class FatalError : public LogHandler {
public:
    void processing(const LogMessage& _message) override {
        throw(std::runtime_error(_message.message()));
    }
    Type canHadle() const {
        return Type::fatal_error;
    }

};

class Error : public LogHandler {

public:
    void processing(const LogMessage& _message) override {
            std::ofstream out;
            out.open(path);
            if (out.is_open()) {
                out << _message.message() << std::endl;
            }
            out.close();
    }

    Type canHadle() const override{
        return Type::error;
    }

private:
    const std::string path = "text.txt";
};


class Warning : public LogHandler {
public:
    void processing(const LogMessage& _message) override {
        std::cout << _message.message() << std::endl;
    }
    Type canHadle() const override {
        return Type::warning;
    }

};

class UnknownError : public LogHandler {

public:
    void processing(const LogMessage& _message) override {
        throw(std::runtime_error("Необработанное исключение"));
    }
    Type canHadle() const override {
        return Type::unknown_error;
    }
  
};

int main()
{
    setlocale(LC_ALL, "rus");
    try {
        LogHandler* first = new FatalError;
        LogHandler* second = new Error;
        LogHandler* third = new Warning;
        LogHandler* fourth = new UnknownError;

        first->next_handler(second);
        second->next_handler(third);
        third->next_handler(fourth);
   
        LogMessage message_1(Type::error, "Невозможно открыть");
        LogMessage message_2(Type::warning, "Проверьте файл");
        LogMessage message_3(Type::fatal_error, "Отсутствие данных");
        LogMessage message_4(Type::unknown_error, "Неизвестная ошибка");

        first->receiveMessage(message_1);
        first->receiveMessage(message_2); 
        first->receiveMessage(message_4);
        first->receiveMessage(message_3);

        delete first;
        delete second;
        delete third;
        delete fourth;
    }
    catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }

	return 0;
}