#include <iostream>
#include "identity.h"
#include <fstream>
#include <string>
#include "globalFile.h"
#include "student.h"
#include "teacher.h"
#include "manager.h"

using namespace std;


//学生菜单
void studentMenu(Identity * &student)
{
    while (true)
    {
        //学生菜单
        student->operMenu();

        Student* stu = (Student*)student;
        int select = 0;

        cin >> select;

        if (select == 1) //申请预约
        {
            stu->applyOrder();
        }
        else if (select == 2) //查看自身预约
        {
            stu->showMyOrder();
        }
        else if (select == 3) //查看所有预约
        {
            stu->showAllOrder();
        }
        else if (select == 4) //取消预约
        {
            stu->cancelOrder();
        }
        else
        {
            delete student;
            cout << "注销成功" << endl;
            system("read");//system("pause");windows
            system("clear");//system("cls");windows
            return;
        }
    }
}

//教师菜单
void TeacherMenu(Identity * &teacher)
{
    while (true)
    {
        //教师菜单
        teacher->operMenu();

        Teacher* tea = (Teacher*)teacher;
        int select = 0;

        cin >> select;

        if (select == 1)
        {
            //查看所有预约
            tea->showAllOrder();
        }
        else if (select == 2)
        {
            //审核预约
            tea->validOrder();
        }
        else
        {
            delete teacher;
            cout << "注销成功" << endl;
            system("read");//system("pause");windows
            system("clear");//system("cls");windows
            return;
        }

    }
}

//管理员菜单
void managerMenu(Identity *&manager) {
    while (true) {
        //管理员菜单
        manager->operMenu();

        Manager *man = (Manager *) manager;
        int select = 0;

        cin >> select;

        if (select == 1)  //添加账号
        {
            cout << "添加账号" << endl;
            man->addPerson();
        } else if (select == 2) //查看账号
        {
            cout << "查看账号" << endl;
            man->showPerson();
        } else if (select == 3) //查看机房
        {
            cout << "查看机房" << endl;
            man->showComputer();
        } else if (select == 4) //清空预约
        {
            cout << "清空预约" << endl;
            man->cleanFile();
        } else {
            delete manager;
            cout << "注销成功" << endl;
            system("read");//system("pause");windows
            system("clear");//system("cls");windows
            return;
        }
    }
}


//登录功能
void LoginIn(string fileName, int type) {

    Identity *person = NULL;

    ifstream ifs;
    ifs.open(fileName, ios::in);

    //文件不存在情况
    if (!ifs.is_open()) {
        cout << "文件不存在" << endl;
        ifs.close();
        return;
    }

    int id = 0;
    string name;
    string pwd;

    if (type == 1)    //学生登录
    {
        cout << "请输入你的学号" << endl;
        cin >> id;

    } else if (type == 2) //教师登录
    {
        cout << "请输入你的职工号" << endl;
        cin >> id;
    }

    cout << "请输入用户名：" << endl;
    cin >> name;

    cout << "请输入密码： " << endl;
    cin >> pwd;


    if (type == 1) {
        //学生登录验证
        int fId;
        string fName;
        string fPwd;
        while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
            if (id == fId && name == fName && pwd == fPwd) {
                cout << "学生验证登录成功!" << endl;
                system("read");
                system("clear");
                person = new Student(id, name, pwd);
                //进入学生子菜单
                studentMenu(person);
                return;
            }
        }
        //学生登录验证
    } else if (type == 2) {
        //教师登录验证
        int fId;
        string fName;
        string fPwd;
        while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
            if (id == fId && name == fName && pwd == fPwd) {
                cout << "教师验证登录成功!" << endl;
                system("read");
                system("clear");
                person = new Teacher(id, name, pwd);
                //进入教师子菜单
                TeacherMenu(person);
                return;
            }
        }
        //教师登录验证
    } else if (type == 3) {
        //管理员登录验证
        string fName;
        string fPwd;
        while (ifs >> fName && ifs >> fPwd) {
            if (name == fName && pwd == fPwd) {
                cout << "验证登录成功!" << endl;
                //登录成功后，按任意键进入管理员界面
                system("read");
                system("clear");
                //创建管理员对象
                person = new Manager(name, pwd);
                //进入管理员子菜单
                managerMenu(person);
                return;
            }
        }
        //管理员登录验证
    }

    cout << "验证登录失败!" << endl;

    system("read");
    system("clear");
    return;
}



int main() {
    int select;
    while (true) {


        cout << "======================  欢迎来到传智播客机房预约系统  ====================="
             << endl;
        cout << endl << "请输入您的身份" << endl;
        cout << "\t\t -------------------------------\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|          1.学生代表           |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|          2.老    师           |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|          3.管 理 员           |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|          0.退    出           |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t -------------------------------\n";
        cout << "输入您的选择: ";

        cin >> select;
        switch (select) {
            case 1:  //学生身份
                LoginIn(STUDENT_FILE, 1);
                break;
            case 2:  //老师身份
                LoginIn(TEACHER_FILE, 2);
                break;
            case 3:  //管理员身份
                LoginIn(ADMIN_FILE, 3);
                break;
            case 0:  //退出系统
                cout << "欢迎下一次使用" << endl;
                system("pause");
                return 0;
            default:
                cout << "输入有误，请重新选择！" << endl;
                system("read");//system("pause");windows
                system("clear");
                break;
        }
    }
    system("read");//system("pause");windows

    return 0;

}
