class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int t =  0;
        int i = 0 ;
        int j = n-1 ; 
       while(j > i){
        

                int b = j - i;
                int h = min (height[i],height[j]);
                t = max(t,b*h);
                while (height[i] <= h && i < j) i++;
               while (height[j] <= h && i < j) j--;
                
       }
    

        return t;
        
    }
};