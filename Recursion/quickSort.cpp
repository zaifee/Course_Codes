//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int a[], int start, int end)
    {
        
        
        
        if(start >= end) return;
        int pivot = end;
        
        int i = start-1;
        int j = start;
        
        
        while(j < pivot){
            
            if(a[j] < a[pivot]){
                i++;
                swap(a[i], a[j]);
            }
            j++;
        }
        i++;
        swap(a[i], a[pivot]);
        
        //recursive calls for left and right part 
        
        quickSort(a, start, i-1);
        quickSort(a, i+1, end);
     
    }
    
   
};


