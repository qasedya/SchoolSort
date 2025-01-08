#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <fstream>


using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::ios;


struct student
{
    string fname;
    string lname;
    string grade;
    unsigned age;
};


std::vector <student> students;
int studentCount = 0;


void add_student(std::vector<student>& list)
{
    cout << "���������� �������� �� �������." << endl;
    student toList;
    cout << "������� ���, �������, ����� � ������� �������: " << endl;
    cin >> toList.fname >> toList.lname >> toList.grade >> toList.age;
    list.push_back(toList);
    studentCount++;
}

void print_student(std::vector<student>& list)
{
    int idx;
    cout << "����� �������." << endl;
    cout << "������� ����� �������" << "[" << "1 - " << studentCount << "]" << ": " << endl;
    cin >> idx;
    idx -= 1;
    if (idx <= studentCount && idx >= 0)
        cout << idx + 1 << ". " << list[idx].fname << ' ' << list[idx].lname << ' ' << list[idx].age << ' ' << list[idx].grade << endl;
    else
        cout << "������������ ����� �������!" << endl;
}

void edit_student(std::vector<student>& list)
{
    int idx;
    cout << "��������� ������." << endl;
    cout << "������� ������ ������� ��� ��������������" << "[" << "1 - " << studentCount << "]" << ": " << endl;
    cin >> idx;
    idx -= 1;
    cout << "������� ����� ���, �������, ����� � ������� ��� �������: " << endl;
    cin >> list[idx].fname >> list[idx].lname >> list[idx].age >> list[idx].grade;
}

void print_all(std::vector<student>& list)
{
    cout << "����� ���������� � ���� ��������." << endl;
    for (int i = 0; i < list.size(); ++i) {
        cout << i + 1 << ". " << list[i].fname << ' ' << list[i].lname << ' ' << list[i].age << ' ' << list[i].grade << endl;
    }
}

void start_ascii()
{
    cout << "   _____      _                 _  _____            _   " << endl;
    cout << "  / ____|    | |               | |/ ____|          | |  " << endl;
    cout << " | (___   ___| |__   ___   ___ | | (___   ___  _ __| |_ " << endl;
    cout << " \\___  \\ / __| '_ \\ / _ \\ / _ \\| |\\___ \\ / _ \\| '__| __|" << endl;
    cout << "  ____) | (__| | | | (_) | (_) | |____) | (_) | |  | |_ " << endl;
    cout << " |_____/ \\___|_| |_|\\___/ \\___/|_|_____/ \\___/|_|   \\__|\n\n" << endl;
}

void start_menu()
{
    cout << "����� ���������� � SchoolSort.\n�������� ���� �� �����, �������������� ����." << endl;
    cout << "1. �������� ������� � ������.\n2. �������� ������ �� �������.\n3. ������� ���������� � ������ �������.\n4. ������� ���������� � ���� ��������.\n5. �������� � ����.\n6. ����� �� ���������." << endl;
}

void save_info(std::vector<student> list)
{
    std::ofstream ofs;
    ofs.open("info.txt", ios::trunc);
    if (ofs.is_open()) {
        for (int i = 0; i < studentCount; ++i) {
            string fname = list[i].fname;
            string lname = list[i].lname;
            string grade = list[i].grade;
            unsigned age = list[i].age;
            ofs << i + 1 << ". " << fname << ' ' << lname << ' ' << grade << ' ' << age << endl;
        }
    }
    ofs.close();
    cout << "��������� ���� � ����������� �������." << endl;
}


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    while (1)
    {
        start_ascii();
        start_menu();
        int chos;
        cin >> chos;
        switch (chos)
        {
        case 1:
            system("cls");
            start_ascii();
            add_student(students);
            system("pause");
            system("cls");
            break;
        case 2:
            system("cls");
            start_ascii();
            edit_student(students);
            system("pause");
            system("cls");
            break;
        case 3:
            system("cls");
            start_ascii();
            print_student(students);
            system("pause");
            system("cls");
            break;
        case 4:
            system("cls");
            start_ascii();
            print_all(students);
            system("pause");
            system("cls");
            break;
        case 5:
            system("cls");
            start_ascii();
            save_info(students);
            system("pause");
            system("cls");
            break;
        case 6:
            return 0;
        default:
            cout << "������ �������� ����� �����." << endl;
            system("pause");
            system("cls");
            break;
        }
    }
}
