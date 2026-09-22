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

using namespace std;

class Cluser
{
public:
    
    struct stUser
    {
        string username;
        string pincode;
        int Permissions = 0;
        bool markdeletuser = false;
    };

    enum enmanegeusers
    {
        eShowuserslist = 1,
        eAddNewusers = 2,
        eDeleteusers = 3,
        eUpdeteusersInfo = 4,
        eFindusers = 5,
        Exit = 6
    };

    enum Permissions
    {
        pAll = -1,
        pShowstudent = 1, pAddstudent = 2, pDeletestudent = 4, pUpdatestudent = 8,
        pFindstudent = 16, pManagestudent = 32, pManageUsers = 64, pShowuser = 128,
        pAdduser = 256, pDeleteuser = 512, pUpdateuser = 1024, pFinduser = 2048,
        pfeesandpeyementsystem = 4096, pTeacherandProfessorManagement = 8192,
        pGradesSystem = 16384, pAttendanceSystem = 32768, psectionManagement = 65536,
        pusermanegementsystem = 131072, pAcademicSubjectManagement = 262144,
        pShowteacher = 524288, pAddteacher = 1048576, pDeleteteacher = 2097152,
        pUpdateteacher = 4194304, pFindteacher = 8388608, pAddsection = 16777216, pDeletesection = 33554432,
        pshowsection = 67108864, pUpdatesection = 134217728, pfindsection = 268435456
    };

    const string userFilename = "User.txt";

    bool chekalluserandreturnuser(vector<stUser>& Vusers, stUser& infoofuser);
    void Menuemanegeusers(stUser user);
    vector<stUser> LoaduserssFromFile(string FileName);

private:
   
    void ImplementRequirementsClassmanigeusersMenue(enmanegeusers choice, stUser user);
    void addusersonfilefinal(vector<stUser>& Vusers);
    void findusersoneScreen(vector<stUser> vusers);
    void deleteusersinfile(string FileName, vector<stUser>& vUsers, stUser User);
    void updateusers(string FileName, vector<stUser>& vusers);
    void PrintAllusers(vector<stUser> vClients);
    bool userfound(vector<stUser>& VUsers);
    int readchoice(int from, int to);
    stUser ReadNewuser(stUser& User);
    string Joinstructstring(stUser& User, string delim = "#//#");
    void printinfouser(stUser vuser, string username);
    void saveUsers(string FileName, vector<stUser>& VUsers);
    string readstring(string message);
    bool chekalluserbyname(vector<stUser>& Vusers, string username);
    vector<string> SplitString(string S1, string delim);
    stUser ConvertRecordTouser(string Line, string Seperator = "#//#");
    bool chekoneuserbyname(stUser vuser, string username);
    void AddDataLineToFile(const string& FileName, const string& stDataLine);
};

