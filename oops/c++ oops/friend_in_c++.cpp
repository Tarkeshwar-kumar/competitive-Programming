
/*
 * A friend class can access private and protected members of other class in which it is declared as friend.
 * Friend Function Like friend class, a friend function can be given a special grant to access private and protected members.
 * A friend function can be:
 * ->A member of another class
 * ->A global function
 *
 *  Friendship is not mutual. If class A is a friend of B, then B doesn’t become a friend of A automatically.
 *  Friendship is not inherited.
 *  ->If a base class has a friend function, then the function doesn’t become a friend of the derived class(es).
 */
#include <iostream>
class A {
private:
    int a;

public:
    A() { a = 0; }
    //friend class B; // Friend Class
};

class B {
private:
    int b;

public:
    void showA(A& x)
    {
        // Since B is friend of A, it can access
        // private members of A
        std::cout << "A::a=" << x.a;
    }
};

int main()
{
    A a;
    B b;
    b.showA(a);
    return 0;
}
