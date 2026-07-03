#include <iostream>
#include "stack_a.h"
#include <stdexcept>

using namespace std;

Stack_A::Stack_A(){
    size=0;
}

void Stack_A::push(int data){
    if (size>=1024){
        throw runtime_error ("Stack Full");
    }
    else{
        stk[size]=data;
        size = size+1;
    }
} 

int Stack_A::pop(){
    if (size<1){
        throw runtime_error ("Empty Stack");
    }
    else{
        int a=stk[size-1];
        size = size-1;
        return a;
    }
}

int Stack_A::get_element_from_top(int idx){
    if(idx>=size || idx<0){
        throw runtime_error ("Index out of range");
    }
    else{
        int a = stk[size-idx-1];
        return a;
    }
}

int Stack_A::get_element_from_bottom(int idx){
    if(idx>=size || idx<0){
        throw runtime_error ("Index out of range");
    }
    else{
        int a = stk[idx];
        return a;
    }
}

void Stack_A::print_stack(bool top){
    if (top == 1){
        for(int i=size-1; i>=0; i--){
            cout<<stk[i]<<endl;
        }
    }
    else{
        for(int i=0; i<size; i++){
            cout<<stk[i]<<endl;
        }
    }
}


int Stack_A::add(){
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

int Stack_A::subtract(){
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

int Stack_A::multiply(){
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

int Stack_A::divide(){
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

int* Stack_A::get_stack(){
    return stk;
}

int Stack_A::get_size(){
    int a=size;
    return a;
}
