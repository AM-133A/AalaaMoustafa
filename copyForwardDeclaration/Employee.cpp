//
// Created by MG on 26/12/2023.
//
#include "Employee.h"
#include "Department.h"
Employee::Employee(string _name) {
    name = _name;
}

void Employee::print() {
    cout << "My name is: " << name << " and departments I work on are: \n";
    for (auto d : deps) {
        d->printDepartment();
    }
}