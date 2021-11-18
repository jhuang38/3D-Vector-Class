#include <iostream>
#include "vector_3d.cpp"

int main();


int main() {
    vector_3d a(1, 0, 0);
    vector_3d b(0, 1, 0);
    vector_3d c = cross_product(a, b);
    std::cout << c * 3 << std::endl;
    a = b;
    std::cout << a;
    return 0;
}
