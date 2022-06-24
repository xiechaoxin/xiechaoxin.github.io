#include <iostream>
#include "src/workerManager.h"
#include "src/worker.h"
#include "src/boss.h"
#include "src/employee.h"
#include "src/manager.h"
using namespace std;

int main() {
    workerManager wm;

//    worker *wk = new employee(1, "zhangsan", 1);
//    wk->showInfo();
//    worker *wk1 = new boss(1, "我是老板", 1);
//    wk1->showInfo();
//    worker *wk2 = new manager(1, "我是管理者", 1);
//    wk2->showInfo();
    int choice = 0;
    while (1) {
        wm.Show_Menu();
        cout << "请输入您的选择" << endl;
        cin >> choice;
        switch (choice) {
            case 0://退出系统
                wm.exitSysten();
                break;
            case 1://增加职工信息
                wm.add_Emp();
                break;
            case 2:
                wm.show_Emp();
                break;
            case 3:
                wm.del_Emp();
                break;
            case 4:
                wm.Mod_Emp();
                break;
            case 5:
                wm.Find_Emp();
                break;
            case 6:
                wm.Sort_Emp();
                break;
            case 7:
                wm.Clean_File();
                break;
            default:
                system("clear");//system("cls");windows;
                break;
        }
    }

    wm.Show_Menu();
    return 0;
}
