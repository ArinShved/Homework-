#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>
#include <pqxx/pqxx>

struct Client {
    std::string name;
    std::string surname;
    std::string email;
    std::vector<std::string> phones;
    int id;
};

class Database {
public:
    Database() {}
    
    void create_tables(pqxx::connection& c) {
        pqxx::work w(c);
        w.exec("CREATE TABLE IF NOT EXISTS clients (id SERIAL PRIMARY KEY, name VARCHAR(255), surname VARCHAR(255), email VARCHAR(255) UNIQUE)");
        w.exec("CREATE TABLE IF NOT EXISTS phones (id SERIAL PRIMARY KEY, client_id INTEGER REFERENCES clients(id), phone VARCHAR(20))");
        w.commit();
    }
    
    void add_client(const Client& client, pqxx::connection& c) {
        if (check_words(client.name) && check_words(client.surname)) {
            pqxx::work w(c);
            w.exec_params("INSERT INTO clients(name, surname, email) VALUES($1, $2, $3)", client.name,
                client.surname, client.email);
            w.commit();
        }
        else {
            std::cout << "Введенные данные содержат недопустимые слова. Пожалуйста, повторите попытку с другим Именем или Фамилией\n";
        }
    }

    void add_phone(const std::string& email, const std::string& phone, pqxx::connection& c) {
        if (check_words(phone)) {
            pqxx::work w(c);
            w.exec_params("INSERT INTO phones (client_id, phone) VALUES ((SELECT id FROM clients WHERE email = $1), $2)",
                email, phone);
                w.commit();
        }
        else {
            std::cout << "Неверный ввод номера\n";
        }
    }

    void update_client(const Client& client, int id, pqxx::connection& c) {
        if (check_words(client.name) && check_words(client.surname)) {
            pqxx::work w(c);
            w.exec_params("UPDATE clients SET name = $1, surname = $2, email = $3  WHERE id = $4",
                client.name, client.surname, client.email, std::to_string(id));
            w.commit();
        }
        else {
            std::cout << "Введенные данные содержат недопустимые слова. Пожалуйста, повторите попытку с другим Именем или Фамилией\n";
        }

    }

    void remove_phone(const std::string& email, const std::string& phone, pqxx::connection& c) {
        pqxx::work w(c);
        w.exec_params("DELETE FROM phones WHERE client_id = (SELECT id FROM clients WHERE email = $1) AND phone = $2",
            email, phone);
        w.commit();
    }

    void remove_client(const std::string& email, pqxx::connection& c) {
        pqxx::work w(c);
        w.exec_params("DELETE FROM phones WHERE client_id = (SELECT id FROM clients WHERE email = $1)", email);
        w.exec_params("DELETE FROM clients WHERE email = $1", email );
        w.commit();
    }
    
    Client find_by_Email(const std::string& email, pqxx::connection& c) {
        pqxx::work w(c);
        pqxx::result r = w.exec_params("SELECT id, name, surname, email FROM clients WHERE email = $1", email);
        if (r.size() == 1) {
            Client client;
            client.id = r[0]["id"].as<int>();
            client.name = r[0]["name"].as<std::string>();
            client.surname = r[0]["surname"].as<std::string>();
            client.email = r[0]["email"].as<std::string>();
            std::cout << "Имя: " << client.name << " Фамилия: " << client.surname << " ID: " << client.id << "\n";
            return client;
        }
        else {
            std::cout << "Не найден\n";
            return Client(); 
        }
    }

    Client find_by_name(const std::string& name, pqxx::connection& c) {
        pqxx::work w(c);
        pqxx::result r = w.exec_params("SELECT id, name, surname, email FROM clients WHERE name LIKE '%' || $1 || '%'", name);
        if (r.size() == 1) {
            Client client;
            client.id = r[0]["id"].as<int>();
            client.name = r[0]["name"].as<std::string>();
            client.surname = r[0]["surname"].as<std::string>();
            client.email = r[0]["email"].as<std::string>();
            std::cout << "Имя: " << client.name << " Фамилия: " << client.surname << " ID: " << client.id << "\n";
            return client;
        }
        else {
            std::cout << "Не найден\n";
            return Client(); 
        }
    }

    Client find_by_surname(const std::string& surname, pqxx::connection& c) {
        pqxx::work w(c);
        pqxx::result r = w.exec_params("SELECT id, name, surname, email FROM clients WHERE surname LIKE '%' || $1 || '%'", surname);
        if (r.size() == 1) {
            Client client;
            client.id = r[0]["id"].as<int>();
            client.name = r[0]["name"].as<std::string>();
            client.surname = r[0]["surname"].as<std::string>();
            client.email = r[0]["email"].as<std::string>();
            std::cout << "Имя: " << client.name << " Фамилия: " << client.surname << " ID: " << client.id << "\n";
            return client;
        }
        else {
            std::cout << "Не найден\n";
            return Client(); 
        }
    }

    friend bool check_words(std::string str);

   
};

bool check_words(std::string str) {
    std::string check = str;
    for (int i = 0; i < str.length(); i++) {
        check[i] = std::toupper(str[i]);
    }
    std::vector<std::string> ban_words = { "SELECT","INSERT", "UPDATE","DELETE","DROP", "TRUNCATE","CREATE","ALTER",
        "GRANT","REVOKE","COMMIT","ROLLBACK", "INFORMATION_SCHEMA", "SYS.TABLES", "SYS.COLUMNS"};
    for (auto i : ban_words) {
        if (check.find(i) != std::string::npos) {
            return false;
        }
    }
    return true;
}


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    try {
        pqxx::connection c(
            "host=localhost "
            "port=5432 "
            "dbname=lesson_4 "
            "user=postgres "
            "password=9757y_Q1");

        Database base;

        Client us{"Luke", "Holle", "orer.com"};
        Client user_1{ "Andru", "Lock", "uuu.com" };
        base.create_tables(c);
        base.add_client(us, c);
        //base.add_client(user_1, c);
        base.add_phone("orer.com", "8(966)987-09-09", c);
        base.add_phone("orer.com", "8(767)987-09-98", c);

        Client user_2{ "Luke", "Ghost", "otqq.com" };
        //base.update_client(user_2, 1, c);
        base.remove_phone("orer.com", "8(767)987-09-98", c);
        
        base.find_by_Email("otqq.com", c);
        base.find_by_name("Andru", c);
        base.find_by_surname("Ghost", c);

      //  base.remove_client("orer.com", c);
    }
    catch (pqxx::sql_error e) {
        std::cout << e.what() << "\n";
    }
    

	return 0;
}