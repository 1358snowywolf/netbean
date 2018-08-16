/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: zduan
 *
 * Created on July 29, 2018, 11:19 AM
 */

#include <cstdlib>
#include <iostream>
#include <queue>
#include <cmath>
#include <climits>
#include "MyStack.h"
#include <unordered_set>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

class TreeNode{
public:
    int val;
    int height;
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;
    
    TreeNode(int input){
        val = input;
        
        if(left != NULL && right != NULL){
            if(left->height > right->height){
                height = left->height + 1;
            }
            else{
                height = right->height + 1;
            }
        }
    }
};

class Binary {
public:
    TreeNode* tree;
    
    Binary(int sorted[], int length){
        tree = transform(sorted, 0, length -1);
    }
    
    TreeNode* transform (int sorted[], int start, int end) {
        if(start == end){
            TreeNode* node = new TreeNode(sorted[start]);
            return node;
        }
        
        if (start > end) {
            return NULL;
        }
        
        int middle = (start + end) / 2;
        
        TreeNode* center = new TreeNode(sorted[middle]);
        
        center->left = transform(sorted, start, middle - 1);
        center->right = transform(sorted, middle + 1, end);
        
        return center;
    }
    
//    TreeNode* insert (int input){
//        
//    }
};

class SameTree{
public:
    bool isSameTree(TreeNode* p, TreeNode* q){
        if(p == NULL && q == NULL) return true;
        
        if(p == NULL || q == NULL) return false;
        
        if(p->val == q->val){
            return (isSameTree(p->left, q->left) && isSameTree(p->right, q -> right));
        }
        else{
            return false;
        }
    }
};

class Univalue{
public:
    int sum; 
    
    Univalue(){
        sum = 0;
    }
    
    int longestUnivaluePath(TreeNode* root){
        if(root == NULL &&
                root->right == NULL && 
                root->left == NULL){ 
            return 0;
        }
        else if(root == NULL) return 0;
        else{
            if(root->left != NULL && root->left->val == root->val){
                sum = longestUnivaluePath(root->left) + 1;
            }
            else if(root->right == NULL && root->right->val == root->val){
                sum = longestUnivaluePath(root->right) + 1;
            }
            else{
                return 0;
            }
        }
        
        return sum;
    }
};

class Result{
public:
    bool bal;
    int height;
    
    Result(bool b, int h): bal(b), height(h) {}
};

class Balance{
public:
    bool isBalanced(TreeNode* root){
        return yesNo(root)->bal;
    }
    
    Result* yesNo(TreeNode* root){
        if(root == NULL){
            return new Result(true, 0);
        }
        else{
            Result* left = yesNo(root->left);
            Result* right = yesNo(root->right);
            int maxHeight = max(left->height, right->height) + 1;
            
            if(left->bal == false || right->bal == false){
                return new Result(false, maxHeight);
            }
            else{
                if(abs(left->height - right->height) > 1){
                    return new Result(false, maxHeight);
                }
                else{
                    return new Result(true, maxHeight);
                }
            }
        }
    }  
};

class TwoSum{
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int start = 0;
        int end = numbers.size() - 1;
        
        while(start != end){
            if(numbers[start] + numbers[end] == target){
                vector<int> answer = {start + 1, end + 1};
                return answer;
            }
            else if(numbers[start] + numbers[end] > target){
                end--;
            }
            else{
                start++;
            }
        }
    }
};

class MinimumDepth{
public:
    int minDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        else if(root->left == NULL && root->right == NULL){
            return 1;
        }
        else{
            int answer = md(root, 1);
            return answer;
        }
    }
    
    int md(TreeNode* root, int height){
        if(root->left == NULL && root->right == NULL){
            return height;
        }
        else if(root->left != NULL && root->right == NULL){
            return md(root->left, height + 1);
        }
        else if(root->left == NULL && root->right != NULL){
            return md(root->right, height + 1);
        }
        else{ //both aren't null
            return min(md(root->left, height + 1), md(root->right, height + 1));
        }
    }
};

class SumPath{
public:
    bool hasPathSum(TreeNode* root, int sum){
        if(root == NULL) return false;
        if(root->left == NULL && root->right == NULL && root->val == sum) return true;
        sum = root->val - sum;
        return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
    }
};

class SubArray{
public:
    int maxSubArray(vector<int>& nums){
        if(nums.size() == 1){
            return nums[0];
        }
        
        int current_max = nums[0];
        int global_max = nums[0];
        
        for(int i = 1; i < nums.size(); i++){
            current_max = max(nums[i], current_max + nums[i]);
            if(current_max > global_max){
                global_max = current_max;
            }
        }
        
        return global_max;
    }
};    //KADANE ALGORITHM

class BinaryTreePaths{
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> answer;
        
