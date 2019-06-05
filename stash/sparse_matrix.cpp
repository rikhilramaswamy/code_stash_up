
class nspm {
public:
	nspm(int r, int c) {
		max_rows = r;
		max_cols =c;
		cout<<"\n size of v1 was: "<<v1.size();
	//	v1 = new vusi(max_rows);	
		v1.resize(max_rows);
		cout<<"\n size of v1 is: "<<v1.size();
	}

	int read_cell(int i, int j) {
		//auto & temps = (*v1)[i];
		auto & temps = v1[i];
		auto itr = temps.find(j);
		if(itr != temps.end()){
			return 1;
		} 
		return 0;
	}

	void set_cell(int i, int j) {
		if( j <0 || j >= max_cols) {
			cout<<"\n col out of range, exiting";
			return;
		}

		if( i <0 || i >=max_rows) {
			cout<<"\n row out of range, exiting";
			return;
		}

		//auto & temps = (*v1)[i];
		auto & temps = (v1)[i];
		auto itr = temps.find(j);
		if(itr != temps.end()){
			cout<<"\n value already set";
		} else {
			temps.insert(j);
			cout<<"\n bit set success";

		}
	}

	void reset_cell(int i , int j) {
		
		if( j <0 || j >= max_cols) {
			cout<<"\n col out of range, exiting";
			return;
		}

		if( i <0 || i >=max_rows) {
			cout<<"\n row out of range, exiting";
			return;
		}

		auto & temps = (v1)[i];
		auto itr = temps.find(j);
		if(itr == temps.end()) {
			cout<<"\n value unset so no-op";
			return;
		}	

		temps.erase(j);
		cout<<"\n value reset";
	}

private:
	int max_rows;
	int max_cols;
	vusi v1;	
};

typedef unordered_set<int> uns;
