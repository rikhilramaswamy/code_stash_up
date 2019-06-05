/* hoares approach */

int partition(vi & arr, int low, int high) {
	int pivot = arr[high];
	int i = low; // left pointer (elem < pivot)
	int j = high-1;

	while(true) {
		while(arr[i] < pivot && i <high)
			i++;

		if( i >= j)
			return i;

		while(arr[j] >pivot && j >0)
			--j;

		if( i >=j)
			return i;

		swap(arr[i], arr[j]);

	}

	swap(arr[i], arr[high]);

	return i;
}
