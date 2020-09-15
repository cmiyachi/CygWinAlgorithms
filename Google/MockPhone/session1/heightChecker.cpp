class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> s(heights);
        sort(s.begin(), s.end());
        int count = 0;
        for (int i = 0; i < heights.size(); ++i) {
            if (heights[i] != s[i])
                ++count;
        }
        return count;
    }
};

lass Solution {
    public:
    int heightChecker(vector<int>& heights) {
            if (heights.empty())
            {
                return 0;
            }
            
            vector<int> heights_copy(heights);
            int size = heights.size();
            for (int i=0; i<size; ++i)
            {
                for (int j=i+1; j>0; --j)
                {
                    if (heights_copy[j] >= heights_copy[j-1])
                    {
                        break;
                    }
                    else
                    {
                        swap(heights_copy[j-1], heights_copy[j]);
                    }
                }
            }

            int has_numbers_not_conformance = 0;
            for (int i=0; i<size; ++i)
            {
                if (heights[i] != heights_copy[i])
                {
                    ++has_numbers_not_conformance;
                }
            }

            return has_numbers_not_conformance;
        }
};