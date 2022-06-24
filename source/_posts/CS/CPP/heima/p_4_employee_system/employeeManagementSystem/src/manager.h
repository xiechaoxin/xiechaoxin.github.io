//
// Created by 谢潮斌 on 2022/5/20.
//
#include "string"
#include "iostream"
#include "worker.h"
#ifndef EMPLOYEEMANAGEMENTSYSTEM_MANAGER_H
#define EMPLOYEEMANAGEMENTSYSTEM_MANAGER_H


class manager :public worker {
public:
    manager(int id, string name, int dId);


    void showInfo() override;

    string getDeptName() override;

};


#endif //EMPLOYEEMANAGEMENTSYSTEM_MANAGER_H
