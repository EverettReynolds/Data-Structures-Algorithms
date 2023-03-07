#include <stack>
#include <bits/stdc++.h>
#include <cstddef> 
#include "bet.h"
using namespace std;

BET::BET  ()
{
  BETPtr root; // root of tree
  stack <BETPtr> s; // a stack
}

BET::~BET  ()
{

}

bool BET::isEmpty() const
{
  if(root == NULL)
  {
    return true;
  }
  else
  {
  return false;
  }
}

void BET::makeEmpty() // public
{
  makeEmpty(root);
}

void BET::makeEmpty( BETPtr& t ) const //private
{
  delete root;
}

void BET::insertPrefixOperator (char token) // prefix expression tree
{
  BETPtr newBet = new BinaryNode;
  newBet -> info.whichType = OPERATOR;
  newBet -> info.theContent.opsymbol = token;
  newBet -> left = s.top();
  s.pop();
  newBet -> right = s.top();
  s.pop();
  s.push(newBet);
  root = newBet;
}

void BET::insertPostfixOperator (char token) //postfix expression tree
{
  BETPtr newBet = new BinaryNode;
  newBet -> info.whichType = OPERATOR;
  newBet -> info.theContent.opsymbol = token;
  newBet -> right = s.top();
  s.pop();
  newBet -> left = s.top();
  s.pop();
  s.push(newBet);
  root = newBet;
  
}

void BET::insertOperand (char token) // infix expression tree
{

  BETPtr newBet = new BinaryNode;
  newBet -> info.whichType = OPERAND;
  newBet -> info.theContent.variable = token;
  newBet -> right = NULL;
  newBet -> left = NULL;
  s.push(newBet);
  
}

void BET::preorder() const //PUBLIC //printing trees
{
  
  if( isEmpty())
  {
    cout << "The Tree is Empty.";
  }
  else
  {
    preorder(root);
  }
  cout << endl;
  
}

void BET::preorder( BETPtr t ) const //PRIVATE
{
  if( t != NULL)
  {
    if((t->info.whichType) == OPERAND)
    {
      cout << t->info.theContent.variable << " ";
    }
    else
    {
       cout << t->info.theContent.opsymbol << " ";
    }
    
    preorder(t->left);
    preorder(t->right);
    
  }
}

void BET::inorder() const //PUBLIC //printing trees
{
  if( isEmpty())
  {
    cout << "The Tree is Empty.";
  }
  else
  {
    inorder(root);
  }
  cout << endl;
}

void BET::inorder( BETPtr t ) const //PRIVATE
{
  if( t!= NULL)
  {
    if(t-> left != NULL)
    {
      cout << "(";
    }
    inorder(t->left);
    if((t->info.whichType) == OPERAND)
    {
      cout << t->info.theContent.variable << " ";
    }
    else
    {
       cout << t->info.theContent.opsymbol << " ";
    }
    inorder(t->right);
    if(t-> right != NULL)
    {
      cout << ")";
    }
  }
}

void BET::postorder() const //PUBLIC //printing trees
{
  
  if( isEmpty())
  {
    cout << "The Tree is Empty.";
  }
  else
  {
    postorder(root);
  }
  cout << endl;
  
}

void BET::postorder( BETPtr t ) const //PRIVATE
{
  if( t != NULL)
  {
    
    postorder(t->left);
    postorder(t->right);
    
    if((t->info.whichType) == OPERAND)
    {
      cout << t->info.theContent.variable << " ";
    }
    else
    {
       cout << t->info.theContent.opsymbol << " ";
    }
  }
}








