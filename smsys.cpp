#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

// Helper functions for safe user input
void clearInputBuffer()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int inputInt(const string& prompt)
{
    int value;
    while (true)
    {
        cout << prompt;
        if (cin >> value)
        {
            clearInputBuffer();
            return value;
        }
        cout << "Invalid input. Please enter a valid number.\n";
        clearInputBuffer();
    }
}

float inputFloat(const string& prompt)
{
    float value;
    while (true)
    {
        cout << prompt;
        if (cin >> value)
        {
            clearInputBuffer();
            return value;
        }
        cout << "Invalid input. Please enter a valid decimal number.\n";
        clearInputBuffer();
    }
}

string inputString(const string& prompt)
{
    string value;
    while (true)
    {
        cout << prompt;
        getline(cin, value);
        if (!value.empty())
        {
            return value;
        }
        cout << "Field cannot be empty. Please try again.\n";
    }
}

class student
{
    string name;
    int roll;
    int age;
    string department;
    float marks;

public:
    student() : roll(0), age(0), marks(0.0f) {}

    void set_details(int roll_no);
    void display_student() const;
    void update_student();
    int get_roll() const;
};

vector<student> s;

void search_student();
void delete_student();

bool roll_check(int roll)
{
    for (size_t i = 0; i < s.size(); i++)
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
    bool running = true;

    while (running)
    {
        cout << "\n---MENU OF STUDENT MANAGEMENT SYSTEM---" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Display student" << endl;
        cout << "3. Search student" << endl;
        cout << "4. Update student" << endl;
        cout << "5. Delete student" << endl;
        cout << "6. Exit" << endl;

        choice = inputInt("Enter your choice: ");

        switch (choice)
        {
        case 1:
        {
            int roll = inputInt("Enter Roll Number: ");
            if (roll_check(roll))
            {
                cout << "Error: Roll number already exists.\n";
            }
            else
            {
                student temp;
                temp.set_details(roll);
                s.push_back(temp);
                cout << "Student Added successfully!\n";
            }
            break;
        }

        case 2:
            if (s.empty())
            {
                cout << "No students found.\n";
            }
            else
            {
                cout << "\n---DISPLAYING STUDENTS---" << endl;
                for (size_t i = 0; i < s.size(); i++)
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
            if (s.empty())
            {
                cout << "No students available to update.\n";
                break;
            }

            int roll = inputInt("Enter roll no. of the student to be updated: ");
            bool found = false;

            for (size_t i = 0; i < s.size(); i++)
            {
                if (s[i].get_roll() == roll)
                {
                    s[i].update_student();
                    found = true;
                    break;
                }
            }

            if (!found)
            {
                cout << "Student with roll no. " << roll << " does not exist.\n";
            }
            break;
        }

        case 5:
            delete_student();
            break;

        case 6:
            cout << "Exiting the program...\n";
            running = false;
            break;

        default:
            cout << "Invalid choice. Please choose between 1 and 6.\n";
            break;
        }
    }

    return 0;
}

void student::set_details(int roll_no)
{
    roll = roll_no;
    name = inputString("Enter Name: ");
    age = inputInt("Enter Age: ");
    department = inputString("Enter Department: ");
    marks = inputFloat("Enter Marks: ");
}

void student::display_student() const
{
    cout << "------------------------\n";
    cout << "Roll:       " << roll << "\n";
    cout << "Name:       " << name << "\n";
    cout << "Age:        " << age << "\n";
    cout << "Department: " << department << "\n";
    cout << "Marks:      " << marks << "\n";
    cout << "------------------------\n";
}

int student::get_roll() const
{
    return roll;
}

void search_student()
{
    if (s.empty())
    {
        cout << "No students available to search.\n";
        return;
    }

    int roll = inputInt("Enter roll no. to search: ");
    bool found = false;

    for (size_t i = 0; i < s.size(); i++)
    {
        if (s[i].get_roll() == roll)
        {
            cout << "\nStudent Found:\n";
            s[i].display_student();
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "Student with roll no. " << roll << " does not exist.\n";
    }
}

void student::update_student()
{
    cout << "\nUpdating details for Roll No: " << roll << "\n";
    name = inputString("Enter new Name: ");
    age = inputInt("Enter new Age: ");
    department = inputString("Enter new Department: ");
    marks = inputFloat("Enter new Marks: ");
    cout << "Student details updated successfully!\n";
}

void delete_student()
{
    if (s.empty())
    {
        cout << "No students available to delete.\n";
        return;
    }

    int roll = inputInt("Enter roll no. of the student to be deleted: ");
    bool found = false;

    for (size_t i = 0; i < s.size(); i++)
    {
        if (s[i].get_roll() == roll)
        {
            s.erase(s.begin() + i);
            found = true;
            cout << "Student Deleted successfully!\n";
            break;
        }
    }

    if (!found)
    {
        cout << "Student with roll no. " << roll << " does not exist.\n";
    }
}
