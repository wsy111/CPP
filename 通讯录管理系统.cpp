#include <iostream>
using namespace std;
#include <string>
#define MAX 1000

//�����ϵ�˽ṹ��
struct Person
{
	//����
	string Name;
	//�Ա�, 1�� 2Ů
	int Sex; 
	//����
	int Age;
	//�绰
	string Phone;
	//סַ
	string Addr;
};

//���ͨѶ¼�ṹ��
struct Addressbooks
{	
	//ͨѶ¼�б������ϵ������
	struct Person personArray[MAX];
	
	//ͨѶ¼�е�ǰ��¼��ϵ�˸���,Ҫ��ʼ��0
	int Size;
};

//��ʾ�˵�
void showMenu()
{
	cout << "***********************" << endl;
	cout << "***** 1.�����ϵ�� *****" << endl;
	cout << "***** 2.��ʾ��ϵ�� *****" << endl;
	cout << "***** 3.ɾ����ϵ�� *****" << endl;
	cout << "***** 4.������ϵ�� *****" << endl;
	cout << "***** 5.�޸���ϵ�� *****" << endl;
	cout << "***** 6.�����ϵ�� *****" << endl;
	cout << "***** 0.�Ƴ�ͨѶ¼ *****" << endl;
	cout << "***********************" << endl;
}

//�����ϵ��
void addPerson(Addressbooks * adb)
{
	//�����ж�ͨѶ¼�Ƿ�������������˾Ͳ��������
	if (adb->Size == MAX)
	{
		cout<<"ͨѶ¼�������޷����!" << endl;
		return;
	}
	else
	{
		//��Ӿ�����ϵ��

		//����
		string name;
		cout<<"������������" << endl;
		cin>>name;
		adb->personArray[adb->Size].Name = name;

		//�Ա�
		int sex;
		cout<<"�������Ա�" << endl;
		cout << "1---��" << endl;
		cout << "2---Ů" << endl;
		
		while (true)
		{
			//1����2���˳�ѭ���� ����һֱѭ��
			cin >> sex;
			if (sex==1 || sex==2)
			{
				adb->personArray[adb->Size].Sex = sex;
				break;
			}
			cout<<"������������������" << endl;
		}

		//����
		int age = 0;
		cout<<"���������䣺" << endl;
		cin >> age;
		adb->personArray[adb->Size].Age = age;

		//�绰
		string phone;
		cout<<"��������ϵ�绰��" << endl;
		cin >> phone;
		adb->personArray[adb->Size].Phone = phone;

		//��ַ
		string address;
		cout<<"�������ͥסַ��" << endl;
		cin >> address;
		adb->personArray[adb->Size].Addr = address;

		//����ͨѶ¼����
		adb->Size++;

		cout<<"��ӳɹ���" << endl;

		system("pause");//�����������
		system("cls");  //��������
	}
}

//��ʾ��ϵ��
void listPerson(Addressbooks* adb)
{
	//�����ж�ͨѶ¼����û����
	if (adb->Size == 0)
	{
		cout<<"ͨѶ¼û����" << endl;
		system("pause");//�����������
		system("cls");	//����
	}
	else
	{
		//ѭ�������ϵ��
		for (int i = 0; i < adb->Size; i++)
		{
			cout << "������" <<adb->personArray[i].Name << "\t";

			cout << "�Ա�" << (adb->personArray[i].Sex == 1?"��":"Ů") << "\t";

			cout << "���䣺" << adb->personArray[i].Age << "\t";

			cout << "�绰��" << adb->personArray[i].Phone << "\t";

			cout << "סַ��" << adb->personArray[i].Addr << endl;

			
		}
		system("pause");//�����������
		system("cls");	//����
	}
}

//main��������ͨѶ¼
int main() 
{	
	//����ͨѶ¼�ṹ�����
	Addressbooks adb;
	//��ʼ��ͨѶ¼�еĵ�ǰ��Ա����
	adb.Size = 0;

	int select = 0;

	while (true)    //ture����ѭ���ص��˵�
	{
		showMenu(); //�˵�����
		cin >> select;
		switch (select)
		{
		case 1:		//1.�����ϵ��
			addPerson(&adb); //&ȡ��ַ���޸�ʵ��
			break;
		case 2:		//2.��ʾ��ϵ��
			listPerson(&adb);
			break;
		case 3:		//3.ɾ����ϵ��
			delPerson(&adb);
			break;
		case 4:		//4.������ϵ��
			findPerson(&adb);
			break;
		case 5:		//5.�޸���ϵ��
			editPerson(&adb);
			break;
		case 6:		//6.�����ϵ��
			delAllPerson(&adb);
			break;
		case 0:		//0.�Ƴ�ͨѶ¼
			cout<<"��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
		default:
			break;
		}
	}
	system("pause");
	return 0;
}