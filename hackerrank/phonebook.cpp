#include <bits/stdc++.h>
using namespace std;
vector<string>  splitInput(string str) ;


vector<string> splitInput(string str) 
{ 
    // Used to split string around spaces. 
    istringstream ss(str); 
	vector<string> result; 
  
    // Traverse through all words 
    do { 
        // Read a word 
        string word; 
        ss >> word; 
  
        // Print the read word 
	// 	cout << word << endl;
		result.push_back(word);
  
        // While there is more to read 
    } while (ss); 
	
	return result; 
} 

std::string& ltrim(std::string& str, const std::string& chars = "\t\n\v\f\r ")
{
    str.erase(0, str.find_first_not_of(chars));
    return str;
}

int main(void)
{
	int n;
	cin >> n;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	
	unordered_map<string, string> phoneBook; 
	
	for (int i = 0; i < n; i++)
	{
		string arr_temp_temp;
		getline(cin, arr_temp_temp);

		vector<string> arr_temp = splitInput(arr_temp_temp);
		phoneBook[arr_temp[0]] = arr_temp[1];
		// cout << arr_temp[0] << " " << phoneBook[arr_temp[0]] << endl; 
	}
	
	vector<string> queries; 
	int num_of_queries = 0; 
	string name; 
	
	while (getline(std::cin, name))
	{
		if (name.empty())
			break;
		queries.push_back(name);
		num_of_queries++;
	}
	
	/* for (int i = 0; i < n; i++)
	{
		string name;
		cin >> name;
		name = ltrim(name);
//cout << "*** " << name; 
		queries[i] = name; //.push_back(name);
	} */
	
	for (int i = 0; i < num_of_queries; i++)
	{
		string name = queries[i]; 
		//cout << "i " << i << " " << queries[i] << endl; 
		std::unordered_map<std::string,string>::const_iterator got = phoneBook.find (name);

		if ( got == phoneBook.end() )
			std::cout << "Not found";
		else
			std::cout << got->first << "=" << got->second;

		std::cout << std::endl;
	}

	return 0; 
}