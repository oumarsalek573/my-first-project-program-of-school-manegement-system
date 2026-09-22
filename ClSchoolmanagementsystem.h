#pragma once
#pragma warning(disable: 4996)
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "Cluser.h"
#include "Clstudent.h"
#include "Clsection.h"

using namespace std;

class ClSchoolmanagementsystem
{
private:
    enum ensystemManegement
    {
        StudentManagement = 1,
        TeacherandProfessorManagement,
        PaymentandFeesSystem,
        GradesSystem,
        absenceandAttendanceSystem,
        sectionManagement,
        usermanegementsystem,
        AcademicSubjectManagement,
        logout,
        Exit
    };

    int readchoice(int from, int to);


    Cluser User;

    void ImplementRequirementsMenuesystemManegement(Cluser::stUser user, ensystemManegement choice);

public:

    Cluser::stUser Login();

    void startmunueprograme(Cluser::stUser User);
};

