//
// Created by MG on 26/12/2023.
//
#include "Department.h"

void Departments::printDepartment() {
    for (auto item:emp) {
        cout << "Dep " << name << "\n which has " << emp.size() << " employees"
        << "and their names are: \n" << item.name << ' ';
    }
}