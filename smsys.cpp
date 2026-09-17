#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

class student
{
    string name;
    int roll;
    int age;
    string department;
    float marks;

public:
    void add_student();

    void display_student();

    void update_student();

    int get_roll();
};

vector<student> s;
void search_student();
void delete_student();
bool roll_check(int roll)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i].get_roll() == roll)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int choice;

    do
    {
        cout << "---MENU OF STUDENT MANAGEMENT SYSTEM---" << endl;
        cout << "1.Add Student" << endl;
        cout << "2.Display student" << endl;
        cout << "3.Search student" << endl;
        cout << "4.Update student" << endl;
        cout << "5.Delete student" << endl;
        cout << "6.Exit" << endl;
        cout << "Enter your choice:";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            student temp;
            temp.add_student();
            if (roll_check(temp.get_roll()))
            {
                cout << " Roll number already exist." << endl;
                break;
            }
            else
            {
                s.push_back(temp);
                cout << "Student Added..." << endl;
            }

            break;
        }

        case 2:
            if (s.empty())
            {
                cout << "No Student found" << endl;
            }
            else
            {
                cout << "---DISPLAYING STUDENTS---" << endl;
                for (int i = 0; i < s.size(); i++)
                {
                    s[i].display_student();
                }
            }

            break;
        case 3:
            search_student();
            break;
        case 4:
        {
            int roll;
            bool found = false;
            cout << "Enter roll no. of the student to be updated:" << endl;
            cin >> roll;
            for (int i = 0; i < s.size(); i++)
            {
                if (s[i].get_roll() == roll)
                {
                    s[i].update_student();
                    cout << endl;
                    found = true;
                    break;
                }
            }
            if (found == false)
            {
                cout << "Student does not exist of this roll no." << endl;
            }
        }
        break;
        case 5:
            delete_student();
            break;
        case 6:
            cout << "Exiting the program..." << endl;
            exit(0);
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (1);
    return 0;
}

void student::add_student()
{
    cout << "Enter your Name:" << endl;
    cin >> name;

    cout << "Enter your Roll Number:" << endl;
    cin >> roll;

    cout << "Enter your Age:" << endl;
    cin >> age;

    cout << "Enter your Department:" << endl;
    cin >> department;

    cout << "Enter your Marks:" << endl;
    cin >> marks;
}

void student::display_student()
{
    cout << "Name:      " << name << endl;
    cout << "Roll:      " << roll << endl;
    cout << "Age:       " << age << endl;
    cout << "Department:" << department << endl;
    cout << "Marks:     " << marks << endl
         << endl;
}

int student::get_roll()
{
    return roll;
}
void search_student()
{
    int roll;
    bool found = false;
    cout << "Enter the roll no. to search for student:" << endl
         << endl;
    cin >> roll;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i].get_roll() == roll)
        {
            s[i].display_student();
            cout << endl;
            found = true;
            cout << "Student Searched..." << endl;
            break;
        }
    }
    if (found == false)
    {
        cout << "Student does not exist of this roll no." << endl;
    }
}
void student::update_student()
{
    cout << "Enter your Name:" << endl;
    cin >> name;

    cout << "Enter your Age:" << endl;
    cin >> age;

    cout << "Enter your Department:" << endl;
    cin >> department;

    cout << "Enter your Marks:" << endl;
    cin >> marks;

    cout << "Student updated..." << endl;
}
void delete_student()
{
    int roll;
    bool found = false;
    cout << "Enter roll no. of the student to be updated:" << endl;
    cin >> roll;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i].get_roll() == roll)
        {
            s.erase(s.begin() + i);
            found = true;
            cout << " Student Deleted..." << endl;
            break;
        }
    }
    if (found == false)
    {
        cout << "Student does not exist of this roll no." << endl;
    }
}
