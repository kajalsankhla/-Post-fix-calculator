#include<iostream>
#include "stack_c.h"
#include <stdexcept>

using namespace std;
 
Stack_C:: Stack_C(){
    stk = new List();
}

Stack_C:: ~Stack_C(){
   delete stk;
}

void Stack_C::push(int data){
   stk -> insert(data);
}

int Stack_C::pop(){
  try{ 
   if(stk -> get_size() != 0){
   return stk -> delete_tail();
   }
   else{
      throw runtime_error("Empty Stack");
   }
}
catch(const std::bad_alloc& ){
throw runtime_error("Out of Memory");
}
}

int Stack_C:: get_element_from_top(int idx){
   if(idx>stk->get_size() - 1){
      throw runtime_error("Index out of range");
   }
   else{
      Node* temp = stk->get_head();
      for (int i = 0; i < stk->get_size()-idx; i++)
      {
         temp = temp->next;
      }
      return temp->get_value();
   }
}

int Stack_C:: get_element_from_bottom(int idx){
   if(idx > stk->get_size() - 1){
      throw runtime_error("Index out of range");
   }
   else{
      Node* temp = stk->get_head();
      for (int i = 0; i < idx+1 ; i++)
      {
         temp = temp->next;
      }
      return temp->get_value();
   }
}

void Stack_C:: print_stack(bool top){
   Node* temp = stk->get_head();
   if(top){
      for (int i = 0; i < stk->get_size(); i++)
      {
         temp = temp->next;
      }
      for (int i = 0; i < stk->get_size(); i++)
      {
         cout<<temp->get_value()<<endl;
         temp = temp->prev;
      }   
   }
   else{
      for (int i = 0; i < stk->get_size(); i++)
      {
         temp = temp->next;
         cout<<temp->get_value()<<endl;
      }  
   }
}

int Stack_C:: add(){
   if( stk -> get_size() < 2){
        throw runtime_error("Not Enough Arguments");
   }
   else{
        Node* temp = stk -> get_head();
        for (int i = 0; i < stk -> get_size(); i++)
        {
            temp = temp->next;
        }
        int a = temp -> get_value();
        int b = temp -> prev -> get_value();
        pop();
        pop();
        int c= a+b;
        stk -> insert(c);
        return c;
   }
}

int Stack_C:: subtract(){
   if( stk -> get_size() < 2){
        throw runtime_error("Not Enough Arguments");
   }
   else{
        Node* temp = stk -> get_head();
        for (int i = 0; i < stk -> get_size(); i++)
        {
            temp = temp->next;
        }
        int a = temp -> get_value();
        int b = temp -> prev -> get_value();
        pop();
        pop();
        int c= b-a;
        stk -> insert(c);
        return c;
   }
}

int Stack_C:: multiply(){
   if( stk -> get_size() < 2){
        throw runtime_error("Not Enough Arguments");
   }
   else{
        Node* temp = stk -> get_head();
        for (int i = 0; i < stk -> get_size(); i++)
        {
            temp = temp->next;
        }
        int a = temp -> get_value();
        int b = temp -> prev -> get_value();
        pop();
        pop();
        int c= a*b;
        stk -> insert(c);
        return c;
   }
}

int Stack_C:: divide(){
   if( stk -> get_size() < 2){
        throw runtime_error("Not Enough Arguments");
   }
   else{
        Node* temp = stk -> get_head();
        for (int i = 0; i < stk -> get_size(); i++)
        {
            temp = temp->next;
        }
        int a = temp -> get_value();
        int b = temp -> prev -> get_value();
        pop();
        pop();
            if(a==0){
                throw runtime_error("Divide by Zero Error");
            }
            else{
               if (a*b >=0){
                int c= b/a;
                stk -> insert(c);
                return c;
               }
               else{
                  int c= b/a;
                  stk -> insert(c-1);
                  return c-1;
               }
            }
   }
}

List* Stack_C:: get_stack(){
   return stk;
}

int Stack_C:: get_size(){
   return stk->get_size();
}
