#include <bits/stdc++.h>

using namespace std;


// Complete the getMinimumCost function below.
int getMinimumCost( int k, std::vector< int > &c ) {
    auto total{ 0 };
    auto diff{ c.size() - k };

    std::sort( c.begin(), c.end() );

    for( auto x{ diff }; x < c.size(); ++x ) {
        total += c[ x ];
    }

    for( int x{ static_cast< int >( diff ) - 1 }, cnt{ k }; x >= 0; --x, ++cnt ) {
        total += c[ x ] * ( 1 + ( cnt / k ) );
    }

    return( total );
}

int main(void)
{
	int n = 5,  k =  3;
	
	vector<int> c{1, 3, 5, 7, 9};
	
	cout << getMinimumCost(k, c);
	
	return 0;
}
