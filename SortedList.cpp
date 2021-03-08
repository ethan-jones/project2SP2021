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
  delete tempPtr;
  delete listData;
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
//   Node<ItemType>* temp = listData;
//   Node<ItemType>* newItem = new Node<ItemType>;
//   for (int i = 0; i < Length+1; i++) {
//     if (temp->info > item || temp == NULL) {
//       if (i == 0) {
//         newItem->next = listData;
//         listData = newItem;
//         delete predecessor;
//         Length++;
//         return;
//       }
//       else {
//         newItem->next = temp;
//         predecessor->next = newItem;
//         Length++;
//         return;
//       }
//     }
//     predecessor = temp;
//     temp = temp->next;
//   }
                            // Node<ItemType>* location;
                            // Node<ItemType>* temp = listData;
                            // location =new Node<ItemType>;
                            // location=listData;
                            // location->next->info=item;
                            // listData= location;
                            // Length++;
                            // if (temp->info == NULL){
                            //     location = listData;
                            // }
                            // else {
                            //     location->info=item;
                            // location->next=listData;
                            // listData= location;
                            // Length++;
                            // }
                            
  Node<ItemType>* location;
  location = new Node<ItemType>;
  predecessor = listData;
  Node<ItemType>* node = listData;
  bool found = false;
    while (found == false) {
    	if (Length == 0) {
		location->info=item;
     		location->next=listData;
      		listData = location;
      		Length++;
		found = true;
	} else if (listData->info > item) {
		location->info = item;
		location->next = listData;
		listData = location;
		found = true;
		Length++;
	} else if (node->info > item) {
		location->info = item;
		location->next = node;
		predecessor->next = location;
		found = true;
		Length++;
	} else if (node->next == NULL) {
		location->info = item;
		location->next = NULL;
		node->next = location;
		Length++;
		found = true;
	} else {
		predecessor = node;
		node = node->next;
	}
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
    // else if (predecessor == NULL) {
    //   Node<ItemType>* temp = listData;
    //   listData = listData->next;
    //   delete temp;
    //   delete predecessor;
    //   Length--;
    // }
    // else {
    //   Node<ItemType>* temp = predecessor->next;
    //   predecessor->next = temp->next;
    //   delete temp;
    //   delete predecessor;
    //   Length--;
    // }
    Node<ItemType>* location=listData;
    Node<ItemType>* tempLocation;
    if(item==(location->info))
    {
        tempLocation=location;
        listData=listData->next;
    }
    else{
        while(item!=location->next->info)
        {
            location=location->next;
        }
        //delete node at location->next
        tempLocation=location->next;
        location->next=location->next->next;

    }
    delete tempLocation;
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
  Node<ItemType>* predecessor = listData;
  Node<ItemType>* node = listData;
  Node<ItemType>* temp2;
  while (otherList.isEmpty() == false) {
    if (node->info == otherList.listData->info) {
      temp2 = otherList.listData;
      otherList.listData = otherList.listData->next;
      delete temp2;
      otherList.Length--;
    } else if (Length == 0) {
      listData = otherList.listData;
      Length = otherList.Length;
      otherList.listData = NULL;
      otherList.Length = 0;
    } else if (listData->info > otherList.listData->info) {
      listData = otherList.listData;
      otherList.listData = otherList.listData->next;
      otherList.Length--;
      Length++;
      listData->next = node;
      predecessor = listData;
    } else if (node->info > otherList.listData->info) {
      predecessor->next = otherList.listData;
      otherList.listData = otherList.listData->next;
      otherList.Length--;
      Length++;
      predecessor->next->next = node;
      predecessor = predecessor->next;
    } else if (node->next == NULL) {
      node->next = otherList.listData;
      otherList.listData = otherList.listData->next;
      otherList.Length--;
      Length++;
      node = node->next;
      node->next = NULL;
    } else {
      predecessor = node;
      node = node->next;
    }
  }
} 

template < class ItemType > bool SortedList < ItemType >::findItem(ItemType item, Node<ItemType>*& predecessor)
{
  Node<ItemType>* temp = listData;
  for (int i = 0; i < Length; i++) {
    if (temp->info == item) {
      if (i == 0) {
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
