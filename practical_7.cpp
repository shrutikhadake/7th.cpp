//inheritance
#include <iostream>

using namespace std;

class BaseException : public exception {
public:
    BaseException(const string& message) : message(message) {}

    virtual const string& what() const override {
        return message;
    }

private:
    string message;
};

class DerivedException : public BaseException {
public:
    DerivedException(const string& message) : BaseException(message) {}
};

class Person {
public:
    void validateAge(int age) {
        if (age < 0 || age > 120) {
            throw DerivedException("Invalid age: " + to_string(age));
        }
    }
};

class Employee : public Person {
public:
    void validateEmployee(int age, const string& title) {
        Person::validateAge(age);
        if (title.empty()) {
            throw BaseException("Employee must have a title");
        }
    }
};

int main() {
    try {
        Employee employee;
        employee.validateEmployee(-1, "");
    } catch (const BaseException& e) {
        cout << "Base exception: " << e.what() << endl;
    } catch (const DerivedException& e) {
        cout << "Derived exception: " << e.what() << endl;
    } catch (const exception& e) {
        cout << "Unexpected exception: " << e.what() << endl;
    }

    return 0;
}


//Exception handling
#include <iostream>

using namespace std;

int divide(int x, int y) {
    if (y == 0) {
        throw exception(); // Throw an exception if y is 0
    }

    return x / y;
}

int main() {
    try {
        int result = divide(10, 0); // Will throw an exception
        cout << "Result: " << result << endl;
    } catch (exception& e) {
        cout << "Error: Division by zero" << endl;
    }

    return 0;
}

//friend function
#include <iostream>

using namespace std;

class Data {
private:
    int value;

public:
    Data(int value) : value(value) {}

    friend void validateData(Data& data) {
        if (data.value < 0) {
            throw invalid_argument("Data value cannot be negative");
        }
    }

    void print() const {
        cout << "Value: " << value << endl;
    }
};

int main() {
    try {
        Data data(-10); // Data value is negative
        validateData(data);
    } catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}


//Virtual function
C++
#include <iostream>

using namespace std;

class Shape {
public:
    virtual double getArea() const = 0;
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double radius) : radius(radius) {}

    double getArea() const override {
        if (radius <= 0) {
            throw invalid_argument("Radius must be positive");
        }

        return radius * radius * 3.14159;
    }
};

class Rectangle : public Shape {
private:
    double length, width;

public:
    Rectangle(double length, double width) : length(length), width(width) {}

    double getArea() const override {
        if (length <= 0 || width <= 0) {
            throw invalid_argument("Length and width must be positive");
        }

        return length * width;
    }
};

int main() {
    try {
        Shape* shapes[] = {new Circle(-1), new Rectangle(-2, 3)};

        for (Shape* shape : shapes) {
            cout << "Area: " << shape->getArea() << endl;
            delete shape;
        }
    } catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
