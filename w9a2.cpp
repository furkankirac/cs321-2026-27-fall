#include <iostream>
#include <string>

// function objects
// lambda functions

using namespace std;

// function object
struct Callable {
    int times;

    Callable() : times() { }
    Callable(int times) : times(times) { }

    void what() const { }

    void operator() (/* const Callable* this, */ const string& text) const {
        for(int i=0; i<this->times; i++)
            cout << text << endl;
    }
};


int main() {
    auto callable = Callable(10);
    // callable.run();
    // callable("Hi there!!!"); // "Hi there!!!" -> char[12] -> char*
    // callable("Bye");
    // callable.operator()();

    auto lambda = [times=3](const string& text) {
        for(int i=0; i<times; i++)
            cout << text << endl;
    };

    lambda("Hi lambda");


    return 0;
}
