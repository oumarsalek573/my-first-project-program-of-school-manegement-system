#include "Cluser.h"
#include <iomanip> 
#include <fstream>
#include <sstream>

    vector<string> Cluser::SplitString(string S1, string delim)
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

    Cluser::stUser Cluser::ConvertRecordTouser(string Line, string Seperator)
{
    stUser user;
    vector<string> vString = SplitString(Line, Seperator);

    user.username = vString[0];
    user.pincode = vString[1];
    user.Permissions = stoi(vString[2]);
    return user;
}

    bool  Cluser::chekalluserandreturnuser(vector<stUser>& Vusers, stUser& infoofuser)
    {
        for (Cluser::stUser& vuser : Vusers)
        {
            if (vuser.username == infoofuser.username && vuser.pincode == infoofuser.pincode)
            {
                infoofuser.Permissions = vuser.Permissions;
                return true;
            }

        }

        return false;


    }

    void Cluser::Menuemanegeusers(stUser user)
    {
        bool exitfrommanegeusers = false;
        while(!exitfrommanegeusers){
            system("cls");
            cout << "\n==================================================" << endl;
            cout << "MANEGE USERS MENUE SCREEN" << endl;
            cout << "==================================================" << endl;
            cout << "\t(1) Show user List " << endl;
            cout << "\t(2) Add New user " << endl;
            cout << "\t(3) Delete user " << endl;
            cout << "\t(4) Updete user Info " << endl;
            cout << "\t(5) Find user " << endl;
            cout << "\t(6) Exit" << endl;
            cout << "==================================================" << endl;
            cout << endl;
            Cluser::enmanegeusers choice = (Cluser::enmanegeusers)readchoice(1, 6);
            
            
            system("cls");
            if(choice== enmanegeusers::Exit)
            {
                break;
            }
            ImplementRequirementsClassmanigeusersMenue(choice, user);
        }
    }

    const string userFilename = "User.txt";

    vector<Cluser::stUser> Cluser::LoaduserssFromFile(string FileName)
    {
        vector<Cluser::stUser> vClients;
        fstream MyFile(FileName, ios::in);
        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                if (!Line.empty())
                {
                    Cluser::stUser user = ConvertRecordTouser(Line);
                    vClients.push_back(user);
                }
            }
            MyFile.close();
        }
        return vClients;
    }

    void Cluser::ImplementRequirementsClassmanigeusersMenue(Cluser::enmanegeusers choice, stUser user)
    {
        int permetion;



        vector<stUser> vusers = LoaduserssFromFile(userFilename);

        auto showNoAccessMessage = []() {
            cout << "\n\n--------------------------------------------" << endl;
            cout << "Access Denied," << endl;
            cout << "You dont Have Permissions To Do this," << endl;
            cout << "Please conact Your Admin." << endl;
            cout << "--------------------------------------------" << endl;
            };

        switch (choice)
        {
        case Cluser::enmanegeusers::eShowuserslist:
            permetion = (int)Cluser::Permissions::pShowuser;
            if ((user.Permissions & permetion) == permetion)
            {
                PrintAllusers(vusers);
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
        case Cluser::enmanegeusers::eAddNewusers:
            permetion = (int)Cluser::Permissions::pAdduser;
            if ((user.Permissions & permetion) == permetion)
            {
                addusersonfilefinal(vusers);
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
        case Cluser::enmanegeusers::eDeleteusers:
            permetion = (int)Cluser::Permissions::pDeleteuser;
            if ((user.Permissions & permetion) == permetion)
            {
                deleteusersinfile(userFilename, vusers, user);
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
        case Cluser::enmanegeusers::eUpdeteusersInfo:
            permetion = (int)Cluser::Permissions::pUpdateuser;
            if ((user.Permissions & permetion) == permetion)
            {
                updateusers(userFilename, vusers);
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
        case Cluser::enmanegeusers::eFindusers:
            permetion = (int)Cluser::Permissions::pFinduser;
            if ((user.Permissions & permetion) == permetion)
            {
                findusersoneScreen(vusers);
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
        case Cluser::enmanegeusers::Exit:

            break;




        }
    }

    void Cluser::addusersonfilefinal(vector<stUser>& Vusers)
    {
        stUser user;
        cout << "\n==================================================" << endl;
        cout << "\t ADD NEW user SCREEN" << endl;
        cout << "==================================================" << endl;
        cout << "Adding New user:" << endl;
        string addclient;
        do {
            cout << "Enter User name: ";
            getline(cin >> ws, user.username);
            while (chekalluserbyname(Vusers, user.username))
            {
                cout << "User with(" << user.username << ") is already exists,Enter another User name ";
                cin >> user.username;
            }

            cout << "\nPlease enter User data:\n";
            user = ReadNewuser(user);
            string line = Joinstructstring(user, "#//#");
            AddDataLineToFile(userFilename, line);
            cout << "Data saved successfully to " << userFilename << endl;
            Vusers = LoaduserssFromFile(userFilename);
            cout << "do you want add another User ? (yes/no)";
            cin >> addclient;

        } while (addclient == "yes" || addclient == "YES" || addclient == "Yes");
    }

    void Cluser::findusersoneScreen(vector<stUser> vusers)
    {
        cout << "\n==================================================" << endl;
        cout << "\tSHOW User SCREEN" << endl;
        cout << "==================================================" << endl;
        cout << endl;

        string username;
        bool found = false;
        cout << "Pleace enter User name: ";
        getline(cin >> ws, username);
        for (stUser& Vuser : vusers)
        {
            if (chekoneuserbyname(Vuser, username)) {
                found = true;

                printinfouser(Vuser, username);
                break;
            }
        }
        if (!found)
        {
            cout << "\nUser with User name ("
                << username
                << ") is Not Found!" << endl;
        }


    }

    void Cluser::deleteusersinfile(string FileName, vector<stUser>& vUsers, stUser User)
    {
        cout << "\n==================================================" << endl;
        cout << "\t DELETE USER SCREEN" << endl;
        cout << "==================================================" << endl;
        string deleteanotheruser;
        do {
            string deleteuser;
            bool found = false;
            string username;
            cout << "Please enter user name: ";
            getline(cin >> ws, username);
            if (username == "Admin" || username == User.username)
            {
                cout << "You cannot Delete this user? \n" << endl;

            }
            else
            {
                for (stUser& vUser : vUsers)
                {
                    if (chekoneuserbyname(vUser, username))
                    {
                        printinfouser(vUser, username);
                        found = true;
                        cout << " Are you sure you want to delete this user? (yes/no):" << endl;
                        cin >> deleteuser;
                        if (deleteuser == "yes" || deleteuser == "Yes" || deleteuser == "YES")
                        {
                            vUser.markdeletuser = true;
                            saveUsers(userFilename, vUsers);
                            cout << endl << "the User your name is " << username << " is delete From the file. " << endl;
                            vUsers = LoaduserssFromFile(userFilename);
                        }
                        break;
                    }
                }
                if (!found)
                {
                    cout << "\nUser with  user name("
                        << username
                        << ") is Not Found!" << endl;
                }
            }
            deleteanotheruser = readstring("do you want delete another user?(yes/no):");
        } while (deleteanotheruser == "yes" || deleteanotheruser == "YES" || deleteanotheruser == "Yes");




    }

    void Cluser::updateusers(string FileName, vector<stUser>& vusers)
    {
        cout << "\n==================================================" << endl;
        cout << "\t UPDATE User INFO SCREEN" << endl;
        cout << "==================================================" << endl;
        string updateanotherUser;
        do {
            string updateuser;
            bool found = false;
            string username;
            cout << "Please enter user name: ";
            getline(cin >> ws, username);
            for (stUser& vuser : vusers)
            {
                if (chekoneuserbyname(vuser, username))
                {
                    printinfouser(vuser, username);
                    found = true;
                    cout << " Are you sure you want to update this client? (yes/no):" << endl;
                    cin >> updateuser;
                    if (updateuser == "yes" || updateuser == "Yes" || updateuser == "YES")
                    {


                        vuser = ReadNewuser(vuser);


                        saveUsers(FileName, vusers);

                        cout << endl << "the user your your user is " << username << " is update sucssesfuly in the file. " << endl;
                    }
                    break;
                }
            }
            if (!found)
            {
                cout << "\nClient with user name ("
                    << username
                    << ") is Not Found!" << endl;
            }
            updateanotherUser = readstring("do you want update another client?(yes/no):");
        } while (updateanotherUser == "yes" || updateanotherUser == "YES" || updateanotherUser == "Yes");


    }

    void Cluser::PrintAllusers(vector<stUser> vClients)
    {
        cout << endl << endl;
        cout << "\n\t\t\t\t\t\t\t\tCLIENTS List (" << vClients.size() << ") Client(s)." << endl;
        cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
        cout << left << setw(65) << "User name"
            << "| " << setw(55) << "Pin Code"
            << "| " << setw(26) << "Permissions" << endl;

        cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";

        for (stUser& C : vClients)
        {
            cout << left << setw(65) << C.username
                << "| " << setw(55) << C.pincode
                << "| " << setw(26) << C.Permissions;
            cout << endl;
        }
        cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
    }

    bool Cluser::userfound(vector<stUser>& VUsers)
    {
        stUser userenter;
        cout << "enter user name? ";
        cin >> userenter.username;

        cout << "enter user pincode? ";
        cin >> userenter.pincode;

        for (stUser& user : VUsers)
        {
            if (user.username == userenter.username && user.pincode == userenter.pincode)
            {
                return true;
            }
        }
        return false;
    }

    int Cluser::readchoice(int from, int to)
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

    Cluser::stUser Cluser::ReadNewuser(stUser& User)
    {
        string Answer;
        cout << "Enter PinCode: ";
        getline(cin >> ws, User.pincode);

        cout << "Do you want him to have authority over the entire system? (y/n) : ";
        cin >> Answer;
        if (Answer == "y" || Answer == "Y")
        {
            User.Permissions = -1;
        }
        else
        {
            User.Permissions = 0;
            cout << "Do you want to give him unlimited permissions on the student management system?? (y/n) : ";
            cin >> Answer;
            if (Answer == "y" || Answer == "Y")
            {
                int c = (int)Cluser::Permissions::pManagestudent | (int)Cluser::Permissions::pAddstudent
                    | (int)Cluser::Permissions::pDeletestudent | (int)Cluser::Permissions::pUpdatestudent
                    | (int)Cluser::Permissions::pFindstudent | (int)Cluser::Permissions::pShowstudent;

                User.Permissions |= c;
            }
            else
            {
                cout << "Do you give him permissions to view student lists?? (y/n) : ";
                cin >> Answer;
                if (Answer == "y" || Answer == "Y")
                {
                    User.Permissions |= (int)Cluser::Permissions::pShowstudent;
                }
                cout << "Do you give him permissions to add student? (y/n) : ";
                cin >> Answer;
                if (Answer == "y" || Answer == "Y")
                {
                    User.Permissions |= (int)Cluser::Permissions::pAddstudent;
                }
                cout << "Do you want him to have the authority to delete a student?? (y/n) : ";
                cin >> Answer;
                if (Answer == "y" || Answer == "Y")
                {
                    User.Permissions |= (int)Cluser::Permissions::pDeletestudent;
                }
                cout << "Do you want him permissions to update a student? (y/n) : ";
                cin >> Answer;
                if (Answer == "y" || Answer == "Y")
                {
                    User.Permissions |= (int)Cluser::Permissions::pUpdatestudent;
                }

                cout << "Do you want him permissions to Search for a student? (y/n) : ";
                cin >> Answer;
                if (Answer == "y" || Answer == "Y")
                {
                    User.Permissions |= (int)Cluser::Permissions::pFindstudent;
                }
            }
            cout << "Do you want him all permissions to Manegeusers system? (y/n) : ";
            cin >> Answer;
            if (Answer == "y" || Answer == "Y")
            {
                int c = (int)Cluser::Permissions::pManageUsers | (int)Cluser::Permissions::pAdduser | 
                    (int)Cluser::Permissions::pDeleteuser | (int)Cluser::Permissions::pUpdateuser
                    | (int)Cluser::Permissions::pFinduser | (int)Cluser::Permissions::pShowuser;

                User.Permissions |= c;
            }

            else
            {
                cout << "Do you want him permissions to Search for a user? (y/n) : ";
                cin >> Answer;
                if (Answer == "y" || Answer == "Y")
                {
                    User.Permissions |= (int)Cluser::Permissions::pFinduser;
                }

                cout << "Do you want him permissions to delete user? (y/n) : ";
                cin >> Answer;
                if (Answer == "y" || Answer == "Y")
                {
                    User.Permissions |= (int)Cluser::Permissions::pDeleteuser;
                }

                cout << "Do you want him permissions to update user? (y/n) : ";
                cin >> Answer;
                if (Answer == "y" || Answer == "Y")
                {
                    User.Permissions |= (int)Cluser::Permissions::pUpdateuser;
                }

                cout << "Do you want him permissions to view User? (y/n) : ";
                cin >> Answer;
                if (Answer == "y" || Answer == "Y")
                {
                    User.Permissions |= (int)Cluser::Permissions::pShowuser;
                }

                cout << "Do you want him permissions to add User? (y/n) : ";
                cin >> Answer;
                if (Answer == "y" || Answer == "Y")
                {
                    User.Permissions |= (int)Cluser::Permissions::pAdduser;
                }
            }

            cout << "Do you want him all permissions to Manege system section? (y/n) : ";
            cin >> Answer;
            if (Answer == "y" || Answer == "Y")
            {
                int c = (int)Cluser::Permissions::psectionManagement | (int)Cluser::Permissions::pAddsection |
                    (int)Cluser::Permissions::pDeletesection | (int)Cluser::Permissions::pUpdatesection
                    | (int)Cluser::Permissions::pfindsection | (int)Cluser::Permissions::pshowsection;

                User.Permissions |= c;
            }

            else
            {
                cout << "Do you want him permissions to Search for a section? (y/n) : ";
                cin >> Answer;
                if (Answer == "y" || Answer == "Y")
                {
                    User.Permissions |= (int)Cluser::Permissions::pfindsection;
                }

                cout << "Do you want him permissions to delete section? (y/n) : ";
                cin >> Answer;
                if (Answer == "y" || Answer == "Y")
                {
                    User.Permissions |= (int)Cluser::Permissions::pDeletesection;
                }

                cout << "Do you want him permissions to update section? (y/n) : ";
                cin >> Answer;
                if (Answer == "y" || Answer == "Y")
                {
                    User.Permissions |= (int)Cluser::Permissions::pUpdatesection;
                }

                cout << "Do you want him permissions to view sections? (y/n) : ";
                cin >> Answer;
                if (Answer == "y" || Answer == "Y")
                {
                    User.Permissions |= (int)Cluser::Permissions::pshowsection;
                }

                cout << "Do you want him permissions to add section? (y/n) : ";
                cin >> Answer;
                if (Answer == "y" || Answer == "Y")
                {
                    User.Permissions |= (int)Cluser::Permissions::pAddsection;
                }
            }
        }
        return User;
    }

    string Cluser::Joinstructstring(stUser& User, string delim )
    {

        stringstream ss;
        ss << User.username << delim
            << User.pincode << delim
            << User.Permissions;
        return ss.str();
    }

    void Cluser::printinfouser(stUser vuser, string username)
    {
        cout << endl << "the user of username \"" << username << "\" the information is:" << endl;
        cout << "------------------------------------------------------------------------------------------------------------------------\n";
        cout << left << setw(15) << "Account Number" << " : "
            << vuser.username << endl;

        cout << left << setw(15) << "Pin Code" << " : "
            << vuser.pincode << endl;

        cout << left << setw(15) << "Client Name" << " : "
            << vuser.Permissions << endl;
        cout << "------------------------------------------------------------------------------------------------------------------------\n";

    }

    void Cluser::saveUsers(string FileName, vector<stUser>& VUsers)
    {
        fstream MyFile(FileName, ios::out);

        if (MyFile.is_open())
        {
            for (stUser& C : VUsers)
            {
                if (!C.markdeletuser)
                {
                    MyFile << Joinstructstring(C) << endl;
                }
            }

            MyFile.close();
        }
    }

    string Cluser::readstring(string message)
    {
        string s1;
        cout << message << endl << " ";
        getline(cin >> ws, s1);
        return s1;
    }

    bool Cluser::chekalluserbyname(vector<stUser>& Vusers, string username)
    {
        for (stUser& vuser : Vusers)
        {
            if (vuser.username == username)
            {
                return true;
            }
        }

        return false;


    }

    bool Cluser::chekoneuserbyname(stUser vuser, string username)
    {

        if (vuser.username == username)
        {
            return true;
        }
        return false;
    }

    void Cluser::AddDataLineToFile(const string& FileName, const string& stDataLine)
    {
        fstream MyFile(FileName, ios::app);
        if (MyFile.is_open())
        {
            MyFile << stDataLine << endl;
            MyFile.close();
        }

    }
