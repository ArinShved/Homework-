#include <iostream>
#include <vector>
#include <fstream>

class Observer {
public:
	virtual void onWarning(const std::string& message) = 0;
	virtual void onError(const std::string& message) = 0;
	virtual void onFatalError(const std::string& message) = 0;
};

class WarningErrors {
private:
	std::vector<std::weak_ptr<Observer>> observers;

	template<typename T>
	void notify(T func, const std::string& message) const {
		for (auto it = observers.begin(); it != observers.end(); it++) {
			if (auto observer = it->lock()) {
				(observer.get()->*func)(message);
			}
		}
	}
public:
	void add_observer(std::shared_ptr<Observer> obs) {
		observers.emplace_back(obs);
	}

	void warning(const std::string& message) const {
		notify(&Observer::onWarning, message);
	};

	void error(const std::string& message) const {
		notify(&Observer::onError, message);
	};

	void fatalError(const std::string& message) const {
		notify(&Observer::onFatalError, message);
	};
};

class ObsInConsole : public Observer {
public:
	void onWarning(const std::string& message) override {
		std::cout << "Первый наблюдатель update: warning " << message << std::endl;
	}
	void onError(const std::string& message) override {
		std::cout << "Первый наблюдатель update: error " << message << std::endl;
	}
	void onFatalError(const std::string& message) override {
		std::cout << "Первый наблюдатель update: fatal error " << message << std::endl;
	}
};

class ObsInFile : public Observer {
public:
	ObsInFile(const std::string _path) : path(_path) {};
	void onWarning(const std::string& message) override {
		printInFile("warning " + message + "\n");
	}
	void onError(const std::string& message) override {
		printInFile("error " + message + "\n");
	}
	void onFatalError(const std::string& message) override {
		printInFile("fatal error " + message + "\n");
	}
protected:
	const std::string path;

	virtual void printInFile(const std::string& mes) {
		std::ofstream out;
		out.open(path, std::ios::app);
		if (out.is_open()) {
			out << "Второй наблюдатель update:" << mes;
		}
		out.close();
	}
};

class ObsInConAndFile : public ObsInFile {
public:
	ObsInConAndFile(const std::string _path) : ObsInFile(_path) {};
	void onWarning(const std::string& message) override {
		printInFile("warning " + message + "\n");
		std::cout << "Третий наблюдатель update: warning " << message << std::endl;
	}
	void onError(const std::string& message) override {
		printInFile("error " + message + "\n");
		std::cout << "Третий наблюдатель update: error " << message << std::endl;
	}
	void onFatalError(const std::string& message) override {
		printInFile("fatal error " + message + "\n");
		std::cout << "Третий наблюдатель update: fatal error " << message << std::endl;
	}
private:
	void printInFile(const std::string& mes) override {
		std::ofstream out;
		out.open(path, std::ios::app);
		if (out.is_open()) {
			out << "Третий наблюдатель update:" << mes;
		}
		out.close();
	}
};

int main() {
	setlocale(LC_ALL, "rus");
	try{
		WarningErrors warn;

		auto first = std::make_shared<ObsInConsole>();
		auto sec = std::make_shared<ObsInFile>("text.txt");
		auto third = std::make_shared<ObsInConAndFile>("text.txt");

		warn.add_observer(first);
		warn.add_observer(sec);
		warn.add_observer(third);

		warn.warning("Stop");
		warn.error("Cannot open");
		warn.fatalError("System error");

	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}