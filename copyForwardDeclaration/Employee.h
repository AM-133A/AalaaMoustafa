//
// Created by MG on 26/12/2023.
//
#include <vector>
#include <iostream>

using namespace std;
#ifndef COPYFORWARDDECLARATION_EMPLOYEE_H
#define COPYFORWARDDECLARATION_EMPLOYEE_H

struct Departments;
struct Employee{
    Employee(string _name);
    string name;
    void print();
    vector<Departments*>deps;
};

#endif //COPYFORWARDDECLARATION_EMPLOYEE_H
