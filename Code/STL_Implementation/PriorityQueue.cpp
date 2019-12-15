struct HEAP{
    int size = 0;
    int* array = new int[2000001];
};

void heapify(HEAP* heap){
    int n = heap->size, k, v, j;
    for (int i = n/2; i >= 1; i--){
        k = i;
        v = heap->array[k];
        bool isHeap = false;

        while(!isHeap && 2*k <= n){
            j = 2*k;
            if (j < n){
                if(heap->array[j] < heap->array[j+1])
                    j++;
            }
            if (v >= heap->array[j])
                isHeap = true;
            else {
                heap->array[k] = heap->array[j];
                k = j;
            }
        }
        heap->array[k] = v;
    }
}

void heapifyTopDown(HEAP* heap, int rt){
    int right = rt*2 + 1;
    int left = rt*2;
    int bigger;

    //trocar com o da esquerda
    if (left <= heap->size && heap->array[left] > heap->array[rt])
        bigger = left;
    else
        bigger = rt;
    //ver se o da direita eh maior
    if (right <= heap->size && heap->array[bigger] < heap->array[right])
        bigger = right;

    // fazer a troca caso ele n esteja no lugar certo
    if (bigger != rt){
        int aux = heap->array[bigger];
        heap->array[bigger] = heap->array[rt];
        heap->array[rt] = aux;
        //ajeita onde ele ta agora
        heapifyTopDown(heap, bigger);
    }

}

void insert(HEAP* heap, int N){
    heap->size++;
    heap->array[heap->size] = N;
    for (int i = heap->size; i > 1 && heap->array[i] > heap->array[i/2];) {
        int aux = heap->array[i];
        heap->array[i] = heap->array[i/2];
        heap->array[i/2] = aux;
        i /= 2;
    }
}

void remove(HEAP* heap){
    cout << heap->array[1] << endl;
    heap->array[1] = heap->array[heap->size];
    heap->size--;
    heapifyTopDown(heap, 1);
}

/*
HEAP* arr = new HEAP();
insert(arr, x);
remove(arr);
*/
