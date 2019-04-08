#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<iostream>
 using namespace std; 
 //grammar
 /*E -> E+T | T
T -> T*F | F
F -> (E) | id*/
 
 
 
 //grammar after removing left refactoring
/*E -> TE'
E' -> +TE' | ε
T -> FT'
T' -> *FT' | ε
F -> (E) | id*/
string input;
int i,error;
void E();
void T();
void Eprime();
void Tprime();
void F();
  
main()
{
i=0;
error=0;

cout<<"Enter an arithmetic expression   :  " ;
cin>>input;
E();
if(input.length()==i&&error==0)
cout<<"\nAccepted..!!!\n";
else cout<<"\nRejected..!!!\n";
}
          
          
  
void E()
{
     T();
     Eprime();
}
void Eprime()
{
     if(input[i]=='+')
     {
     i++;
     T();
     Eprime();
     }
     }
void T()
{
     F();
     Tprime();
}
void Tprime()
{
     if(input[i]=='*')
     {
           i++;
           F();
           Tprime();           
       }
                      
}
     void F()
     {
          if(input[i]=='i' && input[i+1]=='d')
          i=i+2;
          else if(input[i]=='(')
          {
          i++;
          E();
          if(input[i]==')')
          i++;

          else error=1; 
          }
         
          else error=1;
      }
