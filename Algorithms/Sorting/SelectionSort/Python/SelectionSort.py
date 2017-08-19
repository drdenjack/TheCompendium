print("Selection Sort!")

def selectionSort(arr):
    ret=[]
    for foo in range(0,len(arr)):
        idx=0
        for i in range(1,len(arr)):
            if(arr[i]<arr[idx]):
                idx=i
        ret.append(arr[idx])
        arr.pop(idx)
    return ret

arr=[1,5,2,0,8,88,12,3]

print(arr)

sorted_arr=selectionSort(arr)

print(sorted_arr)