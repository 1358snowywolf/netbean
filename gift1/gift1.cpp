/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   gift1.cpp
 * Author: zduan
 *
 * Created on August 15, 2018, 8:07 PM
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class np {
public:
   int initial_amount;
   unordered_map<string, np*> friend_list;
   int final_amout;
   np (string n) : name(n), final_amout(0) {}
private:
   string name;
};

int main(int argc, const char * argv[]) {
   ifstream fin ("/home/zduan/gift1.in");
   ofstream fout ("/home/zduan/gift1.out");
   
   int count;
   fin >> count;
   
   unordered_map<string, np*> np_map;
   
   // begin to read and add all nps to the set.
   for (int i = 0; i< count; i++) {
       string name;
       fin >> name;
       np* item = new np(name);
       np_map.insert({name, item});
   }
   
   np* giver = new np();
   
   // read and add the money and friend into each person.
   for (int i = 0; i< count; i++) {
       string name;
       fin >> name;
       auto person = np_map.find(name);
       if (person != np_map.end()) {
           giver = np_map[name];
           int amount;
           int count_of_friend;
           
           fin >> amount;
           fin >> count_of_friend;
           giver->initial_amount = amount;
           unordered_map<string, np*> list;
           
           for(int j = 0; j< count_of_friend; j++) {
               string friend_name;
               fin >> friend_name;
               list.insert({friend_name, np_map[friend_name]});
           }
           
           giver->friend_list = list;
       }
   }
   
   for(int i = 0; i < giver->friend_list.size(); i++){
       int moneyGive = giver->friend_list[2]->initial_amount;
       int leftover = moneyGive % giver->friend_list.size();
       giver->final_amount = giver->friend_list->final_amount - (moneyGive / giver->friend_list.size());
   }
   
   
   
   return 0;
}

