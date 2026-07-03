#include<iostream>
#include "stack_b.h"
#include <stdexcept>

using namespace std;
 
Stack_B::Stack_B(){
    size=0;
    capacity=1024;
    stk=new int[capacity];
}

Stack_B::~Stack_B(){
    delete stk;
}

void Stack_B::push(int data){
    if (size>=capacity){
        capacity=2*capacity;
        
        int* newstk=new int[capacity];
        for(int i=0;i<size;i++){
            newstk[i]=stk[i];
        }
        delete stk;
        stk=newstk;
        stk[size]=data;
        size++;
    }
    else{
        stk[size]=data;
        size++;
    }
} 

int Stack_B::pop(){
try{    
    if (size<1){
        throw runtime_error ("Empty Stack");
    }
    else if(size>1024 && capacity/2>size){
        int a=stk[size-1];
        capacity = capacity / 2;
        int* newstk=new int[capacity];
        for(int i=0;i<size;i++){
            newstk[i]=stk[i];
        }
        int* oldstk = stk;
        stk = newstk;
        delete oldstk;
        size--;
        return a;
    }
    else{
        int a=stk[size-1];
        size--;
        return a;
    }
}
catch(const std::bad_alloc& ){
throw runtime_error("Out of Memory");
}
}

int Stack_B::get_element_from_top(int idx){
    if(idx>=size || idx<0){
        throw runtime_error ("Index out of range");
    }
    else{
        int a = stk[size-idx-1];
        return a;
    }
}

int Stack_B::get_element_from_bottom(int idx){
    if(idx>=size || idx<0){
        throw runtime_error ("Index out of range");
    }
    else{
        int a = stk[idx];
        return a;
    }
}

void Stack_B::print_stack(bool top){
    if (top){
        for(int i=size-1; i>=0; i--){
            cout<<stk[i]<<endl;
        }
    }
    else{
        for(int i=0; i<size; i=i++){
            cout<<stk[i]<<endl;
        }
    }
}

int Stack_B::add(){
    if (size<=1){
        throw runtime_error("Not Enough Argumets");
    }
    else{
        int a=pop();
        int b=pop();
        int c=a+b;
        push(c);
        return c;
    }
}

int Stack_B::subtract(){
    if (size<=1){
        throw runtime_error("Not Enough Argumets");
    }
    else{
        int a=pop();
        int b=pop();
        int c=b-a;
        push(c);
        return c;
    }
}

int Stack_B::multiply(){
    if (size<=1){
        throw runtime_error("Not Enough Argumets");
    }
    else{
        int a=pop();
        int b=pop();
        int c=b*a;
        push(c);
        return c;
    }
}

int Stack_B::divide(){
    if (size<=1){
        throw runtime_error("Not Enough Argumets");
    }
    else{
        int a=pop();
        int b=pop();
        if (a==0){
            throw runtime_error("Divde By zero error");
        }
        else{
            if (a*b >=0){
                int c=b/a;
                push(c);
                return c;
            }
            else{
                int c=b/a;
                push (c-1);
                return c-1;
            }
        }
    }
}

int* Stack_B::get_stack(){
    return stk;
}

int Stack_B::get_size(){
    int a=size;
    return a;
}
