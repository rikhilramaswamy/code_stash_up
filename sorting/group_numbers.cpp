typedef vector<int> vi;
#define cont_tr(container, it )\
    for(decltype(container.begin()) it = container.begin(); it != container.end(); ++it)

/*
void merge_grps(vi &  arr){
    int low = 0;
    int high = arr.size()-1;
    
    while(low < high){
        if(arr[low] % 2 == 0)
            ++low;
        
        if(arr[high] % 2 != 0)
            --high;
        
        if(low < high && (arr[low] % 2 != 0) && (arr[high] % 2 == 0))
            swap(arr[low], arr[high]);
        
    }
 
}*/

void merge_grps(vi &arr) {
    int low = 0;
    int high = arr.size()-1;
    
    while(low < high) {
        if(arr[low] % 2 == 0 && low != high)
            ++low;
        
        if(low == high) break;
        
        if(arr[high] % 2 != 0 && low != high)
            --high;
        if(low == high) break;
        swap(arr[high], arr[low]);
        
    }
      
}

/*
 * Complete the function below.
 */
vector <int> solve(vector <int> arr) {
    
    merge_grps(arr);
    
    return arr;
}

