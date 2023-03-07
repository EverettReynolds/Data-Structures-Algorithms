#include <iostream>
#include <stdio.h>
#include<string.h>
#include<ctype.h>

using namespace std;


struct RecType 
{ 

int age; 
float weight; 
char gender; 

};



int main()
{

int num = 5;
//int *intPtr = NULL;
int *intPtr = &num;
*intPtr = *intPtr * 10;
cout << *intPtr << endl;

RecType *recPtr = NULL;
recPtr = new RecType();
recPtr -> age = 25;
recPtr -> weight = 190;
recPtr -> gender = 'M';
recPtr -> age = 26;
recPtr -> age = 27;
recPtr -> age = 28;
recPtr -> age = 29;
recPtr -> age = 30;
cout << recPtr -> age << " " << recPtr -> weight << " " << recPtr -> gender << " " << endl;

delete recPtr;
recPtr = NULL;

char *strPtr = new char[50];
strcpy(strPtr, "Operating Systems");
cout << strPtr << endl;
int count = 0;

for(int i = 0; i < strlen(strPtr); i++)
{
  if(islower(*(strPtr+i)))
  {
    count++;
  }
}
cout << "Lower Case Letter Count: " << count << endl;

strPtr = strPtr + 10;
cout << strPtr << endl;

return 0;

}