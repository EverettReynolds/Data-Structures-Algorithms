#include <cstddef> 
#include <iostream>

using namespace std;

template<class ItemType>
struct NodeType
{
	ItemType info;
	NodeType<ItemType>*	next;
	NodeType<ItemType>*	back;
};

template <class ItemType>		
DList<ItemType>::DList()		// Class constructor
{
    length = 0;
    head = NULL;
}

template <class ItemType>
DList<ItemType>::~DList   ()		
{
	// Post: List is empty; All items have been deallocated.

}

template <class ItemType>
void DList<ItemType>::makeEmpty()
{
    // Post: List is empty; all items have been deallocated.

  
  
  delete head;
  length = 0;
  head = NULL;
}

template <class ItemType>
void DList<ItemType>::deleteItem (ItemType item)	
{
	//  Pre :  item to be deleted is passed in via parameter 
        // Post :  item is deleted if it exists in list 
  NodeType<ItemType>* deleteNode = new NodeType<ItemType>;
  deleteNode = location(item);
  deleteLocation(deleteNode);


}

template <class ItemType>
bool DList<ItemType>::inList (ItemType item) const
{
	//  Pre :  item to be located is passed in via parameter 
        // Post :  function returns bool value if item is found 
  NodeType<ItemType>* find = head;
  
 
 while(find!= NULL)
 {
   if(find->info == item)
   {
     return true;
   }
   else
   {
     find = find -> next;
   }
 }
  return false;
   
}

template <class ItemType>
bool DList<ItemType>::isEmpty() const		
{
	// Post : function returns true if list is empty, false otherwise
  if(head == NULL )
  {
    return true;
  }
  
  else
  {
    return false;
  }
	
}

template <class ItemType>
void DList<ItemType>::print() const	
{
	// Pre  : List is not empty 
	// Post : Items in List have been printed to screen
 
 int tempCount = 1;
 NodeType<ItemType>* curr = head;
 
 while(curr != NULL)
 {
   cout << tempCount << ". " << curr -> info << endl;
   curr = curr -> next;
   tempCount++;
 }


}
	
template <class ItemType>
void DList<ItemType>::insertHead(ItemType item)	
{
	//  Pre : item to be inserted is passed in via parameter
        // Post : item is inserted at head of list;  Former first node is 
        //        linked back to this new one via double link;
        //        Length incremented;  Special case handled if list is empty 
        
  NodeType<ItemType>* newNode = new NodeType<ItemType>;
  newNode -> info = item;
  newNode -> back = NULL;

  if (head != NULL)  
  {
    head -> back = newNode;

    newNode-> next = head;

  }
  else
  {
  
  newNode->next = NULL;
  
  }

  head = newNode;
  length++;

	
}

template <class ItemType>
void DList<ItemType>::appendTail(ItemType item)
{
	//  Pre :  item to be inserted is passed in via parameter
        // Post :  item is added to tail of list; Former last node
        //         is linked to this new one via double link 
  NodeType<ItemType>* tailNode = new NodeType<ItemType>;
  tailNode -> info = item;
  
  if(head != NULL)
  {
    tailNode -> back = last();
  }
  if(tailNode -> back != NULL)          
  {
    tailNode -> back -> next = tailNode;
  } 
  if(head == NULL)
  {
    tailNode -> back = NULL;
    head = tailNode;
  }
 
  length++;
  
}

template <class ItemType>
int DList<ItemType>::lengthIs() const	
{
	// Post : Function returns current length of list  
   return length;
   
   
}

template <class ItemType>
NodeType<ItemType>* DList<ItemType>::location(ItemType item) const	//needed for access item
{
	//  Pre : item to be located is passed in via parameter 
        // Post : function returns address of item being searched for --
        //        if not found, NULL is returned  
        NodeType<ItemType>* tempNode = head;
        
        while(tempNode != NULL )
        {
          if ( tempNode -> info == item )
          {
            return tempNode;
          }
          else
          {
            tempNode = tempNode -> next;
          }
        }
        return NULL;
	
}

template <class ItemType>
NodeType<ItemType>* DList<ItemType>::last() const	 // needed for appendTail
{
	// Post : Function returns location of current last item in list
  
  NodeType<ItemType>* lastNode = head;
  
  while(lastNode -> next != NULL)
  {
    lastNode = lastNode -> next;
  }
  
  return lastNode;
	
}

template <class ItemType>
void DList<ItemType>::deleteLocation (NodeType<ItemType>* delPtr)	// Inlist used with, Needed for deleteItem
{

	//  Pre : Item to be deleted exits in list and its location
        //        is passed in via parameter
                   
	// Post : Location passed in is removed from list;  Length
        //        is decremented, and location is deallocated 

        // Special Cases Handled for Deleting Only One Item in List,
        // The Head Item of List, and the Tail Item of List
  if((delPtr -> next == NULL ) && ( delPtr -> back == NULL))
  {
    head == NULL;
  }        
  else if(delPtr -> next == NULL)
  {
    delPtr -> back -> next = NULL;
  }  
  else if(delPtr -> back == NULL)
  {
    delPtr -> next -> back = NULL;
    head = delPtr -> next;
  } 
  else
  {
    delPtr -> next -> back = delPtr -> back;
    delPtr -> back -> next = delPtr -> next;
  }
  
  delete delPtr;
  length--;


}
