#include <cstdlib>
#include <iostream>
#include <ctime>
#include <vector>
#include <cmath>
#include <climits>
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

class CoinExchange{
public:
    int coinExchange(int change, vector<int> coins){
        if(change == 0){
            return 0;
        }
        else{
            sort(coins.begin(), coins.end());
            vector<int> answer (change + 1, 0);
            answer[0] = 0;

            for(int i = 1; i < answer.size(); i++){
                int current_coins = INT_MAX;
                int cent_value = 0;
                for(int d = 0; d < coins.size(); d++){
                    if(i - coins.at(d) >= 0 && answer[i - d] != -1){  //error
                        current_coins = min(current_coins, answer[i - d] + 1);
                        cent_value = coins[d];
                    }
                    
                    if(i - d < 0){
                        break;
                    }
                }
                if(current_coins == INT_MAX){
                    answer[i] = -1;
                }
                else{
                    answer[i] = current_coins + answer[i - cent_value];
                } 
            }
            
            return answer[change - 1];
        }
    }
};

int main(int argc, char** argv) {
    
    int change = 7;
    int array[] = {2};
    vector<int> coins (array, array + sizeof(array) / sizeof(int));
    CoinExchange* ce = new CoinExchange();
    auto thing = ce->coinExchange(change, coins);
    
    return 0;
}