//
// Created by 谢潮斌 on 2022/5/21.
//
#include "string"
#include "iostream"
#include "worker.h"

#ifndef EMPLOYEEMANAGEMENTSYSTEM_BOSS_H
#define EMPLOYEEMANAGEMENTSYSTEM_BOSS_H


class boss :public worker{
public:
    boss(int id, string name, int dId);



    void showInfo() override;

    string getDeptName() override;
};


#endif //EMPLOYEEMANAGEMENTSYSTEM_BOSS_H
