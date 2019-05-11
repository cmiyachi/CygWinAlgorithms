#include <iostream>
#include <vector>

using namespace std; 

typedef std::vector<std::vector<int>> results_t;

void disp(results_t &r);

using std::cout;
using std::endl;

bool isValid(int row, int col, vector<int> temp){
    for(int r=0;r<row;r++){ // check if any preceeding row has a column value which makes this place invalid
        int c = temp[r];
        if(c==col) return false;
        int cd = abs(c-col);
        int rd = abs(r-row);
        if(cd==rd) return false;
    }
    return true;
}

void findPaths(int row, vector<vector<int>> &results, vector<int> &temp, int n){
    if(row == n){
        results.push_back(vector<int>(temp));           
    }else{
        for(int i=1;i<=temp.size();i++){
            if(isValid(row,i,temp)){
                temp[row] = i;
                findPaths(row+1,results,temp,n);            
            }
        }
    }
}


std::vector<std::vector<int>> nQueens(int n){
    vector<vector<int>> results;
    vector<int> temp(n,0); // temp index corresponds to row and j corresponds to column
    findPaths(0,results,temp,n);
    return results;
}


void disp(results_t &r) {
    cout << "Canditates in Board: " << r.size() << endl;
    for (int row=0;row<r.size();row++){
        cout << "B: ";
        for (int col=0;col<r[row].size();col++)
            cout  << r[row][col] << " ";
        cout << endl;
    }
    cout << endl;
    
}

void test_case(int n) {
    results_t r = nQueens(n);
    cout << "TEST CASE "<< n << ": " << endl;
    disp(r);
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    test_case(1);
    test_case(2);
    test_case(3);
    test_case(4);
    test_case(6);
    return 0;
}