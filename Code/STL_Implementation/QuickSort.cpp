void swap(int arr[], int i, int j){
    int aux = arr[i];
    arr[i] = arr[j];
    arr[j] = aux;
}

int partition(int arr[], int first, int last){//Lomuto
    int p = arr[first], s = first;
    for (int i = first+1; i <= last; i++){
        if (abs(arr[i]) < abs(p)){
            s++;
            swap(arr, s, i);
        }
    }
    swap(arr, first, s);

    return s;
}

void quickSort(int arr[], int first, int last){
    if (first < last){
        int s = partition(arr, first, last);

        quickSort(arr, first, s-1);
        quickSort(arr, s+1, last);
    }
}

/*
quickSort(arr, 0, size-1);
*/

int quicksorthelp(int arr[], int l, int h){
	int pivot = arr[l];
	int i = l, j = h;
	while(i<j){
		do{
			i++;
		}while(arr[i] <= pivot);
		do{
			j--;
		}while(arr[j] > pivot);
		if (i<j) swap(arr[i], arr[j]);
	}
	swap(arr[l], arr[j]);
	return j;
}
void quicksort(int arr[], int l, int h){
	if (l<h){
		int pivot = quicksorthelp(arr, l, h);
		quicksort(arr, l, pivot);
		quicksort(arr, pivot+1, h);
	}
}
/*
quicksort(arr, 0, size);
*/

