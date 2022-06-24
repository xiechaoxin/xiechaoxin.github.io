#include <iostream>

#define MAX_CNT 1000 //最大人数
using namespace std;


// struct person
struct Person {
    string m_Name;
    int m_Sex;
    int m_Age;
    string m_Phone;
    string m_Addr;
};

// struct address book
struct Addressbooks {
    struct Person personArray[MAX_CNT];
    int m_Size;
};


void addPerson(Addressbooks *pAddressbooks);

void showPerson(Addressbooks *pAddressbooks);

void delPerson(Addressbooks *abs);

int isExist(Addressbooks *abs, string name);

void findPerson(Addressbooks *abs);

void findPerson(Addressbooks *abs);


void modifyPerson(Addressbooks *abs);

void delAllPerson(Addressbooks *abs);

// show menu
void showMenu() {
    cout << "==== address book ====" << endl;
    cout << "1. add ontact" << endl;
    cout << "2. show contact" << endl;
    cout << "3. del contact" << endl;
    cout << "4. find contact" << endl;
    cout << "5. modify contact" << endl;
    cout << "6. del all contact" << endl;
    cout << "0. exit" << endl;
}

// add person
void addPerson(Addressbooks *abs) {
    if (abs->m_Size == MAX_CNT) {
        cout << "通讯录已满,无法添加" << endl;
        return;
    } else {
        string name;
        cout << "请输入名称:" << endl;
        cin >> name;
        abs->personArray[abs->m_Size].m_Name = name;

        cout << "请输入性别:" << endl;
        cout << "1->男:" << endl;
        cout << "2->女:" << endl;
        int sex = 0;
        while (1) {
            cin >> sex;
            if (sex == 1 || sex == 2) {
                abs->personArray[abs->m_Size].m_Sex = sex;
                break;
            }
            cout << "输入有误,请重新输入" << endl;
        }


        cout << "请输入年龄" << endl;
        int age = 0;
        while (1) {
            cin >> age;
            if (age > 0 && age < 200) {
                abs->personArray[abs->m_Size].m_Age = age;
                break;
            }
            cout << "您输入的年龄不符合[0-200],重新输入" << endl;
        }

        cout << "请输入联系电话" << endl;
        string phone;
        cin >> phone;
        abs->personArray[abs->m_Size].m_Phone = phone;

        cout << "请输入住址" << endl;
        string address;
        cin >> address;
        abs->personArray[abs->m_Size].m_Addr = address;

        abs->m_Size++;

        cout << "添加成功" << endl;

        system("read");//system("pause");windows
        system("clear");//system("cls");windows
    }
}

// show person
void showPerson(Addressbooks *abs) {
    if (abs->m_Size == 0) {
        cout << "address book is null" << endl;
    } else {
        for (int i = 0; i < abs->m_Size; i++) {
            cout << "name-> " << abs->personArray[i].m_Name << "\t";
            cout << "sex-> " << (abs->personArray[i].m_Sex == 1 ? "男" : "女") << "\t";
            cout << "age-> " << abs->personArray[i].m_Age << "\t";
            cout << "phone-> " << abs->personArray[i].m_Phone << "\t";
            cout << "address-> " << abs->personArray[i].m_Addr << "\n";
        }
    }
}

// del person
void delPerson(Addressbooks *abs) {
    cout << "请输入要删除的联系人" << endl;
    string name;
    cin >> name;
    int ret = isExist(abs, name);
    if (ret != -1) {
        for (int i = ret; i < abs->m_Size; i++) {
            abs->personArray[i] = abs->personArray[i + 1];
        }
        abs->m_Size--;
        cout << "删除成功" << endl;
    } else {
        cout << "查不到联系人" << endl;
    }

}

// person is not exist -1
int isExist(Addressbooks *abs, string name) {
    for (int i = 0; i < abs->m_Size; i++) {
        if (abs->personArray[i].m_Name == name) {
            return i;
        }
        return -1;
    }
}


// find person
void findPerson(Addressbooks *abs) {
    cout << "请输入您要查找的联系人" << endl;
    string name;
    cin >> name;
    int ret = isExist(abs, name);
    if (ret != -1) {
        cout << "name-> " << abs->personArray[ret].m_Name << "\t";
        cout << "sex-> " << (abs->personArray[ret].m_Sex == 1 ? "男" : "女") << "\t";
        cout << "age-> " << abs->personArray[ret].m_Age << "\t";
        cout << "phone-> " << abs->personArray[ret].m_Phone << "\t";
        cout << "address-> " << abs->personArray[ret].m_Addr << "\n";
    } else {
        cout << "找不到联系人" << endl;
    }

    system("read");//system("pause");windows
    system("clear");//system("cls");windows
}


// modify person
void modifyPerson(Addressbooks *abs) {
    cout << "请输入联系人姓名" << endl;
    string name;
    cin >> name;
    int ret = isExist(abs, name);
    if (ret != -1) {
        cout << "修改名称" << endl;
        string newName;
        cin >> newName;
        abs->personArray[ret].m_Name = newName;

        cout << "请输入性别:" << endl;
        cout << "1->男:" << endl;
        cout << "2->女:" << endl;
        int sex = 0;
        cin >> sex;
        while (1) {
            if (sex == 1 || sex == 2) {
                abs->personArray[ret].m_Sex = sex;
                break;
            }
            cout << "重新输入性别" << endl;
        }


        cout << "请输入修改年龄" << endl;
        int age = 0;
        while (1) {
            cin >> age;
            if (age > 0 && age < 200) {
                abs->personArray[ret].m_Age = age;
                break;
            }
            cout << "您输入的年龄不符合[0-200],重新输入" << endl;
        }

        cout << "请输入修改联系电话" << endl;
        string phone;
        cin >> phone;
        abs->personArray[ret].m_Phone = phone;

        cout << "请输入住址" << endl;
        string address;
        cin >> address;
        abs->personArray[ret].m_Addr = address;


        cout << "修改成功" << endl;

        system("read");//system("pause");windows
        system("clear");//system("cls");windows
    }
}

// logic del all person
void delAllPerson(Addressbooks *abs) {
    cout << "再次确认,清空按1,不清空按任意键" << endl;
    string doubleCheck;
    cin >> doubleCheck;
    if (doubleCheck == "1") {
        abs->m_Size = 0;
        cout << "已清空所有联系人" << endl;
    } else {
        cout << "没有清空" << endl;
    }
    system("read");//system("pause");windows
    system("clear");//system("cls");windows

}

int main() {

    // 创建通讯录结构体变量
    Addressbooks abs;
    abs.m_Size = 0;


    int select = 0;

    while (1) {

        showMenu();
        cin.get();
        cin >> select;
        switch (select) {
            case 1:// add contact
                addPerson(&abs);
                break;
            case 2:// show contact
                showPerson(&abs);
                break;
            case 3:// del contact
                delPerson(&abs);
                break;
            case 4:// find contact
                findPerson(&abs);
                break;
            case 5:// modify contact
                modifyPerson(&abs);
                break;
            case 6:// del all contact
                delAllPerson(&abs);
                break;
            case 0:
                cout << "欢迎下次光临" << endl;
                cin.get();
                return 0;
            default:
                break;
        }
    }


}








