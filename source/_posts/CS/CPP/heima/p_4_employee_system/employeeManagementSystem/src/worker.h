//
// Created by 谢潮斌 on 2022/5/20.
//
#pragma once
#include <iostream>
#include <string>

using namespace std;
#ifndef EMPLOYEEMANAGEMENTSYSTEM_WORKER_H
#define EMPLOYEEMANAGEMENTSYSTEM_WORKER_H


class worker {
public:
    int m_Id;
    string m_name;
    int m_DeptId;

    virtual void showInfo()=0;

    virtual string getDeptName() = 0;
};


#endif //EMPLOYEEMANAGEMENTSYSTEM_WORKER_H
