#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>
#include <fstream>


using namespace std;

enum Spec { CS, IT, ME, PhIT, TR };

string strSpec[] = { "����'�����i �����", "I����������", "���������� �� ������i��", "�i���� �� i����������", "������� ��������" };

struct Student 
{
	string surnamed;
	short unsigned kurs;
	Spec spec;
	short unsigned physics;
	short unsigned math;
	short unsigned informatik;
};

void Create(char* FileName, Student* s, int amSt) {
	ofstream f(FileName, ios::binary);
	if (!f)
	{
		cerr << "Error opening file '" << FileName << "'" << endl;
		exit(1);
	}
	int sp;
	for (int i = 0; i < amSt; i++) {
		cout << "��i�����: "; cin >> s[i].surnamed;
		cout << "����: "; cin >> s[i].kurs;
		cout << "����i����i��� (0 - ����'�����i �����; 1 - I����������; 2 - ���������� �� ������i��; 3 - �i���� �� i����������; 4 - ������� ��������;) ";
		cin >> sp;
		s[i].spec = (Spec)sp;
		cout << "��i��� � �i����: ";
		cin >> s[i].physics;
		cout << "��i��� � ����������: ";
		cin >> s[i].math;
		cout << "��i��� � �����������: ";
		cin >> s[i].informatik;

		if (!f.write((char*)&s, sizeof(Student)))
		{
			cerr << "Write error" << endl;
			exit(1);
		}
	}
}

void Print(char* FileName, Student* s, int amSt)
{
	ifstream f(FileName, ios::binary);
	if (!f)
	{
		cerr << "Error opening file" << endl;
		exit(1);
	}
	cout << "-------------------------------------------------------------------------------------------" << endl;
	cout << "|  �  | ���� |    �������    |       ������������     | ������ | ���������� |�����������|" << endl;
	cout << "-------------------------------------------------------------------------------------------" << endl;
	cout << left;
	for (int i = 0; i < amSt; i++) {

		cout << "|" << setw(3) << right << i + 1 << "  ";
		cout << "| " << setw(3) << right << s[i].kurs << "  "
			<< "|" << setw(16) << left << s[i].surnamed
			<< "| " << setw(24) << left << strSpec[s[i].spec]
			<< "| " << setw(3) << right << s[i].physics << "    "
			<< "| " << setw(6) << right << s[i].math << "     "
			<< "| " << setw(6) << right << s[i].informatik << "    " << "| ";
		cout << endl;
	}
	cout << "-------------------------------------------------------------------------------------------"
		<< endl;
}
double HighestAverageScore(char* FileName, Student* s, int N)
{
	ifstream f(FileName, ios::binary);
	if (!f)
	{
		cerr << "Error opening file" << endl;
		exit(1);
	}
	double m = 0;
	for (int i = 0; i < N; i++)
	{
		if ((s[i].physics + s[i].math + s[i].informatik) / 3. > m)
		{
			m = (s[i].physics + s[i].math + s[i].informatik) / 3.;
		}
	}
	return m;

}
double ProsPhysik(char* FileName, Student* s, int N)
{
	ifstream f(FileName, ios::binary);
	if (!f)
	{
		cerr << "Error opening file" << endl;
		exit(1);
	}
	int k = 0;
	for (int i = 0; i < N; i++)
	{
		if (s[i].physics == 5 || s[i].physics == 4)
		{
			k++;
		}
	}
	return 100.0 * k / N * 1.;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int amSt;
	cout << "�i���i��� �������i�: "; cin >> amSt;
	Student* s = new Student[amSt];

	cin.get(); cin.sync();
	char FileName[81];
	cout << "������ ��'� �����:"; cin.getline(FileName, sizeof(FileName));
	Create(FileName, s, amSt);
	Print(FileName, s, amSt);
	cout << "��������� ������� ���: " << HighestAverageScore(FileName, s, amSt) << endl;
	cout << "������� �������i�, ��i �������� � �i���� ������ �5� ��� �4�: " << ProsPhysik(FileName, s, amSt) << "%" << endl;
	return 0;
}	