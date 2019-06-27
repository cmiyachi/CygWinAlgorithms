#include <bits/stdc++.h>

using namespace std;

class Codec2 {
	public:
	
    map<int, string> hash_map;
    int i = 0;

	string encode(string longUrl) {
        hash_map[i] = longUrl;
        string url = "http://tinyurl.com/" + to_string(i);
		i++;
		return url; 
    }

    string decode(string shortUrl) {
		char cnum = shortUrl.back(); 
		int inum = atoi(&cnum);	
        return hash_map[inum];
    }
};


class Codec {
	public: 
    map<int, string> hash_map;
    int key; 

	Codec() { srand (time(NULL)); key = rand(); }
	
    string encode(string longUrl) {
        while (hash_map.find(key) != hash_map.end() ) {
            key = rand(); 
        }
        hash_map[key] = longUrl;
        return "http://tinyurl.com/" + to_string(key);
    }

    string decode(string shortUrl) {
        // extract key
		string front = "http://tinyurl.com/"; 
		int front_len = front.length(); 
		string skey = shortUrl.substr(front_len); 
		const char * ckey = skey.c_str();
		//cout << skey << endl; 
		int inum = atoi(ckey); 
		//cout << inum << endl; 
		//cout << hash_map[inum] << endl; 
        return hash_map[inum];
    } 
};


class Solution {
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));

int main(void)
{
	Codec codec;
	
	string new_url = codec.encode("http://wwww.christinemiyachi.com");
	cout << new_url << endl;
	
	cout << codec.decode(new_url) << endl; 
	
	
	
	return 0;
}