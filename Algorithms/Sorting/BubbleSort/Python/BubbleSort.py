print("Bubble Sort!")

def bubbleSort(arr):
    for foo in range(0,len(arr)):
        for i in range(0,len(arr)-1):
            if(arr[i+1]<arr[i]):
                tmp=arr[i]
                arr[i]=arr[i+1]
                arr[i+1]=tmp


arr=[1,5,2,0,8,88,12,3]

print(arr)

bubbleSort(arr)

print(arr)