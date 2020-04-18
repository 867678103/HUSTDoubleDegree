//��6.3�� �� 7.2��
/*
6.3��������������Ϣ����PERSON ����¼��������name �����֤��IDnumber ����
Ϣ�����庯����Աprint �� ��ӡ���˻������Ȼ������PERSON ��������
TEACHER ����¼��ʦ����ְ�ơ���н����Ϣ.���庯����Աprint����ӡ��ʦ�Ļ�
�����.
*/
#include<iostream>
#include<string>
using namespace std;
class PERSON {
protected:
	string name;
	int id;
	PERSON* next; //7.2����
	
public:
	PERSON() = default;
	PERSON(string name_, int id_);
	virtual void print();
	void insert(PERSON* p); //7.2
	void del(PERSON* p); //7.2
};

class TEACHER: public PERSON{
private:
	string title; //ְ��
	double salary;

public:
	TEACHER() = default;
	TEACHER(string name_, int id_, string title_, double salary_);
	virtual void print() override;
};

PERSON::PERSON(string name_, int id_)
{
	name = name_;
	id = id_;
	next = nullptr;
}

void PERSON::print()
{
	cout << "������" << name << endl;
	cout << "���֤�ţ�" << id << endl;
}

TEACHER::TEACHER(string name_ ,int id_, string title_, double salary_)
	:PERSON{ name_,id_ }, title{ title_ }, salary{ salary_ }
{

}

void TEACHER::print()
{
	PERSON::print();
	cout << "ְ���ǣ�" << title << endl;
	cout << "���ʣ�" << salary << endl;
}

void print(PERSON* p)
{
	p->print();
}
/*
7.2�����������У�ÿ���ڵ�����Ͳ�Ҫ����ͬ���ڵ�ָ��ͨ��ʹ�ø���ָ��. �Դ�ѧѧ
������ְ��ԱΪ����ѧ����Ϣ�������������塢��ᱣ�պš��꼶��ƽ���ɼ��ȣ� ְ
Ա��Ϣ�������������䡢��ᱣ�պź͹��ʵȣ�������Ϣ�������������䡢��ᱣ��
�š����ʺ��о������.Ϊ��ѧѧ������ְ��Ա����-�������������롢ɾ���ʹ�
ӡ��ѧ��Ա��Ϣ.*/
class Student : public PERSON {
private:
	int age;
	int insurance; //����
	int grade; //�꼶
	double avg; //ƽ���ɼ�

public:
	Student() = default;
	Student(string name_, int id_, int age_, int insurance_, int grade_, double avg_);
	virtual void print();
};

Student::Student(string name_, int id_, int age_, int insurance_, int grade_, double avg_):
	PERSON{ name_,id_ }, age{ age_ }, insurance{ insurance_ }, grade{ grade_ }, avg{ avg_ }
{

}

void Student::print()
{
	//���������塢��ᱣ�պš��꼶��ƽ���ɼ�
	cout << "������" << name << endl;
	cout << "���䣺" << age << endl;
	cout << "��ᱣ�պţ�" << insurance << endl;
	cout << "�꼶��" << grade << endl;
	cout << "ƽ���ɼ���" << avg << endl;
}


class Prof :public PERSON {
private:
	int age;
	int insurance; //����
	double salary;
	string interest; //�о�����

public:
	Prof() = default;
	Prof(string name_, int id_, int age_, int insurance_, double salary_, string interest_);
	virtual void print();
};

Prof::Prof(string name_, int id_, int age_, int insurance_, double salary_, string interest_):
	PERSON{ name_,id_ }, age{ age_ }, insurance{ insurance_ }, salary{ salary_ }, interest{ interest_ }
{

}

void Prof::print()
{
	//��ӡ���������䡢��ᱣ�պš����ʺ��о�����
	cout << "������" << name << endl;
	cout << "���䣺" << age << endl;
	cout << "��ᱣ�պţ�" << insurance << endl;
	cout << "���ʣ�" << salary << endl;
	cout << "�о�����" << interest << endl;
}


