/** function classifyStrings(s) {
    if (s.match(/[aeiou]{3}/)) return 'bad';
    if (s.match(/[^aeiou?]{5}/)) return 'bad';

    if (s.match(/\?/)) {
        let a = classifyStrings(s.replace(/\?/, 'a'));
        let b = classifyStrings(s.replace(/\?/, 'b'));

        if (a == b) return a;
        return 'mixed';
    }

    return 'good';
} **/
#include <bits/stdc++.h>
#include <string>
#include <iostream> 
#include <regex> 
  
using namespace std; 

string classifyStrings(string s)
{
	//cout << s << endl; 
	regex b("[aeiou]{3}");
	regex c(".*[bcdfghjklmnpqrstvwxyz]{5}.*"); 
	regex d("\\?");
	
	if (regex_match(s,b)) {
		// cout << "vowel match" << endl;
		return "bad";
	}
	if (regex_match(s,c))
	{
	// 	cout << "const match " << endl; 
		return "bad";
	}
	
	if (s.find("?") != std::string::npos)
	{
		string vowel = s; 
		string consanant = s; 
		replace(vowel.begin(),vowel.end(),'?','a');
		replace(consanant.begin(),consanant.end(),'?', 'b');
		string e = classifyStrings(vowel);
		string f = classifyStrings(consanant);
		
		if (e == f) return e;
		return "mixed";
	}
		
	
	/* if(regex_match(s,d)) 
	{
		string vowel = regex_replace(s,d,"a"); 
		string consanant = regex_replace(s,d,"v");
		cout << vowel << " " << consanant << endl;
		string e = classifyStrings(vowel);
		string f = classifyStrings(consanant);
		
		if (e == f) return e;
		return "mixed"; 
		
	}  */
	
	return "good"; 
	
}
int main() 
{ 
	string a = "aeu"; 
	
	// regex z("[aeiou]{3}"); 
	
	//if (regex_match(a,z)) cout << "testing worked\n"; 
// regex b("[aeiou]{3}");
	
	// if (regex_match(a,b)) cout << "works here" << endl;
  
 cout << classifyStrings(a) << endl;
	
	a ="bcdfgf"; 
	   cout << classifyStrings(a) << endl;
	
	a = "a?u"; 
	
   cout << classifyStrings(a) << endl;
	
	a = "aba"; 
	
   cout << classifyStrings(a) << endl;
  
    return 0; 
} 