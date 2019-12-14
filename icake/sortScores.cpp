#include <bits/stdc++.h>
using namespace std; 

 vector<int> sortScores(const vector<int>& unorderedScores, int highestPossibleScore)
{
    // vector of 0s at indices 0..highestPossibleScore
    vector<size_t> scoreCounts(highestPossibleScore + 1);

    // populate scoreCounts
    for (int score : unorderedScores) {
        ++scoreCounts[score];
		cout << scoreCounts[score] << " " << score << endl;; 
    }
	cout << endl; 
    // populate the final sorted array
    vector<int> sortedScores(unorderedScores.size());
    size_t currentSortedIndex = 0;

    // for each item in scoreCounts
    for (int score = highestPossibleScore; score >= 0; --score) {
        size_t count = scoreCounts[score];
		cout << count << endl; 
		cout << "xxxx " << scoreCounts[score] << endl; 
        // for the number of times the item occurs
        for (size_t occurrence = 0; occurrence < count; ++occurrence) {
            // add it to the sorted array
			cout << currentSortedIndex << "index " << score ;
            sortedScores[currentSortedIndex] = score;
            ++currentSortedIndex;
        }
    }

    return sortedScores;
}

int main(void)
{
	const vector<int> unsortedScores {37, 89, 41, 65, 91, 53};
	const int HIGHEST_POSSIBLE_SCORE = 100;

	vector<int> sortedScores = sortScores(unsortedScores, HIGHEST_POSSIBLE_SCORE);
	// sortedScores: [91, 89, 65, 53, 41, 37]
	
	for (int i = 0; i < sortedScores.size(); i++)
	{
		cout << sortedScores[i] <<" , "; 
	}
	
	return 0;
}