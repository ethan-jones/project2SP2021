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
    delete listData;
    listData = listData->next;
  }
  delete listData;
  delete tempPtr;
}

template < class ItemType > void SortedList < ItemType >::makeEmpty() 
{
  Node<ItemType>* tempPtr;
  
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
  } else {
    return false; 
  }
}

template < class ItemType > bool SortedList < ItemType >::isFull() const
{
  Node<ItemType>* location;
  
  try {
    location = new Node<ItemType>;
    delete location;
    return false;
  }
  catch(bad_alloc) {
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
  Node<ItemType>* newItem = new Node<ItemType>;
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
  } else {
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
}
