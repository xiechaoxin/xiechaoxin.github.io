//
// Created by 谢潮斌 on 2022/5/20.
//

#include "manager.h"


void manager::showInfo() {
    cout << "id--> " << this->m_Id
         << "\tname--> " << this->m_name
         << "\tdeptId--> " << this->getDeptName() << endl;

}

string manager::getDeptName() {

    return string("管理者");
}

manager::manager(int id, string name, int dId) {
    this->m_Id = id;
    this->m_name = name;
    this->m_DeptId = dId;

}

