#include <iostream>
#include <string>
#include <vector>

// # sign means that we're using Macro Preprocessor of C

// Dennis Ritchie (inventor of C)
// confessed that Macro Preprocessor was a horrible design decision

struct Book {
    std::string title;
    Book() : title() { }
    Book(std::string title_) : title(title_) { }
};

struct File {

};

template <typename T>
struct Library {
    std::vector<T> items;
    Library() : items() { }
    void push(const T& t) {
        items.emplace_back(t);
    }
};


// struct LibraryOfBooks {
//     std::vector<Book> items;
//     LibraryOfBooks() : items() { }
//     void push(const Book& b) {
//         items.emplace_back(b);
//     }
// };

// struct LibraryOfFiles {
//     std::vector<File> items;
//     void push(const File& b) {
//         items.emplace_back(b);
//     }
// };



int main() {
    // this is living in stack memory (no new operator)
    // auto lib_books = LibraryOfBooks(); // default c-tor
    auto lib_books = Library<Book>(); // default c-tor
    auto b = Book("Lord of the Rings"); // book instance is living on the stack
    lib_books.push(b);

    //LibraryOfFiles* lib_files_ptr = new LibraryOfFiles(); // default c-tor
    auto lib_files_ptr = new Library<File>(); // default c-tor

    return 0;
}
