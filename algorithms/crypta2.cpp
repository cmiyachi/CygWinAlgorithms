// CPP program for solving cryptographic puzzles 
#include <map>
#include <iostream>
#include <vector>
using namespace std; 

// vector stores 1 corresponding to index 
// number which is already assigned 
// to any char, otherwise stores 0 
vector<int> use; 

int final_count = 0; 

// structure to store char and its corresponding integer 
// map<char,int> node; 
// structure to store char and its corresponding integer 
struct node 
{ 
    char c; 
    int v; 
}; 
  
 

// function check for correct solution 
int check(node* nodeArr, const int count, string s1, 
							string s2, string s3) 
{ 
	int val1 = 0, val2 = 0, val3 = 0, m = 1, j, i; 

	// calculate number corresponding to first string 
	for (i = s1.length() - 1; i >= 0; i--) 
	{ 
		char ch = s1[i]; 
		for (j = 0; j < count; j++) 
			if (nodeArr[j].c == ch) 
				break; 

		val1 += m * nodeArr[j].v; 
		m *= 10; 
	} 
	m = 1; 

	// calculate number corresponding to second string 
	for (i = s2.length() - 1; i >= 0; i--) 
	{ 
		char ch = s2[i]; 
		for (j = 0; j < count; j++) 
			if (nodeArr[j].c == ch) 
				break; 

		val2 += m * nodeArr[j].v; 
		m *= 10; 
	} 
	m = 1; 

	// calculate number corresponding to third string 
	for (i = s3.length() - 1; i >= 0; i--) 
	{ 
		char ch = s3[i]; 
		for (j = 0; j < count; j++) 
			if (nodeArr[j].c == ch) 
				break; 

		val3 += m * nodeArr[j].v; 
		m *= 10; 
	} 

	// sum of first two number equal to third return true 
	if (val3 == (val1 + val2)) 
		return 1; 

	// else return false 
	return 0; 
} 

// Recursive function to check solution for all permutations 
bool permutation(const int count, node* nodeArr, int n, 
				string s1, string s2, string s3) 
{ 
	// Base case 
	if (n == count - 1) 
	{ 

		// check for all numbers not used yet 
		for (int i = 0; i < 10; i++) 
		{ 

			// if not used 
			if (use[i] == 0) 
			{ 

				// assign char at index n integer i 
				nodeArr[n].v = i; 

				// if solution found 
				if (check(nodeArr, count, s1, s2, s3) == 1) 
				{ 
					cout << "\nSolution found: ****************"; 
					for (int j = 0; j < count; j++) 
						cout << " " << nodeArr[j].c << " = "
							<< nodeArr[j].v; 
					return true; 
				} 
			} 
		} 
		return false; 
	} 

	for (int i = 0; i < 10; i++) 
	{ 

		// if ith integer not used yet 
		if (use[i] == 0) 
		{ 

			// assign char at index n integer i 
			nodeArr[n].v = i; 

			// mark it as not available for other char 
			use[i] = 1; 

			// call recursive function 
			if (permutation(count, nodeArr, n + 1, s1, s2, s3)) 
				return true; 

			// backtrack for all other possible solutions 
			use[i] = 0; 
		} 
	} 
	return false; 
} 

bool solveCryptographic(string s1, string s2, 
								string s3, node* nodeArr)
{ 
	// count to store number of unique char 
	int count = 0; 

	// Length of all three strings 
	int l1 = s1.length(); 
	int l2 = s2.length(); 
	int l3 = s3.length(); 

	// vector to store frequency of each char 
	vector<int> freq(26); 

	for (int i = 0; i < l1; i++) 
		++freq[s1[i] - 'A']; 

	for (int i = 0; i < l2; i++) 
		++freq[s2[i] - 'A']; 

	for (int i = 0; i < l3; i++) 
		++freq[s3[i] - 'A']; 

	// count number of unique char 
	for (int i = 0; i < 26; i++) 
	{
		// cout << "i " << freq[i] << " ";
		if (freq[i] > 0) 
			count++; 
	}
	// cout << endl << "count " << count;
	
	final_count = count; 
	
	// solution not possible for count greater than 10 
	if (count > 10) 
	{ 
	//	cout << "Invalid strings"; 
		return 0; 
	} 

	// array of nodes 
	// node nodeArr[count]; 

	// store all unique char in nodeArr 
	for (int i = 0, j = 0; i < 26; i++) 
	{ 
		if (freq[i] > 0) 
		{ 
			nodeArr[j].c = char(i + 'A'); 
			j++; 
		} 
	} 
	return permutation((count), nodeArr, 0, s1, s2, s3); 
} 

bool isCryptSolution(std::vector<std::string> crypt, std::vector<std::vector<char>> solution) {

		string s1 = crypt[0];
		string s2 = crypt[1];
		string s3 = crypt[2];
		int count = 0; 
		
		use.reserve(10);
		
		node nodeArr[10]; 
		bool result = solveCryptographic(s1, s2, s3, nodeArr);
		char digits[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
		
		// cout << "count " << nodeArr.size() << endl;
		
		vector<char> temp; 
		solution.resize(10, vector<char>(10));
		
		for (int i = 0; i < final_count; i++)
		{
			// temp.push_back(nodeArr[i].c);
			// temp.push_back(digits[nodeArr[i].v]); 
			solution[i][0] = nodeArr[i].c;
			solution[i][1] = digits[nodeArr[i].v];
		}
		
		return result;
}

// Driver function 
int main() 
{ 
	string s1 = "ONE"; 
	string s2 = "ONE"; 
	string s3 = "TWO"; 
	
	// node nodeArr[10]; 
	std::vector<std::string> crypt;
	
	crypt.push_back(s1);
	crypt.push_back(s2);
	crypt.push_back(s3);
	std::vector<std::vector<char>> solution; // {{'','','','','','','','','',''},
											// {'','','','','','','','','',''},
										// 	{'','','','','','','','','',''}};
	// solution.resize(10, vector<char>(10));
	
	
	
	
	cout << isCryptSolution(crypt, solution); 

	//if (solveCryptographic(s1, s2, s3, nodeArr) == false) 
	//	cout << "No solution"; 
	return 0; 
} 
