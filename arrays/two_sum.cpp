typedef vector<int> vi;
typedef unordered_map<int, int>myMap;
typedef pair<int, int> myMap_pair;
#define pb push_back


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        myMap m1;
        vi res;
        
        for(int i =0; i < nums.size(); i++){
            int temp = target - nums[i];
            auto itr = m1.find(temp);
            if( itr != m1.end()){
                res.pb(itr->second);
                res.pb(i);
                return res;
            } else {
                m1.insert(myMap_pair(nums[i], i));
            }
            
        }
        
        return res;
    }
};
