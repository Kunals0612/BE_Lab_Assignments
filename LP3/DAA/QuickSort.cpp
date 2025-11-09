#include<bits/stdc++.h>
using namespace std;

//deterministic quick sort
class QuickSort{
    public:
        int partition(int low, int high, vector<int>& arr){
            //take pivot as last element
            int pivot = arr[high];
            int i = low - 1;
            
            //shift all the element less than pivot to left
            for(int j = low; j < high; j++){
                if(arr[j] < pivot){
                    i++;
                    swap(arr[j], arr[i]);
                }
            }
            //swap pivot to its correct position
            swap(arr[i + 1], arr[high]);
            return i + 1;
        }

        void quickSort(int low, int high, vector<int>& arr){
            if(low < high){
                int pi = partition(low, high, arr);
                quickSort(low, pi - 1, arr);
                quickSort(pi + 1, high, arr);
            }
        }
        
        void printArray(vector<int>& arr){
            for(int& i : arr){
                cout << i << " ";
            }
            cout << endl;
        }
};

//randomized quicksort: Quicksort worst case is O(n^2) if we take any random index instead of fix low or high 
//This makes the algorithm’s behavior independent of input order, giving an expected O(n log n) time complexity at worst case as well.

class RandomizedQuickSort : public QuickSort{
    private:
        //select any random index and swap it with pivot
        int randomizedPartition(int low, int high, vector<int>& arr){
            int randomIndex = low + rand() % (high - low + 1);
            swap(arr[randomIndex], arr[high]);
            return partition(low, high, arr);
        }
    public:
        void randomizedQuickSort(int low, int high, vector<int>& arr){
            if(low < high){
                int pi = randomizedPartition(low, high, arr);
                randomizedQuickSort(pi + 1, high, arr);
                randomizedQuickSort(low, pi - 1, arr);
            }
        }
};

int main(){
    vector<int> arr = { 10, 9, 8, 1, 7, 5};
    vector<int> arr1 = arr, arr2 = arr;

    QuickSort q;
    q.quickSort(0,arr1.size() - 1, arr1);
    q.printArray(arr1);

    RandomizedQuickSort rq;
    rq.randomizedQuickSort(0, arr2.size() - 1, arr2);
    rq.printArray(arr2);
}