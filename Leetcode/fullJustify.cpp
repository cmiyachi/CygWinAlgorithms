#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

vector<string> fullJustify(vector<string>& words, int maxWidth)
{
    vector<string> justifiedText;

    for (unsigned i = 0, j, lineWordsLength = 0; i < words.size(); i = j, lineWordsLength = 0)
    {
        for (j = i; j < words.size() && lineWordsLength + words[j].size() + (j - i) <= maxWidth; lineWordsLength += words[j++].size());

        string line = words[i];
        for (unsigned k = i + 1; k < j; ++k)
        {
            int paddingSize = 1;
            if (j < words.size())
            {
                paddingSize = (maxWidth - lineWordsLength) / (j - k) + ((maxWidth - lineWordsLength) % (j - k) != 0 ? 1 : 0);
                lineWordsLength += paddingSize;
            }

            line.append(paddingSize, ' ').append(words[k]);
        }

        line.append(maxWidth - line.size(), ' ');
        justifiedText.push_back(line);
    }

    return justifiedText;
}
    vector<string> fullJustify2(vector<string>& words, int maxWidth) {
         int left = 0; 
		 vector<string> result;
        
        while (left < words.size()) {
            int right = findRight(left, words, maxWidth);
            result.push_back(justify(left, right, words, maxWidth));
            left = right + 1;
        }
        
        return result;
    }
private:	
 int findRight(int left, vector<string> words, int maxWidth) {
        int right = left;
        int sum = words[right++].length();
        
        while (right < words.size() && (sum + 1 + words[right].length()) <= maxWidth)
            sum += 1 + words[right++].length();
            
        return right - 1;
    }
    string justify(int left, int right, vector<string> words, int maxWidth) {
        if (right - left == 0) return padResult(words[left], maxWidth);
        
        bool isLastLine = right == words.size() - 1;
        int numSpaces = right - left;
        int totalSpace = maxWidth - wordsLength(left, right, words);
        
        string space = isLastLine ? " " : blank(totalSpace / numSpaces);
        int remainder = isLastLine ? 0 : totalSpace % numSpaces;
		
		string result; 
        
       
        for (int i = left; i <= right; i++)
		{
            result += words[i];
			result += space; 
			result += (remainder == 0 ? " " : "");
			//result = std::regex_replace(result, std::regex(" +$"), "");
		}
        
        return padResult(result, maxWidth);
    }
	int wordsLength(int left, int right, vector<string> words) {
        int wordsLength = 0;
        for (int i = left; i <= right; i++) wordsLength += words[i].length();
        return wordsLength;
    }
    
    string padResult(string result, int maxWidth) {
        return result + blank(maxWidth - result.length());
    }
    
   string blank(int length) {
	   string result;
	   for (int i =0 ; i < length; i++)
		   result += " "; 
        return result; 
    }
	std::string& ltrim(std::string& str, const std::string& chars = "\t\n\v\f\r ")
	{
		str.erase(0, str.find_first_not_of(chars));
		return str;
	}
	 
	std::string& rtrim(std::string& str, const std::string& chars = "\t\n\v\f\r ")
	{
		str.erase(str.find_last_not_of(chars) + 1);
		return str;
	}
	 
	std::string& trim(std::string& str, const std::string& chars = "\t\n\v\f\r ")
	{
		return ltrim(rtrim(str, chars), chars);
	}
};
/*
We start with left being the first word.

findRight: Then we greedily try to go as far right as possible until we fill our current line.

Then we justify one line at a time.

justify: In all cases we pad the right side with spaces until we reach max width for the line;

If it's one word then it is easy, the result is just that word.
If it's the last line then the result is all words separated by a single space.
Otherwise we calculate the size of each space evenly and if there is a remainder we distribute an extra space until it is gone.

*/
int main(void)
{

	vector<string> words{"This", "is", "an", "example", "of", "text", "justification."}; 
	int maxWidth = 16;
	
	Solution sol;
	vector<string> result = sol.fullJustify(words, maxWidth);
	
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << endl;
	
	return 0;
}
    
    