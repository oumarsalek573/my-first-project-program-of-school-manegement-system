#include "Clsection.h"
#include "Clstudent.h"
#include "Cluser.h"
#include <iomanip> 
#include <fstream>
#include <sstream>

using namespace std;

void Clsection::ImplementationRequirementsmunueofsystemsection(enchoiceofmunueofsystemsection choice, Cluser::stUser user)
{
    vector<Simformationofsection>Vsections = LoadsectionsFromFile(fillnameofsection);
    auto showNoAccessMessage = []() {
        cout << "\n\n--------------------------------------------" << endl;
        cout << "Access Denied," << endl;
        cout << "You dont Have Permissions To Do this," << endl;
        cout << "Please conact Your Admin." << endl;
        cout << "--------------------------------------------" << endl;
        };
    int permetion = 0;
    switch (choice)
    {
    case enchoiceofmunueofsystemsection::enAddsection:
        permetion = (int)Cluser::Permissions::pAddsection;
        if ((user.Permissions & permetion) == permetion)
        {
            addsection(Vsections);
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
        Startmunueofsystemsection(user);
        break;
    case enchoiceofmunueofsystemsection::enShowsection:
        permetion = (int)Cluser::Permissions::pshowsection;
        if ((user.Permissions & permetion) == permetion)
        {
            showsectionlist(Vsections);
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
        Startmunueofsystemsection(user);
        break;
    case enchoiceofmunueofsystemsection::enDeletesection:
        permetion = (int)Cluser::Permissions::pDeletesection;
        if ((user.Permissions & permetion) == permetion)
        {
            Deletesection(Vsections);
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
        Startmunueofsystemsection(user);
        break;
    case enchoiceofmunueofsystemsection::enUpdatesection:
        permetion = (int)Cluser::Permissions::pUpdatesection;
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
        Startmunueofsystemsection(user);
        break;
    case enchoiceofmunueofsystemsection::enFindsection:
        permetion = (int)Cluser::Permissions::pfindsection;
        if ((user.Permissions & permetion) == permetion)
        {
            FindSection(Vsections);
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
        Startmunueofsystemsection(user);
        break;
    case enchoiceofmunueofsystemsection::enExit:
        system("cls");
        break;

    }
}

void Clsection::Startmunueofsystemsection(Cluser::stUser user)
{
    cout << "\n========================================================" << endl;
    cout << "MAIN MENUE SCREEN OF SYSTEM MANEGEMENT SECTION" << endl;
    cout << "========================================================" << endl;
    cout << "\t(1)  Show section screen" << endl;
    cout << "\t(2)  Add section screen" << endl;
    cout << "\t(3)  Delete section screen" << endl;
    cout << "\t(4)  Update section screen" << endl;
    cout << "\t(5)  Find section screen" << endl;
    cout << "\t(6)  Exit" << endl;
    cout << "========================================================" << endl;
    cout << endl;

    enchoiceofmunueofsystemsection choice = (enchoiceofmunueofsystemsection)readchoice(1, 6);

    ImplementationRequirementsmunueofsystemsection(choice, user);

}

const string PrimarySections[7] = { "", "1AF", "2AF", "3AF", "4AF", "5AF", "6AF" };
const string MiddleSections[5] = { "", "1AS", "2AS", "3AS", "4AS" };
const string HighSections[11] = { "", "5C", "5D", "5L", "6C", "6D", "6L", "7C", "7D", "7L", "7A" };
const string StageNames[4] = { "", "Primary School", "Middle School", "High School" };

string fillnameofsection = "section.txt";

vector<string> Clsection::SplitString(string S1, string delim)
{
    vector<string> vString;
    size_t pos = 0;
    string sWord;

    while ((pos = S1.find(delim)) != string::npos)
    {
        sWord = S1.substr(0, pos);
        if (sWord != "")
        {
            vString.push_back(sWord);
        }
        S1.erase(0, pos + delim.length());
    }
    if (S1 != "")
    {
        vString.push_back(S1);
    }

    return vString;
}

Clsection::Simformationofsection Clsection::ConvertRecordTosection(string Line, string Seperator)
{
    Simformationofsection section;
    vector<string> vString = SplitString(Line, Seperator);


    section.stage = vString[0];
    section.name = vString[1];
    section.NumberOfStudentsInTheSection = stoi(vString[2]);


    return section;
}

void Clsection::PrintAllsections(vector<Simformationofsection>Vsections)
{
    cout << endl << endl;
    cout << "\n\t\t\t\t\t\t\t\tCLIENTS List (" << Vsections.size() << ") Client(s)." << endl;
    cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
    cout << left << setw(56) << "Name Of Academic Section"
        << "| " << setw(56) << "Name Of Academic Section"
        << "| " << setw(57) << "Number Of Students In The Section" << endl;

    cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";

    for (Simformationofsection& C : Vsections)
    {
        cout << left << setw(56) << C.stage
            << "| " << setw(56) << C.name
            << "| " << setw(57) << C.NumberOfStudentsInTheSection;
        cout << endl;
    }
    cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
}

bool Clsection::isNumber(string str)
{
    if (str.empty()) return false;
    for (char c : str)
    {
        if (!isdigit(c)) return false;
    }
    return true;
}

int Clsection::getValidatedNumber(string massage, bool massegetrueorfalse)
{
    string input;
    while (true)
    {
        if (massegetrueorfalse)
        {
            cout << massage;
        }
        cin >> input;

        if (isNumber(input))
        {
            return stoi(input);
        }
        else
        {
            cout << "Invalid! Please enter digits only (0-9)." << endl;
        }
    }
}

void Clsection::showsectionlist(vector<Simformationofsection>Vsections)
{
    system("cls");
    cout << "\n========================================================================================================================================================================" << endl;
    printspace(64);
    cout << "        SHOW SECTION INFO SCREEN         ";
    printspace(64);
    cout << endl;
    cout << "========================================================================================================================================================================" << endl;
    cout << endl << endl;
    if (Vsections.empty())
    {
        cout << "has not existe a section?";
    }
    else
    {
        PrintAllsections(Vsections);
    }
}

bool Clsection::sectionisfound(vector<Simformationofsection>Vsections, string nameclass, Simformationofsection& Section)
{
    for (Simformationofsection& section : Vsections)
    {
        if (section.name == nameclass)
        {
            Section = section;
            return true;

        }
    }
    return false;
}

bool Clsection::sectionisfound(vector<Simformationofsection>Vsections, string nameclass)
{
    for (Simformationofsection& section : Vsections)
    {
        if (section.name == nameclass)
        {
            return true;

        }
    }
    return false;
}

void Clsection::printrules()
{
    cout << "RULES AND REGULATIONS THAT MUST BE FOLLOWED TO PROTECT DATA FROM LOSS:" << endl << endl;

    for (int i = 1; i <= 111; i++)
    {
        cout << "*";
    }

    cout << endl;



    cout << "*";
    cout << " The sections you will enter must be available.";
    printspace(62);
    cout << "*" << endl;
    cout << "*";
    cout << " If you want to delete a section, you must transfer the student data to another section.";
    printspace(21);
    cout << "*" << endl;
    cout << "*";
    cout << " The section you want to transfer student data to must be of the same type as the section you want to delete.";
    cout << "*" << endl;

    for (int i = 1; i <= 111; i++)
    {
        cout << "*";
    }
    cout << endl << endl;


}

string Clsection::Deconstructstring(string section, string stage)
{
    if (stage == "High School")
    {
        string s1 = "";
        s1 = s1 + section[0] + section[1];
        return s1;
    }
    else
    {
        string s1 = "";
        s1 = s1 + section[0] + section[1] + section[2];
        return s1;
    }



}

int Clsection::returnnumberofsection(string section, string stage)
{

    if (stage == "High School")
    {

        return (int)(section[2] - '0');
    }
    else
    {

        return (int)(section[3] - '0');
    }


}

string Clsection::knowSection(enStage choiceStage) {
    int sectionChoice = 0;

    switch (choiceStage) {
    case PrimarySchool:
        cout << "\n--- Primary School Sections ---\n";
        for (int i = 1; i <= 6; i++) cout << "(" << i << "): " << PrimarySections[i] << endl;
        sectionChoice = readchoice(1, 6);
        return PrimarySections[sectionChoice];

    case MiddleSchool:
        cout << "\n--- Middle School Sections ---\n";
        for (int i = 1; i <= 4; i++) cout << "(" << i << "): " << MiddleSections[i] << endl;
        sectionChoice = readchoice(1, 4);
        return MiddleSections[sectionChoice];

    case HighSchool:
        cout << "\n--- High School Sections ---\n";

        for (int i = 1; i <= 10; i++) cout << "(" << i << "): " << HighSections[i] << endl;
        sectionChoice = readchoice(1, 10);
        return HighSections[sectionChoice];

    default:
        return "Unknown";
    }
}

string Clsection::knowstageandSection(Simformationofsection& section)
{
    system("cls");
    cout << "\n------- Select Stage -------\n";
    for (int i = 1; i <= 3; i++)
    {
        cout << "(" << i << ") :" << StageNames[i] << endl;
    }
    int c = readchoice(1, 3);
    section.stage = StageNames[c];
    return (knowSection((enStage)c));
}

int Clsection::returnThelargestnumber(vector<int>Vnumbers)
{
    int max = Vnumbers[0];

    for (int i = 1; i < Vnumbers.size(); i++) {
        if (Vnumbers[i] > max) {
            max = Vnumbers[i];
        }
    }

    return max;
}

void Clsection::addsection(vector<Simformationofsection>Vsections)
{
    system("cls");
    cout << "\n========================================================================================================================================================================" << endl;
    printspace(64);
    cout << "        ADD SECTION INFO SCREEN         ";
    printspace(64);
    cout << endl;
    cout << "========================================================================================================================================================================" << endl;
    cout << endl << endl;

    Simformationofsection section;

    string SectionInitialName;

    SectionInitialName = knowstageandSection(section);

    cout << "===============================================================================================" << endl;
    cout << "Munue of choise " << endl;
    cout << "===============================================================================================" << endl;
    cout << "(1):you want the program automatically to complete the rest of the process (selecting the section number)." << endl;
    cout << "(2):You complete it." << endl;
    cout << "===============================================================================================" << endl;
    int numberofsection = 0;
    int choice = readchoice(1, 2);
    vector<int>Vnumbersofsections;

    for (Simformationofsection& C : Vsections)
    {
        if ((C.stage == section.stage))
        {
            if (Deconstructstring(C.name, C.stage) == SectionInitialName)
            {
                int x = returnnumberofsection(C.name, C.stage);
                Vnumbersofsections.push_back(x);
            }
        }
    }
    int numberofsectionvalide;
    if (Vnumbersofsections.empty() || Vsections.empty())
    {
        numberofsectionvalide = 1;
    }
    else
    {
        numberofsectionvalide = returnThelargestnumber(Vnumbersofsections) + 1;
    }
    if (choice == 1)
    {
        numberofsection = numberofsectionvalide;
    }
    else
    {
        bool validenumber = false;
        cout << "Enter number of section?" << endl;
        cin >> numberofsection;
        while (!validenumber)
        {
            if (numberofsectionvalide == numberofsection)
            {
                validenumber = true;
            }
            else
            {

                cout << "Invalid number ." << endl;
                cout << "This number is not available." << endl
                    << " Exceeding a number or entering an existing number"
                    << "is not allowed because the last section has the number " << numberofsectionvalide << endl;
                cout << "Enter number of section ? " << endl;
                cin >> numberofsection;
            }

        }
    }

    section.name = SectionInitialName + to_string(numberofsection);

    cout << "The name of section is " << section.name << endl;
    AddDataLineToFile(fillnameofsection, Joinstructstring(section));

    system("cls");

    cout << endl << endl << endl << "\nthe section named " << section.name << " is save on the Database. ";




}

string Clsection::Joinstructstring(Clstudent::Ststudent& student, string delim)
{
    stringstream ss;
    ss << student.NNI << delim
        << student.Namecomplete << delim
        << student.numberphoneofparent << delim
        << student.Gender << delim
        << student.stage << delim
        << student.Academicsection << delim
        << student.dateofbirth.year << delim
        << student.dateofbirth.mounth << delim
        << student.dateofbirth.day << delim
        << fixed << setprecision(2) << student.placeofbirth;

    return ss.str();
}

void Clsection::savestudents(string fillename, vector<Clstudent::Ststudent>& vstudents)
{
    fstream MyFile(fillename, ios::out);

    if (MyFile.is_open())
    {
        for (Clstudent::Ststudent& C : vstudents)
        {
            if (!C.markdeletclient)
            {
                MyFile << Joinstructstring(C) << endl;
            }
        }

        MyFile.close();
    }
}

void Clsection::Deletesection(vector<Simformationofsection>Vsections)
{
    system("cls");
    cout << "\n========================================================================================================================================================================" << endl;
    printspace(64);
    cout << "       DELETE SECTION INFO SCREEN        ";
    printspace(64);
    cout << endl;
    cout << "========================================================================================================================================================================" << endl;
    cout << endl << endl;
    printrules();

    string nameclass;
    Simformationofsection Section;

    cout << "Enter name of section you want delete? " << endl;
    cin >> nameclass;
    while (!sectionisfound(Vsections, nameclass, Section))
    {
        cout << "It seems you did not follow the rules." << endl;
        cout << "Section name does not exist." << endl;
        cout << "Enter name of section you want delete? " << endl;
        cin >> nameclass;
    }

    string characterofsection;
    characterofsection = Deconstructstring(Section.name, Section.stage);

    string newclass;
    cout << endl << endl << "Enter the name of the section you want to transfer the students to." << endl;
    cin >> newclass;

    while ((!iscorrectsection(characterofsection, newclass, Section.stage) || (newclass == nameclass)) || !sectionisfound(Vsections, newclass))
    {
        cout << "It seems you did not follow the rules." << endl;
        cout << "Section name does not exist or not correct." << endl;
        cout << "Enter the name of the section you want to transfer the students to." << endl;
        cin >> newclass;
    }

    // «” Œœ„ ﬂ«∆‰ Clstudent „»«‘—… »œ·« „‰ «·„ƒ‘—
    Clstudent studentManager;
    vector<Clstudent::Ststudent> VStudent = studentManager.LoadClientsFromFile(studentManager.fillename);

    for (Clstudent::Ststudent& C : VStudent)
    {
        if (C.stage == Section.stage)
        {
            if (C.Academicsection == nameclass)
            {
                C.Academicsection = newclass;
            }
        }
    }

    savestudents(studentManager.fillename, VStudent);

    for (Simformationofsection& section : Vsections)
    {
        if (section.name == nameclass)
        {
            section.markdelete = true;
            savesections(fillnameofsection, Vsections);

            vector<Simformationofsection> VsectionsReload = LoadsectionsFromFile(fillnameofsection);

            break;
        }
    }
}

void Clsection::FindSection(vector<Simformationofsection>Vsections)
{
    system("cls");
    cout << "\n========================================================================================================================================================================" << endl;
    printspace(64);
    cout << "          FIND SECTION SCREEN            ";
    printspace(64);
    cout << endl;
    cout << "========================================================================================================================================================================" << endl;
    cout << endl << endl;

    string nameclass;
    Simformationofsection Section;

    cout << "Enter name of section you want search her? " << endl;
    cin >> nameclass;
    while (!sectionisfound(Vsections, nameclass, Section))
    {
        cout << "Section name does not exist." << endl;
        cout << "Enter name of section you want search her? " << endl;
        cin >> nameclass;
    }

    for (int i = 1; i <= 40; i++)
    {
        cout << "*";
    }

    cout << endl;



    cout << "*";
    cout << "Section Name: " << Section.name;
    printspace(62);
    cout << "*" << endl;
    cout << "*";
    cout << "Section stage: " << Section.stage;
    printspace(21);
    cout << "*" << endl;
    cout << "*";
    cout << "Number Of Students In The Section : " << Section.NumberOfStudentsInTheSection;
    cout << "*" << endl;

    for (int i = 1; i <= 40; i++)
    {
        cout << "*";
    }
    cout << endl << endl;



}

void Clsection::printspace(int c)
{
    for (int i = 1; i <= c; i++)
    {
        cout << " ";
    }
}

vector<Clsection::Simformationofsection> Clsection::LoadsectionsFromFile(string FileName)
{
    vector<Simformationofsection> vstudents;
    fstream MyFile(FileName, ios::in);
    if (MyFile.is_open())
    {
        string Line;
        while (getline(MyFile, Line))
        {
            if (!Line.empty())
            {
                Simformationofsection section = ConvertRecordTosection(Line);
                vstudents.push_back(section);
            }
        };
        MyFile.close();
    }
    return vstudents;
}

int Clsection::readchoice(int from, int to)
{
    int choice;
    cout << "choose what do you want to do?[" << from << " to " << to << "]" << endl;
    choice = getValidatedNumber("", false);

    while (choice < from || choice  > to)
    {
        cout << "Wrong choice." << endl << "Only enter the options that are in the attached menu at the beginning of the page." << endl;
        choice = getValidatedNumber("", false);
    }
    return choice;
}

string Clsection::Joinstructstring(Simformationofsection& section, string delim)
{
    stringstream ss;
    ss << section.stage << delim
        << section.name << delim
        << fixed << setprecision(2) << section.NumberOfStudentsInTheSection;
    return ss.str();
}

void Clsection::savesections(string fillename, vector<Simformationofsection>& vsections)
{
    fstream MyFile(fillename, ios::out);

    if (MyFile.is_open())
    {
        for (Simformationofsection& C : vsections)
        {
            if (!C.markdelete)
            {
                MyFile << Joinstructstring(C) << endl;
            }
        }
        MyFile.close();
    }
}

void Clsection::AddDataLineToFile(const string& FileName, const string& stDataLine)
{
    fstream MyFile(FileName, ios::app);
    if (MyFile.is_open())
    {
        MyFile << stDataLine << endl;
        MyFile.close();
    }
}

bool Clsection::iscorrectsection(string characterofsection, string newclass, string stage)
{
    if (stage == "High School")
    {
        string s1 = "";
        s1 = s1 + newclass[0] + newclass[1];
        if (s1 == characterofsection)
        {
            return true;
        }
    }
    else
    {
        string s1 = "";
        s1 = s1 + newclass[0] + newclass[1] + newclass[2];
        if (s1 == characterofsection)
        {
            return true;
        }
    }
    return false;
}