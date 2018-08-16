/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MyStack.cpp
 * Author: zduan
 * 
 * Created on July 29, 2018, 4:53 PM
 */
#include <cstdlib>
#include <iostream>
#include <queue>
#include "MyStack.h"

/** Initialize your data structure here. */
MyStack::MyStack() {
}

/** Push element x onto stack. */
void MyStack::push(int x) {
    stack.push(x);

    for(int i = 0; i < stack.size() - 1; i++){
        stack.push(stack.front());
        stack.pop();
    }
}

/** Removes the element on top of the stack and returns that element. */
int MyStack::pop() {
    int peeked = stack.front();
    stack.pop();

    return peeked;
}

/** Get the top element. */
int MyStack::top() {
    return stack.front();
}

/** Returns whether the stack is empty. */
bool MyStack::empty() {
    return stack.empty();
}
//private:
//    queue<int> stack;
//    queue<int> dummy;

    

//MyStack::~MyStack() {
//}

