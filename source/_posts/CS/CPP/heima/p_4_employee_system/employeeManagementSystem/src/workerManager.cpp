//
// Created by 谢潮斌 on 2022/5/20.
//

#include "workerManager.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

#define  FILENAME "empFile.txt"

workerManager::workerManager() {
    //文件不存在
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    if (!ifs.is_open()) {
        cout << "文件不存在" << endl;
        this->m_EmpNum = 0;
        //初始化
        this->m_EmpArray = NULL;
        this->m_FileIsEmpty = true;
        ifs.close();
        return;
    }
    //文件存在,文件为空
    char ch;
    ifs >> ch;
    if (ifs.eof()) {
        cout << "文件为空" << endl;
        this->m_EmpNum = 0;
        //初始化
        this->m_EmpArray = NULL;
        this->m_FileIsEmpty = true;
        ifs.close();
        return;
    }

    //文件存在,并有数据
    int num = this->get_EmpNum();
    cout << "员工人数为" << num << endl;
    this->m_EmpNum = num;
    this->m_FileIsEmpty = false;
    this->m_EmpArray = new worker *[this->m_EmpNum];

    this->init_Emp();

    for (int i = 0; i < this->m_EmpNum; i++) {
        cout << "\tid--> " << this->m_EmpArray[i]->m_Id
             << "\tname--> " << this->m_EmpArray[i]->m_name
             << "\tdepid--> " << this->m_EmpArray[i]->m_DeptId << endl;

    }

}

workerManager::~workerManager() {
    if (this->m_EmpArray != NULL) {
        delete[] this->m_EmpArray;
        this->m_EmpArray = NULL;
    }
}

void workerManager::Show_Menu() {
    cout << "********************************************" << endl;
    cout << "*********  欢迎使用职工管理系统！ **********" << endl;
    cout << "*************  0.退出管理程序  *************" << endl;
    cout << "*************  1.增加职工信息  *************" << endl;
    cout << "*************  2.显示职工信息  *************" << endl;
    cout << "*************  3.删除离职职工  *************" << endl;
    cout << "*************  4.修改职工信息  *************" << endl;
    cout << "*************  5.查找职工信息  *************" << endl;
    cout << "*************  6.按照编号排序  *************" << endl;
    cout << "*************  7.清空所有文档  *************" << endl;
    cout << "********************************************" << endl;
    cout << endl;
}

void workerManager::exitSysten() {
    cout << "退出程序,欢迎下次使用" << endl;
//    system("read");//system("pause");windows
//    system("clear");//system("cls");windows
    exit(0);//无论在程序哪里调用,都会退出程序
}

void workerManager::add_Emp() {
    cout << "请输入添加员工的数量" << endl;
    int addNum = 0;
    cin >> addNum;
    if (addNum > 0) {
        int newSize = this->m_EmpNum + addNum;
        worker **newSpace = new worker *[newSize];

        //将原来的空间的数据,拷贝到新的空间
        if (this->m_EmpArray != NULL) {
            for (int i = 0; i < this->m_EmpNum; i++) {
                newSpace[i] = this->m_EmpArray[i];
            }
        }

        //添加新的数据
        for (int i = 0; i < addNum; i++) {
            int id;
            string name;
            int dSelect;

            cout << "请输入第 " << i + 1 << " 个新职工编号：" << endl;
            cin >> id;


            cout << "请输入第 " << i + 1 << " 个新职工姓名：" << endl;
            cin >> name;

            cout << "请选择岗位" << endl;
            cout << "1.普通职工" << endl;
            cout << "2.管理者" << endl;
            cout << "3.老板" << endl;
            cin >> dSelect;//todo:这里需要注意如果不是输入123,需要提示重新输入,还有可能死循环


            worker *wk = NULL;
            switch (dSelect) {
                case 1:
                    wk = new employee(id, name, dSelect);
                    break;
                case 2:
                    wk = new manager(id, name, dSelect);
                    break;
                case 3:
                    wk = new boss(id, name, dSelect);
                    break;
                default:
                    cout << "只能输入1~3,请重新输入" << endl;
            }


            //职工保存到数组中
            newSpace[this->m_EmpNum + i] = wk;

        }
        //鸠占鹊巢
        delete this->m_EmpArray;
        this->m_EmpArray = newSpace;

        this->m_EmpNum = newSize;
        cout << "成功添加了" << newSize << "名员工" << endl;
        this->m_FileIsEmpty = false;
        this->save();
    } else {
        cout << "数量输入有误,重新输入" << endl;

    }

}

