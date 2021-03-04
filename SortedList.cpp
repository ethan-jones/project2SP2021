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
  Node<ItemType>* tempPtr;

  // Loop removes all nodes from list
  // deallocating space for each one
  while(listData != NULL) {
    tempPtr = listData;
    delete listData; // added
    listData = listData->next;
  }
  delete listData;
  delete tempPtr;
}

template < class ItemType > void SortedList < ItemType >::makeEmpty()
// Post: List is empty
{
  Node<ItemType>* tempPtr;

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

template < class ItemType > bool SortedList < ItemType >::isEmpty() const
{
  if (Length == 0) {
    return true;
  }
  else {
    return false;
  }
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
  catch(std::bad_alloc)
    {
      return true;
    }
}

template < class ItemType > void SortedList < ItemType >::putItem(ItemType item)
{
  if (isFull() == true) {
    throw FullList();
  }
  Node<ItemType>* predecessor;
  if (findItem(item, predecessor) == true) {
    throw DuplicateItem();
  }
  Node<ItemType>* temp = listData;
  Node<ItemType>* newItem;
  newItem->info = item;
  for (int i = 0; i < Length; i++) {
    if (temp->info > item || temp == NULL) {
      if (i == 0) {
	newItem->next = listData;
	listData = newItem;
	delete predecessor;
	Length++;
	return;
      }
      else {
	newItem->next = temp;
	predecessor->next = newItem;
	Length++;
	return;
      }
    }
    predecessor = temp;
    temp = temp->next;
  }
}

template < class ItemType > void SortedList < ItemType >::deleteItem(ItemType item)
{
  if (isEmpty() == true) {
    throw EmptyList();
  }
  Node<ItemType>* predecessor;
  if (findItem(item, predecessor) == false) {
    throw DeletingMissingItem();
  }
  else if (predecessor == NULL) {
    Node<ItemType>* temp = listData;
    listData = listData->next;
    delete temp;
    delete predecessor;
    Length--;
  }
  else {
    Node<ItemType>* temp = predecessor->next;
    predecessor->next = temp->next;
    delete temp;
    delete predecessor;
    Length--;
  }
}

template < class ItemType > int SortedList < ItemType >::getLength() const
{
  return Length;
}

template < class ItemType > void SortedList < ItemType >::printList(ofstream& outFile)
{
  Node<ItemType>* temp = listData;
  while (temp != NULL) {
    outFile << temp->info << "->";
    temp = temp->next;
  }
  outFile << "NULL";
  delete temp;
}

template < class ItemType > ItemType SortedList < ItemType >::getAt(int index){
  if (index < 1 || index > Length) {
    throw OutOfBound();
  }
  else {
    Node<ItemType>* location;
    location = listData;
    for (int j = 1; j <= index; j++) {
      if (j != index) {
	location = location->next;
      }
    } 
    return location->info;
  }
}
  
template < class ItemType > void SortedList < ItemType >::merge(SortedList& otherList){
  Node<ItemType>* temp = listData;
  Node<ItemType>* predecessor;
  for (int i = 0; i < Length; i++) {
    if (temp > otherList.listData && otherList.listData != NULL) {
      if (i == 0) {
	listData = otherList.listData;
	otherList.listData = otherList.listData->next;
	listData->next = temp;
      }
      else {
	predecessor->next = otherList.listData;
	otherList.listData = otherList.listData->next;
	predecessor->next->next = temp;
      }
      i--;
    }
    else {
      predecessor = temp;
      temp = temp->next;
    }
  }
  Length += otherList.Length;
  otherList.makeEmpty();
}

template < class ItemType > bool SortedList < ItemType >::findItem(ItemType item, Node<ItemType>*& predecessor) {
  Node<ItemType>* temp = listData;
  for (int i = 0; i < Length; i++) {
    if (item == temp->info) {
      if (i == 0) {
	predecessor = NULL;
      }
      return true;
    }
    predecessor = temp;
    temp = temp->next;
  }
  predecessor = NULL;
  return false;
}

