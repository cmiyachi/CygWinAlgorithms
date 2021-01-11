class Solution {
public:
    int trap(vector<int>& height) {
        int idx = 0, n = height.size(), i, curr, area = 0;
        if(n==0)
            return 0;
        
        for(int i=0;i<n;i++)
            if(height[idx] < height[i])
                idx = i;
   
        curr=height[0];
        
        for(i=1;i<=idx;i++)
            if(height[i] >= curr) 
                curr = height[i];
             else 
                area += (curr-height[i]);
        
        curr = height[n-1];
        
        for(i=n-1;i>=idx;i--) 
            if(height[i] >= curr) 
                curr = height[i];
             else 
                area += (curr-height[i]);
            
        return area;
    }
};