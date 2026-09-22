#pragma once

#include <iostream>
#include <string>
#include"dateliberary.h"
#include<ctime>
#include <vector>

using namespace std;
namespace dateliberary
{
    struct stDate
    {
        short Day;
        short Mounth;
        short year;
    };
    
    bool isLeapYear(short Year)
    {
        return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
    }
    
    struct stPERIOD
    {
        stDate Date1;
        stDate Date2;
    };

    int calculeofmounth(short year, short Mounth, short day)
    {
        int a, y, m, d;

        a = (14 - Mounth) / 12;
        y = year - a;
        m = Mounth + 12 * a - 2;


        d = (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

        return d;
    }
    
    int calculeofmounth(stDate date)
    {
        return calculeofmounth(date.year, date.Mounth, date.Day);
    }

    inline short numberofdaysinyear(stDate date1)
    {
    if(isLeapYear(date1.year))
    {
        return 366;
    }
    else
    {
        return 365;
    }
    }

    string getnameofday(int d)
    {
        if (d == 0)
            return "Sunday";
        else if (d == 1)
            return "Monday";
        else if (d == 2)
            return "Tuesday";
        else if (d == 3)
            return "Wednesday";
        else if (d == 4)
            return "Thursday";
        else if (d == 5)
            return "Friday";
        else if (d == 6)
            return "Saturday";
        else
            return "";
    }
    
    short Readnumber(string message)
    {
        short number;
        cout << "\n" << message;
        cin >> number;
        return number;
    }
    
    short NumberOfDaysInAMonth(short Month, short Year)
    {
        if (Month < 1 || Month > 12) return 0;
        int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
        return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : days[Month - 1];
    }
    
    int numberofdaysfromthebeginningyear(stDate date1)
    {
        int sum=0;
        for(short i=1;i< date1.Mounth;i++)
        {
            sum += NumberOfDaysInAMonth(i, date1.year);
        }
        sum += date1.Day;
        return sum;
    }

    bool Knowingifthemonthenteredisthelastmonthoftheyear(short Month, short Year)
    {
        return    (Month == 12);
    }
    
    bool Knowingtheentredateisitthelastdayofthemonth(short Month, short Year, short day)
    {
        return  (NumberOfDaysInAMonth(Month, Year) == day);
    }
    
    stDate increasedatebyoneday(stDate date1)
    {
        if (Knowingtheentredateisitthelastdayofthemonth(date1.Mounth, date1.year, date1.Day))
        {
            date1.Day = 1;
            if (Knowingifthemonthenteredisthelastmonthoftheyear(date1.Mounth, date1.year))
            {
                date1.Mounth = 1;
                date1.year++;
            }
            else
            {
                date1.Mounth++;
            }
        }
        else
        {
            date1.Day++;
        }

        return date1;
    }
    
    stDate decreasedatebyoneday(stDate date1)
    {
        if (date1.Day==1)
        {
            if (date1.Mounth == 1) 
            {
                date1.Mounth = 12;
                date1.year--;
                date1.Day = NumberOfDaysInAMonth(date1.Mounth, date1.year);
                
            }
            else
            {
                date1.Mounth--;
                date1.Day = NumberOfDaysInAMonth(date1.Mounth, date1.year);
            }
        }
        else
        {
            date1.Day--;
        }

        return date1;
    }

    bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
    {
       return (Date1.year < Date2.year) ? true : ((Date1.year == Date2.year) ? (Date1.Mounth < Date2.Mounth ? true : (Date1.Mounth == Date2.Mounth ? Date1.Day < Date2.Day :false)) : false);
    }
    
    bool IsDate1EqualDate2(stDate Date1, stDate Date2)
    {
        return (Date1.year == Date2.year) ? ((Date1.Mounth ==
            Date2.Mounth) ? ((Date1.Day == Date2.Day) ? true : false) : false)
            : false;
    }

    bool IsDate1AfterDate2(stDate Date1, stDate Date2)
    {
        return( !IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));
    }
    
    int isdate1befororequaleorafterdate2(stDate Date1, stDate Date2)
    {
        return    IsDate1BeforeDate2(Date1, Date2) ? -1 : IsDate1EqualDate2(Date1, Date2) ? 0 : IsDate1AfterDate2(Date1, Date2);
    }
    
