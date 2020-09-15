/** Many similar solutions with stack have been posted, and here I added mine with the basic idea and comments in code. As usual, I did not pursuit to solve the problem with fewest lines of code possible but make it as readable as possible.

To solve the problem, there are following observations which I think are the keys:

Obviously, all entries (directories and files) in the file system can be identified by splitting the input string with delimiter '\n', i.e., each line is the name of a new entry.
The level of each entry can be identified by how many consecutive \t are leading the entry's name, assuming root directors and files have level 0.
Once an entry's level is smaller than previous entry's level, it means that any entries above the current entry with greater or equal value of levels have finished their content representation, i.e., any following entries will not be possible to belong to those entries above (so their path information won't be needed for following entries).
For any valid input string, the level increment has to be consecutive while decrement could be arbitrary.
With these observations, a stack to keep the record of the path lengths of all nested parent directories leading to current entry will naturally come to play. Note that the size of the stack is exactly the level of the current entry.

The time complexity estimate is also interesting. Even though there is the outer loop for the input string O(N), we have to break down into the time each time we enter the loop. Actually, each time we process an entry, the time cost is just O(L), where L is the length of this particular entry. So overall time complexity will be just O(N). O(N^2) is the wrong "too conservative" estimate if just naively looking at the loop. */

    int lengthLongestPath(string input) {
      stringstream ss(input);
      stack<int> parentLen; // path length of parent folders to current entry
      int lev, maxL = 0;    // level, length of longest file path
      for (string s; getline(ss, s, '\n');) 
      {
        int curLen = s.length()-(lev = s.rfind('\t')+1); // length and level of current entry
        while (parentLen.size() > lev) parentLen.pop(); // find length of parent directory
        if (!parentLen.empty()) curLen += 1+parentLen.top(); // attach parent path, 1 for '\'
        if (s.rfind('.') < s.size()) maxL = max(maxL, curLen); // update path length if file
        else parentLen.push(curLen); // record current entry path length if directory
      }
      return maxL;
    }
// With the advantage of the random accessibility of unordered_map by key, here is a more compact 4-line solution:

    int lengthLongestPath(string input) {
      int lev, maxL = 0; stringstream ss(input); unordered_map<int,int> L;    
      for(string s; getline(ss,s,'\n'); maxL = max(maxL,(s.find('.')<s.size())*L[lev+1]-1))
        L[(lev = s.rfind('\t')+1)+1] = L[lev]+s.size()-lev+1;
      return maxL;      
    }
	
	input.push_back('\n');
        vector<int> levels(300, 0);
        int level = 0;
        bool isFile = false;
        int ans = 0;
        int length = 0;
            
        for(char c: input){
            switch(c){
                case '\n': { level = 0; length = 0; isFile=false; break; }
                case '\t': { level++; break; }
                case '.' : isFile = true;
                    
                default:
                    length++;
                    levels[level] = length;
                    if(isFile){
                        ans = max(ans, accumulate(levels.begin(), levels.begin() + level + 1, 0) + level);
                    }
            }
        }
        
        return ans;