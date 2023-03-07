#include <stack>
#include <bits/stdc++.h>
#include<iostream> // add continuous loop do-while to cycle through program
#include "bet.h"
using namespace std;

void printMenu(char choice);
void makeEmpty(BET t);
void Prefix(BET& t);
void Infix(BET t);
void Postfix(BET t);
void expressOutput(BET t); // Build another tree will be here
int precedence(char o);


int main()
{
  char choice;
  
  BET t = BET();
  
  do
  {
  
    printMenu(choice);
    cin >> choice;
    switch (toupper(choice))
    {
      case 'A': Prefix(t);  break;
      case 'B': Infix(t); break;
      case 'C': Postfix(t); break;
      case 'Y': printMenu(choice); cin >> choice; break;
      case 'N':  break;
      default : cout << "\tError. Enter Valid Input." << endl;
    }
    
  }while(toupper(choice) != 'N');
  

  cout << "Program Now Deconstructing Tree and Exiting." <<endl;
  return 0;
}

void printMenu(char choice)
{
  cout<< "      &&&&&&&&&&&          Building Binary Trees and Expressions     &&&&&&&&&&&               " << endl;
  cout<< " A) Prefix                 B) Infix                               C) Postfix" << endl;
  cout<< "Your Expression Type ==> ";
  
   
}

void Prefix(BET& t)
{
  string equation;
  char token;
  cout<< "Enter Your Equation ";
  cin >> equation;
  
  for(int i  = equation.length(); i >= 0; i--)
  {
    if(equation[i] == '+' || equation[i] == '-' || equation[i] == '/' || equation[i] == '*')
    {
      t.insertPrefixOperator(equation[i]);
    }
    else
    {
      t.insertOperand(equation[i]);
    }
  
  }
  
  expressOutput(t);
  
  
}

void Infix(BET t)
{
  string equation;
  string translation;
  char token;
  stack <char> s;
  s.push('&');
  cout<< "Enter Your Equation ";
  cin >> equation;
  for(int i  = 0; i < equation.length(); i++)
  {
    if((equation[i] >= 'A' && equation[i] <= 'Z') || (equation[i] >= 'a' && equation[i] <= 'z'))
    {
      translation = translation + equation[i];
    }
    
    else if(equation[i] == '(')
    {
      s.push('(');
    }
    
    else if(equation[i] == ')')
    {
    
      while(s.top() != '&' && s.top() != '(')
      {
        char o = s.top();
        s.pop();
        translation = translation + o;
      }
      
      if(equation[i] == '(')
      {
        char o = s.top();
        s.pop();
      }
      
    }
  
    else
    {
      while(s.top() != '&' && precedence(equation[i]) <= precedence(s.top()))
      {
        char o = s.top();
        s.pop();
        translation = translation + o;
        
      }
      s.push(equation[i]);
    }
  }
  
  while(s.top() != '&')
  {
    char o = s.top();
    s.pop();
    translation = translation + o;
  }
  for(int i  = 0; i < translation.length(); i++)
  {
    if(translation[i] == '+' || translation[i] == '-' || translation[i] == '/' || translation[i] == '*')
    {
      t.insertPostfixOperator(translation[i]);
    }
    else
    {
      t.insertOperand(translation[i]);
    }
  
  }
  
  expressOutput(t);
  
}

void Postfix(BET t)
{
  string equation;
  char token;
  cout<< "Enter Your Equation ";
  cin >> equation;
  
  for(int i  = 0; i < equation.length(); i++)
  {
    if(equation[i] == '+' || equation[i] == '-' || equation[i] == '/' || equation[i] == '*')
    {
      t.insertPostfixOperator(equation[i]);
    }
    else
    {
      t.insertOperand(equation[i]);
    }
  
  }
  
  expressOutput(t);
  
}



void expressOutput(BET t) // call this after BET is built
{
  cout << "Prefix Expression Produced From This Tree: " << endl;
  t.preorder();
  cout << "Infix Expression Produced From This Tree: " << endl;
  t.inorder();
  cout << "Postfix Expression Produced From This Tree: " << endl;
  t.postorder();
  cout << "Build Another Tree? Type 'Y' or 'N' to continue or leave respectively." << endl;
  
}

int precedence(char o)
{

  if(o == '*' || o == '/') 
  {
    return 2; 
  }
  else if(o == '+' || o == '-') 
  {
    return 1; 
  }
  else
  {
    return -1;
  }
}





