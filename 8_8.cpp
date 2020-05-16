#include <bits/stdc++.h>
#include "employee.h"
using namespace std;

template<typename T>        //成员姓名改为大写
void trans(T* array) {
    int i = 0;
    while(array[i] != '\0') {
        if(array[i] >= 'a' && array[i] <= 'z') {
            array[i] = array[i] - 'a' + 'A';
        }
        i++;
    }
}

int main() {
    manager m1;
    technican t1;
    salesmanager sm1;
    salesman s1;
    technicanmanager tm1;
    char namestr[20];

    vector<employee *> vchar;
    vchar.push_back(&m1);
    vchar.push_back(&t1);
    vchar.push_back(&sm1);
    vchar.push_back(&s1);
    vchar.push_back(&tm1);

    int i;
    for(i = 0; i < vchar.size(); i++) {
        cout << "请输入下一个雇员的姓名：";
        cin >> namestr;
        vchar[i]->SetName(namestr);
        trans(vchar[i]->GetName());
        vchar[i]->promote();
    }

    int wh;
    float sl;
    cout << "请输入兼职技术人员" << t1.GetName() << "本月的工作时数：";
    cin >> wh;
    t1.SetworkHours(wh);

    cout << "请输入销售经理" << sm1.GetName() << "所管辖部门本月的销售总额：";
    cin >> sl;
    sm1.Setsales(sl);

    cout << "请输入推销员" << s1.GetName() << "本月的售额：";
    cin >> sl;
    s1.Setsales(sl);

    cout << "请输入技术经理" << tm1.GetName() << "本月的工作时数：";
    cin >> wh;
    tm1.SetworkHours(wh);

    for(i = 0; i < vchar.size(); i++) {
        vchar[i]->pay();
    }

    for(i = 0; i < vchar.size() - 1; i++) {
        int max = i;
        for(int j = i + 1; j < vchar.size(); j++) {
            if(*vchar[j] > *vchar[max]) {
                max = j;
            }
        }
        swap(vchar[i], vchar[max]);
    }

    for(i = 0; i < vchar.size(); i++) {
        cout << vchar[i]->GetName() << "编号" << vchar[i]->GetindividualEmpNo() << "级别为" << vchar[i]->Getgrade()
        << "级，本月工资" << vchar[i]->GetaccumPay() << endl;
    }

    ofstream outFile;
    outFile.open("temp.txt");
    for(i = 0; i < vchar.size(); i++) {
        outFile << vchar[i]->GetName() << "编号" << vchar[i]->GetindividualEmpNo() << "级别为" << vchar[i]->Getgrade()
                << "级，本月工资" << vchar[i]->GetaccumPay() << endl;
    }
    outFile.close();
}