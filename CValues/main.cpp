#include <iostream>

using namespace std;

template <int N>
void print_number() {
    cout << "Printing the number: " << N << endl;
}

int main() {
    print_number<1>(); // Printing the number: 1
    print_number<2>(); // Printing the number: 2
    print_number<3>(); // Printing the number: 3

    return 0;
}