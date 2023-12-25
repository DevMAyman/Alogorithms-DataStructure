#include <iostream>
using namespace std;
int partation (int arr[],int startIndex, int endIndex);
void qickSort(int arr[], int start_index, int end_index);
int main()
{
    int arr[]={5,-1,100,6,-100,-1000};
    qickSort(arr,0,5);
    for(int i=0; i<5;i++){
        cout<<arr[i]<<endl;
    }
}

int partation (int arr[],int startIndex, int endIndex){
    int pivot=arr[startIndex];
    while(startIndex<endIndex){
            if(arr[startIndex]>arr[endIndex]){
                    swap(arr[startIndex],arr[endIndex]);
            }
            if(pivot==arr[startIndex]){
                endIndex--;
            }
            else if(pivot==arr[endIndex]){
                startIndex++;
            }
    }
        return startIndex;
}
void qickSort(int arr[], int start_index, int end_index){
    if(start_index>=end_index) return;
    int p = partation(arr,start_index,end_index);
    qickSort(arr,start_index,p-1);
    qickSort(arr,p+1,end_index);
}
