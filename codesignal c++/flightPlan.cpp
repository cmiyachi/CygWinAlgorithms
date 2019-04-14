/*Note: Try to solve this task in O(m log n) time, where n is a number of cities and m is a number of flights, since this is what you'll be asked to do during an interview.

Elle is trying to arrange a flight from source to dest. She doesn't mind taking multiple connecting flights, but wants to get to her destination dest as soon as possible. She has a timetable of flights, times, where:

times{i}{0} is the starting location of flight i,
times{i}{1} is the destination for flight i,
times{i}{2} is the time flight i departs,
times{i}{3} is the time flight i arrives.
The earliest Elle can leave is midnight (00:00). All times have been encoded as HH:MM. All times are referenced in the timezone of the source, where the hours HH are bigger than 23 if the time is on a subsequent day.

Given the timetable times, source, and dest, return the time when Elle will arrive at dest, if she wants to get here as soon as possible, or "-1" if it's impossible. For her flights:

Assume they all leave and arrive on time.
She needs 60 minutes between flights.
Example

For

times = {{"Chicago", "Denver","03:00", "06:00"},
         {"Chicago", "Denver","03:30", "07:00"},
         {"Chicago", "Los Angeles", "01:00", "05:00"},
         {"Denver", "Austin", "06:30", "08:30"},
         {"Denver", "Austin", "07:30", "09:30"},
         {"Austin", "Denver", "06:30", "08:30"},
         {"Los Angeles", "Phoenix", "06:00", "07:00"},
         {"Los Angeles", "Phoenix", "05:30", "06:50"},
         {"Phoenix", "Austin", "08:00", "08:40"}}
source = "Chicago", and dest = "Austin", the output should be
flightPlan(times, source, dest) = "08:40".

The earliest Elle can get from Chicago to Austin is 08:40, by leaving at 01:00 for a trip duration of 7 hours and 40 minutes: Chicago (leaving at 01:00) --> Los Angeles (arrive at 05:00, leave at 06:00) --> Phoenix (arrive at 07:00, leave at 08:00) --> Austin (arrive at 08:40).

Note that there is a quicker path: Chicago (leaving at 03:00) --> Denver (arrive at 06:00, leave at 07:30) --> Austin (arrive at 09:30), which is only 6 hours and 30 minutes. But this isn't the answer we're looking for because it arrives later.

Input/Output

{execution time limit} 0.5 seconds (cpp)

{input} array.array.string times

A timetable of flights, where:

times{i}{0} is the starting location of flight i,
times{i}{1} is the destination for flight i,
times{i}{2} is the time flight i departs,
times{i}{3} is the time flight i arrives.
All times have been encoded as HH:MM. All times are referenced in the timezone of the source, where the hours HH are bigger than 23 if the time is on a subsequent day.
Guaranteed constraints:
1 ≤ times.length ≤ 104,
1 ≤ times{i}{0}.length, times{i}{1}.length ≤ 15.

{input} string source

The city where Elle starts.

Guaranteed constraints:
1 ≤ source.length ≤ 15,
source ≠ dest.

{input} string dest

The city where Elle wants to travel to.

Guaranteed constraints:
1 ≤ dest.length ≤ 15,
source ≠ dest.

{output} string

Return the time, encoded as HH:MM, when Elle will arrive at dest, if she wants to get here as soon as possible, or "-1" if it's impossible. Hours HH can be b
igger than 23 if the time is on a subsequent day.*/

#include <vector>
#include <string>
#include <unordered_map>
#include<bits/stdc++.h> 
#include <queue>
#include <algorithm>


using namespace std;

// https://codefights.com/interview-practice/task/s7E6FdhGKCdaCMNoL

struct flight{
  int dest;
  int arrival;
  int departure;
  int travellingTime;
};

vector<vector<flight>> adj;
unordered_map<string,int> ump;
int ctr;
#define piii pair<int,pair<int,int>>

