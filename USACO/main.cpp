/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: isabell13
TASK: ride
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */

#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>

using namespace std;

int main(int argc, char** argv) {
    ofstream fout ("gift.out");
    ifstream fin ("gift.in");
//    fin >> comet;
//    fin >> guess;
    
    std::unordered_map<std::string,int> money;
    
    int friends;
    fin >> friends;
    
    for(int i = 0; i <= friends; i++){
        string newFriend;
        fin >> newFriend;
        money.insert({newFriend, 0});
    }
    
    //create a hash table that reads all the names starting from line 1 to line friends + 1
    //continue reading down the thing
    //get name, minus the amount they withdraw from the key's value (int amount)
    //find the amounts you will give to each person (int people) 
    //give giver back his leftover money (int giving = amount / people)
    //for the next people lines, give that amount to their thing (=+ giving)
    //repeat until reach the bottom 

    // print key + " " + value
    return 0;
}

