#include <iostream>
using namespace std;
class Employee {
public:
	virtual double calculateSalary() const = 0; 
	virtual ~Employee() {} 
};

class FullTimeEmployee : public Employee {
private:
	double fixedSalary;

public:
	FullTimeEmployee(double salary) : fixedSalary(salary) {} 

	double calculateSalary() const override { 
		return fixedSalary; 
	}
};

class PartTimeEmployee : public Employee {
private:
	double hoursWorked;
	double hourlyRate;

public:
	PartTimeEmployee(double hours, double rate) : hoursWorked(hours), hourlyRate(rate) {} 
	double calculateSalary() const override {
		return hoursWorked * hourlyRate; 
	}
};

int main() {
	FullTimeEmployee fullTime(35000);
	cout << "Full-Time Employee Salary:" << fullTime.calculateSalary() << endl;

	PartTimeEmployee partTime(30, 20);
	cout << "Part-Time Employee Salary:" << partTime.calculateSalary() << endl;
	system("pause");
	return 0;
}
