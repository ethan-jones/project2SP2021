#include <iostream>
using namespace std;
#include "SortedList.h"

template < class ItemType > SortedList < ItemType >::SortedList()
{
  Length = 0;
  listData = NULL;
}

template < class ItemType > SortedList < ItemType >::~SortedList()
{
  ItemType* tempPtr;

  // Loop removes all nodes from list
  // deallocating space for each one
  while(listData != NULL)
  {
   // tempPtr = listData;
   delete listData; // added
    listData = listData->next;
   // delete tempPtr;
  }
}

template < class ItemType > void SortedList < ItemType >::makeEmpty()
// Post: List is empty
{
  ItemType* tempPtr;

  // Loop removes all nodes from list
  // deallocating space for each one
  while(listData != NULL)
  {
    tempPtr = listData;
    listData = listData->next;
    delete tempPtr;
  }
 
  Length = 0;
}

template < class ItemType > bool SortedList < ItemType >::isFull() const
{
  ItemType* location;
  // Try adding a new node, if successful, there
  // is room for more nodes so list is NOT full
  try
  {
    location = new ItemType;
    delete location;
    return false;
  }
  // If adding a new node was unsuccessful,
  // the list is full
  catch(bad_alloc)
  {
    return true;
  }
}

template < class ItemType > void SortedList < ItemType >::putItem(ItemType item)
{
  ItemType* location = new ItemType;
  location->info = item;
  location->next = listData;
  listData = location;

  Length++;			// Increment length of list
}

template < class ItemType > void SortedList < ItemType >::deleteItem(ItemType item)
{
  ItemType* location;
  ItemType* tempLocation;

  location = listData;

  if (item.ComparedTo(location->info) == 0)
  {
    tempLocation = location;
    listData = listData->next;
  }
  else
  {
    while (!((item.ComparedTo((location->next)->info) == 0)))
      location = location->next;

    tempLocation = location->next;
    location->next = (location->next)->next;
  }

  delete tempLocation;
  Length--;
}

template < class ItemType > int SortedList < ItemType >::getLength() const
{
  return Length;
}

template < class ItemType > void SortedList < ItemType >::printList(ofstream&)
{
    SortedList<int> list;
    ofstream outFile;
	outFile.open("outFile.txt");
  int length;
  ItemType item;
ItemType* location;
location = listData;
  length = list.getLength();
  for (int counter = 1; counter <= length; counter++)
  {
    location.Print(outFile);
    location = location->next;
  }
  location.Print(outFile);
  outFile << endl;
}

  template < class ItemType > ItemType SortedList < ItemType >::getAt(int i){
      ItemType* location;
      ItemType* tmpLocation;
      int counter = 0;
      location = listData;
      do{
      if(int i = 0){
          return location->info;
      }
      else {
          location = location->next;
          counter++;
      }
      } while(counter >= i);
      return location->info;
    /*  
      if (int z = 0;z < i;z++){
     if (item.ComparedTo(location->info) == EQUAL)
  {
    tempLocation = location;
    listData = listData->next;
    counter = z;
    z = lenghth;
  }
  else
  {
    while (!((item.ComparedTo((location->next)->info) == EQUAL)))
      location = location->next;

    tempLocation = location->next;
    location->next = (location->next)->next;
    counter++;
  } 
      }
  }
  */
  }
  
  template < class ItemType > void SortedList < ItemType >::merge(SortedList& otherList){
  }
  