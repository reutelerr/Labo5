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
#include <limits>
using namespace std;


const char WEEKDAYS[7] = {'L', 'M', 'M', 'J', 'V', 'S', 'D'};
const string MONTHS[12] = {"Janvier", "Fevrier", "Mars", "Avril", "Mai", "Juin", "Juillet", "Aout", "Septembre", "Octobre", "Novembre", "Decembre"};
const char SPACE = ' ';
const int DISPLAY_WIDTH = 21;

bool checkBissextile (int yearNum)
{
    if (yearNum % 100)
    {
        return !(yearNum % 4);
    }
    else
    {
        return !(yearNum % 400);
    }
}

int yearStartIndex(int year)
{
    year -= 1;
    return year + year/4 - year/100 + year/400 % 7;
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
    cout << setw(((lineLength + (int)input.length()) / 2))
    << right << input
    << setw((lineLength - (int)input.length()+1)/2 + 1) <<'\n';
}

void displayEmptyLine(int lineLength = DISPLAY_WIDTH)
{
    cout << setw(lineLength +1) << '\n';
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
    bool EndOfLine = true;
    for (int i=1; i<= numDays; ++i)
    {
        
        cout<< setw(3) << i;//Jour courant
        
        if(not((i+mondayIndex+monthStartIndex)%7))
        {
            cout<<endl;
            EndOfLine = true;
        }
        else
        {
            EndOfLine = false;
        }
        
    }
    if(not(EndOfLine))
    {
        cout << setw(DISPLAY_WIDTH - ((numDays+monthStartIndex+mondayIndex)%7)*3 + 1);//Fin de dernière ligne
        cout << '\n';
    }
    
        
    return monthStartIndex = (monthStartIndex + numDays)%7;
}

void displayYear (int yearNum, int mondayIndex)
{
    //Initial Operations
    bool isBissextile = checkBissextile (yearNum);
    int monthStartIndex = yearStartIndex(yearNum);
    
    //Display
    displayCenteredText(to_string(yearNum));
    displayEmptyLine();
    for (int i = 1; i<=12; ++i)
    {
        monthStartIndex = displayMonth (i, monthStartIndex, isBissextile, mondayIndex);
        displayEmptyLine();
    }
    
    
    
    
}


unsigned int entreeCorrecte(string AskingMessage, string ErrorMessage, unsigned int borneMin, unsigned int borneMax) {
    unsigned int yearToDisplay;
    do {
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cout << AskingMessage << ' ';
        cin >> yearToDisplay;
        
        if (yearToDisplay < borneMin || yearToDisplay > borneMax || cin.fail()) {
            cout << ErrorMessage << endl;
        }
        
    } while (yearToDisplay < borneMin || yearToDisplay > borneMax || cin.fail());
    return yearToDisplay;
}

int main() {
    cout << setfill(SPACE);
    unsigned int yearToDisplay = entreeCorrecte("Quelle annee voulez-vous afficher? (1600-3000)", "Entree non valide", 1600, 3000);
    
    unsigned int dayToDisplay = entreeCorrecte("Quel jour de la semaine est le lundi? (1-7)", "Entree non valide", 1, 7);
    cout<<endl;
    displayYear(yearToDisplay, dayToDisplay-1);
    return 0;
}
