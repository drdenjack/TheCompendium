print("Merge Sort!")

def mergeSort(arr):
    tmp=arr*1
    mergeSortSub(arr,tmp,0,len(arr)-1)


def mergeSortSub(arr,tmp,low,high):
    if(low<high):
        mid=(low+high)//2
        mergeSortSub(arr,tmp,low,mid)
        mergeSortSub(arr,tmp,mid+1,high)
        merge(arr,tmp,low,mid,high)


def merge(arr,tmp,low,mid,high):
    for i in range(low,high+1):
        tmp[i]=arr[i]

    tmp_low=low
    tmp_high=mid+1
    curr=low

    while(tmp_low <= mid and tmp_high<=high):
        if(tmp[tmp_low]<=tmp[tmp_high]):
            arr[curr]=tmp[tmp_low]
            tmp_low+=1
        else:
            arr[curr]=tmp[tmp_high]
            tmp_high+=1
        curr+=1

    while(tmp_low<=mid):
        arr[curr]=tmp[tmp_low]
        tmp_low+=1
        curr+=1

arr=[1,5,2,0,8,88,12,3]

#arr=[1,5,2]

print(arr)

mergeSort(arr)

print(arr)
