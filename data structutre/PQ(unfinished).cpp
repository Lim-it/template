template<class T>
class PQ{
public:
    int size;
    vector<T> heap;
    T front();
    T back();
    void insert();
    void delete_node();
private:
    void top_heapify();
    void bottom_heapify();
};

void PQ::top_heapify(int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    //if (l < size && heap[l] > heap[largest])
    if (l < size && cmp(heap[l], heap[largest])) //for custom cmp
        largest = l;
    //if (r < size && heap[r] > heap[largest])
    if (l < size && cmp(heap[r], heap[largest]) //for custom cmp
        largest = r;

    if (largest != i) {
        swap(heap[i], heap[largest]);
        top_heapify(heap, largest);
    }
}

void PQ::bottom_heapify(int i){
    int parent = (i - 1) / 2;
    //if (heap[i] > heap[parent]) {
    if (cmp(heap[i], heap[parent])) { //for custom cmp
        swap(heap[i], heap[parent]);
        bottom_heapify(parent);
    }
}

void PQ::insert(T node) {
    size++;
    if (size == 0) {
        heap.push_back(node);
    } 
    else {
        heap.push_back(node);
        bottom_heapify(heap, size - 1);
    }
}

// Function to delete an element from the tree
void PQ::delete_node(T node) {
    size--;
    int i;
    for (i = 0; i < size; i++) {
        if (node == heap[i]) break;
    }
    swap(&heap[i], &heap[size - 1]);

    heap.pop_back();
    for (int i = size / 2 - 1; i >= 0; i--) {
        top_heapify(hT, i);
    }
}

void PQ::front(){
    return heap[0];
}
void PQ::back(){
    return heap[size-1];
}{\rtf1}