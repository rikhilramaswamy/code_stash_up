 void set_part_bt(unsigned int &num, int pos){  
        num = num  | (1 << pos);    
    }
    
typedef unordered_map<unsigned int, int> myMap;
typedef pair<unsigned int, int> myMap_pair;
    
    
     vector<string> findRepeatedDnaSequences(string s) {
        myMap m1;
         vs empty_vector;
         mySet ms1;
         
        
        
        int total = s.size();
        // a: 00, c:01, g:10, t:11
         // bits: 0-19 are 10length char 
         // bits: 20-31 is mask 
         //int mask = 00000000000011111111111111111111;
         unsigned int mask = 0x000fffff;
         unsigned int num =0;
         
         if ( total< 10)
             return empty_vector;
         
         // first step is to hash the first 10 chars
         int index =0;
         int i=0;
         for(; i <=9; i++){
             switch(s[i]){
                     case 'A':
                        ++index;
                        ++index;
                        break;
                     case 'C':
                        ++index;
                        set_part_bt(num, index);
                        ++index;
                        break;
                     case 'G':
                        set_part_bt(num, index);
                        ++index;
                        ++index;
                        break;
                     case 'T':
                        set_part_bt(num, index);
                        ++index;
                        set_part_bt(num, index);
                        ++index;
                        break;
                 default:
                     cout<<"\n we should NOT be here";
                     break;
             }
             
         }
         assert(index == 20);
         
        m1.insert(myMap_pair(num, 0));
       // cout<<"\n first_num: "<<num<<"\t index: "<<0;
         
        // now do rolling hash
         // insert new char and remove old char
        int bit_18 = 18;
        int bit_19 = 19;
        //for(; i <= total-10; i++){
        for(; i < total; i++){

            num = num & mask;
            num = num >> 2;
            switch(s[i]){
                     case'A':
                        
                        break;
                     case 'C':
                     set_part_bt(num, bit_19);
                        break;
                     case 'G':
                        set_part_bt(num, bit_18);
                        break;
                     case 'T':
                        set_part_bt(num, bit_18);
                        set_part_bt(num, bit_19);
                        break;
                 default:
                     cout<<"\n we should NOT be here";
                     break;
             }
           // cout<<"\n next_num: "<<num<<"\t index: "<<i-9;

            auto itr = m1.find(num);
            if( itr == m1.end()){
                m1.insert(myMap_pair(num, i -9));
            } else {
                string temp = s.substr(itr->second, 10);
                ms1.insert(temp);
            }
        }
         
        /*
          int test = 8;
         int test_mask =0x00000007;
         cout<<"\n num was: "<<test;
         //set_part_bt(num, 1);
         //test = test >> 2;
         test = test & test_mask;
         cout<<"\n num is: "<<test;
         cout<<"\n sizeof(int) : "<<sizeof(int);*/
         
        
         if (!ms1.empty()) {
             vs final_res(ms1.begin(), ms1.end());
            return final_res;
        }
       
        
        
        return empty_vector;
    }
