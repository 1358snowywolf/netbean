#include <cstdlib>
#include <iostream>
#include <ctime>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Fibbonaci{
public:
    long slow(long number){
        if(number <= 1){
            return number;
        }
        else{
            return slow(number - 1) + slow(number - 2);
        }
    }
    
    long fast(long number){
        long array[100];
        array[0] = 0;
        array[1] = 1;
        
        for(int i = 2; i < number; i++){
            array[i] = array[i + 1] + array[i + 2];
        }
        
        return array[number];
    }
};

class GCD{
public:
    int greatestCommonDivisor(int a, int b){
        int p = max(a, b);
        int q = min(a, b);
        int r = 0;
        
        while(q != 0){
            r = p % q;
            p = q;
            q = r;
        }
        
        return p;
    }
};

class Exchange{
public:
    int moneyExchange(int cents){
        int leftover = cents % 10;
        int amount = cents / 10;
        cents = cents % 10;
        
        leftover = cents % 5;
        amount = amount + (cents / 5);
        cents = cents % 5;
        
        amount = amount + cents;
        return amount;
    }
};

class DynamicProgramming101{
public:
    int knapsack(int maxWeight, vector<int> weight, vector<int> values){
        if(maxWeight == 0) return 0;
        
        vector<int> answers(maxWeight, 0);
        int currentMax = 0;
        
        for(int i = 0; i < maxWeight; i++){
            currentMax = 0;
            for(int d = 0; d < weight.size(); d++){
                if(weight[d] <= i){
                    if(answers[i - weight[d]] + values[d] > currentMax){
                        currentMax = answers[i - weight[d]] + values[d];
                    }
                }
            }
            answers[i] = currentMax;
        }
        
        return answers[maxWeight - 1];
    }
};

class QuickSort{
public:
    void sort(vector<int>& vec, int left, int right){
        if(right - left < 1){
            return;
        }
        else{
            int middle = partition101(vec, left, right);
            
            sort(vec, left, middle - 1);
            sort(vec, middle + 1, right);
            
            return;
        }
    }
    
    int partition101(vector<int>& vec, int left, int right){
        int i = left - 1;
        
        for(int j = left; j < right; j++){
            if(vec[j] <= vec[right]){
                i++;
                int tmp = vec[i];
                vec[i] = vec[j];
                vec[j] = tmp;
            }
        }
        
        int tmp = vec[i + 1];
        vec[i + 1] = vec[right];
        vec[right] = tmp;
        
        return i + 1;
    }
};

int main(int argc, char** argv) {
    QuickSort* qs = new QuickSort();
    int arr[] = {8, 5, 0, 2};
    vector<int> vec (arr, arr + sizeof(arr) / sizeof(int));
    qs->sort(vec, 0, vec.size() - 1);
    
    for(int i = 0; i < vec.size(); i++){
        cout << vec[i] << endl;
    }
    
    return 0;
}