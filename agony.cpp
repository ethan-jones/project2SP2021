#include <iostream>
using namespace std;
#include "SortedList.h"

template < class ItemType > SortedList < ItemType >::SortedList()
{
  
}

template < class ItemType > SortedList < ItemType >::~SortedList()
{
  
}

template < class ItemType > void SortedList < ItemType >::makeEmpty()
// Post: List is empty
{
  
}

template < class ItemType > bool SortedList < ItemType >::isEmpty() const
{
  
}

template < class ItemType > bool SortedList < ItemType >::isFull() const
{
  
}

template < class ItemType > void SortedList < ItemType >::putItem(ItemType item)
{
  
}

template < class ItemType > void SortedList < ItemType >::deleteItem(ItemType item)
{
  
}

template < class ItemType > int SortedList < ItemType >::getLength() const
{
  return Length;
}

template < class ItemType > void SortedList < ItemType >::printList(ofstream& outFile)
{
  Node<ItemType>* temp = listData;
  for (int i = 0; i < Length; i++) {
    outFile << temp->info << "->";
    temp = temp->next;
  }
  outFile << "NULL";
}

template < class ItemType > ItemType SortedList < ItemType >::getAt(int index)
{
  if (index < 1 || index > Length) {
    throw OutOfBound();
  }
  Node<ItemType>* temp = listData;
  for (int j = 1; j < index; j++) {
    temp = temp->next;
  }
  return temp->info;
}
  
template < class ItemType > void SortedList < ItemType >::merge(SortedList& otherList)
{
  Node<ItemType>* temp = listData;
  Node<ItemType>* temp2;
  Node<ItemType>* predecessor;
  Node<ItemType>* predecessor2;
  while (otherList.listData != NULL) {
    while (findItem(otherList.listData->info, predecessor2) == true) {
      temp2 = otherList.listData;
      otherList.listData = otherList.listdata->next;
      delete temp2;
    }
    if (otherList.listData->info == NULL) {
      break;
    }
    if (otherList.listData < temp) {
      if (temp == listData) {
	temp2 = otherList.listData;
	otherlist.listData = otherList.listData->next;
	temp2->next = temp;
	listData = temp2;
	temp = temp2;
	predecessor = listData;
	Length++;
      }
      else {
	temp2 = otherList.listData;
	otherList.listData = otherList.listData->next;
	predecessor->next = temp2;
	temp2->next = temp;
	predecessor = temp2;
	Length++;
      }
    }
    else {
      predecessor = temp;
      temp = temp->next;
    }
  }
}

template < class ItemType > bool SortedList < ItemType >::findItem(ItemType item, Node<ItemType>*& predecessor)
{
  Node<ItemType>* temp = listData;
  for (int i = 0; i < Length; i++) {
    if (temp->info == item) {
      if (i = 0) {
	predecessor = NULL;
	return true;
      }
      return true;
    }
    predecessor = temp;
    temp = temp->next;
  }
  return false;
}

