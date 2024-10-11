#include <iostream>
#include <WT/Dbo/Dbo.h>
#include <Wt/Dbo/backend/Postgres.h>
#include <Windows.h>
#include <string>


#pragma execution_character_set( "utf-8")

class Book;
class Shop;
class Stock;
class Sale;

class Publisher {
public:
	std::string name = "";
	Wt::Dbo::collection< Wt::Dbo::ptr<Book>> books;

	template<class Action>
	void persist(Action& a) {
		Wt::Dbo::field(a, name, "name");
		Wt::Dbo::hasMany(a, books, Wt::Dbo::ManyToOne, "publisher");
	}
};

class Book {
public:
	std::string title = "";
	Wt::Dbo::ptr<Publisher> id_publisher;
	Wt::Dbo::collection < Wt::Dbo::ptr<Stock>> id_books;

	template<class Action>
	void persist(Action& a) {
		Wt::Dbo::field(a, title, "title");
		Wt::Dbo::belongsTo(a, id_publisher, "publisher");
		Wt::Dbo::hasMany(a, id_books, Wt::Dbo::ManyToMany, "id_book");
	}
};

class Stock{
public:
	Wt::Dbo::collection< Wt::Dbo::ptr<Book>> id_book;
	Wt::Dbo::ptr<Shop> id_shop;
	Wt::Dbo::collection< Wt::Dbo::ptr<Sale>> sale;
	int count = 0;

	template<class Action>
	void persist(Action& a) {
		Wt::Dbo::field(a, count, "count");
		Wt::Dbo::hasMany(a, id_book, Wt::Dbo::ManyToMany, "id_book");
		Wt::Dbo::belongsTo(a, id_shop, "id_shop");
		Wt::Dbo::hasMany(a, sale, Wt::Dbo::ManyToOne, "stock");
	}
};

class Sale {
public:
	double price = 0;
	Wt::Dbo::SqlDateTimeType date_sale;
	int count = 0;
	Wt::Dbo::ptr<Stock> sale;

	template<class Action>
	void persist(Action& a) {
		Wt::Dbo::field(a, price, "price");
		Wt::Dbo::field(a, count, "count");
		Wt::Dbo::field(a, date_sale, "date of sale");
		Wt::Dbo::belongsTo(a, sale, "stock");
	}
};

class Shop {
public:
	int shop_id = 0;
	std::string name;
	Wt::Dbo::collection< Wt::Dbo::ptr<Stock>> id_shop;

	template<class Action>
	void persist(Action& a) {
		Wt::Dbo::field(a, name, "name");
		Wt::Dbo::hasMany(a, id_shop, Wt::Dbo::ManyToOne, "id_shop");
	}
};

int main() {
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	//setlocale(LC_ALL, "rus");

	try {
		std::string connection_str =
			"host=localhost "
			"port=5432 "
			"dbname=lesson_5 "
			"user=postgres "
			"password=9757y_Q1";
		
		
		std::unique_ptr<Wt::Dbo::backend::Postgres> con;

		con = std::make_unique<Wt::Dbo::backend::Postgres>(connection_str);
		Wt::Dbo::Session s;
		s.setConnection(std::move(con));

		s.mapClass<Publisher>("publisher");
		s.mapClass<Book>("book");
		s.mapClass<Sale>("sale");
		s.mapClass<Stock>("stock");
		s.mapClass<Shop>("shop");
		
		s.createTables();
	}
	catch ( const Wt::Dbo::Exception& e) {
		std::cout << e.what() << std::endl;
	}

	return 0;

}