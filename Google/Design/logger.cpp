#include <bits/stdc++.h> 
using namespace std;

/*
Instead of logging print times, I store when it's ok for a message to be printed again. Should be slightly faster, because I don't always have to add or subtract (e.g., timestamp < log[message] + 10) but only do in the true case. Also, it leads to a shorter/simpler longest line of code. Finally, C++ has 0 as default, so I can just use ok[message]. */


class Logger {
public:

    map<string, int> ok;

    bool shouldPrintMessage(int timestamp, string message) {
        if (timestamp < ok[message])
            return false;
        ok[message] = timestamp + 10;
        return true;
    }
};

int main(void)
{
	Logger *logger = new Logger();

	// logging string "foo" at timestamp 1
	cout << logger->shouldPrintMessage(1, "foo") << endl; //returns true; 

	// logging string "bar" at timestamp 2
	cout << logger->shouldPrintMessage(2,"bar") << endl; //returns true;

	// logging string "foo" at timestamp 3
	cout << logger->shouldPrintMessage(3,"foo") << endl; //returns false;

	// logging string "bar" at timestamp 8
	cout << logger->shouldPrintMessage(8,"bar") << endl; //returns false;

	// logging string "foo" at timestamp 10
	cout << logger->shouldPrintMessage(10,"foo") << endl; // returns false;

	// logging string "foo" at timestamp 11
	cout << logger->shouldPrintMessage(11,"foo") << endl; //returns true;
	
	
	return 0;
}