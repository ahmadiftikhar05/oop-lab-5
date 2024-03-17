#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Book {
private:
    string title;
    string author;
    int year;

public:
    Book(string title, string author, int year) : title(title), author(author), year(year) {}

    string getTitle() const {
        return title;
    }

    string getAuthor() const {
        return author;
    }

    int getYear() const {
        return year;
    }

    void display() const {
        cout << "Title: " << title << ", Author: " << author << ", Year: " << year << endl;
    }
};

class Library {
private:
    vector<Book> books;

public:
    void addBook(const Book& book) {
        books.push_back(book);
    }

    void removeBook(const string& title) {
        auto it = find_if(books.begin(), books.end(), [&](const Book& book) {
            return book.getTitle() == title;
            });

        if (it != books.end()) {
            books.erase(it);
            cout << "Book removed successfully." << endl;
        }
        else {
            cout << "Book not found." << endl;
        }
    }

    void listBooks() const {
        cout << "Listing all books in the library:" << endl;
        for (const Book& book : books) {
            book.display();
        }
    }
};
int main() {
    Library library;
    library.addBook(Book("The Great Gatsby", "F. Scott Fitzgerald", 1925));
    library.addBook(Book("To Kill a Mockingbird", "Harper Lee", 1960));
    library.addBook(Book("1984", "George Orwell", 1949));
    library.listBooks();
    library.removeBook("To Kill a Mockingbird");
    library.listBooks();
    return 0;
}