    int getdefdays(stDate date1, stDate date2)
    {
        int days = 0;
        if (IsDate1BeforeDate2(date1, date2))
        {
            while (IsDate1BeforeDate2(date1, date2))
            {
                days++;
                date1 = increasedatebyoneday(date1);
            }
        }
        else
        {
            while (IsDate1AfterDate2(date1, date2))
            {
                days++;
                date1 = increasedatebyoneday(date1);
            }
            days *= -1;
        }
        return days;
    }
    
    stDate getsystemdate()
    {
        stDate date2;
        time_t t = time(0);
        tm* now = localtime(&t);
        date2.year = now->tm_year + 1900;
        date2.Mounth = now->tm_mon + 1;
        date2.Day = now->tm_mday;
        
        
        return date2;
    }
    
    stDate increaseDateByXday(stDate date1,int xdays)
    {
    for(int i=1;i<= xdays;i++)
    {
        date1 = increasedatebyoneday(date1);
    }
    return date1;
    }

    stDate decreaseDateByXday(stDate date1, int xdays)
    {
        for (int i = 1; i <= xdays; i++)
        {
            date1 = decreasedatebyoneday(date1);
        }
        return date1;
    }

    stDate increaseDateByoneWeek(stDate date1)
    {
        date1= increaseDateByXday(date1, 7);
        return date1;
    }

    string printdateabeautifullform(stDate date1)
    {
        return getnameofday(calculeofmounth(date1)) + " , " + to_string(date1.Day) + "/" + to_string(date1.Mounth) + "/" + to_string(date1.year);
    }

    stDate decreaseDateByoneWeek(stDate date1)
    {
        date1 = decreaseDateByXday(date1, 7);
        return date1;
    }

    stDate increaseDateByXWeek(stDate date1, int XWeek)
    {
        for (int i = 1; i <= XWeek; i++)
        {
            date1 = increaseDateByoneWeek(date1);
        }
        return date1;
    }

