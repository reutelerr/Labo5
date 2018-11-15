/* ---------------------------
 Laboratoire : 4
 Fichier :     main.cpp
 Auteur(s) :   Emmanuel Janssens, Robin Reuteler,v Benoit Perret
 Date :        14.11.2018
 
 But :
 
 Remarque(s) :
 
 Compilateur : GNU GCC Compiler
 --------------------------- */
#include <iostream>
#include <string>
using namespace std;


const char WEEKDAYS[7] = {'L', 'M', 'M', 'J', 'V', 'S', 'D'};
const string MONTHS[12] = {"Janvier", "Fevrier", "Mars", "Avril", "Mai", "Juin", "Juillet", "Aout", "Septembre", "Octobre", "Novembre", "Decembre"};

bool checkBissextile (int yearNum)
{
    if (yearNum % 100)
    {
        return !(yearNum % 400);
    }
    else
    {
        return !(yearNum % 4);
    }
}

void displayMonth (int month, int& monthStartDay, bool isBissextile, int mondayIndex)
{
    cout<<MONTHS[month]<<endl;
    for(int i=1; i<=7; ++i)
    {
        cout<<"  "<<WEEKDAYS[(i-mondayIndex+7)%7];
    }
    cout<<endl;
    
    int numDays = (month%2)+30;
    monthStartDay = (monthStartDay + numDays)%7;
    
    if (month==2)
    {
        numDays -= 2;
        if (isBissextile)
        {
            numDays+=1;
        }
    }
    
}

void displayYear (int yearNum, int mondayIndex)
{
    bool isBissextile = checkBissextile (yearNum);
    int monthStartDay = yearStartDay(yearNum);
    
    for (int i = 0; i<12; ++i)
    {
        displayMonth (i, monthStartDay, isBissextile, mondayIndex);
    }
    
}


int main()
{
    return 0;
}
