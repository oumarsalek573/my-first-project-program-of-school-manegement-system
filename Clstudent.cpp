#include "Clstudent.h"
#include "Cluser.h"
#include <iomanip>
#include <fstream>
#include <sstream>

using namespace std;

        vector<string> Clstudent::SplitString(string S1, string delim)
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

        Clstudent::Ststudent Clstudent::ConvertRecordToClient(string Line, string Seperator)
        {
            Ststudent student;
            vector<string> vString = SplitString(Line, Seperator);

            student.NNI = vString[0];
            student.Namecomplete = vString[1];
            student.numberphoneofparent = vString[2];
            student.Gender = vString[3];
            student.stage = vString[4];
            student.Academicsection = vString[5];
            student.dateofbirth.year = stoi(vString[6]);
            student.dateofbirth.mounth = stoi(vString[7]);
            student.dateofbirth.day = stoi(vString[8]);
            student.placeofbirth = vString[9];

            return student;
        }

        const string fillename = "studentdatafile.txt";

        static string fillnameofsection = "section.txt";

        Clstudent::Simformationofsection Clstudent::ConvertRecordTosection(string Line, string Seperator)
        {
            Simformationofsection section;
            vector<string> vString = SplitString(Line, Seperator);


            section.stage = vString[0];
            section.name = vString[1];
            section.NumberOfStudentsInTheSection = stoi(vString[2]);


            return section;
        }

        void Clstudent::startofprograme(vector<Clstudent::Ststudent>& Students, Cluser::stUser User)
        {
            while (true)
            {
                system("cls");
                printpageofprogram();
                Clstudent::enchoiceMunueprogram choice = (Clstudent::enchoiceMunueprogram)readchoice(1, 6);
                ImplementRequirementsMunueprogram(choice, Students, User);

                if (choice == Clstudent::enchoiceMunueprogram::enExit)
                {
                    break;
                }
                system("cls");
            }


        }

        vector<Clstudent::Simformationofsection> Clstudent::LoadsectionsFromFile(string FileName)
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

        vector<Clstudent::Ststudent> Clstudent::LoadClientsFromFile(string fillename)
        {
            
            vector<Clstudent::Ststudent> vstudents;
             fstream MyFile(fillename, ios::in);
             if (MyFile.is_open())
             {
                 string Line;
                 while (getline(MyFile, Line))
                 {
                     if (!Line.empty())
                     {
                         Clstudent::Ststudent student = ConvertRecordToClient(Line);
                         vstudents.push_back(student);
                     }
                 };
                 MyFile.close();
             }
             return vstudents;
        }

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

        string Clstudent::Deconstructstring(string section, string stage)
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

        string Clstudent::knownameofsection(string firstnameofsection, vector<Simformationofsection> Vsections)
        {
            vector<string>Vnameofsection = {""};
            for (int i = 0; i < Vsections.size(); i++)
            {
                if (firstnameofsection == Deconstructstring(Vsections[i].name, Vsections[i].stage))
                {
                    Vnameofsection.push_back(Vsections[i].name);
                }
            };
        
            for(int i = 1; i < Vnameofsection.size(); i++)
            {
                cout << "(" << i << "):" << Vnameofsection[i] << endl;
            }
            int c;
            if (Vnameofsection.size() >= 2)
            {
                c = readchoice(1, Vnameofsection.size() - 1);
                return Vnameofsection[c];
            }
            else
            {
                cout << "Sorry!!.\n There are no sections of this type......" << endl;
                system("pause > 0");
                return "no existe";
            }
        }

        void Clstudent::showstudentslistwithstageandsectionof(vector<Clstudent::Ststudent>Students, vector<Simformationofsection> Vsections)
        {
            system("cls");
            cout << "\n=======================================================================================================================================================================" << endl;
            printspace(8);
            cout << "     SCREEN OF SHOW LIST OF STUDENTS     ";
            printspace(8);
            cout << endl;
            cout << "=======================================================================================================================================================================" << endl;
            cout << endl;
            
            cout << "\n\n------- Enter the academic stage for the section whose data you want to view -------\n\n";
            for (int i = 1; i <= 3; i++)
            {
                cout << "(" << i << "):" << StageNames[i] << endl;
            }

            int c = readchoice(1, 3);


            int sectionChoice = 0;

            

            switch ((Clstudent::enStage)c) {
            case Clstudent::enStage::PrimarySchool:
            {
                cout << "\n--- Primary School Sections ---\n";
                for (int i = 1; i <= 6; i++) cout << "(" << i << "): " << PrimarySections[i] << endl;
                sectionChoice = readchoice(1, 6);
                string firstnameofsection = PrimarySections[sectionChoice];
                string nameofsection= knownameofsection(firstnameofsection, Vsections);
                PrintAllstudentsofthissection(returnstudentsofthissection(nameofsection, "Primary School", Students), nameofsection);
                break;
            }
            case Clstudent::enStage::MiddleSchool:
            {
                cout << "\n--- Middle School Sections ---\n";
                for (int i = 1; i <= 4; i++) cout << "(" << i << "): " << MiddleSections[i] << endl;
                sectionChoice = readchoice(1, 4);
                string firstnameofsection = MiddleSections[sectionChoice];
                string nameofsection = knownameofsection(firstnameofsection, Vsections);
                PrintAllstudentsofthissection(returnstudentsofthissection(nameofsection, "Middle School", Students), nameofsection);
                break;
            }

            case Clstudent::enStage::HighSchool:
            {
                cout << "\n--- High School Sections ---\n";

                for (int i = 1; i <= 10; i++) cout << "(" << i << "): " << HighSections[i] << endl;
                sectionChoice = readchoice(1, 10);
                string firstnameofsection = HighSections[sectionChoice];
                string nameofsection = knownameofsection(firstnameofsection, Vsections);
                if(nameofsection != "no existe") 
                {
                    PrintAllstudentsofthissection(returnstudentsofthissection(nameofsection, "High School", Students), nameofsection);
                }
                break;
            }

            default:
                break;
            }




        }

        void Clstudent::Deletestudentinfile(string fillename, vector<Clstudent::Ststudent>& vstudents)
        {
            system("cls");
            cout << "\n========================================================================================================================================================================" << endl;
            printspace(8);
            cout << "       DELETE STUDENTS INFO SCREEN        ";
            printspace(8);
            cout << endl;
            cout << "========================================================================================================================================================================" << endl;
            cout << endl << endl;

            cout << "\n========================================================================= Select Student Info ==========================================================================\n" << endl;

            Ststudent student;

            do {
                cout << "Enter the National identification number of student Which you want deleted" << endl;
                cin >> student.NNI;
            } while (student.NNI.size() != 10 || !studentfound(vstudents, student.NNI));
            cin.ignore();

            for (Ststudent& C : vstudents)
            {
                if (C.NNI == student.NNI)
                {

                    printstudentofthissection(C);

                    cout << "Are you sure you want to delete This student ?" << endl;
                    cout << "=======================" << endl;
                    cout << "(1)-Yes   " << endl;
                    cout << "(2)-No " << endl;
                    cout << "=======================" << endl;
                    int c = readchoice(1, 2);
                    if (c == 1)
                    {
                        C.markdeletclient = true;
                        savestudents(fillename, vstudents);
                        cout << endl << "the student your name is " << C.Namecomplete << " is delete From the Database. " << endl;
                        vstudents = LoadClientsFromFile(fillename);
                        break;
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }

        void Clstudent::updetestudent(string fillename, vector<Ststudent>& vstudents, vector<Simformationofsection> Vsections)
        {
            system("cls");
            cout << "\n========================================================================================================================================================================" << endl;
            printspace(8);
            cout << "        UPDETE STUDENTS INFO SCREEN       ";
            printspace(8);
            cout << endl;
            cout << "========================================================================================================================================================================" << endl;
            cout << endl << endl;

            cout << "\n========================================================================= Select Student Info ==========================================================================\n" << endl;

            Ststudent student;

            do {
                cout << "Enter the National identification number of student Which you want updete" << endl;
                cin >> student.NNI;
            } while (student.NNI.size() != 10 || !studentfound(vstudents, student.NNI));
            cin.ignore();

            for (Ststudent& C : vstudents)
            {
                if (C.NNI == student.NNI)
                {

                    printstudentofthissection(C);

                    cout << "Are you sure you want to delete This student ?" << endl;
                    cout << "=======================" << endl;
                    cout << "(1)-Yes   " << endl;
                    cout << "(2)-No " << endl;
                    cout << "=======================" << endl;
                    int c = readchoice(1, 2);

                    if (c == 1)
                    {
                        do {
                            cout << "Enter the National identification number of student? " << endl;
                            cin >> C.NNI;
                        } while (C.NNI.size() != 10 || studentfound(vstudents, C.NNI, student.NNI));

                        cin.ignore();
                        cout << "Enter the student's full name? " << endl;
                        getline(cin, C.Namecomplete);

                        cout << "Enter the number phone of parent ? " << endl;
                        cin >> C.numberphoneofparent;

                        system("cls");

                        cout << "(1):male" << endl;
                        cout << "(2):Female" << endl;

                        int x = readchoice(1, 2);
                        if (x == 1)
                        {
                            C.Gender = "male";
                        }
                        else
                        {
                            C.Gender = "Female";
                        }


                        C.Academicsection = knownameofsection(knowstageandSection(C), Vsections);

                        system("cls");

                        C.dateofbirth = fdateofbirth();

                        system("cls");
                        C.placeofbirth = choiceplaceofbirth();

                        savestudents(fillename, vstudents);
                        cout << endl << "\nthe student your name is " << C.Namecomplete << " is delete From the Database. " << endl;
                        vstudents = LoadClientsFromFile(fillename);
                        break;
                    }
                    else
                    {
                        break;
                    }
                }
            }


        }

        void Clstudent::finduser(vector<Ststudent>& vStudents)
        {
            system("cls");
            cout << "\n========================================================================================================================================================================" << endl;
            printspace(8);
            cout << "        FIND STUDENT INFO SCREEN          ";
            printspace(8);
            cout << endl;
            cout << "========================================================================================================================================================================" << endl;
            cout << endl << endl;
            Ststudent student;
            do {
                cout << "Enter the National identification number of student Which you want updete" << endl;
                cin >> student.NNI;
            } while (student.NNI.size() != 10 || !studentfound(vStudents, student.NNI));
            cin.ignore();
            for (Ststudent C : vStudents)
            {
                if (C.NNI == student.NNI)
                {
                    printstudentofthissection(C);
                }
            }
        }

        void Clstudent::Studentregistration(vector<Ststudent>& vStudents, vector<Simformationofsection> Vsections)
        {
            system("cls");
            cout << "\n========================================================================================================================================================================" << endl;
            printspace(8);
            cout << "       Student registration screen       ";
            printspace(8);
            cout << endl;
            cout << "========================================================================================================================================================================" << endl;
            cout << endl << endl;

            cout << "\n========================================================================= Select Student Info ==========================================================================\n" << endl;
            Ststudent student;
            do {
                cout << "Enter the National identification number of student? " << endl;
                cin >> student.NNI;
            } while (student.NNI.size() != 10 || studentfound(vStudents, student.NNI));
            cin.ignore();
            cout << "Enter the student's full name? " << endl;
            getline(cin, student.Namecomplete);

            cout << "Enter the number phone of parent ? " << endl;
            cin >> student.numberphoneofparent;

            system("cls");

            cout << "(1):male" << endl;
            cout << "(2):Female" << endl;

            int c = readchoice(1, 2);
            if (c == 1)
            {
                student.Gender = "male";
            }
            else
            {
                student.Gender = "Female";
            }
            student.Academicsection = knownameofsection(knowstageandSection(student), Vsections);

            system("cls");

            student.dateofbirth = fdateofbirth();

            system("cls");
            student.placeofbirth = choiceplaceofbirth();

            AddDataLineToFile(fillename, Joinstructstring(student));

            vStudents = LoadClientsFromFile(fillename);
            cout << "Done the student has been registered ? " << endl;

        }

        int Clstudent::readchoice(int from, int to)
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

        string Clstudent::Joinstructstring(Ststudent& student, string delim )
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

        void Clstudent::printspace(int c)
        {
            for (int i = 1; i <= c; i++)
            {
                cout << "\t";
            }
        }

        string Clstudent::knowDistrict(Clstudent::enMauritaniaStates choiceState) {
            int districtChoice = 0;

            switch (choiceState) {
            case Hodh_Ech_Charghi:
                for (int i = 1; i <= 8; i++) cout << "(" << i << "): " << HodhCharghiNames[i] << endl;
                districtChoice = readchoice(1, 8);
                return HodhCharghiNames[districtChoice];

            case Hodh_El_Gharbi:
                for (int i = 1; i <= 5; i++) cout << "(" << i << "): " << HodhGharbiNames[i] << endl;
                districtChoice = readchoice(1, 5);
                return HodhGharbiNames[districtChoice];

            case Assaba:
                for (int i = 1; i <= 5; i++) cout << "(" << i << "): " << AssabaNames[i] << endl;
                districtChoice = readchoice(1, 5);
                return AssabaNames[districtChoice];

            case Gorgol:
                for (int i = 1; i <= 5; i++) cout << "(" << i << "): " << GorgolNames[i] << endl;
                districtChoice = readchoice(1, 5);
                return GorgolNames[districtChoice];

            case Brakna:
                for (int i = 1; i <= 5; i++) cout << "(" << i << "): " << BraknaNames[i] << endl;
                districtChoice = readchoice(1, 5);
                return BraknaNames[districtChoice];

            case Trarza:
                for (int i = 1; i <= 7; i++) cout << "(" << i << "): " << TrarzaNames[i] << endl;
                districtChoice = readchoice(1, 7);
                return TrarzaNames[districtChoice];

            case Adrar:
                for (int i = 1; i <= 4; i++) cout << "(" << i << "): " << AdrarNames[i] << endl;
                districtChoice = readchoice(1, 4);
                return AdrarNames[districtChoice];

            case Dakhlet_Nouadhibou:
                for (int i = 1; i <= 2; i++) cout << "(" << i << "): " << NouadhibouNames[i] << endl;
                districtChoice = readchoice(1, 2);
                return NouadhibouNames[districtChoice];

            case Tagant:
                for (int i = 1; i <= 3; i++) cout << "(" << i << "): " << TagantNames[i] << endl;
                districtChoice = readchoice(1, 3);
                return TagantNames[districtChoice];

            case Tiris_Zemmour:
                for (int i = 1; i <= 3; i++) cout << "(" << i << "): " << TirisNames[i] << endl;
                districtChoice = readchoice(1, 3);
                return TirisNames[districtChoice];

            case Inchiri:
                for (int i = 1; i <= 2; i++) cout << "(" << i << "): " << InchiriNames[i] << endl;
                districtChoice = readchoice(1, 2);
                return InchiriNames[districtChoice];

            case Nouakchott_West:
                for (int i = 1; i <= 3; i++) cout << "(" << i << "): " << NouakchottWestNames[i] << endl;
                districtChoice = readchoice(1, 3);
                return NouakchottWestNames[districtChoice];

            case Nouakchott_North:
                for (int i = 1; i <= 3; i++) cout << "(" << i << "): " << NouakchottNorthNames[i] << endl;
                districtChoice = readchoice(1, 3);
                return NouakchottNorthNames[districtChoice];

            case Nouakchott_South:
                for (int i = 1; i <= 3; i++) cout << "(" << i << "): " << NouakchottSouthNames[i] << endl;
                districtChoice = readchoice(1, 3);
                return NouakchottSouthNames[districtChoice];

            case Guidimagha:
                for (int i = 1; i <= 4; i++) cout << "(" << i << "): " << GuidimaghaNames[i] << endl;
                districtChoice = readchoice(1, 4);
                return GuidimaghaNames[districtChoice];
            default:
                return "Unknown";
            }
        }

        void Clstudent::savestudents(string fillename, vector<Ststudent>& vstudents)
        {
            fstream MyFile(fillename, ios::out);

            if (MyFile.is_open())
            {
                for (Ststudent& C : vstudents)
                {
                    if (!C.markdeletclient)
                    {
                        MyFile << Joinstructstring(C) << endl;
                    }
                }

                MyFile.close();
            }
        }

        string Clstudent::choiceplaceofbirth()
        {
            cout << "\n------- Select State -------\n";
            for (int i = 1; i <= 15; i++)
            {
                if (i <= 9)
                    cout << "(" << i << ") :" << StateNames[i] << endl;
                else
                    cout << "(" << i << "):" << StateNames[i] << endl;
            }
            return(knowDistrict((enMauritaniaStates)readchoice(1, 15)));
        }

        void Clstudent::AddDataLineToFile(const string& FileName, const string& stDataLine)
        {
            fstream MyFile(FileName, ios::app);
            if (MyFile.is_open())
            {
                MyFile << stDataLine << endl;
                MyFile.close();
            }

        }

        bool Clstudent::isLeapYear(short Year)
        {
            return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
        }

        short Clstudent::NumberOfDaysInAMonth(short Month, short Year)
        {
            if (Month < 1 || Month > 12) return 0;
            int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
            return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : days[Month - 1];
        }

        bool Clstudent::validatedate(stdateofbirth& date)
        {
            time_t t = time(0);
            tm* now = localtime(&t);
            int Year = now->tm_year + 1900;
            int Month = now->tm_mon + 1;
            int Day = now->tm_mday;

            int age = Year - date.year;
            if (date.year < 1 || date.year > Year || age < 5)
                return false;
            if (date.mounth < 1 || date.mounth > 12)
                return false;
            if (date.day < 1 || date.day > NumberOfDaysInAMonth(date.mounth, date.year))
                return false;

            return true;
        }

        Clstudent::stdateofbirth Clstudent::fdateofbirth()
        {
            stdateofbirth date;
            do
            {
                cout << "Enter year of birth? ";
                cin >> date.year;
                cout << "Enter month of birth? ";
                cin >> date.mounth;
                cout << "Enter day of birth? ";
                cin >> date.day;

                if (!validatedate(date))
                    cout << "Invalid date, please try again." << endl;

            } while (!validatedate(date));

            return date;
        }

        string Clstudent::knowSection(enStage choiceStage) {
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

        string Clstudent::knowstageandSection(Ststudent& student)
        {
            system("cls");
            cout << "\n------- Select Stage -------\n";
            for (int i = 1; i <= 3; i++)
            {
                cout << "(" << i << ") :" << StageNames[i] << endl;
            }
            int c = readchoice(1, 3);
            student.stage = StageNames[c];
            return (knowSection((enStage)c));
        }

        void Clstudent::ImplementRequirementsMunueprogram(Clstudent::enchoiceMunueprogram choice, vector<Ststudent>& Students, Cluser::stUser User)
        {

            int permission;
            vector<Simformationofsection> Vsections = LoadsectionsFromFile(fillnameofsection);
            auto showNoAccessMessage = []() {
                cout << "\n\n--------------------------------------------\n";
                cout << "Access Denied,\n";
                cout << "You dont Have Permissions To Do this,\n";
                cout << "Please contact Your Admin.\n";
                cout << "--------------------------------------------\n";
            };

            switch (choice)
            {
            case Clstudent::enchoiceMunueprogram::eShowstudentList:

                permission = (int)Cluser::Permissions::pShowstudent;

                if ((User.Permissions & permission) == permission)
                {
                    system("cls");
                    showstudentslistwithstageandsectionof(Students, Vsections);
                }
                else
                {
                    showNoAccessMessage();
                }

                cout << "Press any key to go back...";
                system("pause>0");
                system("cls");

                break;

            case Clstudent::enchoiceMunueprogram::eregistrationstudent:

                permission = (int)Cluser::Permissions::pAddstudent;

                if ((User.Permissions & permission) == permission)
                {
                    system("cls");
                    Studentregistration(Students, Vsections);
                }
                else
                {
                    showNoAccessMessage();
                }

                cout << "Press any key to go back...";
                system("pause>0");
                system("cls");

                break;

            case Clstudent::enchoiceMunueprogram::eFindstudent:

                permission = (int)Cluser::Permissions::pFindstudent;

                if ((User.Permissions & permission) == permission)
                {
                    system("cls");
                    finduser(Students);
                }
                else
                {
                    showNoAccessMessage();
                }

                cout << "Press any key to go back...";
                system("pause>0");
                system("cls");

                break;

            case Clstudent::enchoiceMunueprogram::eDeletestudent:

                permission = (int)Cluser::Permissions::pDeletestudent;

                if ((User.Permissions & permission) == permission)
                {
                    system("cls");
                    Deletestudentinfile(fillename, Students);
                }
                else
                {
                    showNoAccessMessage();
                }

                cout << "Press any key to go back...";
                system("pause>0");
                system("cls");

                break;

            case Clstudent::enchoiceMunueprogram::eUpdetestudentInfo:

                permission = (int)Cluser::Permissions::pUpdatestudent;

                if ((User.Permissions & permission) == permission)
                {
                    system("cls");
                    updetestudent(fillename, Students, Vsections);
                }
                else
                {
                    showNoAccessMessage();
                }

                cout << "Press any key to go back...";
                system("pause>0");
                system("cls");

                break;

            case Clstudent::enchoiceMunueprogram::enExit:
                break;
            }
        }

        bool Clstudent::studentfound(vector<Ststudent>& Students, string NNI)
        {
            for (Ststudent& vstudent : Students)
            {
                if (vstudent.NNI == NNI)
                {
                    return true;
                }
            }
            return false;
        }

        bool Clstudent::studentfound(vector<Ststudent>& Students, string NNI, string oldnumber)
        {
            for (Ststudent& vstudent : Students)
            {
                if (vstudent.NNI == NNI)
                {
                    if (NNI == oldnumber)
                    {

                    }
                    else
                    {
                        return true;
                    }
                }
            }
            return false;
        }

        void Clstudent::printpageofprogram()
        {
            cout << "\n==================================================" << endl;
            cout << "MAIN MENUE SCREEN OF STUDENT MANEGMENT" << endl;
            cout << "==================================================" << endl;
            cout << "\t(1) Show Student List " << endl;
            cout << "\t(2) Student registration " << endl;
            cout << "\t(3) Delete Student " << endl;
            cout << "\t(4) Updete Student Info " << endl;
            cout << "\t(5) Find Student " << endl;
            cout << "\t(6) EXIT " << endl;
            cout << "==================================================" << endl;
            cout << endl;
        }

        void Clstudent::printstudentofthissection(Ststudent Student)
        {
            cout << endl << endl;
            cout << "\n\t\t\t\t\t\t\t\t--------------------Student information--------------------\n" << endl;
            cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";

            cout << left << setw(15) << "Student Name"
                << left << ":" << Student.Namecomplete << endl
                << setw(15) << "Parent phone"
                << left << ":" << Student.numberphoneofparent << endl
                << setw(15) << "Gender"
                << left << ":" << Student.Gender << endl
                << setw(15) << "Acad.Stage"
                << left << ":" << Student.stage << endl
                << setw(15) << "Acad.section"
                << left << ":" << Student.Academicsection << endl
                << setw(15) << "Yr. of Birth"
                << left << ":" << Student.dateofbirth.year << endl
                << setw(15) << "mth. of birth"
                << left << ":" << Student.dateofbirth.mounth << endl
                << setw(15) << "dy. of birth"
                << left << ":" << Student.dateofbirth.day << endl
                << setw(15) << "place of birth"
                << left << ":" << Student.placeofbirth << endl;
            cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
            cout << endl << endl;

        }

        void Clstudent::PrintAllstudentsofthissection(vector<Ststudent> Students, string namesection)
        {
            system("cls");
            cout << "\n=======================================================================================================================================================================" << endl;
            printspace(8);
            cout << "     SCREEN OF SHOW LIST OF STUDENTS     ";
            printspace(8);
            cout << endl;
            cout << "=======================================================================================================================================================================" << endl;
            cout << endl;

            cout << endl << endl;
            cout << "\n\t\t\t\t\t\t\t\STUDENTS List (" << Students.size() << ") student(s)." << endl;
            cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
            cout << left << setw(10) << "NNI"
                << "| " << setw(42) << "Student Name"
                << "| " << setw(12) << "Parent phone"
                << "| " << setw(6) << "Gender"
                << "| " << setw(14) << "Acad.Stage"
                << "| " << setw(12) << "Acad.section"
                << "| " << setw(12) << "Yr. of Birth"
                << "| " << setw(13) << "mth. of birth"
                << "| " << setw(12) << "dy. of birth"
                << "| " << setw(13) << "place of birth" << endl;

            cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";

            for (Ststudent& C : Students)
            {
                cout << left << setw(10) << C.NNI
                    << "| " << setw(42) << C.Namecomplete
                    << "| " << setw(12) << C.numberphoneofparent
                    << "| " << setw(6) << C.Gender
                    << "| " << setw(14) << C.stage
                    << "| " << setw(12) << C.Academicsection
                    << "| " << setw(12) << C.dateofbirth.year
                    << "| " << setw(13) << C.dateofbirth.mounth
                    << "| " << setw(12) << C.dateofbirth.day
                    << "| " << setw(13) << C.placeofbirth << endl;
                cout << endl;
            }
            cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";

            cout << endl << endl;
        }

        vector<Clstudent::Ststudent> Clstudent::returnstudentsofthissection(string nameofsection, string nameofstage, vector<Ststudent>Students)
        {
            vector<Ststudent>Studentsofsectionnow;
            {
            cout << "================= show student of section " << nameofsection << "=================" << endl;
            cout << "================= number of student is " << endl;
            for (Ststudent& vstudent : Students)
                if (nameofstage == vstudent.stage)
                {
                    if (nameofsection == vstudent.Academicsection)
                    {
                        Studentsofsectionnow.push_back(vstudent);
                    }
                }
            }
            return Studentsofsectionnow;
        }



