#include<iostream>
using namespace std;
#include "dlist.h"
#include "stdlib.h"

void PrintMenu(char sel); //done
void HeadInsert (DList<int>& list); //done
void TailInsert (DList<int>& list); //done
void AccessItem (DList<int>& list); //done
void Delete (DList<int>& list); // done
void PrintList (const DList<int>& list); //done
void PrintLength (const DList<int>& list); //done
void makeEmpty( DList<int>& list); // Done


int main()
{
  DList<int> list;
  char sel;
  do
  {
  
    PrintMenu (sel);
    cin >> sel;
    switch (toupper(sel))
    {
    
    case 'H' : HeadInsert(list); break;
    case 'T' : TailInsert(list); break;
    case 'A' : AccessItem(list); break;
    case 'D' : Delete(list); break;
    case 'P' : PrintList(list); break;
    case 'L' : PrintLength(list); break;
    case 'E' : makeEmpty(list); break; // Here's an Easter Egg not in my menu
    case 'Q' : cout << "\tExiting Program...\n"; break;
    default : cout << "\tError. Try Again." << endl;
    
    }
    
  } while(toupper(sel) != 'Q');
  
  
}

void PrintMenu(char sel)
{
  cout<<"|----------------------------|"<<endl;
  cout<<"|------------Menu------------|"<<endl;
  cout<<"|----------------------------|"<<endl;
  cout<<"|                            |"<<endl;
  cout<<"| H: Insert item at front    |"<<endl;
  cout<<"| T: Insert item at back     |"<<endl;
  cout<<"| A: Access an item in list  |"<<endl;
  cout<<"| D: Delete an item in list  |"<<endl;
  cout<<"| P: Print the list          |"<<endl;
  cout<<"| L: Print the list's length |"<<endl;
  cout<<"| Q: Quit the program        |"<<endl;
  cout<<"|                            |"<<endl;
  cout<<"|----------------------------|"<<endl;
  cout<<"|                            |"<<endl;
  cout<<"|  Please enter your choice: |"<<endl;
}

void HeadInsert (DList<int>& list)
{
  int item;
  cout << "\v\tItem to be Inserted Onto Head of List : ";

  cin >> item;
  if (! list.inList(item))
      list.insertHead(item);
  else
      cout << "\t Item Already Exists in List. No Duplicates Allowed." << endl;
  
}

void TailInsert (DList<int>& list)
{
  int item;
  cout << "\v\tItem to be Inserted Onto Tail of List : ";
  cin >> item;
  if (! list.inList(item))
  {
      list.appendTail(item);
  }
  else
      cout << "\t Item Already Exists in List. No Duplicates Allowed." << endl;
}

void AccessItem (DList<int>& list)
{
  int item;
  cout << "\v\tWhat item do you want to access? : ";
  cin >> item;
  if ( list.inList(item))
  {
      list.deleteItem(item);
      list.insertHead(item);
  }
  else
      cout << "The Item is not in the List." << endl;
}

void Delete (DList<int>& list)
{
  int item;
  cout << "\v\tItem to be Deleted From The List : ";
  cin >> item;
  if ( list.inList(item))
  {
      list.deleteItem(item);
  }
  else
      cout << "\t Item Does Not Exist In The List." << endl;
  

}

void PrintList ( const DList<int>& list)
{
  cout << "Printing List..." << endl;
  list.print();
}

void PrintLength (const DList<int>& list)
{
  int length;
  length = list.lengthIs();
  cout << " The Length of the list is " << length << endl;
  list.lengthIs();
}

void makeEmpty(DList<int>& list)
{
  list.makeEmpty();
}




