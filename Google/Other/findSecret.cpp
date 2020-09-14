#include <bits/stdc++.h>
using namespace std;

/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */

/*
the idea is to
1. minimize the cases where a guess could fail,
2. assume the cases that could fail are words with minimum # of letter matchs with other words in the list

make guess A, with # of matches M

3. maximize the change where a guess could be successful
4. assume those cases (could be successful) are cases (words in the list) that has M # of matchs with the guess word A 
*/
class Solution {
public:
    void findSecretWord(vector<string>& wordlist, Master& master) {
    ///i will need to make 10 guess myself??!    
        int times = 10;
        while(times--){
        //step1: minimize the failing cases
        //here we want to select the word with max # of matchs with other words in the list
        unordered_map<string, int> freq;
        for(auto& w1 : wordlist){
            for(auto& w2 : wordlist){
                if(w1 != w2 && match(w1,w2)==0){
                    freq[w1]++;
                }
            }
        }
        //find the word with minimum freq[word]
        int Max = INT_MAX;
        string candid = wordlist[0];
        for(auto& f: freq){
            if(Max >= f.second){
                candid = f.first;
                Max = f.second;
            }
        }
        //compute the matchs 
        int x = master.guess(candid);
        //build a new word list based the guess result
        vector<string> newWordList;
        for(auto& w : wordlist){
            if(match(w,candid) == x){
                newWordList.push_back(w);
            }
        }

        swap(wordlist,newWordList);
        }
    }
    int match(string A, string B){
        int count = 0;
        int len = A.size();
        for(int i = 0; i < len; i++){
            if(A[i] == B[i]){
                count++;
            }
        }
        return count;
    }
};