//File: LinkedList.cpp
//Created: October 1, 2016
//Author: Kyle Shake
//Purpose: Defines functions declared in LinkedList.h

#include <fstream>
#include <cstdlib>
#include <iostream>
#include <string>
#include "LinkedList.h"

using namespace std;

LinkedList::LinkedList(){
   head = NULL;
}


//Create unique copy constructor
LinkedList::LinkedList(const LinkedList& src){
   head = NULL;
   Node* srccur;
   srccur = src.head;

   Node* prev = NULL;
   while (srccur != NULL)
   {
      Node* newnode = new Node;
      if (newnode == NULL)
      {
         cout << "Memory Allocation Error" << endl;
         exit(1);
      }
      newnode->Line = srccur->Line;

      if (prev == NULL)
      { head = newnode;
      }
      else
      {prev->nextSTR = newnode;
      }
      newnode->nextSTR = NULL;

      prev = newnode;
      srccur = srccur->nextSTR;
   }
}

//Add string to the end of the linked list
bool LinkedList::add_string (string newline){
   Node* newnode = new Node;
   if (newnode == NULL) {return false;}
   
   newnode->Line = newline;
   newnode->nextSTR = NULL;

   if(head == NULL)
   {
      head = newnode;
      return true;
   }

   Node* current = head;
   while (current->nextSTR != NULL)
   {
      current = current->nextSTR;
   }

   current->nextSTR = newnode;
   return true;
}

//Insert a string at a certain linenumber 
//**READ ME** Cannot figure out how to create enough blank items in linked list to expand list
//in the case where the user wants to add a string to a line number higher than what the text file already provides
bool LinkedList::insert_stringat(int linenumber, string newline)
{
   if (linenumber <= 0) return false; //incorrect line number
   
   Node* current;   
   Node* previous;
   current = head;
   previous = NULL;
   int curlinenumber = 0;
   while (current != NULL)
   {
      curlinenumber++;
      if (curlinenumber == linenumber)		break; //once the function finds where we want to insert the newline
							//break out of the loop
      previous = current;
      current = current->nextSTR;
   }
   while (current == NULL && linenumber > curlinenumber)  //if current pointer comes to the end 
   {							// of the linked list and linenumber is higher than
      string temp = "";					//number of items in list, create blank items until 
      add_string(temp);
      curlinenumber++;
   }              	
   
   newline = "This is the string you just inserted";

   Node* newnode = new Node;
   if (newnode == NULL)		return false; //dynamic allocation failed

   newnode->Line = newline;
   if (previous == NULL)
   {
      newnode->nextSTR = head;
      head = newnode;
   }
   else
   {
      newnode->nextSTR = current;
      previous->nextSTR = newnode;
   }
   return true;
}

//Traverse the linked list searching for a Node by its line number

bool LinkedList::search(int linenumber, Node* &ptr, Node* &previous)
{
   previous = NULL;
   Node* current = head;
   int curlinenumber = 0;
   while (current != NULL)
   {
      curlinenumber++;
      if (curlinenumber == linenumber)		break; 
      
      previous = current;
      current = current->nextSTR;
   }
   if (current == NULL)		return false; // empty list or line number doesn't exist
   else
   {
      ptr = current;
      return true;
   }
}

//Uses search function to find the Node that points to a string  at a certain line number and then deletes that pointer.
bool LinkedList::delete_string(int linenumber)
{
   if (head == NULL)		return false; //if list is empty, do nothing
  
   Node* previous;
   Node* ptr;
   
   if (!search(linenumber, ptr, previous))	
   {
      cout << "That line number does not exist!" << endl;
      return false; //linenumber not found
   }
   if (previous !=NULL)
   {
      previous->nextSTR = ptr->nextSTR;
   }
   else
   {
      head = ptr->nextSTR;
   }
   delete ptr;
   return true;
}

//Function saves the linked list under the same filename used as an argument
void LinkedList::saveList(string filename)
{
   fstream outData;
   outData.open(filename.c_str());
   Node* current = head;
   while (current != NULL)
   {
      outData << current->Line << endl;
      current = current->nextSTR;
   }
}

//Function prints the linked list line by line including line numbers for reference
void LinkedList::printStringList()
{
   Node* current = head;
   int i = 1;
   while (current != NULL)
   {
      cout << i << "> " << current->Line << endl;
      current = current->nextSTR;
      i++;
   }
   cout << endl;
}



