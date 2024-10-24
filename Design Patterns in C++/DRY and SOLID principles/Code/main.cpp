#include <fstream>

enum class Format{
    Text,
    HTML,
    JSON
};

class Data{
public:
    Data(std::string _data, Format _format)
        : data(std::move(_data)), format(_format) {}

    std::string get_data() const{
        return data;
    }

    Format get_format() const {
        return format;
    }
private:
    std::string data;
    Format format;
};

class ProcessingData {
public:
    virtual std::string print(Data& data) = 0;
    virtual void saveTo(std::ofstream& file, Data& data) = 0;
};

class  ProcessingHTML : public ProcessingData {
public:
      std::string print(Data& data) override {
        if (data.get_format() != Format::HTML) {
            throw std::runtime_error("Invalid format!");
        }
        else {
            return "<html>" + data.get_data() + "<html/>";
        }
    }
    virtual void saveTo(std::ofstream& file, Data& data) {
        if (file.is_open()) {
            file << print(data);
        }
    }
};

class  ProcessingText : public ProcessingData {
public:
     std::string print(Data& data) override {
        if (data.get_format() != Format::Text) {
            throw std::runtime_error("Invalid format!");
        }
        else {
            return data.get_data();
        }
    }
    virtual void saveTo(std::ofstream& file, Data& data) {
        if (file.is_open()) {
            file << print(data);
        }
    }
};

class  ProcessingJSON : public ProcessingData {
public:
    std::string print(Data& data) override {
        if (data.get_format() != Format::JSON) {
            throw std::runtime_error("Invalid format!");
        }
        else {
            return"{ \"data\": \"" + data.get_data() + "\"}";
        }
    }
    virtual void saveTo(std::ofstream& file, Data& data) {
        if (file.is_open()) {
            file << print(data);
        }
    }
};
