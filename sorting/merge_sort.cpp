typedef vector<int> vi;
#define cont_tr(container, it) \
 for( decltype(container.begin()) it = container.begin(); it != container.end(); ++it)

/*
void nMerge(vi& arr, int low, int mid, int high) {
        cout<<"\n nMerge with low: "<<low<<"\t high:"<<high;

    int nsize = high -low +1;
    cout<<"\n nsize: "<<nsize;
    
    vi buff(nsize);
    int arr1_end = mid ; int arr1_indx = low;
    int arr2_end = high ;int arr2_indx = mid+1;

    for(int j = 0; j < nsize; j++) {
        if(arr1_indx <= arr1_end && arr2_indx <= arr2_end ) {
            if(arr[arr1_indx] <= arr[arr2_indx]){
                buff[j] = arr[arr1_indx++];}
            else{
                 buff[j] = arr[arr2_indx++];
            }
            continue;
        }
        
        if(arr1_indx <= arr1_end){
            buff[j] = arr[arr1_indx++];
        }
        
         if(arr2_indx <= arr2_end){
             buff[j] = arr[arr2_indx++];
         }
             
    }
     cout<<"\n BUFFFER are ....";
    cont_tr(buff, it) {
        cout<<"\t "<<(*it);
    }

    // copy the auxillary array to main array
    int k = low;
    for(int j =0; j < nsize; j++) {
        arr[k++] = buff[j];
    }
}   

void MergeSort_helper(vi &arr, int low ,int high){
    
    
    if(low < high) {
        cout<<"\n helper with low: "<<low<<"\t high:"<<high;
        int mid = (low + high)/2;
        MergeSort_helper(arr, low, mid);
        MergeSort_helper(arr, mid+1, high);
        nMerge(arr, low,mid ,high);
    } 
}

*/


void nmerge(vi &arr, int low, int mid, int high){
    
    int alow = low;
    int ahigh = mid;
    int blow = mid+1;
    int bhigh = high;
    
    int temp_size = high - low +1;
    vi temp(temp_size, 0);
    for(int i =0 ; i < temp_size; i++){
        if(alow <= ahigh && blow <=bhigh ){
            if(arr[alow] < arr[blow])
                temp[i] = arr[alow++];
            else
                 temp[i] = arr[blow++];  
            continue;
        }
         if(alow <= ahigh)
             temp[i] = arr[alow++];
        
          if(blow <= bhigh)
              temp[i] = arr[blow++];
        
    }
    
    for(int j = low, i =0; j<=high && i <temp_size ; i++, j++ )
        arr[j] = temp[i];
    
}

void MergeSort_helper(vi &arr, int low, int high) {
    
    if(low >= high)
        return;
    // for handling overflow
    int mid = low + (high -low)/2 ;
    MergeSort_helper(arr, low, mid);
    MergeSort_helper(arr, mid+1, high);
    nmerge(arr, low, mid, high);
    
}


// Complete the MergeSort function below.
vector<int> MergeSort(vector<int> intArr) {
    int low = 0;
    int high = intArr.size() -1 ;
    
    MergeSort_helper(intArr, low, high);
    /*
    cout<<"\n POST .TEMP elems are ....";
    cont_tr(intArr, it) {
        cout<<"\t "<<(*it);
    }*/
    
    return intArr;
}


