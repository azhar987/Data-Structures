#include<iostream>

using namespace std;
class Heap
{
    private:
        int *h;
        int maxSize;
        int m;
    public:
        Heap(int *arr, int ms, int sz)
        {
            h = arr; //point to the array 
            maxSize = ms; //maximum size
            m = sz; //number of elements in the array           
        }

        Heap(int ms)
        {
            maxSize = ms;
            h = new int[maxSize+1];
            m = 0;
        }
        void insert(int x);
        bool isHeap(int arr[], int i, int n);
        void print();
        int deleteMin();
        int deleteMinH();
        void heapify(int i);
        void buildHeap();
};
bool isHeap(int arr[], int i, int n)
{
    if (i >= (n - 1) / 2)
        return true;
 
    if (arr[i] >= arr[2 * i + 1] &&
        arr[i] >= arr[2 * i + 2]
        && isHeap(arr, 2 * i + 1, n)
        && isHeap(arr, 2 * i + 2, n))
        return true;
 
    return false;
}
void Heap::print()
{
    for (int i = 1; i <= m; i++)
        cout<<h[i]<<"\t";
    cout<<endl;
}
void Heap::insert(int c)
{
    if(m == maxSize)
    {
        cout<<"No space in heap"<<endl;
        return;
    }
    m++;
    int i;
    for (i = m; i > 1; i = i/2)
    {
        if (c >= h[i/2])
            break;
            
            

        h[i] = h[i/2];       
    }
    h[i] = c;
}

int Heap::deleteMin()
{
    if (m == 0) 
    {
        cout<<"Heap Empty..."<<endl;
        return 0;
    }
    
    int x = h[1];
    int last = h[m];
    m--;
    int i, j;
    for (i = 1, j = 2; j <= m; i = j, j *= 2) 
    {
        if (j < m)
            if (h[j] > h[j+1]) 
                j++;    // j points to the smaller child
        
        if (last <= h[j]) //final childs
            break;
        h[i] = h[j]; // move child up
    }
    h[i] = last;
    return x;
}

int Heap::deleteMinH()
{
    int root = h[1]; 
    h[1] = h[m]; //assign last element to first
    m--;
    heapify(1);
    return root;
}

void Heap::heapify(int i) 
{ 
    int smallest = i; // Initialize smallest as root 
    int l = 2 * i; // left = 2*i 
    int r = 2 * i + 1; // right = 2*i + 1
  
    // If left child is larger than root 
    if (l <= m && h[l] < h[smallest]) 
        smallest = l; 
  
    // If right child is smaller than smallest so far 
    if (r <= m && h[r] < h[smallest]) 
        smallest = r; 
  
    // If not is not parent 
    if (smallest != i) 
    { 
        swap(h[i], h[smallest]); 
  
        // Recursively heapify the affected sub-tree 
        heapify(smallest); 
    } 
} 
  
// Function to build a Min-Heap from the given array 
void Heap::buildHeap() 
{ 
    // Index of last non-leaf node 
    int startIdx = (m / 2); 
  
    // Perform reverse level order traversal 
    // from last non-leaf node and heapify 
    // each node 
    for (int i = startIdx; i > 0; i--)
        heapify(i); 
}

int main()
{
    Heap h(15);
    h.insert(13);
    h.insert(16);
    h.insert(21);
    h.insert(14);
    h.insert(19);
    h.print();
    h.deleteMinH();
    h.print();

    // Heap h1(15);
    // h1.insert(65);
    // h1.insert(26);
    // h1.insert(32);
    // h1.insert(24);
    // h1.insert(31);
    // h1.insert(19);
    // h1.insert(68);
    // h1.insert(21);
    // h1.insert(16);
    // h1.insert(13);
    // h1.insert(22);
    // //h1.insert(35);
    // h1.print();
    // h1.deleteMinH();
    // h1.print();
    
    cout<<"------------------------------"<<endl;
    int arr[] = {0, 65, 31, 32, 26, 21, 19, 68, 13, 24, 15, 14, 16, 5, 70, 12};
    int arr_sz = sizeof(arr)/sizeof(int);
    cout<<"Size of array: "<<arr_sz<<endl;
    Heap h2(arr, arr_sz, arr_sz-1);
    cout<<"Before heap: "<<endl;
    h2.print();
    h2.buildHeap();
    cout<<"After Heap: "<<endl;
    h2.print();
    int n = arr_sz- 1;
 
    isHeap(arr, 0, n) ? printf("      Yes       ") : printf("    No    ");
    return 0;
}