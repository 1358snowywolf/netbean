/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: isabell13
TASK: gift1
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */


#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class np {
public:
   int initial_amount;
   vector<np*> friend_list;
   int final_amount;
   np (string n) : name(n), final_amount(0) {}
private:
   string name;
};

int main(int argc, const char * argv[]) {
   ifstream fin ("gift1.in");
   ofstream fout ("gift1.out");
   
   int count;
   fin >> count;
   
   unordered_map<string, np*> np_map;
   vector<string> np_name;
   
   // begin to read and add all nps to the set.
   for (int i = 0; i< count; i++) {
       string name;
       fin >> name;
       np* item = new np(name);
       np_map.insert({name, item});
       np_name.push_back(name);
   }
   
   // read and add the money and friend into each person.
   for (int i = 0; i< count; i++) {
       string name;
       fin >> name;
       auto person = np_map.find(name);
       if (person != np_map.end()) {
           np* giver = np_map[name];
           int amount;
           int count_of_friend;
           
           fin >> amount;
           fin >> count_of_friend;
           giver->initial_amount = amount;
           vector<np*> list;
           
           for(int j = 0; j< count_of_friend; j++) {
               string friend_name;
               fin >> friend_name;
               list.push_back(np_map[friend_name]);
           }
           
           giver->friend_list = list;
       }
   }
   
   //calculations
   for(int i = 0; i < np_name.size(); i++){
       string current_name = np_name[i];
       int giving = np_map[current_name]->initial_amount;
       int number_of_recievers = np_map[current_name]->friend_list.size();
       int leftovers = 0;
       int amount_giving = 0;
       
       if(number_of_recievers == 0){
           leftovers = giving;
       }
       else{
           leftovers = giving % number_of_recievers;
           amount_giving = giving / number_of_recievers;
       }
       
       np_map[current_name]->final_amount += leftovers;
       np_map[current_name]->final_amount -= giving;
       
       for(int i = 0; i < number_of_recievers; i++){
           np_map[current_name]->friend_list[i]->final_amount += amount_giving;
       }
   }

   // printing
   for(int i = 0; i < np_name.size(); i++){
       int end_money = np_map[np_name[i]]->final_amount;
       fout << np_name[i] << " " << end_money << endl;
   }
   
   return 0;
}