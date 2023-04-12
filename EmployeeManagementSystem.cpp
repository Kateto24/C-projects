#include <iostream>

using namespace std;

const int maxEmp = 20;
//int num;

struct Employee
{
    string name;
    int ID;
    string departement;
    double experience;
    int age;
};

int num;
void ShowMenu();

Employee employee[maxEmp];

void Build()
{
    cout << endl;
    /*int num;*/
    cout << "Build the table of employees. " << endl;
    cout << "---------------" << endl;
    cout << "Enter the number of new employees: ";
    cin >> num;
    cout << endl;

    if (num > maxEmp)
    {
        cout << "Maximum employee can be " << maxEmp << endl;
        num = 20;
    }

    cout << "---------------" << endl;
    /*int count = num;*/
    cout << "Enter the following data." << endl;

    for (int i = 0; i < num; i++) {
        cout << "Enter name of employee: ";
        cin >> employee[i].name;
        cout << "Enter ID of employee: ";
        cin >> employee[i].ID;
        cout << "Enter departement of employee: ";
        cin >> employee[i].departement;
        cout << "Enter expirience of employee: ";
        cin >> employee[i].experience;
        cout << "Enter age of employee: ";
        cin >> employee[i].age;
        cout << "---------------" << endl;
    }

    ShowMenu();
}

void Insert() 
{
    if (num < maxEmp)
    {
        int i = num;
        num++;

        cout << "Enter the info about the employee!" << endl;
        cout << "Enter name of employee: ";
        cin >> employee[i].name;
        cout << "Enter ID of employee: ";
        cin >> employee[i].ID;
        cout << "Enter departement of employee: ";
        cin >> employee[i].departement;
        cout << "Enter expirience of employee: ";
        cin >> employee[i].experience;
        cout << "Enter age of employee: ";
        cin >> employee[i].age;
        /*cout << "---------------" << endl;*/
    }
    else
    {
        cout << "The Employee Table is full!" << endl ;
    }

    ShowMenu();
}

void DeleteRecordByIndex(int i)
{
    for (int j = i; j < num - 1; j++) {
        employee[j].name = employee[j + 1].name;
        employee[j].ID = employee[j + 1].ID;
        employee[j].departement = employee[j + 1].departement;
        employee[j].experience = employee[j + 1].experience;
        employee[j].age = employee[j + 1].age;
    }
    return;
}

void DeleteRecord()
{
    cout << endl;
    cout << "Enter the employee ID: ";
    int id;
    cin >> id;

    for (int i = 0; i < num; i++)
    {
        if (employee[i].ID == id)
        {
            DeleteRecordByIndex(i);
            num--;
            break;
        }
    }

    ShowMenu();
}

void Search()
{
    cout << endl;
    cout << "Enter ID of employee: ";
    int id;
    cin >> id;
    bool isIDValid = 1;

    for (int i = 0; i < num; i++)
    {
        if (employee[i].ID == id)
        {
            cout << employee[i].name << endl
                << employee[i].departement << endl
                << employee[i].experience << endl
                << employee[i].age << endl;

            break;
        }
        /*else
        {
            cout << "We don't have employee with this ID!" << endl;
            break;
        }*/
    }

    if (isIDValid == 1)
    {
        cout << "We don't have employee with this ID!" << endl;
        cout << endl;
    }

    ShowMenu();
}

static void ShowMenu() 
{
    cout << "---------------" <<
        "Employee Management System" <<
        "---------------" << endl;

    cout << "Choose option: " << endl;
    cout << "Available Options:\n\n";
    cout << "Build Table         (1)\n";
    cout << "Insert New Entry    (2)\n";
    cout << "Delete Entry        (3)\n";
    cout << "Search a Record     (4)\n";
    cout << "Exit                (5)\n";

    cout << endl;
    int option;
    cout << "Enter option: ";
    cin >> option;

    if (option <= 0 || option > 5)
    {
        while (option <= 0 || option > 5)
        {
            cout << "Wrong number! Please enter again! -> ";
            cin >> option;
        }
    }

    if (option == 1) {
        Build();
    }
    else if (option == 2) {
        Insert();
    }
    else if (option == 3) {
        DeleteRecord();
    }
    else if (option == 4) {
        Search();
    }
    else if (option == 5) {
        return;
    }
    else {
        cout << "Expected Options"
            << " are 1/2/3/4/5";
        ShowMenu();
    }
    
}

int main()
{  
    ShowMenu();

    return 0;
}