    bool isendofweek(int d)
    {
        if (d == 6)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    bool isaweekend(int d)
    {
        if (d == 6 || d==0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    bool isabusnniseday(int d)
    {
        return !isaweekend(d);
        
    }
    
    int DaysUntilEndOfWeek(stDate date)
    {
        int  remainderofweek = 7 - calculeofmounth(date) - 1;

        return remainderofweek;
    }
    
    int DaysUntilEndOfMonth(stDate date1)
    {
        int  remainderofmonth = NumberOfDaysInAMonth(date1.Mounth, date1.year) - date1.Day;

        return remainderofmonth+1;
    }

    int DaysUntilEndOfYear(stDate date1)
    {
       
        int  remainderofmonth = numberofdaysinyear(date1)- numberofdaysfromthebeginningyear(date1);

        return remainderofmonth+1;
    }

    stDate decreaseDateByXWeek(stDate date1, int XWeek)
    {
        for (int i = 1; i <= XWeek; i++)
        {
            date1 = decreaseDateByoneWeek(date1);
        }
        return date1;
    }

    stDate increaseDateByonemounth(stDate date1)
    {   
            if (Knowingifthemonthenteredisthelastmonthoftheyear(date1.Mounth, date1.year))
            {
                date1.Mounth = 1;
                date1.year++;
            }
            else
            {
                date1.Mounth++;
            }
            int numberofdays = dateliberary::NumberOfDaysInAMonth(date1.Mounth, date1.year);
            
            if(date1.Day> numberofdays)
            {
                date1.Day = numberofdays;
            }
            
            
            
            return date1;
    }

    short Vacationperiode(stDate date2, stDate date1)
    {

        int day = 0;


        while (IsDate1BeforeDate2(date2, date1))
        {
            if (!(isaweekend(calculeofmounth(date1))))
            {
                day++;
            }
            date1 = increasedatebyoneday(date1);
        }
        return day + 1;

    }

    inline stDate CalculateVacationReturnDate(stDate DateFrom, short VacationDays)
    {

        short WeekEndCounter = 0;

        while (isaweekend(calculeofmounth(DateFrom)))
        {
            DateFrom = increasedatebyoneday(DateFrom);
        }

        
        for (short i = 1; i <= VacationDays + WeekEndCounter; i++)
        {

            if (isaweekend(calculeofmounth(DateFrom)))
                WeekEndCounter++;

            DateFrom = increasedatebyoneday(DateFrom);
        }

        while (isaweekend(calculeofmounth(DateFrom)))
        {
            DateFrom = increasedatebyoneday(DateFrom);
        }
        DateFrom = decreasedatebyoneday(DateFrom);
        return DateFrom;
    }

    stDate decreaseDateByonemounth(stDate date1)
    {
        if (date1.Mounth==1)
        {
            date1.Mounth = 12;
            date1.year--;
        }
        else
        {
            date1.Mounth--;
        }
        int numberofdays = dateliberary::NumberOfDaysInAMonth(date1.Mounth, date1.year);

        if (date1.Day > numberofdays)
        {
            date1.Day = numberofdays;
        }



        return date1;
    }

    stDate increaseDateByXmounth(stDate date1, int Xmounth)
    {

        for(int i=1;i<= Xmounth;i++)
        {
            date1= increaseDateByonemounth(date1);
        }
        return date1;
    }

    stDate decreaseDateByXmounth(stDate date1, int Xmounth)
    {

        for (int i = 1; i <= Xmounth; i++)
        {
            date1 = decreaseDateByonemounth(date1);
        }
        return date1;
    }

    stDate increaseDateByoneyear(stDate date1)
    {
            date1.year++;
        return date1;
    }

    stDate decreaseDateByoneyear(stDate date1)
    {
        date1.year--;
        return date1;
    }

    stDate increaseDateByXyears(stDate date1, int Xyears)
    {

        for (int i = 1; i <= Xyears; i++)
        {
            date1 = increaseDateByoneyear(date1);
        }
        return date1;
    }
    
    stDate decreaseDateByXyears(stDate date1, int Xyears)
    {

        for (int i = 1; i <= Xyears; i++)
        {
            date1 = decreaseDateByoneyear(date1);
        }
        return date1;
    }

    stDate increaseDateByXyearsfaster(stDate date1, int Xyears)
    {
        date1.year += Xyears;
        
        return date1;
    }

    stDate decreaseDateByXyearsfaster(stDate date1, int Xyears)
    {
        date1.year -= Xyears;

        return date1;
    }

    stDate increaseDateByonedecade(stDate date1)
    {
        date1 = increaseDateByXyears(date1,10);
        
        return date1;
    }

    stDate decreaseDateByonedecade(stDate date1)
    {
        date1 = decreaseDateByXyears(date1, 10);

        return date1;
    }

    stDate increaseDateByXdecade(stDate date1,int Xdecade)
    {
        for (int i = 1; i <= Xdecade; i++) 
        {
            date1 = increaseDateByXyears(date1, 10);
        }
        return date1;
    }

    stDate decreaseDateByXdecade(stDate date1, int Xdecade)
    {
        for (int i = 1; i <= Xdecade; i++)
        {
            date1 = decreaseDateByXyears(date1, 10);
        }
        return date1;
    }

    stDate increaseDateByXdecadefaster(stDate date1, int Xdecade)
    {
        date1.year += (Xdecade*10);
        return date1;
    }

    stDate decreaseDateByXdecadefaster(stDate date1, int Xdecade)
    {
        date1.year -= (Xdecade * 10);
        return date1;
    }

    stDate increaseDateByonecenthery(stDate date1)
    {
           date1 = increaseDateByXdecade(date1, 10);
        
        return date1;
    }

    stDate decreaseDateByonecenthery(stDate date1)
    {
        date1.year -= 100;

        return date1;
    }

    stDate increaseDateByonemilineum(stDate date1)
    {
        for (int i = 1; i <= 10; i++) 
        {

            date1 = increaseDateByonecenthery(date1);
        }
        return date1;
    }

    stDate decreaseDateByonemilineum(stDate date1)
    {
        date1.year -= 1000;
       
        return date1;
    }

    bool isoverlapperiodes(stPERIOD P1, stPERIOD P2)
    {
        return (IsDate1BeforeDate2(P1.Date1, P2.Date2) || IsDate1EqualDate2(P1.Date1, P2.Date2))
            &&
            (IsDate1BeforeDate2(P2.Date1, P1.Date2) || IsDate1EqualDate2(P2.Date1, P1.Date2));
    }

    short periodelengthindays(stDate Date1, stDate Date2)
    {
    
        return getdefdays(Date1, Date2);
    
    }

    bool isWithinperiode(stPERIOD P1, stDate dateWithin)
    {
        return
            (IsDate1BeforeDate2(dateWithin, P1.Date2) || IsDate1EqualDate2(dateWithin, P1.Date2))
            &&
            (IsDate1AfterDate2(dateWithin, P1.Date1) || IsDate1EqualDate2(dateWithin, P1.Date1));
    }

    vector<string> SplitString(string S1, string delim)
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

    int CountOverlapDays(stPERIOD P1, stPERIOD P2)
    {
        int daysoverlap = 0;
        if (isoverlapperiodes(P1, P2))
        {
            return daysoverlap;
        }
        if (isoverlapperiodes(P1, P2))
        {
            if (IsDate1BeforeDate2(P1.Date1, P2.Date1))
            {
                if (IsDate1BeforeDate2(P1.Date2, P2.Date2)) 
                {
                    daysoverlap = getdefdays(P2.Date1, P1.Date2);
                    return daysoverlap;
                }
                else
                {
                    daysoverlap = getdefdays(P2.Date1, P2.Date2);
                    return daysoverlap;
                }
            }
            else if (IsDate1AfterDate2(P1.Date1, P2.Date1))
            {
                if (IsDate1BeforeDate2(P2.Date2,P1.Date2))
                {
                    daysoverlap = getdefdays(P1.Date1, P2.Date2);
                    return daysoverlap;
                }
                else 
                {
                    daysoverlap = getdefdays(P1.Date1, P1.Date2);
                    return daysoverlap;
                }
            }
            else
            {
                if (IsDate1BeforeDate2(P1.Date2, P2.Date2))
                {
                    daysoverlap = getdefdays(P1.Date1, P1.Date2);
                    return daysoverlap;
                }
                else
                {
                    daysoverlap = getdefdays(P1.Date1, P2.Date2);
                    return daysoverlap;
                }
            }
        }
        return daysoverlap;
       
    }

    bool Validateinputdate(stDate date)
    {
   
        if (date.year < 1)
            return false;
        if(date.Mounth<1 || date.Mounth>12)
        {
        return false;
        }
        else if (date.Day < 1 || date.Day>NumberOfDaysInAMonth(date.Mounth, date.year))
        {
        return false;
        }
        else
        {
        return true;
        }
    }

    stDate readdate()
    {
        stDate Date;
        Date.Day = dateliberary::Readnumber("enter day ? ");
        Date.Mounth = dateliberary::Readnumber("enter mounth ? ");
        Date.year = dateliberary::Readnumber("enter year ? ");
        while(!Validateinputdate(Date))
        {
            cout << endl << "Wrong date enter another date : " << endl;
            Date.Day = dateliberary::Readnumber("enter day ? ");
            Date.Mounth = dateliberary::Readnumber("enter mounth ? ");
            Date.year = dateliberary::Readnumber("enter year ? ");
        }
        return Date;
    }

    stPERIOD readperiode()
    {
        stPERIOD Periode;

        cout << "\n Enter start Date :" << endl << endl;
        Periode.Date1 = readdate();
        cout << endl << "\n Enter End Date :" << endl << endl;
        Periode.Date2= readdate();

        return Periode;
    }

    string readstring(string message)
    {
        string datestring;
        cout << message << endl;
        getline(cin >> ws, datestring);
        return datestring;
    }

    stDate fulldatestructur(string datestring) 
    {
        stDate date;
        vector<string>Vdate;
        Vdate = SplitString(datestring, "/");

        date.Day =stoi(Vdate[0]);
        date.Mounth = stoi(Vdate[1]);
        date.year = stoi(Vdate[2]);
        return date;
    }

}