/* ---------------------------
 Laboratoire : 4
 Fichier :     main.cpp
 Auteur(s) :   Emmanuel Janssens, Robin Reuteler, Benoit Perret
 Date :        14.11.2018
 
 But :
 
 Remarque(s) :
 
 Compilateur : GNU GCC Compiler
 --------------------------- */
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>

using namespace std;


const char WEEKDAYS[7] = {'L', 'M', 'M', 'J', 'V', 'S', 'D'};
const string MONTHS[12] = {"Janvier", "Fevrier", "Mars", "Avril", "Mai", "Juin", "Juillet", "Aout", "Septembre", "Octobre", "Novembre", "Decembre"};
const char SPACE = '.';
const int NUMBER_OF_YEAR_DIGITS = 4;
const int DISPLAY_WIDTH = 20;
const int DEMI_DISPLAY_WIDTH = DISPLAY_WIDTH / 2;

bool checkBissextile(int yearNum) {
   if (yearNum % 100) {
      return !(yearNum % 400);
   } else {
      return !(yearNum % 4);
   }
}

void displayMonth(int month, int monthStartDay, bool isBissextile, int mondayIndex) {
   /* Si le nombre de lettre du mois est impair on le transforme en nombre pair afin
    *  de faciliter les divisions sur les entiers pour obtenir un alignement exact. */
   const int NbLetterMonth = (MONTHS[month - 1].length()) % 2 != 0 ? MONTHS[month - 1].length() + 1 : MONTHS[month - 1].length();
   cout << SPACE << setw(((DISPLAY_WIDTH - NbLetterMonth) / 2) + NbLetterMonth) <<
   setfill(SPACE) << right << MONTHS[month - 1] <<
   setw(((DISPLAY_WIDTH - NbLetterMonth) / 2))
   << setfill(SPACE) << SPACE << endl;
   for (int i = 1; i <= 7; ++i) {
      cout << "  " << WEEKDAYS[(i - mondayIndex + 7) % 7];
   }
   cout << endl;

   //Initial Operations
   int numDays = (month % 2) + 30;
   monthStartDay = (monthStartDay + numDays) % 7;

   if (month == 2) {
      numDays -= 2;
      if (isBissextile) {
         numDays += 1;
      }
   }

   //Display

}

void displayYear(int yearNum, int mondayIndex) {
   //Initial Operations
   bool isBissextile = checkBissextile(yearNum);
   // int monthStartDay = yearStartDay(yearNum);

   for (int i = 0; i < 12; ++i) {
      // displayMonth(i, monthStartDay, isBissextile, mondayIndex);
   }

   //Display


}

int main() {
   unsigned int yearToDisplay;
   unsigned int dayToDisplay;
   const int NB_DIGITS_YEAR = 4;
   do {
      if (cin.fail()) {
         cin.clear();
         cin.ignore(numeric_limits<streamsize>::max(), '\n');
      }
      cout << "Quelle annee voulez-vous afficher? (1600-3000)" << endl;
      cin >> yearToDisplay;
   } while (yearToDisplay < 1600 || yearToDisplay > 3000);
   do {
      if (cin.fail()) {
         cin.clear();
         cin.ignore(numeric_limits<streamsize>::max(), '\n');
      }
      cout << "Quel jour de la semaine est le lundi? (1-7)" << endl;
      cin >> dayToDisplay;

   } while (cin.fail() || (dayToDisplay < 1 || dayToDisplay > 7));
   cout << SPACE << setw(((DISPLAY_WIDTH - NUMBER_OF_YEAR_DIGITS) / 2) + NUMBER_OF_YEAR_DIGITS) << setfill(SPACE) << right << yearToDisplay << setw(((DISPLAY_WIDTH - NUMBER_OF_YEAR_DIGITS) / 2)) << setfill(SPACE) << SPACE << endl;
   displayMonth(3, 0, 0, 5);

   return 0;
}
