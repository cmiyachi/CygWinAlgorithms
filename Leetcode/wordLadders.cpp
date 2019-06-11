/*
 * Time Limit Exceeded
*/
#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<iostream>
#include<string>
#include<vector>

using namespace std;




class SolutionSlow {
public:
    vector<vector<string> > findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string> > result;
        vector<string> transforms;
        transforms.push_back(beginWord);
        findLadders(result, transforms, beginWord, endWord, wordList);
        return result;
    }
    
    void findLadders(vector<vector<string> >& result, vector<string>& transforms, string beginWord, string endWord, vector<string>& wordList){
        if(beginWord==endWord){
            while(!result.empty()){
                if(result.back().size()>transforms.size())
                    result.pop_back();
                else break;
            }
            if(result.empty()||((!result.empty())&&result.back().size()==transforms.size())) result.push_back(transforms);
            return;
        }
        for(int i=0;i<wordList.size();i++){
            if(isTransformed(beginWord, wordList[i])){
                bool hadAdd=false;
                for(int j=0;j<transforms.size();j++){
                    if(wordList[i]==transforms[j]){
                        hadAdd=true;
                        break;
                    }
                }
                if(!hadAdd){
                    transforms.push_back(wordList[i]);
                    findLadders(result, transforms, wordList[i], endWord, wordList);
                    transforms.pop_back();
                }
            }
        }
    }
    
    bool isTransformed(string w1, string w2){
        int count=0;
        for(int i=0;i<w1.length();i++){
            if(w1[i]!=w2[i]) count++;
            if(count>1) return false;
        }
        if(count==1) return true;
        else return false;
    }
};

class Solution {
public:
    void generatePath(vector<vector<string> >& result_path, vector<string>& temp_path, unordered_map<string, unordered_set<string> >& path, string start, string end){
        temp_path.insert(temp_path.begin(), start);
        if(start==end){
            result_path.push_back(temp_path);
            return;
        }
        
        for(auto it=path[start].begin();it!=path[start].end();it++){
            generatePath(result_path, temp_path, path, *it, end);
            temp_path.erase(temp_path.begin());
        }
        
    }
    
    vector<vector<string> > findLadders(string beginWord, string endWord, vector<string>& wordList){
        
        unordered_set<string> current_step;
        unordered_set<string> next_step;
        
        unordered_map<string, unordered_set<string> > path;
        
        unordered_set<string> unvisited;
        
        for(int i=0;i<wordList.size();i++) unvisited.insert(wordList[i]);
        
        
        if(unvisited.count(beginWord)>0)
            unvisited.erase(beginWord);
        current_step.insert(beginWord);
        
        while(current_step.count(endWord)==0&&unvisited.size()>0) {
            for(auto pcur=current_step.begin();pcur!=current_step.end();++pcur){
                string word=*pcur;
                for(int i=0;i<word.length();i++){
                    for(int j=0;j<26;j++){
                        string temp=word;
                        if(temp[i]=='a'+j) continue;
                        temp[i]='a'+j;
                        if(unvisited.count(temp)>0){
                            next_step.insert(temp);
                            path[temp].insert(word);
                        }
                    }
                }
            }
            
            if(next_step.empty()) break;
            for(auto it=next_step.begin();it!=next_step.end();++it){
                unvisited.erase(*it);
            }
            
            current_step=next_step;
            next_step.clear();
        }
        
        vector<string> temp_path;
        vector<vector<string> > result_path;
        
        if(current_step.count(endWord)>0){
            generatePath(result_path, temp_path, path, endWord, beginWord);
        }
        
        return result_path;
    }
    
};


int main(){
    string beginWord;
    cin>>beginWord;
    string endWord;
    cin>>endWord;
    
    int n;
    cin>>n;
    vector<string> wordList;
    for(int i=0;i<n;i++){
        string word;
        cin>>word;
        wordList.push_back(word);
    }
    
    Solution *solution=new Solution();
    vector<vector<string> > result = solution->findLadders(beginWord, endWord, wordList);
    
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}