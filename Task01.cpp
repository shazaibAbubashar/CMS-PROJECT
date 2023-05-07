#include <iostream>
#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
// it is Course class
/////////////////////////////////////////Class Course///////////////////////////////////
class Course
{
public:
    int id;
    int credit_hour;
    string course_name;

public:
    Course()
    {
        id = 0;
        course_name = "";
        credit_hour = 0;
    }
    Course(int i, int ch, string cn)
    {
        id = i;
        credit_hour = ch;
        course_name = cn;
    }
    int get_id()
    {
        return id;
    }
    string get_course_name()
    {
        return course_name;
    }
    int get_credit_hour()
    {
        return credit_hour;
    }
    void display_course(vector<Course> c)
    {
        for (auto i : c)
        {
            cout << "ID = " << i.get_id() << " "
                 << "NAME = " << i.get_course_name() << " "
                 << "Credit_hour = " << i.get_credit_hour() << endl;
        }
    }
};
/////////////////////////////////// Student Class//////////////////////////////
vector<Course> vec;
class Student
{
public:
    int id;
    string name;
    string pas;
    string Roll_no;
    long int semester_dues;
    int Current_Semester;

public:
    Student() {}
    Student(int i, string n, string r, string p, int cs, int sd)
    {
        id = i;
        name = n;
        Roll_no = r;
        pas = p;
        Current_Semester = cs;
        this->semester_dues = sd;
    }
    int getid()
    {
        return id;
    }
    void write_in_file()
    {
        fstream outfile("bitf21m021.txt", ios::app);
        try
        {
            if (!outfile)
            {
                throw;
                runtime_error("file not opened");
            }
            else
            {
                outfile << "id = " << id << endl;
                outfile << "Name = " << name << endl;
                outfile << "Roll No = " << Roll_no << endl;
                outfile << "Password = " << pas << endl;
                outfile << "Current semester = " << Current_Semester << endl;
                cout << "\n**********************************************************" << endl;
                cout << "Congratulation Data is write in a file successfully!!!" << endl;
                cout << "**********************************************************" << endl
                     << endl;
                outfile.close();
            }
        }
        catch (exception &e)
        {
            cout << e.what() << endl;
        }
    }
    bool Login()
    {
        int flag = 0;
        string pass, username, line;
        cout << "Enter password : ";
        fflush(stdin);
        getline(cin, pass);
        cout << "Enter the username : ";
        fflush(stdin);
        getline(cin, username);
        fstream infile("bitf21m021.txt", ios::in);
        if (name == username && pass == pas)
        {

            flag = 1;
        }
        if (flag == 1)
        {
            cout << "\n***************************************************" << endl;
            cout << "Congratulation!!! You looged in the software" << endl;
            cout << "***************************************************" << endl;
            return true;
        }
        else
        {
            return false;
        }
        infile.close();
    }