void workerManager::save() {
    ofstream ofs;

    ofs.open(FILENAME, ios::out);
    for (int i = 0; i < this->m_EmpNum; i++) {
        ofs << this->m_EmpArray[i]->m_Id << "\t"
            << this->m_EmpArray[i]->m_name << "\t"
            << this->m_EmpArray[i]->m_DeptId << endl;
    }
    ofs.close();

}

int workerManager::get_EmpNum() {
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    int id;
    string name;
    int did;
    int num = 0;

    while (ifs >> id && ifs >> name && ifs >> did) {
        num++;
    }
    return num;

}

void workerManager::init_Emp() {
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    int id;
    string name;
    int did;
    int index;

    while (ifs >> id && ifs >> name && ifs >> did) {
        worker *w = NULL;
        if (did == 1) {
            w = new employee(id, name, did);
        } else if (did == 2) {
            w = new manager(id, name, did);
        } else if (did == 3) {
            w = new boss(id, name, did);
        }
        this->m_EmpArray[index++] = w;
    }
    ifs.close();
    return;
}

void workerManager::show_Emp() {
    if (this->m_FileIsEmpty) {
        cout << "文件不存在,或者记录为空" << endl;
    } else {
        for (int i = 0; i < this->m_EmpNum; i++) {
            //多态
            this->m_EmpArray[i]->showInfo();
        }
    }
    system("read");//system("pause");windows
    system("clear");//system("cls");windows
}

void workerManager::del_Emp() {
    if (this->m_FileIsEmpty) {
        cout << "文件不存在,或者记录为空" << endl;
    } else {
        cout << "请输入想要删除的员工id" << endl;
        int id;
        cin >> id;
        int index = this->isExist(id);
        if (index != -1) {
            for (int i = index; i < this->m_EmpNum - 1; i++) {
                this->m_EmpArray[i] = this->m_EmpArray[i + 1];
            }
            this->m_EmpNum--;
            this->save();
            cout << "删除成功" << endl;
        } else {
            cout << "删除失败,找不到该员工" << endl;
        }
    }
    system("read");//system("pause");windows
    system("clear");//system("cls");windows
}

//判断员工id是否存在,存在返回index,不存在返回0
int workerManager::isExist(int id) {
    for (int i = 0; i < this->m_EmpNum; i++) {
        if (this->m_EmpArray[i]->m_Id == id) {
            return i;
        }
    }
    return -1;
}

//修改职工
void workerManager::Mod_Emp() {
    if (this->m_FileIsEmpty) {
        cout << "文件不存在或记录为空！" << endl;
    } else {
        cout << "请输入修改职工的编号：" << endl;
        int id;
        cin >> id;

        int ret = this->isExist(id);
        if (ret != -1) {
            //查找到编号的职工

            delete this->m_EmpArray[ret];

            int newId = 0;
            string newName = "";
            int dSelect = 0;

            cout << "查到： " << id << "号职工，请输入新职工号： " << endl;
            cin >> newId;

            cout << "请输入新姓名： " << endl;
            cin >> newName;

            cout << "请输入岗位： " << endl;
            cout << "1、普通职工" << endl;
            cout << "2、经理" << endl;
            cout << "3、老板" << endl;
            cin >> dSelect;

            worker *worker = NULL;
            switch (dSelect) {
                case 1:
                    worker = new employee(newId, newName, dSelect);
                    break;
                case 2:
                    worker = new manager(newId, newName, dSelect);
                    break;
                case 3:
                    worker = new boss(newId, newName, dSelect);
                    break;
                default:
                    break;
            }

            //更改数据 到数组中
            this->m_EmpArray[ret] = worker;

            cout << "修改成功！" << endl;

            //保存到文件中
            this->save();
        } else {
            cout << "修改失败，查无此人" << endl;
        }
    }

    //按任意键 清屏
    system("read");//system("pause");windows
    system("clear");//system("cls");windows
}

