//
// Created by 谢潮斌 on 2022/5/20.
//

#pragma once

#include <iostream>
#include "worker.h"
#include <fstream>
using namespace std;
#ifndef EMPLOYEEMANAGEMENTSYSTEM_WORKERMANAGER_H
#define EMPLOYEEMANAGEMENTSYSTEM_WORKERMANAGER_H


class workerManager {
public:
    //构造函数
    workerManager();

    void Show_Menu();

    void save();

    //退出系统
    void exitSysten();

    //析构函数
    virtual ~workerManager();

    //添加员工
    void add_Emp();

    //统计人数
    int get_EmpNum();

    void init_Emp();

    void show_Emp();

    void del_Emp();

    int isExist(int id);

    //修改职工
    void Mod_Emp();

    void Find_Emp();

    void Sort_Emp();

    void Clean_File();

    int m_EmpNum;

    worker **m_EmpArray;

    bool m_FileIsEmpty;
};


#endif //EMPLOYEEMANAGEMENTSYSTEM_WORKERMANAGER_H
