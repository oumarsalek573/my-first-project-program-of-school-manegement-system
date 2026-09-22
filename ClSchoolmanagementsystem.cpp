#pragma warning(disable: 4996)

#include "ClSchoolmanagementsystem.h"
#include "Clstudent.h"
#include "Cluser.h"
#include <iomanip> 
#include <fstream>
#include <sstream>
#include"Clsection.h"

using namespace std;

    int ClSchoolmanagementsystem::readchoice(int from, int to)
    {
        int choice;
        cout << "choose what do you want to do?[" << from << " to " << to << "]" << endl;

        cin >> choice;
        while (choice < from || choice  > to) {
            cout << "Wrong choice." << endl << "Only enter the options that are in the attached menu at the beginning of the page." << endl;
            cin >> choice;
        }
        return choice;
    }


    void ClSchoolmanagementsystem::ImplementRequirementsMenuesystemManegement(Cluser::stUser user, ClSchoolmanagementsystem::ensystemManegement choice)
    {
        Clstudent student;
        Clsection section;
        Cluser User;

        vector<Clstudent::Ststudent>VStudent = student.LoadClientsFromFile(student.fillename);
        auto showNoAccessMessage = []() {
            cout << "\n\n--------------------------------------------" << endl;
            cout << "Access Denied," << endl;
            cout << "You dont Have Permissions To Do this," << endl;
            cout << "Please conact Your Admin." << endl;
            cout << "--------------------------------------------" << endl;
        };
        int permetion;
        switch (choice)
        {
        case ClSchoolmanagementsystem::ensystemManegement::StudentManagement:
            permetion = (int)Cluser::Permissions::pManagestudent;
            if ((user.Permissions & permetion) == permetion)
            {
                student.startofprograme(VStudent, user);
                cout << "Press any key to go back to MANEGE USERS MENUE..";
                system("pause>0");
                system("cls");
            }

            else
            {
                showNoAccessMessage();
                cout << "Press any key to go back to MANEGE USERS MENUE..";
                system("pause>0");
                system("cls");
            }
           
            break;
        case ClSchoolmanagementsystem::ensystemManegement::usermanegementsystem:
            permetion = (int)Cluser::Permissions::pManageUsers;
            if ((user.Permissions & permetion) == permetion)
            {
                User.Menuemanegeusers(user);
                cout << "Press any key to go back to MANEGE USERS MENUE..";
                system("pause>0");
                system("cls");
            }

            else
            {
                showNoAccessMessage();
                cout << "Press any key to go back to MANEGE USERS MENUE..";
                system("pause>0");
                system("cls");
            }
            break;
        case ClSchoolmanagementsystem::ensystemManegement::TeacherandProfessorManagement:
            permetion = (int)Cluser::Permissions::pTeacherandProfessorManagement;
            if ((user.Permissions & permetion) == permetion)
            {
                cout << "Press any key to go back to MANEGE USERS MENUE..";
                system("pause>0");
                system("cls");
            }

            else
            {
                showNoAccessMessage();
                cout << "Press any key to go back to MANEGE USERS MENUE..";
                system("pause>0");
                system("cls");

            }
            break;
        case ClSchoolmanagementsystem::ensystemManegement::PaymentandFeesSystem:
            permetion = (int)Cluser::Permissions::pfeesandpeyementsystem;
            if ((user.Permissions & permetion) == permetion)
            {
                cout << "Press any key to go back to MANEGE USERS MENUE..";
                system("pause>0");
                system("cls");
            }

            else
            {
                showNoAccessMessage();
                cout << "Press any key to go back to MANEGE USERS MENUE..";
                system("pause>0");
                system("cls");
            }
            break;
        case ClSchoolmanagementsystem::ensystemManegement::AcademicSubjectManagement:
            permetion = (int)Cluser::Permissions::pAcademicSubjectManagement;
            if ((user.Permissions & permetion) == permetion)
            {
                cout << "Press any key to go back to MANEGE USERS MENUE..";
                system("pause>0");
                system("cls");
            }

            else
            {
                showNoAccessMessage();
                cout << "Press any key to go back to MANEGE USERS MENUE..";
                system("pause>0");
                system("cls");
            }
            break;
        case ClSchoolmanagementsystem::ensystemManegement::absenceandAttendanceSystem:
            permetion = (int)Cluser::Permissions::pAttendanceSystem;
            if ((user.Permissions & permetion) == permetion)
            {
                cout << "Press any key to go back to MANEGE USERS MENUE..";
                system("pause>0");
                system("cls");
            }

            else
            {
                showNoAccessMessage();
                cout << "Press any key to go back to MANEGE USERS MENUE..";
                system("pause>0");
                system("cls");
            }
            break;
        case ClSchoolmanagementsystem::ensystemManegement::GradesSystem:
            permetion = (int)Cluser::Permissions::pGradesSystem;
            if ((user.Permissions & permetion) == permetion)
            {

                cout << "Press any key to go back to MANEGE USERS MENUE..";
                system("pause>0");
                system("cls");
            }

            else
            {
                showNoAccessMessage();
                cout << "Press any key to go back to MANEGE USERS MENUE..";
                system("pause>0");
                system("cls");

            }
            break;
        case ClSchoolmanagementsystem::ensystemManegement::Exit:

            break;
        case ClSchoolmanagementsystem::ensystemManegement::logout:

            break;
        case ClSchoolmanagementsystem::ensystemManegement::sectionManagement:
            section.Startmunueofsystemsection(user);
            break;
        }
    }



    Cluser::stUser ClSchoolmanagementsystem::Login()
    {
        vector<Cluser::stUser> Vusers = User.LoaduserssFromFile(User.userFilename);
        Cluser::stUser user;
        cout << "\n==================================================" << endl;
        cout << "Login SCREEN" << endl;
        cout << "==================================================" << endl;
        cout << endl;
        cout << "enter user name? " << endl;
        cin >> user.username;
        cout << "enter pincode? " << endl;
        cin >> user.pincode;

        while (!(User.chekalluserandreturnuser(Vusers, user)))
        {
            system("cls");
            cout << "\n==================================================" << endl;
            cout << "Login SCREEN" << endl;
            cout << "==================================================" << endl;
            cout << endl;
            cout << "There is an error in the code or the name." << endl;
            cout << "enter user name? " << endl;
            cin >> user.username;
            cout << "enter pincode? " << endl;
            cin >> user.pincode;
        }
        return user;
    }


    void ClSchoolmanagementsystem::startmunueprograme(Cluser::stUser User)
    {
        system("cls");
        ClSchoolmanagementsystem::ensystemManegement choice = (ClSchoolmanagementsystem::ensystemManegement)0;
        while (choice != ClSchoolmanagementsystem::ensystemManegement::logout)
        {
            cout << "\n========================================================" << endl;
            cout << "MAIN MENUE SCREEN OF SYSTEM MANEGEMENT" << endl;
            cout << "========================================================" << endl;
            cout << "\t(1)  Student Management system" << endl;
            cout << "\t(2)  Professor and Teacher Management System" << endl;
            cout << "\t(3)  Payment / Fees Management system" << endl;
            cout << "\t(4)  Grades and Results Management System" << endl;
            cout << "\t(5)  Attendance and absence Management system" << endl;
            cout << "\t(6)  section Management System" << endl;
            cout << "\t(7)  Users Management system" << endl;
            cout << "\t(8)  Academic Subjects Management System" << endl;
            cout << "\t(9)  LOGOUT" << endl;
            cout << "\t(10) EXIT" << endl;
            cout << "========================================================" << endl;
            cout << endl;

            choice = (ensystemManegement)readchoice(1, 10);
            system("cls");
            if (choice == ensystemManegement::Exit)
            {
                break;
            }
            ImplementRequirementsMenuesystemManegement(User, choice);

        }
        if (choice == ensystemManegement::logout)
        {
            Cluser::stUser user = Login();
            
            startmunueprograme(user);
        }
    
    }


