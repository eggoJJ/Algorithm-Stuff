import array # i like arrays
import random
import timeit
from timeit import default_timer as timer

def buildHeap(a): # Function to build heap O(nlogn) , for loop through array takes n time, each heapify call is logn
    for i in range((len(a)-1)//2,-1,-1): # We start from the bottom of our tree, n/2 represents the first internal node
        maxHeapify(a,i,len(a))

       
def maxHeapify(a,i,length): #Function to turn our structure into a maxheap, O(logn)
                            #Works by comparing children indices and making the appropriate swaps, then recursively calling heapfiy on the child that was swapped    
    leftIndex = 2*i +1          
    rightIndex = 2*i +2

    if(leftIndex < length and a[i] < a[leftIndex]): # before we check to see if we should swap, make sure our index is not out of bounds 
        if(rightIndex < length and a[rightIndex] > a[leftIndex]): # compare left and right child, choose bigger value and swap that
           a[i], a[rightIndex] = a[rightIndex], a[i]
           maxHeapify(a,rightIndex,length)
        else:
            a[i], a[leftIndex] = a[leftIndex], a[i]
            maxHeapify(a,leftIndex,length)
      
    elif(rightIndex < length and a[i] < a[rightIndex]): # if left child didnt meet criteria's, make sure to check right 
          a[i], a[rightIndex] = a[rightIndex], a[i]
          maxHeapify(a,rightIndex,length)
       

def heapSort(a): # Implementation of heapSort O(nlogn)

    for i in range(len(a)-1,-1,-1): # to HeapSort: we take our last index, swap it with the root (max value), then heapify the root
        a[0],a[i] = a[i], a[0]
        maxHeapify(a,0,i)           # changing the length constraints to make sure we dont heapify the sorted values


def selectionSort(a): #implementation of selectionSort O(n^2)

        for i in range(len(a)):  # works by selecting the smallest value in each subarray and making the necessary swap
                for j in range(i,len(a)):
                        if(a[i] > a[j]):
                                a[i],a[j] = a[j], a[i]

def HeapsortTimer(): # Timer Function: HeapSort
        a = array.array('i',(0 for i in range(0,1000)))

        for j in range(len(a)):
                a[j] = random.randint(-10000,10000)
        
        buildHeap(a)
        heapSort(a)
   

def selectionSortTimer(): #Timer Function: SelectionSort
        a = array.array('i',(0 for i in range(0,1000)))

        for j in range(len(a)):
                a[j] = random.randint(-10000,10000)
        selectionSort(a)




## main

n = eval(input("Enter a number: "))
testCase = 100
generateArrayTime = .012118946180000001    # Pre-Process Calculation, average time of generating and filling an array of 1000
a = array.array('i',(0 for i in range(0,n)))

for i in range(len(a)):
        a[i] = random.randint(-10000,10000)

buildHeap(a)
for i  in range(len(a)):
        print(a[i], end= ",")
        if(i == len(a) - 1): print()

heapSort(a)
for i in range(len(a)):
    print(a[i], end = ",")
    if(i == len(a) - 1): print()

heapTime = (timeit.timeit(stmt=HeapsortTimer,number=testCase))/testCase - generateArrayTime # Call our Timer helper function 100 times, - the amount of time to generate an Array
print("HeapSort takes: ",heapTime," seconds")
selectionTime = (timeit.timeit(stmt=selectionSortTimer,number=testCase))/testCase - generateArrayTime # same thing but for Selection Sort
print("SelectionSort takes: ",selectionTime," seconds")
