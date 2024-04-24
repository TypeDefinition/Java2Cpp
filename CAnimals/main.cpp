#include <iostream>
#include <vector>

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

struct Insect : public Animal {
	virtual void crawl() {};
};
struct Ant : public Insect {};
struct Ladybird : public Insect {
	void fly() {}
};

struct Bird : public Animal {
	virtual void walk() {}
};
struct Penguin : public Bird {
	void swim() {}
};
struct Gentoo : public Penguin {};
struct Crow : public Bird {
	void fly() {}
};

struct Fish : public Animal {
	void swim() {}
};

template <class T>
void foo(vector<T> vec) {
	vec.push_back(T{});
	vec.back().walk();
}

template <class T>
void bar(vector<T> vec) {
	vec.push_back(T{});
	vec.back().crawl();
}

template <class T>
void baz(T animal) requires can_swim<T> {
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
	// Does not call fly().
}

int main()
{
	foo(vector<Bird>{});
	// foo(vector<Insect>()); // Cannot compile

	bar(vector<Insect>{});
	// bar(vector<Bird>{}); // Cannot compile.

	baz(Fish{}); // Invokes baz<T>.
	baz(Penguin{}); // Invokes baz<Penguin>.
	baz(Gentoo{}); // Invokes baz<T>.
	// baz(Ant{}); // Cannot compile.

	kee(Crow{});
	// kee(Fish{}); // Cannot compile.

	return 0;
}
