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
        pqxx::work w(c);
        w.exec("INSERT INTO clients(name, surname, email) VALUES('" + client.name + "','"
            + client.surname + "', '" + client.email + "')");
        w.commit();
    }

    void add_phone(const Client& client, const std::string& phone, pqxx::connection& c) {
        pqxx::work w(c);
        w.exec("INSERT INTO phones (client_id, phone) VALUES ((SELECT id FROM clients WHERE email = '"
            + client.email + "'),'" + phone + "')");
        w.commit();
    }

    void update_client(const Client& client, int id, pqxx::connection& c) {
        pqxx::work w(c);
        w.exec("UPDATE clients SET name = '" +client.name +"', surname = '" + client.surname + 
            "', email = '" + client.email + "' WHERE id = " + std::to_string(id));
        w.commit();
    }

    void remove_phone(const Client& client, const std::string& phone, pqxx::connection& c) {
        pqxx::work w(c);
        w.exec("DELETE FROM phones WHERE client_id = (SELECT id FROM clients WHERE email = '"
            + client.email +"') AND phone = '"+ phone + "'");
        w.commit();
    }

    void remove_client(const Client& client, pqxx::connection& c) {
        pqxx::work w(c);
        w.exec("DELETE FROM phones WHERE client_id = (SELECT id FROM clients WHERE email = '"+ client.email +"')");
        w.exec("DELETE FROM clients WHERE email = '" + client.email +"'");
        w.commit();
    }
    
    Client find_by_Email(const std::string& email, pqxx::connection& c) {
        pqxx::work w(c);
        pqxx::result r = w.exec("SELECT id, name, surname, email FROM clients WHERE email = '" + email + "'");
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
        pqxx::result r = w.exec("SELECT id, name, surname, email FROM clients WHERE name LIKE '%' ||'" + name + "' || '%'");
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
        pqxx::result r = w.exec("SELECT id, name, surname, email FROM clients WHERE surname LIKE '%' ||'" + surname +"' || '%'");
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

    
};


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
      
        Client us{ "Luke", "Holle", "oit.com" };
        Client user_1{ "Andru", "Lock", "uu.com" };
        base.create_tables(c);
        base.add_client(us, c);
        base.add_client(user_1, c);
        base.add_phone(us, "8(966)987-09-09", c);
        base.add_phone(us, "8(767)987-09-98", c);

        Client user_2{ "Luke", "Ghost", "ot.com" };
        base.update_client(user_2, 1, c);
        base.remove_phone(us, "8(767)987-09-98", c);
        
        base.find_by_Email("oit.com", c);
        base.find_by_name("Andru", c);
        base.find_by_surname("Ghost", c);

        base.remove_client(us, c);
    }
    catch (pqxx::sql_error e) {
        std::cout << e.what() << "\n";
    }
    

	return 0;
}