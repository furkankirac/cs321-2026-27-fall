#include <iostream>

// operator overloading
// function objects
// lambda functions

using namespace std;

void just_do_it() { cout << "do it" << endl; }
void just_do_it(int times) {
    for(int i=0; i<times; i++)
        cout << "do it v2" << endl;
}

enum Color { // int
    RED, // = 0,
    GREEN, // = 1,
    BLUE // = 2
};

struct Output {
    Color color = RED;

    Output() { }
    Output(Color color_) : color(color_) { }

    // "Hi there" is a char[]
    const Output& operator<<(const char* arr) const
    {
        auto& self = *this;
        //this->color;
        // arr[0] = 'W';
        cout << arr;
        return self; // pointer dereferencing operator*
    }

    const Output& operator<<(int i) const {
        cout << i;
        return *this;
    }
};

// const Output& operator<<(const Output& o, const char* arr)
// {
//     // o.color = GREEN;
//     // arr[0] = 'W';
//     // o.color;
//     cout << arr;
//     return o;
// }

// const Output& operator<<(const Output& o, int i) { cout << i; return o; }

int main() {
    // cout << "Hi there"; // "Hi there" -> char[9] -> char*

    // Output output; // instantiate an object from Output
    auto output = Output();
    output << "Hi there" << 5 << "bla bla";
    // void << 5;


    // output << 5;
    // operator<<(output, "Hi there");

    // bool b = false;
    // bool not_b = !b; // ! is a unary operator
    // int a = -3;
    // int minus_a = -a; // - here is a unary operator

    // just_do_it();
    // just_do_it(3);

    return 0;
}
