 vi extract_neighbors(vi & arr, int index, int k , int x){
        vi res;
          int low = max(0, index -k -1);
            int len = arr.size()-1;
         int high = min( len, index+k-1);
         
         while( high-low > k -1){
             if(low < 0 || (x - arr[low] <= (arr[high] -x)))
                 --high;
             else if (high > arr.size()-1 || (x- arr[low]> (arr[high] - x)) )
                 ++low;
             else 
                 cout<<"\n we should not be here";
             
         }
         //cout<<"\n low: "<<low<<"\t high: "<<high;
         for(int i = low; i <=high; i++ ){
             res.pb(arr[i]);
         }
         
         return res;
         
     }
    
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        int res = -1;
        int low = 0;
        int high = arr.size()-1;
       
	// special case: if search-key > arr[high] => result index is high 
	// othere extreme case: search-key < arr[low] : is taken care by your modified-binary search (
        if(x > arr[high]){
            res = high;
        } else {
        
		while (low <= high) {
			int mid = (low + high);
			if(arr[mid] == x){
				res = mid;
				break;
			}else if (arr[mid] < x){
				low = mid+1;
			} else {
		// requirement is to return the index of the ceiling if key is NOT found 
                // so just cache it here
                // Q) what happens if search-key > arr[high] ?
                // soln: special case this situation 
			res = mid;
		        high = mid -1;
			}	
		}
        }
        
       //cout<<"\n res was: "<<res;
        return extract_neighbors(arr,  res,  k , x);