void workerManager::Find_Emp() {

    if (this->m_FileIsEmpty) {
        cout << "文件不存在或记录为空！" << endl;
    } else {
        cout << "请输入查找的方式：" << endl;
        cout << "1、按职工编号查找" << endl;
        cout << "2、按姓名查找" << endl;

        int select = 0;
        cin >> select;


        if (select == 1) //按职工号查找
        {
            int id;
            cout << "请输入查找的职工编号：" << endl;
            cin >> id;

            int ret = isExist(id);
            if (ret != -1) {
                cout << "查找成功！该职工信息如下：" << endl;
                this->m_EmpArray[ret]->showInfo();
            } else {
                cout << "查找失败，查无此人" << endl;
            }
        } else if (select == 2) //按姓名查找
        {
            string name;
            cout << "请输入查找的姓名：" << endl;
            cin >> name;

            bool flag = false;  //查找到的标志
            for (int i = 0; i < m_EmpNum; i++) {
                if (m_EmpArray[i]->m_name == name) {
                    cout << "查找成功,职工编号为："
                         << m_EmpArray[i]->m_Id
                         << " 号的信息如下：" << endl;

                    flag = true;

                    this->m_EmpArray[i]->showInfo();
                }
            }
            if (flag == false) {
                //查无此人
                cout << "查找失败，查无此人" << endl;
            }
        } else {
            cout << "输入选项有误" << endl;
        }

    }
    system("read");//system("pause");windows
    system("clear");//system("cls");windows

}

void workerManager::Sort_Emp() {
    if (this->m_FileIsEmpty) {
        cout << "文件不存在或记录为空！" << endl;
        system("pause");
        system("cls");
    } else {
        cout << "请选择排序方式： " << endl;
        cout << "1、按职工号进行升序" << endl;
        cout << "2、按职工号进行降序" << endl;
        int select = 0;
        cin >> select;
        //选择排序
        for (int i = 0; i < m_EmpNum; i++) {
            int minOrMax = i;
            for (int j = i + 1; j < m_EmpNum; j++) {
                if (select == 1) {//升序
                    if (m_EmpArray[minOrMax]->m_Id > m_EmpArray[j]->m_Id) {
                        minOrMax = j;
                    }
                } else {
                    if (m_EmpArray[minOrMax]->m_Id < m_EmpArray[j]->m_Id) {
                        minOrMax = j;
                    }
                }
            }
            if (i != minOrMax) {
                worker *temp = m_EmpArray[i];
                m_EmpArray[i] = m_EmpArray[minOrMax];
                m_EmpArray[minOrMax] = temp;
            }


        }
        cout << "排序成功,排序后结果为：" << endl;
        this->save();
        this->show_Emp();

    }

}

void workerManager::Clean_File() {
    cout << "确认清空？" << endl;
    cout << "1、确认" << endl;
    cout << "2、返回" << endl;

    int select = 0;
    cin >> select;

    if (select == 1) {
        //如果存在文件,删除并重新创建
        ofstream ofs(FILENAME, ios::trunc);
        ofs.close();
        //删掉所有的数据
        if (this->m_EmpArray != NULL) {
            for (int i = 0; i < this->m_EmpNum; i++) {
                if (this->m_EmpArray[i] != NULL) {
                    delete this->m_EmpArray[i];
                }
            }
            this->m_EmpNum = 0;
            delete[] this->m_EmpArray;
            this->m_EmpArray = NULL;
            this->m_FileIsEmpty = true;
            cout << "清空成功" << endl;

        }
    }
    system("read");//system("pause");windows
    system("clear");//system("cls");windows

}