        if(root == nullptr)return answer;
        else{
            DepthFirstSearch(root, to_string(root->val), answer);
            return answer;
        }
    }
    
    void DepthFirstSearch(TreeNode* root, string node, vector<string>& answer){
        if(root->left == NULL && root->right == NULL){
            answer.push_back(node);
        }
        
        if(root->left != NULL){
            DepthFirstSearch(root->left, node + "->" + to_string(root->left->val), answer);
        }
        
        if(root->right != NULL){
            DepthFirstSearch(root->right, node + "->" + to_string(root->right->val), answer);
        }
    }
};

class Symmetric{
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        else if(root->left == NULL && root->right == NULL) return true;
        else return check(root->left, root->right);
    }
    bool check(TreeNode* left, TreeNode* right){
        if(left == NULL && right == NULL) return true;
        else if(left == NULL || right == NULL) return false;
        else if(left->val != right->val) return false;
        else return check(left->left, right->right) && check(left->right, right->left);
    }
};

class Same{
public:
    stack<char> first;
    stack<char> second;
    
    bool backspaceCompare(string S, string T) {
        for(int i = 0; i < S.size(); i++){
            if(S[i] == '#' && !first.empty()) first.pop();
            else first.push(S[i]);
        }
        
        for(int i = 0; i < T.size(); i++){
            if(T[i] == '#' && !second.empty()) second.pop();
            else second.push(T[i]);
        }
        
        return first == second;
    }
};

class YouWillNeverTakeUsAlive{
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        else if(nums.size() == 1) return nums.front();
        else if(nums.size() == 2) return max(nums[0], nums[1]);
        else{
            int odd = nums[0];
            int even = nums[1];
            
            for(int i = 2; i < nums.size(); i++){
                if((i + 1) % 2 == 0){  //even
                    if(odd < even){
                        odd = even;
                    }    
                    even = even + nums[i];
                }
                else{  //odd
                    if(odd > even){
                        even = odd;
                    }
                    odd = odd + nums[i];
                }
            }
            
            return max(odd, even);
        }
    }
};

class Solution784{
public:
    vector<string> letterCasePermutation(string S) {
        recursive(S, 0);
        
        return answer;
    }
    
    void recursive(string str, int index){
        if(index == str.length()){
            answer.push_back(str);
        } else{
            recursive(str, index + 1);
            if(isalpha(str[index])){
                if(islower(str[index])){
                    str[index] = toupper(str[index]);
                } else{
                    str[index] = tolower(str[index]);
                }
                recursive(str, index + 1);
            }
        }
    }
    
private:
    vector<string> answer;
};

class Solution394{
public:
    string decodeString(string s){
        int startIndex = 0;
        return recursive(s, startIndex);
    }
    string recursive(const string& s, int& index){
        string letters = "";
        int num = 0;

        for(int i = index; i < s.size(); i++){
            if(isdigit(s[i])){
                num = num * 10;
                num = num + (s[i] - '0');
            }
            else if(s[i] == '['){
                string let = recursive(s, ++i);

                for(int d = 0; d < num; d++){
                    letters += let;
                }
                
                num = 0;
            }
            else if(isalpha(s[i])){
                letters += s[i];
            }
            else{
                index = i;
                return letters;
            }
        }
        
        return letters;
    }
};

class communism{
public:
    void putin(int GDP){
        cout << GDP << endl;
        GDP++;
        cout << GDP << endl;
    }
    
    void yeltin(int& debt){
        cout << debt << endl;
        debt++;
        cout << debt << endl;
    }
};

class Solution046{
public:
    vector<vector<int>> permute(vector<int>& nums){
        vector<int> actual;
        helper(actual, nums);
        
        return result;
        
    }

    void helper(vector<int> actual, vector<int> leftover){
        if(leftover.empty()){
            result.push_back(actual);
        }
        else{
            for(int i = 0; i < leftover.size(); i++){
                int insert = leftover[i];
                auto backupOne = actual;
                auto backupTwo = leftover;
                
                actual.push_back(insert);
                leftover.erase(leftover.begin() + i);
                helper(actual, leftover);
                
                actual = backupOne;
                leftover = backupTwo;
            }
        }    
    }
    
private:
    vector<vector<int>> result;
};

class Solution035{
public:
    int searchInsert(vector<int>& nums, int target) {
        return binarySearch(nums, 0, nums.size() - 1, target);
    }
    
    int binarySearch(vector<int> array, int start, int end, int target){
        if(end < start){ //not found in the thing
            return start;
        }
        else{
            int middle = start + ((end - start) / 2);
            
            if(array[middle] == target){
                return middle;
            }
            else if(array[middle] < target){
                return binarySearch(array, middle + 1, end, target);
            }
            else{
                return binarySearch(array, start, middle - 1, target);
            }
        }
    }
};

