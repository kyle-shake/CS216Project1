// File: LinkedList.h
// Created: October 1, 2016
// Author: Kyle Shake
// Purpose: Declaration of a structure Node and class LinkedList


#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;


struct Node
{
   int Linenumber;
   string Line;
   Node* nextSTR;

};


class LinkedList
{
   private:
      Node* head;

   public:
      LinkedList();
      LinkedList(const LinkedList& src);
      bool add_string(string);
      bool insert_stringat(int, string);
      bool search(int, Node*&, Node*&);
      bool delete_string(int);
      void saveList(string);
      void printStringList ();

};


#endif /* LINKEDLIST_H */