int findEarliest(string source,string dest){
  int src=ump[source];
  int des=ump[dest];
  priority_queue<piii,vector<piii>,greater<piii>> pq;
  vector<int> dis(ctr,INT_MAX);
  vector<int> vis(ctr,false);
  dis[src]=0;
  pq.push({0,{src,-60}});
  while(!pq.empty()){
    piii tp=pq.top();
    pq.pop();
    int miniDis=tp.first;
    int node=tp.second.first;
    int arrivedAtNode=tp.second.second;
    if(node==des)return miniDis;
    dis[node]=miniDis;
    vis[node]=true;
    int sz=adj[node].size();
    for(int i=0;i<sz;i++){
      int child=adj[node][i].dest;
      if(vis[child] or adj[node][i].departure<arrivedAtNode+60)continue;
      if(dis[child]>adj[node][i].arrival){
       dis[child]=adj[node][i].arrival; 
       pq.push({dis[child],{child,adj[node][i].arrival}}); 
      }
    }
  }
  return -1;
}

std::string flightPlan(std::vector<std::vector<std::string>> times, std::string source, std::string dest) {
  adj=vector<vector<flight>>(times.size()*2+5);
  ctr=1;
  ump[source]=ctr++;
  ump[dest]=ctr++;
  int sz=times.size();
  for(int i=0;i<times.size();i++){
    if(ump[times[i][0]]==0)ump[times[i][0]]=ctr++;
    if(ump[times[i][1]]==0)ump[times[i][1]]=ctr++;
    string timeDstr=times[i][2];
    string timeAstr=times[i][3];
    int timeD;
    int timeA;
      timeD=((timeDstr[0]-'0')*10+(timeDstr[1]-'0'))*60+((timeDstr[3]-'0')*10+(timeDstr[4]-'0'));
      timeA=((timeAstr[0]-'0')*10+(timeAstr[1]-'0'))*60+((timeAstr[3]-'0')*10+(timeAstr[4]-'0'));
    
    int src=ump[times[i][0]];
    int des=ump[times[i][1]];
    flight ff;
    ff.dest=des;
    ff.arrival=timeA;
    ff.departure=timeD;
    ff.travellingTime=timeD+(timeA-timeD);
    adj[src].push_back(ff);
  }

  int earliest = findEarliest(source,dest);
  if(earliest==-1) return "-1";

  int hrs=earliest/60;
  int min=earliest%60;
  string hrstr;
  if(hrs==0)hrstr="00";
  else if(hrs<10){
    hrstr="0";
    hrstr+=(char)((hrs%10)+'0');
  }
  else {
    while(hrs>0){
      hrstr+=(char)((hrs%10)+'0');
      hrs/=10;
    }  
    reverse(hrstr.begin(),hrstr.end());
  }

  string minstr;
  if(min==0)minstr="00";
  else if(min<10){
    minstr="0";
    minstr+=(char)((min%10)+'0');
  }
  else {
    while(min>0){
      minstr+=(char)((min%10)+'0');
      min/=10;
    }  
    reverse(minstr.begin(),minstr.end());
  }
  
  return hrstr+":"+minstr;
}
/*
std::string flightPlan(std::vector<std::vector<std::string>> times, std::string source, std::string dest) {

} */

int main(void)
{
	std::vector<std::vector<std::string>> times = {{"Chicago", "Denver","03:00", "06:00"},
         {"Chicago", "Denver","03:30", "07:00"},
         {"Chicago", "Los Angeles", "01:00", "05:00"},
         {"Denver", "Austin", "06:30", "08:30"},
         {"Denver", "Austin", "07:30", "09:30"},
         {"Austin", "Denver", "06:30", "08:30"},
         {"Los Angeles", "Phoenix", "06:00", "07:00"},
         {"Los Angeles", "Phoenix", "05:30", "06:50"},
         {"Phoenix", "Austin", "08:00", "08:40"}};
		 
	string source = "Chicago", dest = "Austin"; 
	
	cout << flightPlan(times, source, dest); 
	
	return 0;
}