class Solution456{
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> sta;
        sta.push(nums[0]);
        
        for(int i = 1; i < nums.size(); i++){
            if(sta.size() == 1 && sta.top() < nums[i]) sta.push(nums[i]);
            else if(sta.size() == 2 && sta.top() > nums[i]) return true;
            else{
                while(!sta.empty()){
                    sta.pop();
                }
                sta.push(nums[i]);
            }
        }
        
        return false;
    }
};

class Solution456I{
public:
    bool find132pattern(vector<int>& nums){
        if(nums.size() < 3){
            return false;
        }
                
        for(int i = 0; i <= nums.size() - 3; i++){
            for(int j = i + 1; j <= nums.size() - 2; j++){
                for(int k = j + 1; k <= nums.size() - 1; k++){
                    if(nums.at(i) < nums.at(j) && 
                            nums.at(j) > nums.at(k) && 
                            nums.at(i) < nums.at(k)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

class Solution456II{
public:
    bool find132pattern(vector<int>& nums){
        if(nums.size() < 3){
            return false;
        }
        
        int min = INT_MAX;
        
        for(int j = 0; j < nums.size() - 1; j++){
            if(min > nums.at(j)){
                min = nums.at(j);
            }
            for(int k = j + 1; k < nums.size(); k++){
                if(nums.at(j) > nums.at(k) && nums.at(k) > min){
                    return true;
                }
            }
        }
        
        return false;
    }
};

class ListNode{
public:
    int val;
    ListNode* next;
    
    ListNode(int input){
        val = input;
    }
};

class Solution0{
public:
    ListNode* mergeKLists(vector<ListNode*>& lists){
        if(lists.size() == 0){
            return NULL;
        }
        else if(lists.size() == 1){
            return lists[0];
        }
        else{
            return recursive(lists);
        }
    }
    
private:
    ListNode* recursive(vector<ListNode*>& lists){
        if(lists.size() == 2){  //merge the two ListNodes
            return finalRecursive(lists[0], lists[1]);
        }
        else{   //call two recursive for half of the list
            if(lists.size() % 2 == 1){ //is odd
                vector<ListNode*> leftover;
                leftover.push_back(lists.at(0));
                lists.erase(lists.begin());
                
                return finalRecursive(leftover[0], recursive(lists));
            }
            else{  //is even
                vector<ListNode*> firstPart;
                vector<ListNode*> secondPart;
                int midIndex = lists.size() / 2;
                
                for(int i = 0; i < midIndex; i++){
                    firstPart.push_back(lists[i]);
                }
                
                for(int i = midIndex; i < lists.size(); i++){
                    secondPart.push_back(lists[i]);
                }
                
                ListNode* left = recursive(firstPart);
                ListNode* right = recursive(secondPart);
                
                return finalRecursive(left, right);
            }    
        }
    }
    
    ListNode* finalRecursive(ListNode* first, ListNode* second){
        ListNode* head = new ListNode(1);
        ListNode* dummyHead = head;

        while(first != NULL || second != NULL){ //if at least one isn't null
            if(first != NULL && second != NULL){ //both aren't null
                ListNode* node = new ListNode(min(first->val, second->val));
                dummyHead->next = node;
                dummyHead = dummyHead->next;

                if(first->val <= second->val){
                    first = first->next;
                }
                else{
                    second = second->next;
                }    
            }
            else if(first != NULL && second == NULL){ // second is null
                ListNode* node = new ListNode(first->val);
                dummyHead->next = node;
                dummyHead = dummyHead->next;
                first = first->next;
            }
            else{
                ListNode*node = new ListNode(second->val);
                dummyHead->next = node;
                dummyHead = dummyHead->next;
                second = second->next;
            }    
        }

        return head->next;
    }
};

int main(int argc, char** argv) {
    ListNode* xx = new ListNode(111);
    
    vector<ListNode*> vec;
    ListNode* tmp;
    ListNode* first = new ListNode(1); // 1->4->6
    tmp = first;
    tmp->next = new ListNode(4);
    tmp = tmp->next;
    tmp->next = new ListNode(6);
    ListNode* yy = new ListNode(111);

    
    
    ListNode* second = new ListNode(1); // 1->3->4
    tmp = second;
    tmp->next = new ListNode(3);
    tmp = tmp->next;
    tmp->next = new ListNode(4);
    first->next = yy;
    yy->next = xx;
    
    
    ListNode* third = new ListNode(2);
    tmp = third;
    tmp->next = new ListNode(6);

    vec.push_back(first);
    vec.push_back(second);
    vec.push_back(third);
    
//    Solution0* sol = new Solution0();
//    auto a = sol->mergeKLists(vec);
    
    cout << first << endl;
    cout << first->next << endl;
    cout << first->next->next << endl;
    
    
    
    return 0;
}