#include "ClSchoolmanagementsystem.h"
class Clteacher
{
    struct SDateofBirth
    {
        int yearofbirth;
        int monthofbirth;
        int dayofbirth;
    };

    struct SPersonalinformation
    {
        string  FullName;
        string NNI;
        string numberphone;
        SDateofBirth DateofBirth;
        int Salary;
    };

    struct SAcademicqualifications
    {
        vector<string>Universitydegree;
        vector<string> Specialization;
        string YearsofExperience;
    };

    struct SProfessionalData
    {
        string Subject;
        string AssignedClasses;
        int Numberofworkinghours;

    };


     void startclassteacher(Cluser::stUser user)
     {
     
     
     
     
     
     
     
     
     }






};
int main()
{
    ClSchoolmanagementsystem Schoolmanagementsystem;
    Schoolmanagementsystem.startmunueprograme(Schoolmanagementsystem.Login());
}