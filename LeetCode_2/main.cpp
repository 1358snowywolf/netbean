/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: zduan
 *
 * Created on August 12, 2018, 12:57 PM
 */

#include <cstdlib>
#include <iostream>
#include <queue>
#include <cmath>
#include <climits>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

class TreeNode{
public:
    int val;
//    int height;
    TreeNode* left;
    TreeNode* right;
//    TreeNode* parent;
    
    TreeNode(int input){
        val = input;
//        if(left != NULL && right != NULL){
//            if(left->height > right->height){
//                height = left->height + 1;
//            }
//            else{
//                height = right->height + 1;
//            }
//        }
    }
};

class Solution739{
public:
    vector<int> dailyTemperatures(vector<int>& temperatures){
        vector<int> answer (temperatures.size(), 0);
        stack<pair<int, int>> idk;
        
        for(int i = 0; i < temperatures.size(); i++){
            while(!idk.empty()){
                if(idk.top().first < temperatures[i]){  //hotter
                    answer[idk.top().second] = i - idk.top().second;
                    idk.pop();
                }
                else{      //colder, 
                    break;
                }
            }

            pair<int, int> input (temperatures[i], i);
            idk.push(input); 
        }
        
        return answer;
    }
};

class Solution496{
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums){
        stack<int> big;
        vector<int> answer (findNums.size(), -1);
        
        for(int i = findNums.size() - 1; i >= 0; i--){   //put into stack
            if(!big.empty() && big.top() < findNums[i]){
                while(big.top() < findNums[i]){
                    big.pop();
                    big.push(findNums[i]);
               }
            }
            else{
                big.push(findNums[i]);
            }
        }
        
        for(int i = 0; i < findNums.size(); i++){  //fill up vector with NUMBERS
            if(!big.empty()){
                if(big.top() == findNums[i]){
                    big.pop();
                }
                if(!big.empty()){
                    if(findNums[i] < big.top())
                    answer[i] = big.top();
                }
                else{
                    break;
                }
            } 
        }
        
            unordered_map<int, int> numberIndex;
        
        for(int i = 0; i < nums.size(); i++){       //make unordered_map
            pair<int,int> input (nums[i], i);
            numberIndex.insert(input);
        }
        
        for(int i = 0; i < answer.size(); i++){
            if(answer[i] == -1){
                continue;
            }
            else{
                if(numberIndex.find(answer[i]) != numberIndex.end()){
                    int thing = numberIndex[answer[i]];
                    answer[i] = thing;
                }
            }
        }
        
        return answer;
    }
};

class Solution046{
public:
    int lengthOfLastWord(string s) {
        int length = 0;
        
        if(s.size() == 0){
            return 0;
        }
        else{
            for(int i = s.size() - 1; i >= 0; i--){
                if(s[i] == ' ' && length != 0){
                    return length;
                }
                else{
                    if(i == s.size() - 1 && s[i] == ' '){
                        continue;
                    }
                    else if(length == 0 && s[i] == ' '){
                        continue;
                    }
                    else{
                        length++;
                    }
                }
            }
        }
        
        return length;
    }
};

class Solution014{
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0){
            return "";
        }
        if(strs.size() == 1){
            return strs[0];
        }
        string answer = strs[0];
        
        for(int i = 1; i < strs.size(); i++){
            string current = strs[i];
            for(int d = 0; d < answer.size(); d++){
                if(answer.size() == 0){
                    return answer;
                }
                if(answer[d] != current[d]){
                    answer = answer.substr(0, d);
                    break;
                }
            }
            
            answer += strs[i];
        }
        
        return answer;
    }
};

class Solution235{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p == root || q == root){
            return root;
        }
        if(p == root->left || p == root->right){
            if(q == root->right || q == root->left){
                return root;
            }
        }
        
        vector<TreeNode*> list;
        list.push_back(root);
        
        vector<TreeNode*> right = recursive(list, root->right, p, q);
        vector<TreeNode*> left = recursive(list, root->left, p, q);
        
        TreeNode* lca = root;
        bool pinright = false;
        bool qinright = false;
        
        for(int i = 0; i < right.size(); i++){  //finding out where everything is
            if(p == right[i]){
                pinright = true;
                if(qinright){
                    return q;
                }
            }
            if(q == right[i]){
                qinright = true;
                if(pinright){
                    return p;
                }
            }
            if(qinright && pinright){
                break;
            }
        }
        
        if(pinright == false && qinright == false){
            for(int i = 0; i < left.size(); i++){
                if(left[i] == p){
                    lca = p;
                }
                if(left[i] == q){
                    lca = q;
                }
            }
        }
        
        for(int i = 0; i < left.size(); i++){
            for(int d = 0; d < right.size(); d++){
                if(left[i] == right[i]){
                    lca = left[i];
                }
            }
        }
        
        return lca;
    }
    
    vector<TreeNode*> recursive(vector<TreeNode*>& list, TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == p || root == q){
            return list;
        }
        else{
            list.push_back(root);
            
            if(root->left != NULL){
                recursive(list, root->left, p, q);
            }
            if(root->right != NULL){
                recursive(list, root->right, p, q);
            }
            
            return list;
        }
    }
};

