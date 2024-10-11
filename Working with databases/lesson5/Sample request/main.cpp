#include <iostream>
#include <WT/Dbo/Dbo.h>
#include <Wt/Dbo/backend/Postgres.h>
#include <Windows.h>
#include <string>


#pragma execution_character_set( "utf-8")

class Book;
class Shop;
class Stock;

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
	Wt::Dbo::collection< Wt::Dbo::ptr<Stock>> stock_id;
	
	template<class Action>
	void persist(Action& a) {
		Wt::Dbo::field(a, title, "title");
		Wt::Dbo::belongsTo(a, id_publisher, "publisher");
		Wt::Dbo::hasMany(a, stock_id, Wt::Dbo::ManyToOne, "book_stock");
		
	}
};

class Stock {
public:
	Wt::Dbo::ptr<Book> book;
	Wt::Dbo::ptr<Shop> shop;
	int count = 0;

	template<class Action>
	void persist(Action& a) {
		Wt::Dbo::belongsTo(a, book, "book_stock");
		Wt::Dbo::belongsTo(a, shop, "shop_stock");
		Wt::Dbo::field(a, count, "count");
	}
};

class Shop {
public:
	std::string name;
	Wt::Dbo::collection < Wt::Dbo::ptr<Stock>> stock_id;

	template<class Action>
	void persist(Action& a) {
		Wt::Dbo::field(a, name, "name");
		Wt::Dbo::hasMany(a, stock_id, Wt::Dbo::ManyToOne, "shop_stock");
	}
};

int main() {
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);

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
		s.mapClass<Stock>("stock");
		s.mapClass<Shop>("shop");

		s.createTables();

		Wt::Dbo::Transaction transaction{ s };

		std::unique_ptr<Publisher> tolstoi{ new Publisher{"Tolstoi"} };
		std::unique_ptr<Publisher> gogol{ new Publisher{"Gogol"} };
		Wt::Dbo::ptr<Publisher> un_gogol = s.add(std::move(gogol));
		Wt::Dbo::ptr<Publisher> un_tolstoi = s.add(std::move(tolstoi));

		std::unique_ptr<Book> book_1{ new Book{"War and Peace. Volume 1", un_tolstoi} };
		std::unique_ptr<Book> book_2{ new Book{"War and Peace. Volume 2", un_tolstoi} };
		std::unique_ptr<Book> book_3{ new Book{"War and Peace", un_tolstoi} };
		std::unique_ptr<Book> book_4{ new Book{"Dead Souls", un_gogol} };
		Wt::Dbo::ptr<Book> b_tolstoi_1 = s.add(std::move(book_1));
		Wt::Dbo::ptr<Book> b_tolstoi_2 = s.add(std::move(book_2));
		Wt::Dbo::ptr<Book> b_tolstoi_3 = s.add(std::move(book_3));
		Wt::Dbo::ptr<Book> b_gogol = s.add(std::move(book_4));
		
		std::unique_ptr<Shop> shop_1{ new Shop{"Star"}};
		std::unique_ptr<Shop> shop_2{ new Shop{"Way"}};
		std::unique_ptr<Shop> shop_3{ new Shop{"Mountains"} };
		std::unique_ptr<Shop> shop_4{ new Shop{"Don"} };
		Wt::Dbo::ptr<Shop> sh_1 = s.add(std::move(shop_1));
		Wt::Dbo::ptr<Shop> sh_2 = s.add(std::move(shop_2));
		Wt::Dbo::ptr<Shop> sh_3 = s.add(std::move(shop_3));
		Wt::Dbo::ptr<Shop> sh_4 = s.add(std::move(shop_4));

		std::unique_ptr<Stock> stock_1{ new Stock{b_tolstoi_1, sh_1, 2} };
		std::unique_ptr<Stock> stock_2{ new Stock{b_tolstoi_2, sh_4, 3} };
		std::unique_ptr<Stock> stock_3{ new Stock{b_tolstoi_1, sh_2, 1} };
		std::unique_ptr<Stock> stock_4{ new Stock{b_tolstoi_3, sh_3, 4} };
		std::unique_ptr<Stock> stock_5{ new Stock{b_gogol, sh_1, 2} };
		std::unique_ptr<Stock> stock_6{ new Stock{b_gogol, sh_4, 2} };
		Wt::Dbo::ptr<Stock> st_1 = s.add(std::move(stock_1));
		Wt::Dbo::ptr<Stock> st_2 = s.add(std::move(stock_2));
		Wt::Dbo::ptr<Stock> st_3 = s.add(std::move(stock_3));
		Wt::Dbo::ptr<Stock> st_4 = s.add(std::move(stock_4));
		Wt::Dbo::ptr<Stock> st_5 = s.add(std::move(stock_5));
		Wt::Dbo::ptr<Stock> st_6 = s.add(std::move(stock_6));

		transaction.commit();

		
		std::string str;
		std::cout << "Введите инициалы автора: ";
		std::getline(std::cin, str);
		
		typedef Wt::Dbo::collection<Wt::Dbo::ptr<Book>> list_of_books;
		typedef Wt::Dbo::collection < Wt::Dbo::ptr<Stock>> list_of_stocks;
		typedef Wt::Dbo::collection < Wt::Dbo::ptr<Shop>> list_of_shops;

		Wt::Dbo::Transaction t{ s };
		Wt::Dbo::ptr<Publisher> pub = s.find<Publisher>().where("name = ?").bind(str);
		std::cout << pub->name << "\nКакие книги написал: \n";
		for (const Wt::Dbo::ptr<Book>& i_book : pub->books) {
			std::cout << i_book->title << "\n";
		}

		std::cout << "Где можно найти: \n";

		for (const Wt::Dbo::ptr<Book>& i_book : pub->books){
			list_of_stocks find_stock = s.find<Stock>().where("book_stock_id = ?").bind(i_book);
			for (const Wt::Dbo::ptr<Stock>& i_stock : find_stock) {
				list_of_shops find_shop = s.find<Shop>().where("id = ?").bind(i_stock->shop);
				for (const Wt::Dbo::ptr<Shop>& i_shop : find_shop) {
					std::cout << i_shop->name << "\n";
				}
			}
		}
		
		t.commit();
	}
	catch (const Wt::Dbo::Exception& e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}