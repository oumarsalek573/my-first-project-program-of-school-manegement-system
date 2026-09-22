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

using namespace std;
class Clsection
{
public:
    struct Simformationofsection
    {
        string name = "";
        string stage = "";
        int NumberOfStudentsInTheSection = 0;
        bool markdelete = false;
    };

    void Startmunueofsystemsection(Cluser::stUser user);

    vector<Simformationofsection> LoadsectionsFromFile(string FileName);

    string fillnameofsection = "section.txt";
private:
    enum enchoiceofmunueofsystemsection
    {
        enShowsection = 1,
        enAddsection,
        enDeletesection,
        enUpdatesection,
        enFindsection,
        enExit
    };

    void ImplementationRequirementsmunueofsystemsection(enchoiceofmunueofsystemsection choice, Cluser::stUser user);

    const string PrimarySections[7] = { "", "1AF", "2AF", "3AF", "4AF", "5AF", "6AF" };
    const string MiddleSections[5] = { "", "1AS", "2AS", "3AS", "4AS" };
    const string HighSections[11] = { "", "5C", "5D", "5L", "6C", "6D", "6L", "7C", "7D", "7L", "7A" };
    const string StageNames[4] = { "", "Primary School", "Middle School", "High School" };

    vector<string> SplitString(string S1, string delim);

    Simformationofsection ConvertRecordTosection(string Line, string Seperator = "#//#");

    void PrintAllsections(vector<Simformationofsection>Vsections);

    bool isNumber(string str);

    int getValidatedNumber(string massage, bool massegetrueorfalse);

    void showsectionlist(vector<Simformationofsection>Vsections);

    bool sectionisfound(vector<Simformationofsection>Vsections, string nameclass, Simformationofsection& Section);

    bool sectionisfound(vector<Simformationofsection>Vsections, string nameclass);

    void printrules();

    enum enStage {
        PrimarySchool = 1,
        MiddleSchool = 2,
        HighSchool = 3
    };

    string Deconstructstring(string section, string stage);

    int returnnumberofsection(string section, string stage);

    string knowSection(enStage choiceStage);

    string knowstageandSection(Simformationofsection& section);

    int returnThelargestnumber(vector<int>Vnumbers);

    void addsection(vector<Simformationofsection>Vsections);

    string Joinstructstring(Clstudent::Ststudent& student, string delim = "#//#");

    void savestudents(string fillename, vector<Clstudent::Ststudent>& vstudents);

    void Deletesection(vector<Simformationofsection>Vsections);

    void FindSection(vector<Simformationofsection>Vsections);

    void printspace(int c);

    int readchoice(int from, int to);

    string Joinstructstring(Simformationofsection& section, string delim = "#//#");

    void savesections(string fillename, vector<Simformationofsection>& vsections);

    void AddDataLineToFile(const string& FileName, const string& stDataLine);

    bool iscorrectsection(string characterofsection, string newclass, string stage);
};