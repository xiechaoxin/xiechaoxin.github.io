//
// Created by 谢潮斌 on 2022/5/20.
//

#include "employee.h"

void employee::showInfo() {

    cout << "id--> " << this->m_Id
         << "\tname--> " << this->m_name
         << "\tdeptId--> " << this->getDeptName() << endl;

}

string employee::getDeptName() {

    return string("员工");

}

employee::employee(int id, string name, int dId) {

    this->m_Id = id;
    this->m_name = name;
    this->m_DeptId = dId;

}


