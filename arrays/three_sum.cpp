typedef vector<int> vi;
typedef vector< vi > vii;
typedef set<vi> mySet;
#define pb push_back

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vii res;
        mySet s1;
        
        if(nums.empty())
            return res;
        
        sort(nums.begin(), nums.end());
        
        for(int i=0; i < nums.size()-1; i++){
            int curr = nums[i];
            int st = i+1;
            int endd = nums.size()-1;
            while(st < endd){
                long sum = nums[st] + nums[endd];
                long temp = sum +curr;
                if(temp == 0){
                    vi t1;
                    t1.pb(curr);
                    t1.pb(nums[st]);
                    t1.pb(nums[endd]);
                    s1.insert(t1);
                    //res.pb(t1);
                    st++;
                } else if(temp > 0){
                    endd--;
                } else {
                    st++;
                }     
            }
        }
        
        for(auto vec :s1){
            res.pb(vec);
        }
        
        return res;
    }
};
