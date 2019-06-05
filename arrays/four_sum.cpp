typedef vector<int> vi;
typedef vector< vi > vii;
typedef set<vi> mySet;
#define pb push_back

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vii res;
        mySet s1;
        
        if(nums.empty() || nums.size() <=3)
            return res;
        
        sort(nums.begin(), nums.end());
        for(int k =0; k < nums.size()-2; k++){
            
            int curr0 = nums[k];
        
         for(int i= k+1; i < nums.size()-1; i++){
            int curr = nums[i];
            int st = i+1;
            int endd = nums.size()-1;
            while(st < endd){
                long sum = nums[st] + nums[endd];
                long temp = sum +curr + curr0;
                //long temp = target + temp1;
                if(temp == target){
                    vi t1;
                    t1.pb(curr0);
                    t1.pb(curr);
                    t1.pb(nums[st]);
                    t1.pb(nums[endd]);
                    s1.insert(t1);
                    //res.pb(t1);
                    st++;
                } else if(temp > target){
                    endd--;
                } else {
                    st++;
                }     
            }
            }
        
        }
        for(auto vec :s1){
            res.pb(vec);
        }
        
        return res;
        
    }
};
