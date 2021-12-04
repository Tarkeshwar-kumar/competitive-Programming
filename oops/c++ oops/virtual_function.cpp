/*
 * A virtual function is a member function which is declared within a base class and is re-defined(Overridden) by a derived class
 * They are mainly used to achieve Runtime polymorphism
 * Functions are declared with a virtual keyword in base class.
 * The resolving of function call is done at Run-time.
 *
 * NOTE::
 * ->Virtual functions cannot be static.
 * ->A virtual function can be a friend function of another class.
 * ->Virtual functions should be accessed using pointer or reference of base class type to achieve run time polymorphism.
 * ->The prototype of virtual functions should be the same in the base as well as derived class.
 * ->They are always defined in the base class and overridden in a derived class. It is not mandatory for the derived class to
 *   override (or re-define the virtual function), in that case, the base class version of the function is used.
 * ->A class may have virtual destructor, but it cannot have a virtual constructor.
 *
 * Compile-time(early binding) VS run-time(late binding) behavior of Virtual Functions
 * ->Runtime polymorphism is achieved only through a pointer (or reference) of base class type.
 * ->Also, a base class pointer can point to the objects of base class as well as to the objects of derived class.
 * ->Late binding(Runtime) is done in accordance with the content of pointer (i.e. location pointed to by pointer) and Early
 *   binding(Compile time) is done according to the type of pointer.
 *->If we have created a virtual function in the base class and it is being overridden in the derived class then we don’t need
 *  virtual keyword in the derived class, functions are automatically considered as virtual functions in the derived class.
 */

/*
 * If a class contains a virtual function then compiler itself does two things:
 * ->If object of that class is created then a virtual pointer(VPTR) is inserted as a data member of the class to point to
 *   VTABLE of that class. For each new object created, a new virtual pointer is inserted as a data member of that class.
 * ->Irrespective of object is created or not, a static array of function pointer called VTABLE where each cell contains the
 *   address of each virtual function contained in that class.
 *
 */


//Initially, we create a pointer of type base class and initialize it with the address of the derived class object.


// CPP program to illustrate
// working of Virtual Functions
#include <iostream>
using namespace std;

class base {
public:
    void fun_1() { cout << "base-1\n"; }
    virtual void fun_2() { cout << "base-2\n"; }
    virtual void fun_3() { cout << "base-3\n"; }
    virtual void fun_4() { cout << "base-4\n"; }
};

class derived : public base {
public:
    void fun_1() { cout << "derived-1\n"; }
    void fun_2() { cout << "derived-2\n"; }
    void fun_4(int x) { cout << "derived-4\n"; }
};

int main()
{
    base* p;
    derived obj1;
    p = &obj1;

    // Early binding because fun1() is non-virtual
    // in base
    p->fun_1();

    // Late binding (RTP)
    p->fun_2();

    // Late binding (RTP)
    p->fun_3();

    // Late binding (RTP)
    p->fun_4();

    // Early binding but this function call is
    // illegal(produces error) because pointer
    // is of base type and function is of
    // derived class
    // p->fun_4(5);
}
// CPP program to illustrate
// working of Virtual Functions
#include <iostream>
using namespace std;

class base {
public:
    void fun_1() { cout << "base-1\n"; }
    virtual void fun_2() { cout << "base-2\n"; }
    virtual void fun_3() { cout << "base-3\n"; }
    virtual void fun_4() { cout << "base-4\n"; }
};

class derived : public base {
public:
    void fun_1() { cout << "derived-1\n"; }
    void fun_2() { cout << "derived-2\n"; }
    void fun_4(int x) { cout << "derived-4\n"; }
};

int main()
{
    base* p;
    derived obj1;
    p = &obj1;

    // Early binding because fun1() is non-virtual
    // in base
    p->fun_1();

    // Late binding (RTP)
    p->fun_2();

    // Late binding (RTP)
    p->fun_3();

    // Late binding (RTP)
    p->fun_4();

    // Early binding but this function call is
    // illegal(produces error) because pointer
    // is of base type and function is of
    // derived class
    // p->fun_4(5);
}
