typedef vector<int> vi;

/*
 * Complete the function below.
 */
vector<int> getProductArray(vector<int> nums) {
    vi res(nums.size(), 1);

    // Write your code here.
    if (nums.empty()){
        return res;
    }
    
    vi left_prod(nums.size(), 1);
    vi right_prod(nums.size(), 1);
    
    // pass:1 compute left product (exclusive of curr-index)
    int curr_prod = nums[0];
    for(int i =1 ;i < nums.size(); i++){
        left_prod[i] = curr_prod;
        curr_prod *= nums[i];
    }

    // pass:2 compute right product (exclusive of curr-index)
     curr_prod = nums[nums.size()-1];
    for(int i = nums.size()-2; i >=0; i--){
        right_prod[i] =curr_prod;
        curr_prod *= nums[i];
    }

    for(int i =0; i < nums.size(); i++){
        res[i] = left_prod[i] * right_prod[i];
    }
    
    return res;

}


