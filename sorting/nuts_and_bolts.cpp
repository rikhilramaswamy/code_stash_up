#include <iostream>
using namespace std;

#include <algorithm>
#include <vector>
typedef vector<int> vi;
#define cont_tr(container, it)\
    for(decltype(container.begin()) it = container.begin(); it != container.end(); ++it)
#define pb push_back

int nbpart(vi &bolts, int nv, int low, int high) {

        int ind = low;
        int i =low;
        for( ; i < high; i++) {
                if(bolts[i] < nv) {
                        swap(bolts[i], bolts[ind]);
                        ind++;
                } else if(bolts[i] == nv) {   // this case is important
                        swap(bolts[i], bolts[high]);
                }
        }

        swap(bolts[high], bolts[ind]);

        return ind;
}


void rec_nb(vi& nuts, vi&  bolts, int low, int high) {
        if(low < high) {
        cout<<"rec_nb : low:"<<low<<"\thigh: "<<high;
      int piv = nbpart(bolts, nuts[high], low, high);
                nbpart(nuts, bolts[piv], low, high);


                cout<<"\n printing bolts...";
                cont_tr(bolts  , it) {
                        cout<<"\t "<<(*it);
                }

                cout<<"\n printing nuts...";
                cont_tr(nuts  , it) {
                        cout<<"\t "<<(*it);
                }
                rec_nb(nuts, bolts, low, piv-1);
                rec_nb(nuts, bolts, piv+1, high);
        }
}




int main() {
/* Enter your code here. Read input from STDIN. Print output to STDOUT */
    vi bolts ;
    vi arr;
           vi nuts;
        bolts.pb(2);
        bolts.pb(3);
        //bolts.pb(4);
        //bolts.pb(1);

        nuts.pb(3);
        nuts.pb(2);
        //nuts.pb(2);
        //nuts.pb(3);

        cout<<"\n printing bolts...";
        cont_tr(bolts , it) {
                cout<<"\t "<<(*it);
        }

        cout<<"\n printing nuts...";
        cont_tr(nuts , it) {
                cout<<"\t "<<(*it);
        }

        cout<<"\n invoking solve() ";

//      solve(nuts, bolts, 0);
        int high = bolts.size() -1;
        rec_nb(nuts, bolts, 0 , high);
        cout<<"\n printing bolts...";
        cont_tr(bolts , it) {
                cout<<"\t "<<(*it);
        }

        cout<<"\n printing nuts...";
        cont_tr(nuts , it) {
                cout<<"\t "<<(*it);
        }
        cout<<"\n";
        return 0;
   
}
