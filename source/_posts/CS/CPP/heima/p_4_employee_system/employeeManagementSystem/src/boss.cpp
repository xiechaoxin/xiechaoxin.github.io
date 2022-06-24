//
// Created by 谢潮斌 on 2022/5/21.
//

#include "boss.h"

boss::boss(int id, string name, int dId) {

    this->m_Id = id;
    this->m_name = name;
    this->m_DeptId = dId;
}

void boss::showInfo() {
    cout << "id--> " << this->m_Id
         << "\tname--> " << this->m_name
         << "\tdeptId--> " << this->getDeptName() << endl;

}

string boss::getDeptName() {
    return string("老板");

}
