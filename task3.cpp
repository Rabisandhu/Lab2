#include <iostream>

using namespace std;

class LibraryItem {
public:
	virtual void display() const = 0;
	virtual const char* getName() const = 0; 
	virtual ~LibraryItem() {} 
};

class Book : public LibraryItem {
private:
	char title[100];
	char author[100];
	int pages;

public:
	Book() {
		title[0] = '\0';
		author[0] = '\0';
		pages = 0;
	}

	Book(const char* t, const char* a, int p) {
		int i;
		for (i = 0; t[i] != '\0' && i < 99; i++) {
			title[i] = t[i];
		}
		title[i] = '\0'; 
		for (i = 0; a[i] != '\0' && i < 99; i++) {
			author[i] = a[i];
		}
		author[i] = '\0';

		pages = p;
	}

	void display() const override {
		cout << "Book Title: " << title << ", Author: " << author << ", Pages: " << pages << endl;
	}

	const char* getName() const override {
		return title;
	}

	int getPages() const {
		return pages;
	}
};

class Newspaper : public LibraryItem {
private:
	char name[100];
	char date[11];
	char edition[50];

public:
	Newspaper() {
		name[0] = '\0';
		date[0] = '\0';
		edition[0] = '\0';
	}

	Newspaper(const char* n, const char* d, const char* e) {
		int i;
		for (i = 0; n[i] != '\0' && i < 99; i++) {
			name[i] = n[i];
		}
		name[i] = '\0'; 

		for (i = 0; d[i] != '\0' && i < 10; i++) {
			date[i] = d[i];
		}
		date[i] = '\0'; 

		for (i = 0; e[i] != '\0' && i < 49; i++) {
			edition[i] = e[i];
		}
		edition[i] = '\0'; 
	}

	void display() const override {
		cout << "Newspaper Name: " << name << ", Date: " << date << ", Edition: " << edition << endl;
	}

	const char* getName() const override {
		return name;
	}
};

class Library {
private:
	Book books[10];
	Newspaper newspapers[10];
	int bookCount = 0;
	int newspaperCount = 0;

public:
	Library() {}

	void addBook(const Book& book) {
		if (bookCount < 10) {
			books[bookCount++] = book;
		}
	}

	void addNewspaper(const Newspaper& newspaper) {
		if (newspaperCount < 10) {
			newspapers[newspaperCount++] = newspaper;
		}
	}

	void displayCollection() const {
		cout << "Books:\n";
		for (int i = 0; i < bookCount; i++) {
			books[i].display();
		}
		cout << "Newspapers:\n";
		for (int i = 0; i < newspaperCount; i++) {
			newspapers[i].display();
		}
	}

	void sortBooksByPages() {
		for (int i = 0; i < bookCount - 1; i++) {
			for (int j = i + 1; j < bookCount; j++) {
				if (books[i].getPages() > books[j].getPages()) {
					Book temp = books[i];
					books[i] = books[j];
					books[j] = temp;
				}
			}
		}
	}

	void sortNewspapersByEdition() {
		for (int i = 0; i < newspaperCount - 1; i++) {
			for (int j = i + 1; j < newspaperCount; j++) {
				if (compareStrings(newspapers[i].getName(), newspapers[j].getName()) > 0) {
					Newspaper temp = newspapers[i];
					newspapers[i] = newspapers[j];
					newspapers[j] = temp;
				}
			}
		}
	}

	int compareStrings(const char* str1, const char* str2) const {
		for (int i = 0;; i++) {
			if (str1[i] == '\0' && str2[i] == '\0') return 0; 
			if (str1[i] == '\0') return -1; 
			if (str2[i] == '\0') return 1; 
			if (str1[i] < str2[i]) return -1; 
			if (str1[i] > str2[i]) return 1; 
		}
	}

	Book* searchBookByTitle(const char* title) {
		for (int i = 0; i < bookCount; i++) {
			if (compareStrings(books[i].getName(), title) == 0) {
				return &books[i];
			}
		}
		return nullptr;
	}

	Newspaper* searchNewspaperByName(const char* name) {
		for (int i = 0; i < newspaperCount; i++) {
			if (compareStrings(newspapers[i].getName(), name) == 0) {
				return &newspapers[i];
			}
		}
		return nullptr;
	}
};

int main() {
	Book book1("The Catcher in the Rye", "J.D. Salinger", 277);
	Book book2("To Kill a Mockingbird", "Harper Lee", 324);

	Newspaper newspaper1("Washington Post", "2024-10-13", "Morning Edition");
	Newspaper newspaper2("The Times", "2024-10-12", "Weekend Edition");

	Library library;

	library.addBook(book1);
	library.addBook(book2);
	library.addNewspaper(newspaper1);
	library.addNewspaper(newspaper2);

	cout << "Before Sorting:\n";
	library.displayCollection();

	library.sortBooksByPages();
	library.sortNewspapersByEdition();

	cout << "\nAfter Sorting:\n";
	library.displayCollection();

	Book* foundBook = library.searchBookByTitle("The Catcher in the Rye");
	if (foundBook) {
		cout << "\nFound Book:\n";
		foundBook->display();
	}
	else {
		cout << "\nBook not found.\n";
	}

	Newspaper* foundNewspaper = library.searchNewspaperByName("The Times");
	if (foundNewspaper) {
		cout << "\nFound Newspaper:\n";
		foundNewspaper->display();
	}
	else {
		cout << "\nNewspaper not found.\n";
	}
	system("pause");
	return 0;
}
