//
// Created by 谢潮斌 on 2022/5/25.
//
#pragma once
#include<iostream>
using namespace std;


#ifndef APPOINTMENTSYSTEM_IDENTITY_H
#define APPOINTMENTSYSTEM_IDENTITY_H


//身份抽象类
class Identity
{
public:

    //操作菜单
    virtual void operMenu() = 0;

    string m_Name; //用户名
    string m_Pwd;  //密码
};


#endif //APPOINTMENTSYSTEM_IDENTITY_H
