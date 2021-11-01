#include <iostream>
using namespace std;
#include <string>
#define MAX 1000

//设计联系人结构体
struct Person
{
	//姓名
	string Name;
	//性别, 1男 2女
	int Sex; 
	//年龄
	int Age;
	//电话
	string Phone;
	//住址
	string Addr;
};

//设计通讯录结构体
struct Addressbooks
{	
	//通讯录中保存的联系人数组
	struct Person personArray[MAX];
	
	//通讯录中当前记录联系人个数,要初始化0
	int Size;
};

//显示菜单
void showMenu()
{
	cout << "***********************" << endl;
	cout << "***** 1.添加联系人 *****" << endl;
	cout << "***** 2.显示联系人 *****" << endl;
	cout << "***** 3.删除联系人 *****" << endl;
	cout << "***** 4.查找联系人 *****" << endl;
	cout << "***** 5.修改联系人 *****" << endl;
	cout << "***** 6.清空联系人 *****" << endl;
	cout << "***** 0.推出通讯录 *****" << endl;
	cout << "***********************" << endl;
}

//添加联系人
void addPerson(Addressbooks * adb)
{
	//首先判断通讯录是否已满，如果满了就不能在添加
	if (adb->Size == MAX)
	{
		cout<<"通讯录已满，无法添加!" << endl;
		return;
	}
	else
	{
		//添加具体联系人

		//姓名
		string name;
		cout<<"请输入姓名：" << endl;
		cin>>name;
		adb->personArray[adb->Size].Name = name;

		//性别
		int sex;
		cout<<"请输入性别：" << endl;
		cout << "1---男" << endl;
		cout << "2---女" << endl;
		
		while (true)
		{
			//1或者2可退出循环， 否则一直循环
			cin >> sex;
			if (sex==1 || sex==2)
			{
				adb->personArray[adb->Size].Sex = sex;
				break;
			}
			cout<<"输入有误，请重新输入" << endl;
		}

		//年龄
		int age = 0;
		cout<<"请输入年龄：" << endl;
		cin >> age;
		adb->personArray[adb->Size].Age = age;

		//电话
		string phone;
		cout<<"请输入联系电话：" << endl;
		cin >> phone;
		adb->personArray[adb->Size].Phone = phone;

		//地址
		string address;
		cout<<"请输入家庭住址：" << endl;
		cin >> address;
		adb->personArray[adb->Size].Addr = address;

		//更新通讯录人数
		adb->Size++;

		cout<<"添加成功！" << endl;

		system("pause");//按任意键继续
		system("cls");  //清屏操作
	}
}

//显示联系人
void listPerson(Addressbooks* adb)
{
	//首先判断通讯录中有没有人
	if (adb->Size == 0)
	{
		cout<<"通讯录没有人" << endl;
		system("pause");//按任意键继续
		system("cls");	//清屏
	}
	else
	{
		//循环输出联系人
		for (int i = 0; i < adb->Size; i++)
		{
			cout << "姓名：" <<adb->personArray[i].Name << "\t";

			cout << "性别：" << (adb->personArray[i].Sex == 1?"男":"女") << "\t";

			cout << "年龄：" << adb->personArray[i].Age << "\t";

			cout << "电话：" << adb->personArray[i].Phone << "\t";

			cout << "住址：" << adb->personArray[i].Addr << endl;

			
		}
		system("pause");//按任意键继续
		system("cls");	//清屏
	}
}

//main函数创建通讯录
int main() 
{	
	//创建通讯录结构体变量
	Addressbooks adb;
	//初始化通讯录中的当前人员个数
	adb.Size = 0;

	int select = 0;

	while (true)    //ture无限循环回到菜单
	{
		showMenu(); //菜单调用
		cin >> select;
		switch (select)
		{
		case 1:		//1.添加联系人
			addPerson(&adb); //&取地址来修改实参
			break;
		case 2:		//2.显示联系人
			listPerson(&adb);
			break;
		case 3:		//3.删除联系人
			delPerson(&adb);
			break;
		case 4:		//4.查找联系人
			findPerson(&adb);
			break;
		case 5:		//5.修改联系人
			editPerson(&adb);
			break;
		case 6:		//6.清空联系人
			delAllPerson(&adb);
			break;
		case 0:		//0.推出通讯录
			cout<<"欢迎下次使用" << endl;
			system("pause");
			return 0;
		default:
			break;
		}
	}
	system("pause");
	return 0;
}