class Staff : public PERSON {
private:
	int age;
	int insurance; //����
	double salary;

public:
	Staff() = default;
	Staff(string name_, int id_, int age_, int insurance_, double salary_);
	virtual void print();
};
Staff::Staff(string name_, int id_, int age_, int insurance_, double salary_):
	PERSON{ name_,id_ }, age{ age_ }, insurance{ insurance_ }, salary{ salary_ }
{

}

void Staff::print()
{
	//��ӡ���������䡢��ᱣ�պź͹���
	cout << "������" << name << endl;
	cout << "���䣺" << age << endl;
	cout << "��ᱣ�պţ�" << insurance << endl;
	cout << "���ʣ�" << salary << endl;
}

//������:����ͷ���
void PERSON::insert(PERSON* p)
{
	cout << "����ѧ������1����ʦ����2����ְ������3:" << endl;
	int num;
	cin >> num;

	string name_;
	int id_;
	int age_;
	int insurance_;
	int grade_;
	double avg_;
	double salary_;
	string interest_; //�о�����

	PERSON* t;

	switch (num)
	{
		case 1:
			//string name_, int id_, int age_, int insurance_, int grade_, double avg_
			cout << "������ѧ��������";
			cin >> name_;
			cout << "������ѧ�����֤��";
			cin >> id_;
			cout << "������ѧ�����䣺";
			cin >> age_;
			cout << "��������ᱣ�պţ�";
			cin >> insurance_;
			cout << "������ѧ���꼶��";
			cin >> grade_;
			cout << "������ѧ��ƽ���ɼ���";
			cin >> avg_;
			t = new Student{ name_,id_,age_,insurance_,grade_,avg_ };
			t->next = p->next;
			p->next = t;
			cout << "����ѧ���ɹ�!\n";
			break;
		case 2:
			cout << "��������ʦ������";
			cin >> name_;
			cout << "��������ʦ���֤��";
			cin >> id_;
			cout << "��������ʦ���䣺";
			cin >> age_;
			cout << "��������ᱣ�պţ�";
			cin >> insurance_;
			cout << "��������ʦ���ʣ�";
			cin >> salary_;
			cout << "��������ʦ�о�����";
			cin >> interest_;
			t = new Prof{ name_,id_,age_,insurance_,salary_,interest_ };
			t->next = p->next;
			p->next = t;
			cout << "������ʦ�ɹ�\n";
			break;
		case 3:
			cout << "������ְ��������";
			cin >> name_;
			cout << "������ְ�����֤��";
			cin >> id_;
			cout << "������ְ�����䣺";
			cin >> age_;
			cout << "��������ᱣ�պţ�";
			cin >> insurance_;
			cout << "������ְ�����ʣ�";
			cin >> salary_;
			t = new Staff{ name_,id_,age_,insurance_,salary_ };
			t->next = p->next;
			p->next = t;
			cout << "����ְ���ɹ�\n";
			break;
	}
}

//ɾ�����
void PERSON::del(PERSON* p)
{
	cout << "��������Ҫɾ����������";
	string name_;
	cin >> name_;
	bool flag = false;
	PERSON* t = p;
	p = p->next;
	while (p)
	{
		if (p->name == name_)
		{
			flag = true;
			break;
		}
		t = t->next;
		p = p->next;
	}
	t->next = t->next->next;
	delete p;
	cout << "�ɹ�ɾ���ý��\n";
}

int main()
{
	//6.3 test
	TEACHER t{ "������",123456789,"����",99999999.99 };
	t.print();
	print(&t);
	cout << endl;
	
	//7.2 test
	PERSON* p = new PERSON(); //����ͷ���
	p->insert(p);
	p->insert(p);
	p->del(p);

	return 0;
}
