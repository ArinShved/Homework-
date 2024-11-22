#include <iostream>
#include <fstream>
#include <vector>
#include <memory>

class Data{
public:
    Data(const std::string& _data, const std::string& _title): data(_data), title(_title) {}

    std::string get_data() const{
        return data;
    }

    std::string get_title() const {
        return title;
    }
private:
    std::string data;
    std::string title;
};

class ProcessingData {
public:
    virtual ~ProcessingData() = default;
    virtual std::string wrap_element(const std::string& data) const = 0;
    virtual std::string wrap_data(std::vector<std::string>& data) const = 0;
};

class  ProcessingHTML : public ProcessingData {
public:
      std::string wrap_element(const std::string& data) const override  {
         return "<html>" + data + "<html/>";
      }

      std::string wrap_data(std::vector<std::string>& data) const override {
          std::string new_str = "<html>";
          for (int i = 0; i < data.size(); i++) {
              new_str += data[i];
          }
          return new_str + "<html/>";
      }
};

class  ProcessingText : public ProcessingData {
public:
     std::string wrap_element(const std::string& data) const override {
         return data;
     }

     std::string wrap_data(std::vector<std::string>& data) const override {
         std::string new_str = "";
         for (int i = 0; i < data.size(); i++) {
             new_str += data[i];
         }
         return new_str;
     }
};

class  ProcessingJSON : public ProcessingData {
public:
    std::string  wrap_element(const std::string& data) const override {
        return"{ \"data\": \"" + data + "\"}";
    }

    std::string wrap_data(std::vector<std::string>& data) const override {
        std::string new_str = "{ \"data\": \"";
        for (int i = 0; i < data.size(); i++) {
            new_str += data[i];
        }
        return new_str + "\"}";
    }
};

class SavingData {
public:
    virtual void saveTo(std::string file_name, Data& data, std::shared_ptr<ProcessingData> processing) {
        std::vector<std::string> arr = before_saving(data, processing);
        std::ofstream out;
        out.open(file_name, std::ios::app);
        if (out.is_open()) {
            out << processing->wrap_data(arr) << std::endl;
        }
        out.close();
    };
protected:
    virtual std::vector<std::string> before_saving(Data& data, std::shared_ptr<ProcessingData> processing) {
        std::vector<std::string> data_arr;
        data_arr.push_back(processing->wrap_element(data.get_data()));
        data_arr.push_back(processing->wrap_element(data.get_title()));
        return data_arr;
    }
};

int main() {
    try {
        auto printer_1 = std::make_shared<ProcessingHTML>();
        auto printer_2 = std::make_shared<ProcessingText>();
        auto printer_3 = std::make_shared<ProcessingJSON>();

        Data text_1("*num_", "1");
        Data text_2("*num_", "2");

        auto saving = std::make_shared<SavingData>();

        saving->saveTo("text.txt", text_1, printer_1);
        saving->saveTo("text.txt", text_2, printer_2);
        saving->saveTo("text.txt", text_1, printer_3);

    }
    catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
