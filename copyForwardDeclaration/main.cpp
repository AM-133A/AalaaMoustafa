#include <iostream>
using namespace std;
#include "Employee.h"
#include "Department.h"
int main() {
    Employee e1("Mohsen");
    Employee e2("Abd Alssamad");
    Departments *d1 = new Departments;
    d1->name = "DS";
    d1->emp.push_back(e1);
    e1.deps.push_back(d1);
    e1.print();
    return 0;
}
