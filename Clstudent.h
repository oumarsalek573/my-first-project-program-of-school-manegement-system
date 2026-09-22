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

class Clstudent
{
    
    public:
        struct stdateofbirth
        {
            int  year = 0;
            int mounth = 0;
            int day = 0;

        };

        struct Ststudent
        {
            string NNI;
            string Namecomplete;
            string numberphoneofparent;
            string stage;
            string Gender;
            stdateofbirth dateofbirth;
            string placeofbirth;
            string Academicsection;
            bool markdeletclient = false;
            int fees=0;
        };

        void startofprograme(vector<Ststudent>& Students, Cluser::stUser User);

        const string fillename = "studentdatafile.txt";

        vector<Ststudent> LoadClientsFromFile(string fillname);

    private:
        struct Simformationofsection
        {
            string name = "";
            string stage = "";
            int NumberOfStudentsInTheSection = 0;
            bool markdelete = false;
        };
        bool isLeapYear(short Year);
        short NumberOfDaysInAMonth(short Month, short Year);
        string StateNames[16] = {
               "", "Hodh Ech Charghi", "Hodh El Gharbi", "Assaba", "Gorgol", "Brakna",
               "Trarza", "Adrar", "Dakhlet Nouadhibou", "Tagant", "Tiris Zemmour",
               "Inchiri", "Nouakchott West", "Nouakchott North", "Nouakchott South", "Guidimagha"
        };
        string HodhCharghiNames[9] = { "", "Nema", "Timbedga", "Amourj", "Bassouknou", "Djiguenni", "Oualata", "N'Beiket Lehwach", "Dhar" };
        string HodhGharbiNames[6] = { "", "Ayoun", "Tintane", "Tamchekett", "Kobenni", "Touil" };
        string AssabaNames[6] = { "", "Kiffa", "Barkeol", "Guerou", "Kankossa", "Boumdeid" };
        string GorgolNames[6] = { "", "Kaedi", "Maghama", "M'Bout", "Monguel", "Lexeiba" };
        string BraknaNames[6] = { "", "Aleg", "Boghe", "Magta Lahjar", "Bababe", "M'Bagne" };
        const string TrarzaNames[8] = { "", "Rosso", "Boutilimit", "Metherthera", "R'Kiz", "Wad Naga", "Keul Macene", "Tekane" };
        const string AdrarNames[5] = { "", "Atar", "Chinguetti", "Ouadane", "Aoujeft" };
        const string NouadhibouNames[3] = { "", "Nouadhibou", "Chami" };
        const string TagantNames[4] = { "", "Tidjikja", "Moudjeria", "Tichit" };
        const string TirisNames[4] = { "", "Zouerate", "F'Derick", "Bir Moghrein" };
        const string InchiriNames[3] = { "", "Akjoujt", "Bennechab" };
        const string NouakchottWestNames[4] = { "", "Tevragh Zeina", "Ksar", "Sebkha" };
        const string NouakchottNorthNames[4] = { "", "Dar Naim", "Teyarett", "Toujounine" };
        const string NouakchottSouthNames[4] = { "", "Arafat", "El Mina", "Riyad" };
        const string GuidimaghaNames[5] = { "", "Selibabi", "Ould Yenge", "Khabou", "Ghabou" };
        const string StageNames[4] = { "", "Primary School", "Middle School", "High School" };
        const string PrimarySections[7] = { "", "1AF", "2AF", "3AF", "4AF", "5AF", "6AF" };
        const string MiddleSections[5] = { "", "1AS", "2AS", "3AS", "4AS" };
        const string HighSections[11] = { "", "5C", "5D", "5L", "6C", "6D", "6L", "7C", "7D", "7L", "7A" };


