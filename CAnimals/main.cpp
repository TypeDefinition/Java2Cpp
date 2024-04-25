#include <iostream>
#include <vector>
#include <type_traits>

using namespace std;

template <class T>
concept can_swim = requires(T animal) {
	{ animal.swim() };
};

template <class T>
concept can_fly = requires(T animal) {
	{ animal.fly() };
};

struct Animal {};

struct Insect : public Animal { void crawl() {}; };
struct Ant : public Insect {};
struct Ladybird : public Insect { void fly() {} };

struct Bird : public Animal { void walk() {} };
struct Crow : public Bird { void fly() {} };
struct Penguin : public Bird { void swim() {} };
struct Gentoo : public Penguin {};

struct Fish : public Animal { void swim() {} };

template <class T>
void foo(vector<T> vec) requires is_base_of_v<T, Penguin> {
	cout << "foo<T>" << endl;
	vec.push_back(T{});
	vec.back().walk();
}

template <class T>
void bar(vector<T> vec) requires is_base_of_v<Insect, T> {
	cout << "bar<T>" << endl;
	vec.push_back(T{});
	vec.back().crawl();
}

template <class T>
void baz(T animal) {
	cout << "baz<T>" << endl;
	animal.swim();
}

template <>
void baz(Penguin animal) {
	cout << "baz<Penguin>" << endl;
	animal.swim();
}

template <class T>
void kee(T animal) requires can_fly<T> {
	cout << "kee<T>" << endl;
	// Does not even call fly().
}

template <int N>
void print_number() {
	cout << "Printing the number " << N << "." << endl;
}

int main()
{
	print_number<1>();
	print_number<2>();
	print_number<5>();

	return 0;
}
