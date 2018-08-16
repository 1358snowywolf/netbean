/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: zduan
 *
 * Created on August 14, 2018, 8:18 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    unordered_set<string> color = {"red", "green", "blue"};
    auto itr = color.find("green");
    
    if(itr != color.end()){
        cout << *itr << endl;
    }
    
    color.insert("white");
    
    vector<string> vec = {"purple", "pink"};
    color.insert(vec.begin(), vec.end() - 1);
    
    return 0;
}

