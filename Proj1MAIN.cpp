//File: Proj1MAIN.cpp
//Created: October 1, 2016
//Author: Kyle Shake
//Purpose: Main function for Project 1 Assignment. Program is a simple line editor using linked list structure


#include <iostream>
#include <fstream>
#include <string>
#include "LinkedList.h"

using namespace std;

int main(int argc, char* argv[])
{
   //Validating that user has entered correct number of arguments
   if ( argc == 1 )
   {
      cerr << "Missing command line argument!" << endl;
      cerr << "Usage: ./myEditor <input text filename>" << endl;
      return 1;
   }
   if (argc > 2)
   {
      cerr << "Too many arguments!" << endl;
      cerr << "Usage ./myEditor <input text filename>" << endl;
      return 1;
   }
   string filename(argv[1]);

   //Validating text file
   fstream in_file;
   in_file.open(argv[1], ios::in);
   if (in_file.fail())
   {
      cerr << "Argument was not a valid text file." << endl;
      return 1;
   }

   //Import txt file into Linked List
   LinkedList LLofStrings;
   string lineoftext;
   while (!in_file.eof())
   {
      getline(in_file, lineoftext);
      LLofStrings.add_string(lineoftext);
   }
   in_file.close();

   //Create user menu
   string choice;
   int linechoice;
   string newstr;

   do {
   
   choice = "";
   linechoice = 0;

   cout << "Welcome to my text editor." << endl;
   cout << "To insert text at the end of the file, type \'I\' followed by the text." << endl;
   cout << "To insert text at a certain line number, type \'I\' followed by a space and the desired line number." << endl;
   cout << "To delete a line, type \'D\' followed by a space and the line number." << endl;
   cout << "To print all the lines, type \'L\' and press enter." << endl;
   cout << "To save the current content, type \'S\' and press enter." << endl;
   cout << "To display this introdcution, type 'H' and press enter." << endl;
   cout << "To quit, type 'Q' and press enter." << endl;
    
   cin >> choice;
  
   //If user chooses to insert text at a certain line number (inserting text to come)
   if (choice == "I")
   {
      cin >> linechoice;
      LLofStrings.insert_stringat(linechoice, newstr);
   }  
 //If user chooses to delete a line
   else if (choice == "D")
   {
      cin >> linechoice;
      LLofStrings.delete_string(linechoice);
   }
   //If user chooses to print all the lines
   else if (choice == "L")
   {
       LLofStrings.printStringList();
   }
   //If user chooses to save current list
   else if (choice == "S")
   {
      LLofStrings.saveList(filename);
   }
   //If user chooses to exit the program **Allow user chance to save before exiting**
   else if (choice == "Q")
   {  
      string tosave;
      cout << "Do you want to save the change? (Y-yes; N-no)" << endl;
      cin >> tosave;
      if (tosave == "Y" || tosave == "y")
      {
         LLofStrings.saveList(filename);
         cout << "The list has been saved." << endl;
         cout << "Thank you for using myEditor." << endl;
         break;
      }
      else
      {
         cout << "Thank you for using myEditor." << endl;
         break;
      }
   }
   // If user has entered incorrect input
   else
   { 
      cout << "Invalid menu option. Please try again." << endl;
   }
   } while(choice != "Q");      

return 0;
} 
