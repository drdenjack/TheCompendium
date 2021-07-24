print("Bubble Sort!")

def bubbleSort(arr):
    for _ in range(len(arr)):
        for i in range(len(arr) - 1):
            if arr[i+1] < arr[i]:
                arr[i], arr[i+1] = arr[i+1], arr[i]

arr1 = [1,5,2,0,8,88,12,3]
print(arr1)
bubbleSort(arr1)
print(arr1)

extras = [100] * 10000
arr2 = [1,5,2,0,8,88,12,3] + extras
expected = sorted(arr2)
bubbleSort(arr2)
assert arr2 == expected
print(f'tried it with an array of size {len(arr2)} and the assert passed!')