class Solution235II{
public:
    Solution235II() : result(NULL) {}
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL){
            return NULL;
        }
        if(p == q){
            return p;
        }
        vector<TreeNode *> tmp;
        recursive(root, tmp, p, q);
        return result;
    }
    
    void recursive(TreeNode* root, vector<TreeNode*> list, TreeNode* p, TreeNode* q){
        if(root == NULL || result != NULL){
            return;
        }
        
        list.push_back(root);
        if(root == p || root == q){
            if(global_list.size() == 0){
                for(auto item = list.begin(); item !=list.end(); item++){
                    global_list.push_back(*item);
                }
            }
            else{
                for(int i = 0; i < min(global_list.size(), list.size()); i++){
                    if (list[i] == global_list[i]) {
                        result = global_list[i];
                    } else {
                        break;
                    }
                }
                return;
            }
        }  
        recursive(root->left, list, p, q);
        recursive(root->right, list, p, q);

    }
    
private:
    vector<TreeNode*> global_list;
    TreeNode* result;
};

class Trie{
public:
    bool isLeaf;
    Trie* character[26];
    
    // constructor
    Trie(){
        this->isLeaf = false;
        
        for(int i = 0; i < 26; i++){
            this->character[i] = NULL;
        }
    }
        
    void insert(string);
};

void Trie::insert(string key){
    Trie* curr = this;
    
    for(int i = 0; i < key.length(); i++){
        if(curr->character[key[i] - 'a'] == NULL){
            curr->character[key[i] - 'a'] = new Trie();
        }
        
        if(i + 1 == key.length()){
            curr->isLeaf = true;
        }
        
        curr = curr->character[key[i] - 'a'];
    }
}

class Solution014II{
public:
    string longestCommonPrefix(vector<string>& strs){
        if(strs.size() == 0){
            return "";
        }
        else if(strs.size() == 1){
            return strs[0];
        }
        else{
            auto same = strs[0];
            trie = new Trie();
            
            for(int i = 0; i < strs.size(); i++){
                trie->insert(strs[i]);
                
                if(strs[i] == ""){
                    return "";
                }
                
                if(same != strs[i]){
                    same = -1;
                }

                if(i + 1 == strs.size() && same == strs[0]){
                    return same;
                }
            }

            string answer = "";
            int times = 0;
            int index = 0;

            while(trie != nullptr){
                for(int i = 0; i < 26; i++){
                    if(trie->character[i] != NULL){
                        if(times >= 1){
//                            answer += (char)('a' + index);
                            return answer;
                        }
                        else{
                            index = i;
                            times++;
                        }
                        
                    }
                }

                answer += (char)('a' + index);
                if(trie->isLeaf){
                    return answer;
                }
                trie = trie->character[index];
                times = 0;
            }

            return answer;
        }
    }
    
private:
    Trie* trie; // = new Trie();
};

int main(int argc, char** argv) {
//    TreeNode* root = new TreeNode(6);
//    TreeNode* left = new TreeNode(2);
//    TreeNode* leftleft = new TreeNode(0);
//    TreeNode* leftright = new TreeNode(4);
//    TreeNode* leftrightleft = new TreeNode(3);
//    TreeNode* leftrightright = new TreeNode(5);
//    TreeNode* right = new TreeNode(8);
//    TreeNode* rightleft = new TreeNode(7);
//    TreeNode* rightright = new TreeNode(9);
//    
//    root->left = left;
//    root->right = right;
//    left->left = leftleft;
//    left->right = leftright;
//    right->left = rightleft;
//    right->right = rightright;
//    leftright->left = leftrightleft;
//    leftright->right = leftrightright;
//    
//    Solution235II* sol = new Solution235II();
//    auto thing = sol->lowestCommonAncestor(root, leftrightright, leftrightright);
    
    string array[] = {"ab", "a"};                                                     //the extra a.
    vector<string> vec (array, array + sizeof(array) / sizeof(array[0]));
    Solution014II* sol = new Solution014II();
    auto thing = sol->longestCommonPrefix(vec);
    
    cout << thing;
    
    return 0;
}

