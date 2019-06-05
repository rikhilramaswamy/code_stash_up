typedef vector<string> vs;
#define pb push_back


void generate_all_subsets_helper(string sofar, string rest, vs & vs_out){
    if(rest.empty()) {
           vs_out.pb(sofar);
            return;
    }
    
    string remaining = rest.substr(1);
    generate_all_subsets_helper(sofar + rest.substr(0,1), remaining,vs_out );
    generate_all_subsets_helper(sofar, remaining, vs_out);

}

/*
 * Complete the function below.
 */
vector <string> generate_all_subsets(string s) {
    vs vs_out;
    generate_all_subsets_helper("", s, vs_out);
    
    return vs_out;

}