        enum Permissions
        {
            pShowstudent = 1,
            pAddstudent = 2,
            pDeletestudent = 4,
            pUpdatestudent = 8,
            pFindstudent = 16,
            pManagestudent = 32,
            pManageUsers = 64,
            pShowuser = 128,
            pAdduser = 256,
            pDeleteuser = 512,
            pUpdateuser = 1024,
            pFinduser = 2048,
            pfeesandpeyementsystem = 4096,
            pTeacherandProfessorManagement = 8192,
            pGradesSystem = 16384,
            pAttendanceSystem = 32768,
            psectionManagement = 65536,
            pusermanegementsystem = 131072,
            pAcademicSubjectManagement = 262144,
            pShowteacher = 524288,
            pAddteacher = 1048576,
            pDeleteteacher = 2097152,
            pUpdateteacher = 4194304,
            pFindteacher = 8388608
        };

        enum enchoiceMunueprogram {
            eShowstudentList = 1,
            eregistrationstudent = 2,
            eDeletestudent = 3,
            eUpdetestudentInfo = 4,
            eFindstudent = 5,
            enExit = 6
        };

        enum enStage {
            PrimarySchool = 1,
            MiddleSchool = 2,
            HighSchool = 3
        };

        enum enMauritaniaStates {
            Hodh_Ech_Charghi = 1,    // «·ÕÊ÷ «·‘—ﬁÌ
            Hodh_El_Gharbi,     // «·ÕÊ÷ «·€—»Ì
            Assaba,              // ·⁄’«»…
            Gorgol,              // ﬂÊ—ﬂÊ·
            Brakna,              // ·»—«ﬂ‰…
            Trarza,              // « —«—“…
            Adrar,               // ¬œ—«—
            Dakhlet_Nouadhibou,  // œ«Œ·  ‰Ê«–Ì»Ê
            Tagant,              //  ﬂ«‰ 
            Tiris_Zemmour,       //  Ì—” “„Ê—
            Inchiri,             // ≈Ì‰‘Ì—Ì
            Nouakchott_West,     // ‰Ê«ﬂ‘Êÿ «·€—»Ì…
            Nouakchott_North,    // ‰Ê«ﬂ‘Êÿ «·‘„«·Ì…
            Nouakchott_South,    // ‰Ê«ﬂ‘Êÿ «·Ã‰Ê»Ì…
            Guidimagha           // ﬂÌœÌ „«€«
        };

        void showstudentslistwithstageandsectionof(vector<Ststudent>Students, vector<Simformationofsection> Vsections);
       
        string Deconstructstring(string section, string stage);

        string knownameofsection(string firstnameofsection, vector<Simformationofsection> Vsections);

        void Deletestudentinfile(string fillename, vector<Ststudent>& vstudents);

        void updetestudent(string fillename, vector<Ststudent>& vstudents, vector<Simformationofsection> Vsections);

        void finduser(vector<Ststudent>& vStudents);

        void Studentregistration(vector<Ststudent>& vStudents, vector<Simformationofsection> Vsections);

        int readchoice(int from, int to);

        string Joinstructstring(Ststudent& student, string delim = "#//#");

        void printspace(int c);

        string knowDistrict(enMauritaniaStates choiceState);

        void savestudents(string fillename, vector<Ststudent>& vstudents);

        string choiceplaceofbirth();

        void AddDataLineToFile(const string& FileName, const string& stDataLine);

        vector<string> SplitString(string S1, string delim = "#//#");

        Ststudent ConvertRecordToClient(string Line, string Seperator = "#//#");

        Simformationofsection ConvertRecordTosection(string Line, string Seperator = "#//#");
        
        vector<Simformationofsection>LoadsectionsFromFile(string FileName);

        bool validatedate(stdateofbirth& date);

        stdateofbirth fdateofbirth();

        string knowSection(enStage choiceStage);

        string knowstageandSection(Ststudent& student);

        void ImplementRequirementsMunueprogram(enchoiceMunueprogram choice, vector<Ststudent>& Students, Cluser::stUser User);

        bool studentfound(vector<Ststudent>& Students, string NNI);

        bool studentfound(vector<Ststudent>& Students, string NNI, string oldnumber);

        void printpageofprogram();

        void printstudentofthissection(Ststudent Student);

        void PrintAllstudentsofthissection(vector<Ststudent> Students, string namesection);

        vector<Ststudent> returnstudentsofthissection(string nameofsection, string nameofstage, vector<Ststudent>Students);
};

