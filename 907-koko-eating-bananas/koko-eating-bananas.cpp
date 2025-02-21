class Solution {
public:
    long long ceiling(vector<int>& piles, int x){
        long long ans=0;
        for(int i=0;i<piles.size();i++){
            ans+=(piles[i]+x-1)/x;
        }
        return ans;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int end=*max_element(piles.begin(),piles.end());
        int ans=end;
        int low=1;
        while(low<=end){
           int mid=low+(end-low)/2;
           long long time=ceiling(piles,mid);
           if(time<=h){
            ans=mid;
            end=mid-1;
           }
           else{
            low=mid+1;
           }
        }
        return ans;
    }
};