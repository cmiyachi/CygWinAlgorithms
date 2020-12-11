#include <bits/stdc++.h>
using namespace std;

class Visit
{ 
public: 
	string site;
	int user;
	
	Visit(string site, int user)
	{
		this->site = site;
		this->user = user;
	}
};
set<int> intersection(set<int> s1, set<int> s2) 
{ 
    set<int> intersect; 
  
    // Find the intersection of the two sets 
    set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), 
                     inserter(intersect, intersect.begin())); 
  
    return intersect; 
} 
double jaccard_index(set<int> s1, set<int> s2) 
{ 
    // Sizes of both the sets 
    double size_s1 = s1.size(); 
    double size_s2 = s2.size(); 
  
    // Get the intersection set 
    set<int> intersect = intersection(s1, s2); 
  
    // Size of the intersection set 
    double size_in = intersect.size(); 
  
    // Calculate the Jaccard index 
    // using the formula 
    double jaccard_in = size_in 
                        / (size_s1 + size_s2 - size_in); 
  
    // Return the Jaccard index 
    return jaccard_in; 
} 

double compute_similarity( string a, string b, unordered_map<string, set<int>> visitors)
{
	set<int> set1, set2;
	set1 = visitors[a];
	set2 = visitors[b]; 
	
	return jaccard_index(set1, set2);
}
class CompareStuff
{
	public:
	double jacard_index;
	vector<string> sites; // limit to 2
};

bool Compare(CompareStuff *a, CompareStuff* b)
{
    return a->jacard_index < b->jacard_index; 
}

  vector<vector<string>> top_pairs(vector<Visit *> log, int k)
  {
	  unordered_map<string, set<int>> sites_to_users;
	  vector<string> sites_only;
	  
	for (Visit * item : log)
	{
		sites_to_users[item->site].insert(item->user); 
		sites_only.push_back(item->site); 
	}
	
	set<string> sss( sites_only.begin(), sites_only.end() );
	sites_only.assign( sss.begin(), sss.end() );
	
	priority_queue<CompareStuff*, std::vector<CompareStuff*>, std::function<bool(CompareStuff*, CompareStuff*)>> pq(Compare);
	
	for (int i = 0; i < sites_only.size(); i++)
		for (int j = i+1; j < sites_only.size(); j++)
		{
			double score = compute_similarity(sites_only[i], sites_only[j], sites_to_users);
			CompareStuff *compare_stuff = new CompareStuff();
			compare_stuff->jacard_index = score;
			compare_stuff->sites = {sites_only[i], sites_only[j]};
			pq.push(compare_stuff); 
		}
		
	vector<vector<string>> results;
	
	while (!pq.empty() && k != 0)
	{
		CompareStuff *cs = pq.top();
		pq.pop();
		results.push_back(cs->sites);
		k--; 
	}
	
	return results;
  } 
	
	int main(void)
	{
		vector<Visit *> log;
		Visit *visit = new Visit("google.com",1);
		log.push_back(visit);
		
		Visit *visit2 = new Visit("google.com",3);
		log.push_back(visit2);
		
		Visit *visit3 = new Visit("google.com",5);
		log.push_back(visit3);
		
		Visit *visit4 = new Visit("pets.com",1);
		log.push_back(visit4);
		
		Visit *visit5 = new Visit("pets.com",2);
		log.push_back(visit5);
		
		Visit *visit6 = new Visit("yahoo.com",6);
		log.push_back(visit6);
		
		Visit *visit7 = new Visit("yahoo.com",2);
		log.push_back(visit7);
		
		Visit *visit8 = new Visit("yahoo.com",3);
		log.push_back(visit8);
		
		Visit *visit9 = new Visit("yahoo.com",4);
		log.push_back(visit9);
		
		Visit *visit10 = new Visit("yahoo.com",5);
		log.push_back(visit10);
		
		Visit *visit11 = new Visit("wikipedia.com",4);
		log.push_back(visit11);
		
		Visit *visit12 = new Visit("wikipedia.com",5);
		log.push_back(visit12);
		
		Visit *visit13 = new Visit("wikipedia.com",6);
		log.push_back(visit13);
		
		Visit *visit14 = new Visit("wikipedia.com",7);
		log.push_back(visit14);
		
		Visit *visit15 = new Visit("bing.com",1);
		log.push_back(visit15);
		
		Visit *visit16 = new Visit("bing.com",3);
		log.push_back(visit16);
		
		Visit *visit17 = new Visit("bing.com",5);
		log.push_back(visit17);
		
		Visit *visit18 = new Visit("bing.com",6);
		log.push_back(visit18);
		
		vector<vector<string>> results = top_pairs(log, 1);
		
		for (vector<string> r : results)
		{
			for (string s : r)
			{
				cout << s << " ";
			}
			cout << endl;
		}
		
		return 0;
	}