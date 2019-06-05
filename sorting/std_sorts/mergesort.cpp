63 void nmerge(vi & orig, int low, int mid, int high) {
 64         int temp_size = high -low +1;
 65         vi temp(temp_size, 0);
 66
 67         int a_len = mid - low +1; // low:mid
 68         int b_len = high - mid;  // mid+1:high
 69         int a_i = low;
 70         int b_i = mid+1;
 71
 72         // merge two sorted lists
 73         for(int i =low; i < temp_size; i++) {
 74                  if(a_i < a_len && b_i <= b_len) {
 75                         if(orig[a_i] <= orig[b_i]){
 76                                 temp[i] = orig[a_i];
 77                                 a_i++;
 78                         }else {
 79                                 temp[i] = orig[b_i];
 80                                 b_i++;
 81                         }
 82                         continue;
 83                 }
 84
 85                 if( a_i < a_len) {
 86                         temp[i] = orig[a_i];
 87                         a_i++;
 88                 }
 89
 90                 if( b_i <= b_len) {
 91                         temp[i] = orig[b_i];
 92                         b_i++;
 93                 }
 94         }
 95
 96         // copy merged temp list into ORIGINAL list
 97         for(int i = low; i < temp_size; i++) {
 98                 orig[i] = temp[i];
 99         }
100 }
