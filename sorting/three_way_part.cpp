void three_way_part(vi & orig, int low, int high) {
	int end_1 = low;
	int start_3 = high;
	int run = low;
	while( run <= start_3) {
		if( orig[run] == 1) {
			swap(orig[run], orig[end_1]);
			end_1++;
			run++;
		} else if(orig[run] == 2) {
			run++;
		} else {
			swap(orig[run], orig[start_3]);
			--start_3;
			// NOTE runner is NOT incremented here
		}

	}
}
void print_v(vi & orig) {
	cout<<"\n printing vector elems: ";
	for(auto & e: orig)
		cout<<"\t "<<e;
}
