//
// Created by 谢潮斌 on 2022/5/20.
//
#include "string"
#include "iostream"
#include "worker.h"
#ifndef EMPLOYEEMANAGEMENTSYSTEM_EMPLOYEE_H
#define EMPLOYEEMANAGEMENTSYSTEM_EMPLOYEE_H


class employee :public worker {
public:
    employee(int id, string name, int dId);


    void showInfo() override;

    string getDeptName() override;

};


#endif //EMPLOYEEMANAGEMENTSYSTEM_EMPLOYEE_H
