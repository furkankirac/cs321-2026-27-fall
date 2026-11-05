#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>


int do_smt(float f) {
    static bool init = false;
    if(!init) {
        init = true;
        std::cout << "Initializing" << std::endl;
    }
    return f + 1.1f;
}


int main() {
    float a = 3.14f;
    int b = do_smt(a);

    int c = 123;

    // C way of dynamic runtime allocation
    {
        int* ptr = (int *)malloc(1000000 * sizeof(int));
        ptr[10] = 5;
        free(ptr);
    }

    // legacy C++ way of doing it
    {
        int* ptr = new int[1000000];
        ptr[10] = 5;
        delete[] ptr;
    }
    {
        int* ptr = new int;
        ptr[0] = 5;
        delete ptr;
    }

    // new way of doing it
    {
        auto ints = std::vector<int>(1000000);
    }
    // here is where ints got destructed


    return 0;
}
