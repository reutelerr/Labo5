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
const char SPACE = '.';
const int NUMBER_OF_YEAR_DIGITS = 4;
const int DISPLAY_WIDTH = 21;

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

int getDaysInMonth(int month, bool isBissextile)
{
    int numDays = 0;
    
    
    switch(month)
    {
        case 2:
            numDays = 28;
            if(isBissextile)
            {
                numDays+=1;
            }
            break;
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
            numDays = ((month+1)%2)+30;
            break;
        default:
            numDays = ((month)%2)+30;
            break;
    }
    
    return numDays;
}

void displayCenteredText(string input, int lineLength = DISPLAY_WIDTH)
{
    cout << setw(((lineLength + (int)input.length() + 1) / 2))
    << right << input
    << setw((lineLength - (int)input.length())/2 + 1) <<'\n';
}


/*
 @brief
 
 @param int month
 @param int monthStartIndex entier de 0 à 6
 @param bool isBissextile indique si l'année est bissextile
 @param int mondayIndex entier de 1 à 7
*/
int displayMonth (int month, int monthStartIndex, bool isBissextile, int mondayIndex)
{
    //Month Header
    
    displayCenteredText(MONTHS[month-1]);
    
    for (int i = 0; i < 7; ++i) {
        cout << "  " << WEEKDAYS[(i - mondayIndex + 7) % 7];
    }
    cout << endl;
    
    //Initial Operations
    int numDays = getDaysInMonth(month, isBissextile);
    
    //Display
    
    //Jours vides
    for(int i=0; i<(monthStartIndex+mondayIndex)%7;++i)
    {
        cout<<setw(3)<<SPACE;
;
    }
    //Jours pleins
    for (int i=1; i<= numDays; ++i)
    {
        
        cout<< setw(3) << i;//Jour courant
        
        if(not((i+mondayIndex+monthStartIndex)%7))
        {
            cout<<endl;
        }
        
    }
    cout << setw(DISPLAY_WIDTH - ((numDays+monthStartIndex+mondayIndex)%7)*3 + 1);
    cout << '\n';
        
    return monthStartIndex = (monthStartIndex + numDays)%7;
}

void displayYear (int yearNum, int mondayIndex)
{
    //Initial Operations
    bool isBissextile = checkBissextile (yearNum);
    int monthStartIndex = yearStartIndex(yearNum);
    
    for (int i = 1; i<=12; ++i)
    {
        monthStartIndex = displayMonth (i, monthStartIndex, isBissextile, mondayIndex);
    }
    
    //Display
    
    
}


int main()
{
    cout << setfill(SPACE);
    displayYear (2018, 0);
    return 0;
}
