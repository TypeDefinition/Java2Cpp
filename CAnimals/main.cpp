#include <iostream>
#include <vector>
#include <type_traits>

using namespace std;

struct Animal {};

struct Bird : public Animal { void walk() {} };
struct Crow : public Bird { void fly() {} };
struct Penguin : public Bird { void swim() {} };

template <class T>
void foo(vector<T> vec) requires is_base_of_v<T, Penguin> {
	vec.push_back(T{}); // OK!
    vec.back().swim(); // Depends on T.
}

template <class T>
void bar(vector<T> vec) requires is_base_of_v<Bird, T> {
	vec.push_back(T{}); // OK!
	vec.back().walk(); // OK!
}

int main() {
    foo<Animal>({}); // Animal cannot swim!
    foo<Penguin>({}); // OK!

    bar<Bird>({}); // OK!
    bar<Penguin>({}); // OK!

    return 0;
}