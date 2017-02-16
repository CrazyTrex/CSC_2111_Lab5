/*
	Jignesh Patel & Adam Rucker
	2/16/2017
	Lab 5/ SortedListLinked Lab
*/
#include "SortedListLinked.h"
#include "CD.h"
using CSC2110::CD;
#include "ListArray.h"
using CSC2110::ListArray;
#include "ListArrayIterator.h"
using CSC2110::ListArrayIterator;
#include <iostream>
using namespace std;

void addCDs(ListArray<CD>* list, SortedListLinked<CD>* lb)
{
   ListArrayIterator<CD>* iter = list->iterator();
	int index = 0;
   //DO THIS
   //iterate over and add the cds to the list box (use lb->addItem)
	while(iter->hasNext())
	{
		CD* current = iter->next();
		lb->add(current);
	}
   delete iter;
}

void deleteCDs(ListArray<CD>* list)
{
   ListArrayIterator<CD>* iter = list->iterator();

   //DO THIS  
   //iterate over and delete the cds
   
   while(iter->hasNext())
   {
	   CD* current = iter->next();
	   delete current;
   }



   delete iter;
}

int main(int argc, char* argv[])
{
	//test with 3 cds
    ListArray<CD>* cds = CD::readCDs("test.txt");
	SortedListLinked<CD>* lb = new SortedListLinked<CD>(&CD::compare_items);
	addCDs(cds, lb);
	ListLinkedIterator<CD>* iter = lb->iterator();
	
	while(iter->hasNext())
	{
		CD* current = iter->next();
		current->displayCD();
	}
	delete iter;
	
	//quick test of remove;
	cout<<"----------------------------------------------\n\n";//line break between tests;
	//testing the remove function with the 3 cds and trying to remove a cd and then trying to remove it again to test 
	//to see if it works without the cd present
	CD* testRemove = cds->get(1);
	lb->remove(testRemove);
	lb->remove(testRemove);
	
	iter = lb->iterator();
	while(iter->hasNext())
	{
		CD* current = iter->next();
		current->displayCD();
	}
	delete iter;
	//delete the data from the first 2 tests
	deleteCDs(cds);
	delete cds;
	delete lb;
	cout<<"-----------------------------------------------\n\n";//line break between tests
	//testing the SortedListLinked with 14 cds
	cds = CD::readCDs("test2.txt"); 
	lb = new SortedListLinked<CD>(&CD::compare_items);
	addCDs(cds, lb);
	iter = lb->iterator();
	
	while(iter->hasNext())
	{
		CD* current = iter->next();
		current->displayCD();
	}
	delete iter;
	//did not delete cds or lb because they will be used in the next test
	
	cout<<"-----------------------------------------\n\n";//line break between tests
	//testing the remove twice from the 14 cd list so it should print out 12 cds in order
	testRemove = cds->get(4);
	lb->remove(testRemove);
	testRemove = cds->get(5);
	lb->remove(testRemove);
	iter = lb->iterator();
	while(iter->hasNext())
	{
		CD* current = iter->next();
		current->displayCD();
	}
	
	delete iter;
	deleteCDs(cds);
	delete cds;
	delete lb;
	cout<<"--------------------------------------------------------\n\n";//line break between tests
	//testing the SortedListLinked with all of the cds;
	cds = CD::readCDs("cds.txt");
	lb = new SortedListLinked<CD>(&CD::compare_items);
	addCDs(cds, lb);
	iter = lb->iterator();
	
	while(iter->hasNext())
	{
		CD* current = iter->next();
		current->displayCD();
	}
	delete iter;
	deleteCDs(cds);
	delete cds;
	delete lb;
	return 0;
}
