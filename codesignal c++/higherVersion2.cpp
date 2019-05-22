#include <bits/stdc++.h>

using namespace std;

int higherVersion2(std::string ver1, std::string ver2) {
	
	// split the string into major, minor, and revision number
	std::stringstream ver1stream(ver1);
	std::string ver1_segment;
	std::vector<int> seg1list;
	std::stringstream ver2stream(ver2);
	std::string ver2_segment;
	std::vector<int> seg2list;
	
	// convert version string into array of numbers
	while(std::getline(ver1stream, ver1_segment, '.'))
	{
		stringstream segstream(ver1_segment);
		int num = 0;
		segstream >> num; 
		seg1list.push_back(num);
		// cout << num << endl; 
	}
	while(std::getline(ver2stream, ver2_segment, '.'))
	{
		stringstream segstream(ver2_segment);
		int num = 0;
		segstream >> num; 
		seg2list.push_back(num);
		// cout << num << endl; 
	}
	
	// determine if ver 1 is less than, equal or greater than ver2
	for (int i = 0; i < seg1list.size(); i++) // assumes the size is always 3
	{
		if (seg1list[i] >  seg2list[i])
			return 1;
		else if (seg1list[i] < seg2list[i])
			return -1;
	}
		
    // if we finished the loop, they are equal
	return 0;

}

int main(void)
{
	string ver1 = "1.1.1", ver2 = "1.1.1";
	
	cout << higherVersion2(ver1, ver2);
	return 0;
}