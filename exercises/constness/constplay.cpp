#include <iostream>
#include <string>

/* This is a dummy function to demonstrate pass by value.
 * Since it doesn't do anything with the argument, we suppress
 * possible compiler warnings using `maybe_unused`.
 */
void copy(int a) {
    [[maybe_unused]] int val = a;
}

void copyConst(const int a) {
    [[maybe_unused]] int val = a;
}

void write(int* a) {
    *a = 42;
}
void write(int& a) {
    a = 42;
}

void read(const int* a) {
    [[maybe_unused]] int val = *a;
}
void read(int const & a) {
    [[maybe_unused]] int val = a /* = 2 */; // заборонено присвоєння, якщо аргумент const
}

struct Test {
    void hello(std::string &s) {
        std::cout << "Hello " << s << '\n';
    }
    void helloConst(std::string &s) const {
        std::cout << "Hello " << s << '\n';
    }
};

int main() {
    // try pointer to constant
    int a = 1, b = 2;
    int const *i = &a;
    // *i = 5; // не можна змінювати значення через вказівник на const
    i = &b;

    // try constant pointer
    int * const j = &a;
    *j = 5;
    // j = &b; // j є const-вказівником, не можна переназначити

    // try constant pointer to constant
    int const * const k = &a;
    // *k = 5; // значення за адресою не можна змінити
    // k = &b; // не можна переназначити const-вказівник

    // try constant arguments of functions
    int l = 0;
    const int m = 0;
    copy(l);
    copy(m);
    copyConst(l);
    copyConst(m);

    // try constant arguments of functions with pointers
    {
      int *p = &a;
      const int *r = &b;
      write(p);
      // write(r); // write приймає int*, але r є const int*
      read(p);
      read(r);
    }

    // try constant arguments of functions with references
    {
      int p = 0;
      const int r = 0;
      // write(2); // не можна створити неконстантне посилання на тимчасове значення
      // write(r); // write приймає посилання на int, але r є const
      // read(2); // не можна створити посилання на тимчасове значення з const int&
      read(r);
    }

    // try constant method in a class
    Test t;
    const Test tc;
    std::string s("World");
    t.hello(s);
    // tc.hello(s); // метод hello не є const, не можна викликати на const-об'єкті
    t.helloConst(s);
    tc.helloConst(s);

    return 0;
}