    void displaymenu()
    {
        int choice;
        do
        {
            system("cls");
            cout << "-----------Menu-----------" << endl
                 << endl;
            cout << "1. Pay Semester Dues\n";
            cout << "2. Add Courses\n";
            cout << "3. View Enrolled Courses\n";
            cout << "4. Exit\n";
            cout << "Enter your choice : ";
            cin >> choice;
            if (choice == 1)
            {

                paySemesterDues();
            }
            else if (choice == 2)
            {
                Course c1;
                int i, ch;
                string cn;
                cout << "Enter id of the course : ";
                cin >> i;
                cout << "Enter course name : ";
                fflush(stdin);
                getline(cin, cn);
                cout << "Enter credit hour of the course : ";
                cin >> ch;
                Course c(i, ch, cn);
                vec.push_back(c);
                cout << "***********************************************" << endl;
                cout << "Succesfully course added in a enrolled courses" << endl;
                cout << "***********************************************" << endl;
            }
            else if (choice == 3)
            {
                Course c1;
                cout << "**********************" << endl;
                cout << "View Courses\n";
                c1.display_course(vec);
                cout << "**********************" << endl;
            }
        } while (choice != 4);
    }
    void paySemesterDues()
    {
        int amount;
        try
        {
            cout << "Enter the semester dues you wanna pay? ";
            cin >> amount;
            if (amount < 0)
            {
                throw logic_error("Amount can't be negative");
            }
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
        fstream outfile("bitf21m021.txt", ios::app);
        semester_dues = semester_dues - amount;
        outfile << "Remaining dues = " << semester_dues << endl;
        outfile.close();
    }

    void get_stduent_data()
    {
    }
};
//////////////////////// Global Functions for admin processing/////////////////////
void addrecord();
void showallrecord();
void manage_student()
{
    int choice = 0;
    do
    {
        Student s;
        system("cls");
        cout << "---------Menu---------" << endl
             << endl;
        cout << "1. Add Students\n";
        cout << "2. Update Student\n";
        cout << "3. Delete Student\n";
        cout << "4. View all Students\n";
        cout << "5. Assigned Courses\n";
        cout << "6. Exit\n";
        cout << "Enter your choice : ";
        cin >> choice;
        if (choice == 1)
        {
            addrecord();
        }
        else if (choice == 4)
        {
            showallrecord();
        }
    } while (choice != 6);
}
void addrecord()
{
    ofstream file;
    file.open("student.txt", ios::app);
    int choice = 0;
    Student s1;
    char ch;
    cout << "Do you want to enter more records? ";
    cin >> ch;
    while (ch == 'y' || ch == 'Y')
    {
        cout << "Enter name of the student : ";
        fflush(stdin);
        getline(cin, s1.name);
        cout << "Enter semester dues : ";
        cin >> s1.semester_dues;
        cout << "Enter current semester : ";
        cin >> s1.Current_Semester;
        cout << "Enter id of the student : ";
        cin >> s1.id;
        cout << "Enter Roll No of the student : ";
        cin >> s1.Roll_no;
        file << "Name = " << s1.name << endl;
        file << "Semester Dues = " << s1.semester_dues << endl;
        file << "Current Semester = " << s1.Current_Semester << endl;
        file << "Id = " << s1.id << endl;
        file << "Roll No = " << s1.Roll_no << endl;
        cout << "Congratulation Data saved to file\n";
        cout << "Do you want to enter more records? ";
        cin >> ch;
    }
    file.close();
}
void print(Student s)
{
    cout << "Name = " << s.name << endl;
    cout << "Semester Dues = " << s.semester_dues << endl;
    cout << "Current Semester = " << s.Current_Semester << endl;
    cout << "Id = " << s.id << endl;
    cout << "Roll No = " << s.Roll_no << endl;
}
void showallrecord()
{
    Student s2;
    ifstream read;
    read.open("student.txt", ios::in);
    while (!(read.eof()))
    {
        read >> s2.name;
        read >> s2.semester_dues;
        read >> s2.Current_Semester;
        read >> s2.id;
        read >> s2.Roll_no;
        print(s2);
    }
    read.close();
    // file.seekg(0, ios::beg);
    // cout << "Name\t Roll No\t semester dues\t Current semester\t id\n";
    // file.read(reinterpret_cast<char *>(&s2), sizeof(s2));
    // while (!(file.eof()))
    // {
    //     cout << s2.name << "\t";
    //     cout << s2.Roll_no << "\t";
    //     cout << s2.semester_dues << s2.Current_Semester << s2.id;
    //     file.read(reinterpret_cast<char *>(&s2), sizeof(s2));
    //     // sleep(5);
    // }
}
///////////////////////////////// teacher class//////////////////////////////
class Teacher
{
private:
    int id;
    string name;
    string pas;

public:
    Teacher(int id, string pass, string name)
    {
        this->id = id;
        this->name = name;
        pas = pass;
    }
    void enroll_Courses()
    {
        int n;
        cout << "How many courses do you want to enter: ";

        cin >> n;
        string st;
        vector<string> courses;
        ofstream outFile("teacher.txt", ios::out | ios::app);
        cout << "Enter courses: ";

        for (int i = 0; i < n; i++)
        {
            fflush(stdin);
            cin >> st;
            outFile << "Course [" << i << "]: " << st << endl;
        }
        outFile.close();
    }
    void mark_Attendence()
    {

        int n;
        string subject;
        cout << "Enter subject : ";
        cin >> subject;
        cout << "How many students do you want to enter: ";
        cin >> n;
        string crs;
        char att;
        ofstream outFile("teacher.txt", ios::out);
        outFile << "Subject: " << subject << endl;
        cout << "Enter student name and attendence(P/A): ";
        for (int i = 0; i < n; i++)
        {
            fflush(stdin);
            getline(cin, crs);
            cin >> att;
            outFile << crs << " : " << att << endl;
        }
        outFile.close();
    }
    void view_Assigned_Courses()
    {
        ifstream MyReadFile("teacher.txt");
        string myText;
        while (getline(MyReadFile, myText))
        {
            cout << myText << endl;
        }
    }
    void write_in_file()
    {
        fstream outfile("bitf21m021.txt", ios::app);
        try
        {
            if (!outfile)
            {
                throw;
                runtime_error("file not opened");
            }
            else
            {
                outfile << "id = " << id << endl;
                outfile << "Name = " << name << endl;
                outfile << "Password No = " << pas << endl;
                cout << "**********************************************************" << endl;
                cout << "Congratulation Data is write in a file successfully!!!" << endl;
                cout << "**********************************************************" << endl
                     << endl;
                outfile.close();
            }
        }
        catch (exception &e)
        {
            cout << e.what() << endl;
        }
    }
    bool LoginTeacher()
    {
        int flag = 0;
        string pass, username, line;
        cout << "Enter password : ";
        fflush(stdin);
        getline(cin, pass);
        cout << "Enter the username : ";
        fflush(stdin);
        getline(cin, username);
        fstream infile("bitf21m021.txt", ios::in);
        if (name == username && pas == pass)
        {
            flag = 1;
        }
        if (flag == 1)
        {
            cout << "\n***************************************************" << endl;
            cout << "Congratulation!!! You looged in the software" << endl;
            cout << "***************************************************" << endl;
            cout << "***************************************************" << endl;
            cout << "Welcome In the Teacher Class" << endl;
            cout << "***************************************************" << endl;
            return true;
        }
        else
        {
            return false;
        }
        infile.close();
    }
    void display_menu()
    {
        int choice = 0;
        do
        {
            system("cls");
            cout << "----------Menu--------" << endl
                 << endl;
            cout << "1. Enrolled courses\n";
            cout << "2. Mark Attendance\n";
            cout << "3. View Assigned Courses\n";
            cout << "4. Exit\n";
            cout << "Enter your choice : ";
            cin >> choice;
            if (choice == 1)
            {
                enroll_Courses();
            }
            else if (choice == 2)
            {
                mark_Attendence();
            }
            else if (choice == 3)
            {
                cout << "*******************************************" << endl;
                cout << "view Assigned Course";
                view_Assigned_Courses();
                cout << "*******************************************" << endl;
            }
        } while (choice != 3);
    }
};
/// ////////////////////////////////////Admin Class////////////////////////////////////////
class Admin
{
private:
    int id;
    string name;
    string password;

public:
    Admin(){};
    Admin(int id, string name, string password)
    {
        this->id = id;
        this->name = name;
        this->password = password;
    }
    void write_in_file()
    {
        fstream outfile("bitf21m021.txt", ios::app);
        try
        {
            if (!outfile)
            {
                throw;
                runtime_error("file not opened");
            }
            else
            {
                outfile << "id = " << id << endl;
                outfile << "Name = " << name << endl;
                outfile << "Password No = " << password << endl;
                cout << "**********************************************************" << endl;
                cout << "Congratulation Data is write in a file successfully!!!" << endl;
                cout << "**********************************************************" << endl
                     << endl;
                outfile.close();
            }
        }
        catch (exception &e)
        {
            cout << e.what() << endl;
        }
    }
    bool LoginAdmin()
    {
        int flag = 0;
        string pass, username, line;
        cout << "Enter password : ";
        fflush(stdin);
        getline(cin, pass);
        cout << "Enter the username : ";
        fflush(stdin);
        getline(cin, username);
        fstream infile("bitf21m021.txt", ios::in);
        if (name == username && password == pass)
        {
            flag = 1;
        }
        if (flag == 1)
        {
            cout << "\n***************************************************" << endl;
            cout << "Congratulation!!! You looged in the software" << endl;
            cout << "***************************************************" << endl;
            cout << "***************************************************" << endl;
            cout << "WELCOME IN THE ADMIN CLASS" << endl;
            cout << "***************************************************" << endl;
            return true;
        }
        else
        {
            return false;
        }
        infile.close();
    }
    void display_admin_menu()
    {
        int choice = 0;

        do
        {
            system("cls");
            cout << "1. Manage students\n";
            cout << "2. Mange Teachers\n";
            cout << "3. Mange Courses\n";
            cout << "4. Exit\n";
            cout << "Enter your choice : ";
            cin >> choice;
            if (choice == 1)
            {
                Admin a;
                manage_student();
            }
        } while (choice != 4);
    }
};
int main()
{
    int choice = 0;
    do
    {
        cout << "Enter 1. to student class\n";
        cout << "Enetr 2. Teacher class\n";
        cout << "Enter 3. Admin class\n";
        cout << "Enter 4. Exit\n\n";
        cout << "Enter your choice : ";
        cin >> choice;
        if (choice == 1)
        {
            long int semester_dues;
            int id;
            string name, r, p;
            int cs;
            cout << "Enter id of the student : ";
            cin >> id;
            fflush(stdin);
            cout << "Enter name of the Student : ";
            getline(cin, name);

            cout << "Enter Roll_No of the Student : ";
            fflush(stdin);
            getline(cin, r);
            cout << "Enter password to write in the Student : ";
            fflush(stdin);
            getline(cin, p);
            cout << "Enter current semester : ";
            cin >> cs;
            cout << "Enter semester dues : ";
            cin >> semester_dues;
            if (semester_dues < 0)
            {
                cout << "Amount can't be negative\n";
            }
            Student s(id, name, r, p, cs, semester_dues);
            s.write_in_file();
            if (s.Login())
            {
                s.displaymenu();
            }
            else if (!s.Login())
            {
                cout << "Invalid username or password\n";
            }
        }
        else if (choice == 2)
        {
            string na;
            int idt;
            string pas;
            cout << "Enter id of the Teacher to write in the file: ";
            cin >> idt;
            cin.ignore();
            cout << "Enter name of the teacher to write in a file: ";
            fflush(stdin);
            getline(cin, na);
            cout << "Enter password to write in the file : ";
            fflush(stdin);
            getline(cin, pas);
            Teacher t(idt, pas, na);
            t.write_in_file();
            if (t.LoginTeacher())
            {
                t.display_menu();
            }
            else
            {
                cout << "Invalid username or password\n";
            }
        }
        else if (choice == 3)
        {

            int ai;
            string an, ap;
            cout << "Enter id of the admin to write in the file : ";
            cin >> ai;
            cout << "Enter name of the admin to write in the file : ";
            fflush(stdin);
            getline(cin, an);
            cout << "Enter admin password to write in the file : ";
            fflush(stdin);
            getline(cin, ap);
            Admin a(ai, an, ap);
            a.write_in_file();
            if (a.LoginAdmin())
            {
                a.display_admin_menu();
            }
            else
            {
                cout << "Invalid username or password\n";
            }
        }
    } while (choice != 4);

    return 0;
}