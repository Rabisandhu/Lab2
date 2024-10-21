#include <iostream>
using namespace std;
class Shape {
public:
	virtual double area() const = 0; 
	virtual ~Shape() {} 
};

class Circle : public Shape {
private:
	double radius;
	float pi = 3.14;
public:
	Circle(double r) : radius(r) {} 

	double area() const override { 
		return pi * radius * radius; 
	}
};

class Rectangle : public Shape {
private:
	double length;
	double width;

public:
	Rectangle(double l, double w) : length(l), width(w) {} 

	double area() const override { 
		return length * width; 
	}
};

int main() {
	Circle circle(8.0);
	cout << "Area of Circle: " << circle.area() << endl;

	Rectangle rectangle(6.0, 10.0);
	cout << "Area of Rectangle: " << rectangle.area() << endl;
	system("pause");
	return 0;
}
