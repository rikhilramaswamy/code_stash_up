#include<map>
typedef vector<int> vi;
typedef set<string> ss;
typedef vector<string> vs;
typedef map<int, int> mii;
typedef pair<int,int> mii_pair;
#define pb push_back
#define cont_tr(container, it)\
    for(decltype(container.begin()) it = container.begin(); it != container.end(); ++it)


/*
vector<string> findZeroSum(vector<int> arr) {
    // Write your code here.
    
    mii mymap;
    
    cont_tr(arr, it) {
        int val = (*it);
        
        decltype(mymap.begin())  mit = mymap.find(val);
        if (mit != mymap.end()){
            mit->second++;
        } else {
            mymap.insert(mii_pair(val, 1));
        }
        
    }
    
    decltype(mymap.begin())  miti = mymap.begin();
    while(miti != mymap.end()){
        //cout<<"\t key: "<<miti->first<<"\t val: "<<miti->second;
        miti++;
    }
    
    ss ss1;

    for(int i =0; i < arr.size(); ++i){
        
        for(int j = i+1; j < arr.size(); ++j){
             decltype(mymap.begin())  miti_i = mymap.find(arr[i]);
             miti_i->second--;
             decltype(mymap.begin())  miti_j = mymap.find(arr[j]);
              miti_j->second--;
            
            int temp = arr[i] + arr[j];
            int neg_temp = (-1) * temp;
            decltype(mymap.begin())  mit = mymap.find(neg_temp);
            if (mit != mymap.end() && mit->second > 0){
                   vi v11;
                    v11.pb(arr[i]);
                    v11.pb(arr[j]);
                    v11.pb(neg_temp);
                     sort(v11.begin(), v11.end());
                
                   string s = to_string(v11[0]);
                   s += "," + to_string(v11[1]) +"," + to_string(v11[2]);

                   ss1.insert(s);
            } 
             miti_i->second++;
             miti_j->second++;
            
        }
        
    }

    
      vs res(ss1.begin(), ss1.end());

    return res;

}
*/

void findZeroSum_helper(vi & arr, ss & myset){
    //cout<<"arr.size() -2:"<<arr.size() -2;
    for(int i=0; i < arr.size() -2 ; i++){
        int temp_curr_sum = arr[i];
        int lp = i+1;
        int hp = arr.size() -1;
        
        while(lp != hp){
            //cout<<"\nlp: "<<lp<<"\t hp: "<<hp;
            int nsum = arr[lp] + arr[hp];
            int res = (nsum + temp_curr_sum );
            //cout<<"res: "<<res;
            if(res == 0){
                cout<<"\n trig 11";
                string s1 = to_string(temp_curr_sum) + "," +  to_string(arr[lp]) + "," + to_string(arr[hp]);
                myset.insert(s1);
                //break; 
               // ++lp;
                
                --hp;
            } else if(res > 0){
                --hp;
            } else {
                ++lp;
            }
    
        }
  
    }
}




vector<string> findZeroSum(vector<int> arr) {
    ss myset;
    
    sort(arr.begin(), arr.end());
    
    cont_tr(arr, it){
        cout<<"\t "<<(*it);
        
    }
    findZeroSum_helper(arr, myset);

   // cout<<"\n size-set:"<<myset.size();
    vs v1(myset.begin(), myset.end());
    
    return v1;

}


