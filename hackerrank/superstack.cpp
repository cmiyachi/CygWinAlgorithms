#include <bits/stdc++.h> 
using namespace std; 

int main() 
{
	int no_cmds; 
	cin >> no_cmds;
	list<int> superStack; 
	
	for (int i = 0; i < no_cmds; i++)
	{
		string cmd;
		int  value;
		cin >> cmd;
		
		if (cmd == "push")
		{
			cin >> value; 
			superStack.emplace_front(value); 
		}
		else if (cmd == "pop")
		{
			superStack.pop_front(); 
		}
		else if (cmd == "inc")
		{
			cin >> value; 
			int inc;
			int this_count = 0;
			cin >> inc; 
			for (int j = 0; j < value; j++)
				for (std::list<int>::reverse_iterator rit=superStack.rbegin(); rit!=superStack.rend(); ++rit)
				{
					*rit = *rit+inc;
					this_count++;
					if (this_count >= value)  break; 
				}
		}

       if (superStack.empty()) cout << "EMPTY" << endl; 
	   else 
		   cout << superStack.front() << endl; 
	}
}
      