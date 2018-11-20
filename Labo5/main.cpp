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
#include <iomanip>
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

int yearStartIndex(int year)
{
    return (1 + 2*13 + (3*(13+1)/5) + (year-1) + ((year-1) /4) - ((year-1) /100) + ((year-1) /400))%7;
}

void displayMonth (int month, int& monthStartIndex, bool isBissextile, int mondayIndex)
{
    //Month Header
    cout<<MONTHS[month-1]<<endl;
    for(int i=0; i<7; ++i)
    {
        cout<<"  "<<WEEKDAYS[(i-mondayIndex+7)%7];
    }
    cout<<endl;
    
    //Initial Operations
    int numDays = ((month+1)%2)+30;
    if (month==2)
    {
        numDays -= 2;
        if (isBissextile)
        {
            numDays+=1;
        }
    }
    
    //Display
    
    //Jours vides
    for(int i=0; i<(monthStartIndex+mondayIndex)%7;++i)
    {
        cout<<"   ";
    }
    //Jours pleins
    for (int i=1; i<= numDays; ++i)
    {
        cout<<" ";
        
        if(i< 10)
        {
            cout<<" ";//Espace en plus lorsqu'on est sur 1 digit seulement
        }
        cout<<i;//Jour courant
        
        if(not((i+mondayIndex+monthStartIndex)%7))
        {
            cout<<endl;
        }
        
    }
    
    
        
    monthStartIndex = (monthStartIndex + numDays)%7;
}

void displayYear (int yearNum, int mondayIndex)
{
    //Initial Operations
    bool isBissextile = checkBissextile (yearNum);
    int monthStartIndex = yearStartIndex(yearNum);
    
    for (int i = 1; i<=12; ++i)
    {
        displayMonth (i, monthStartIndex, isBissextile, mondayIndex);
    }
    
    //Display
    
    
}


int main()
{
    displayYear (2018, 3);
    return 0;
}
