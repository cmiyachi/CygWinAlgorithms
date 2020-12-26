#include <bits/stdc++.h>
using namespace std;
class TimeMap {
   public:
   /** Initialize your data structure here. */
   unordered_map <string, vector < pair <int, string> > > m;
   TimeMap() {
      m.clear();
   }
   void set(string key, string value, int timestamp) {
      m[key].push_back({timestamp, value});
   }
   string get(string key, int timestamp) {
      string ret = "";
      vector <pair <int, string> >& v = m[key];
      int low = 0;
      int high = v.size() - 1;
      while(low <= high){
         int mid = low + (high - low) / 2;
         if(v[mid].first <= timestamp){
            ret = v[mid].second;
            low = mid + 1;
         }else{
            high = mid - 1;
         }
      }
      return ret;
   }
   
   void print_map()
   {
	   			cout << "********" << endl; 

	   for (auto const& [key, val] : m)
		{
			std::cout << key        // string (key)
					  << ':'  ;
			for (auto p : val)
			{
				cout << p.first << ",";
				cout << p.second << endl;
			}
			cout << "****" << endl; 
		}
   }
};
main(){
   TimeMap ob;
   (ob.set("foo","bar",1));
   cout << (ob.get("foo", 1)) << endl;
   cout << (ob.get("foo", 3)) << endl;
   (ob.set("foo","bar2",4));
   cout << (ob.get("foo", 4)) << endl;
   cout << (ob.get("foo", 5)) << endl;
   ob.print_map();
}