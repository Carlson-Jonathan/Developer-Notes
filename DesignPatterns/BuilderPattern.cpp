/***************************************************************************************************
 *                                        The Builder Pattern
 *  
 * Builders add a more dynamic touch to object creation. In the example below, we can create unique, 
 * yet immutable objects by cherry-picking their setup functions. What makes the builder pattern 
 * special is the combination of features that allow you to accomplish things that ordinary code 
 * style would not. Though each of these features individually can be easily subsituted by more 
 * effective code, the combination of these features allow use to create some interesting things 
 * that would otherwise be very difficult to create. Here are some interesting things to note about 
 * the builder pattern:
 * 
 * - Builder classes are typically nested inside parent classes making a sort-of super constructor.
 *   Nesting the class in this fasion keeps everything neat and tidy and avoids namespace clutter.
 * 
 * - Creating a new object using the builder pattern allows you to cherry-pick which function to 
 *   call while setting up your object. This allows for the creation of more unique objects.
 * 
 * - Using the builder pattern, you can create objects that are immutable after their
 *   initialization, yet customizable durring creation. Try doing that through ordinary methods!
 * 
 * - The unique function call chains during object creation can provide additional information and
 *   readability assuming your functions are all well-named.
 * 
 **************************************************************************************************/ 


#include <iostream>
using namespace std;

class ComplexObject {
private:
    int a, b, c, d;
    std::string e;

    ComplexObject(int a, int b, int c, int d, std::string e)
        : a(a), b(b), c(c), d(d), e(e) {}

public:
    class Builder {
    private:
        int a = 0, b = 0, c = 0, d = 0;
        std::string e = "";

    public:
        Builder& setA(int a) { this->a = a; return *this; }
        Builder& setB(int b) { this->b = b; return *this; }
        Builder& setC(int c) { this->c = c; return *this; }
        Builder& setD(int d) { this->d = d; return *this; }
        Builder& setE(const std::string& e) { this->e = e; return *this; }

        ComplexObject build() {
            return ComplexObject(a, b, c, d, e);
        }
    };

    void printValues() {
        cout
            << "a = " << a
            << "\nb = " << b
            << "\nc = " << c
            << "\n\n";
    }
};

int main() {

    ComplexObject object = ComplexObject::Builder().setA(4).setB(3).setC(6).build();
    object.printValues();
    return 0;
}