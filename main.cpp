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
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;



enum  MONTHS{JANVIER=1,FEVRIER=2,MARS=3,AVRIL=4,MAI=5,JUIN=6,
             JUILLET=7,AOUT=8,SEPTEMBRE=9,OCTOBRE=10,NOVEMBRE=11,DECEMBRE=12};
            
enum  WEEKDAYS{L,MA,ME,J,V,S,D};

const int DAYS_IN_WEEK = 7;
const int LINE_LENGTH = 21;
const int CELL_LENGTH =  LINE_LENGTH/DAYS_IN_WEEK;

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

string getMonth(MONTHS month)
{
   string m = "";
   switch(month)
   {
      case MONTHS::JANVIER:
         m = "Janvier";
         break;
      case MONTHS::FEVRIER:
         m = "Fevrier";
         break;
      case MONTHS::MARS:
         m = "Mars";
         break;
      case MONTHS::AVRIL:
         m = "Avril";
         break;
      case MONTHS::MAI:
         m = "Mai";
         break;
      case MONTHS::JUIN:
         m = "Juin";
         break;
      case MONTHS::JUILLET:
         m = "Juillet";
         break;
      case MONTHS::AOUT:
         m = "Aout";
         break;
      case MONTHS::SEPTEMBRE:
         m = "Septembre";
         break;
      case MONTHS::OCTOBRE:
         m = "Octobre";
         break;
      case MONTHS::NOVEMBRE:
         m = "Novembre";
         break;
      case MONTHS::DECEMBRE:
         m = "Decembre";
         break;
      default:
         m = "unknown";
         break;
   }
   
   return m;
}

char getDay(WEEKDAYS days)
{
   char d;
   switch(days)
   {
      case L:
         d = 'L';
         break;
      case MA:
         d = 'M';
         break;
      case ME:
         d= 'M';
         break;
      case J:
         d = 'J';
         break;
      case V:
         d = 'V';
         break;
      case S:
         d = 'S';
         break;
      case D:
         d = 'D';
         break;
      default:
         break;
            
   }
   
   return d;
}

int getDaysInMonth( MONTHS month )
{
   int numDays = 0;
   

   switch(month)
   {
       case MONTHS::AOUT:
       case MONTHS::SEPTEMBRE:
       case MONTHS::OCTOBRE:
       case MONTHS::NOVEMBRE:
       case MONTHS::DECEMBRE:
         numDays = ((month+1)%2)+30;
         break;
      default:
         numDays = ((month)%2)+30;
         break;         
   }    
   
   return numDays;
}

void displayCenteredText(string input, int lineLength)
{
   cout<< setw((lineLength / 2) + input.length() / 2 + lineLength % 2 ) << input << setw((lineLength / 2) - input.length() / 2) << endl;
}
void displayMonth (int currentMonth, int startOff, int&currentOff, bool isBissextile, int mondayIndex)
{
   displayCenteredText( getMonth(MONTHS(currentMonth)),LINE_LENGTH);
   
   for(int i = 1; i <= DAYS_IN_WEEK; i++)
   {
      cout<<setw(CELL_LENGTH)<<setfill(' ')<<getDay((WEEKDAYS((i-mondayIndex+DAYS_IN_WEEK)%DAYS_IN_WEEK)));
   }
   cout<<endl;
   
   int numDays = getDaysInMonth((MONTHS)currentMonth);
   if(currentMonth == MONTHS::FEVRIER)
   {
      numDays -=2;
      if(isBissextile)
      {
         numDays++;
      }
   }
   
   if(currentMonth == MONTHS::JANVIER)
   {
      currentOff = startOff + mondayIndex -1 ;
   }  
   
    for( int i = 1; i <=   currentOff + numDays; i++)
    {
       if(!(i <= currentOff || i-currentOff > numDays))
       {
          cout<<setw(CELL_LENGTH)<<setfill(' ')<<(i-currentOff);   
       }
       else
          cout<<setw(CELL_LENGTH)<<setfill(' ')<<' ';
              
       if(i%DAYS_IN_WEEK == 0)
          cout<<endl;
    }
    
    currentOff = (currentOff+numDays)%DAYS_IN_WEEK;

}

/**
 * @brief    N = d + 2m + [3(m+1)/5] + y + [y/4] - [y/100] + [y/400] + 2
 * 
 * @param year
 * @return 
 */
int findFirstDayOfYear(int year)
{
   
   int m = MONTHS::JANVIER;
   int d = 13; 
   int result = m + 2*(d) + (3*(d+1)/5) + (year-1) + ((year-1) /4) - ((year-1) /100) + ((year-1) /400) ;
   
   
   return result%DAYS_IN_WEEK;
}
void displayYear (int yearNum, int mondayIndex)
{
   
   int startOffset = findFirstDayOfYear(yearNum);
   int currentOffset=startOffset;
   for(int i = 1; i <= 12; i++)
   {   
      cout<<setw(LINE_LENGTH)<<setfill(' ')<<endl;
      displayMonth(i,startOffset,currentOffset,checkBissextile(yearNum),mondayIndex); 
      cout<<setw(LINE_LENGTH)<<setfill(' ')<<endl;
   }
}


int main()
{   
   
   displayYear(2015,2);
    return 0;
}