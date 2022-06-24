//
// Created by 谢潮斌 on 2022/5/25.
//
#pragma once
#include<iostream>
#include <vector>

using namespace std;
#include "identity.h"
#include "computerRoom.h"
#include "fstream"
#include "globalFile.h"


#ifndef APPOINTMENTSYSTEM_STUDENT_H
#define APPOINTMENTSYSTEM_STUDENT_H


class Student: public Identity{

public:
    Student();


//有参构造(学号、姓名、密码)
    Student(int id, string name, string pwd);

    //菜单界面
    virtual void operMenu();

    //申请预约
    void applyOrder();

    //查看我的预约
    void showMyOrder();

    //查看所有预约
    void showAllOrder();

    //取消预约
    void cancelOrder();

    //学生学号
    int m_Id;

    vector<ComputerRoom> vCom;

};


#endif //APPOINTMENTSYSTEM_STUDENT_H
