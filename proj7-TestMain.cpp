#include "proj7-MyVector.h"

int main() {

    MyVector<int> a;

    cout << "Testing default constructor..." << endl;
    cout << "Size: " << a.getSize() << " should be 0" << endl;

    cout << "Testing pushBack function..." << endl;
    for (int i = 0; i < DEFAULT; i++) {

        a.pushBack(i);
    }

    a.pushFront(-1);
    cout << "If working correctly, should print out -1 -9 in order" << endl;
    for (int i = 0; i < a.getSize(); i ++) {
        cout << a[i] << " ";
    }
    cout << endl;

    cout << "Testing out the = operator..." << endl;
    MyVector<int> b;
    b = a;

    cout << "If working correctly, should print out -1 -9 in order" << endl;
    for (int i = 0; i < b.getSize(); i ++) {
        cout << b[i] << " ";
    }
    cout << endl;

    cout << "Testing out the copy constructor..." << endl;
    MyVector<int> c(a);

    cout << "If working correctly, should print out -1 -9 in order" << endl;
    for (int i = 0; i < c.getSize(); i++) {
        cout << c[i] << " ";
    }
    cout << endl;

    cout << "Testing the popBack function..." << endl;
    int pA;

    a.popBack(pA);
    cout << "The popBack value should be 0: " << pA << endl;

    cout << "Testing the popFront function..." << endl;
    int pB;

    b.popFront(pB);
    cout << "The popFront value should be -1: " << pB << endl;

    cout << "Testing the errase function..." << endl;
    c.erase();

    cout << "Size of the vector after erase function should be 0: ";
    cout << c.getSize() << endl;

    cout << "Testing the isEmpty function..." << endl;

    if (c.isEmpty()) {
        cout << "Should see this message if both the erase function and";
        cout << " isEmpty function both work properly!" << endl;
    }
    else {
        cout << "SHOULD NOT SEE THIS MESSAGE" << endl;
    }

    cout << "Testing the front function..." << endl;
    cout << "Should print out 0: " << b.front() << endl;

    cout << "Testing the back function..." << endl;
    cout << "Should print out 9: " << b.back() << endl;

    cout << "Testing the template..." << endl;
    MyVector<char> d;

    d.pushBack('h');
    d.pushBack('e');
    d.pushBack('l');
    d.pushBack('l');
    d.pushBack('o');

    cout << "If template char is allowed, ";
    cout << "\"hello\" should print to the screen: ";

    for (int i = 0; i < d.getSize(); i ++) {
        cout << d[i];
    }
    cout << endl;


    return 0;

}
