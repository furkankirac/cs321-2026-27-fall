#include <iostream>
#include <string>
#include <vector>

struct Book {
    std::string title;
    std::string author;
    int year;

    Book(std::string t, std::string a, int y)
      : title(t), author(a), year(y) {}
};

struct Library {
    std::vector<Book> books_;

    void addBook(std::string title, std::string author, int year) {
        books_.push_back(Book(std::move(title), std::move(author), year));
    }

    int size() const { return static_cast<int>(books_.size()); }

    void print(const std::string& label) const {
        std::cout << label << " (contains " << size() << " book(s)):\n";
        for (std::size_t i = 0; i < books_.size(); ++i) {
            std::cout << "  #" << (i + 1) << ": \"" << books_[i].title
                      << "\" by " << books_[i].author
                      << " (" << books_[i].year << ")\n";
        }
    }
};

int main() {
    Library library;

    // Add at least 3 different books to one instance of the library
    library.addBook("The Great Gatsby", "F. Scott Fitzgerald", 1925);
    library.addBook("To Kill a Mockingbird", "Harper Lee", 1960);
    library.addBook("The Hobbit", "J. R. R. Tolkien", 1937);

    // Write all the contents of the library to the output
    library.print("Library contents");

    return 0;
}
