#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;
// Complete the checkMagazine function below.
void checkMagazine(vector<string> magazine, vector<string> note) {
    unordered_map<string, int> map;
    unordered_map<string, int>::iterator it;
    int flag = 1;
    for (int i = 0; i < magazine.size(); i++){
        it = map.find(magazine[i]);
        if (it == map.end()){
            map.insert(pair<string, int>(magazine[i], 1));
        }
        else{
            map[magazine[i]]++;
        }
    }
    for (int i=0; i<note.size();i++){
        it = map.find(note[i]);
        if (it == map.end()){
            flag = 0;
        }
        else if (it->second == 0){
            flag = 0;
        }
        map[note[i]]--;
    }
    if (flag == 0? cout<<"No": cout<<"Yes");
    
}

int main() {
    vector<string> magazine = {"give", "me", "one", "grand", "total", "tonight"};
    vector<string> note = {"give", "one", "grand", "total"};
    vector<string> note1 = {"give", "one", "one", "grand", "total"};
    vector<string> note2 = {"give", "two", "grand", "total"};


    checkMagazine(magazine, note);
    checkMagazine(magazine, note1);
    checkMagazine(magazine, note2);

    return 0;
}