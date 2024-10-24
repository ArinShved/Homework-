#include <iostream>
#include <fstream>
#include <vector>

class LogCommand {
public:
    virtual ~LogCommand() = default;
    virtual void print(const std::string& message) = 0;
};

class PrintInConsole: public LogCommand {
public:
    void print(const std::string& message) override {
        std::cout << message << std::endl;
   }
};

class PrintInFile : public LogCommand {
private:
   const std::string path;
public:
    PrintInFile(const std::string& _path) : path(_path) {};
    void print(const std::string& message) {
        std::ofstream out;
        out.open(path);
        if (out.is_open()) {
            out << message << std::endl;
        }
        out.close();
    }
};

class Renote {
public:
    void oid_print(LogCommand& lgc, const std::string& message) {
        lgc.print(message);
    };
};



int main() {
    setlocale(LC_ALL, "rus");
    try {
        PrintInConsole con;
        PrintInFile file("test.txt");
        Renote func;

        func.oid_print(con, "Консоль");
        func.oid_print(file, "Файл");
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

	return 0;
}