/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MyStack.h
 * Author: zduan
 *
 * Created on July 29, 2018, 4:53 PM
 */
#include <cstdlib>
#include <iostream>
#include <queue>

#ifndef MYSTACK_H
#define MYSTACK_H

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack();
    
    /** Push element x onto stack. */
    void push(int x);
    
    /** Removes the element on top of the stack and returns that element. */
    int pop();
    
    /** Get the top element. */
    int top();
    /** Returns whether the stack is empty. */
    bool empty();
    
private:
    std::queue<int> stack;
    std::queue<int> dummy;
};

#endif /* MYSTACK_H */

