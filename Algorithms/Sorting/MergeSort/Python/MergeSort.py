print("Merge Sort!")

# def mergeSort(arr):
#     tmp = arr.copy()
#     mergeSortSub(arr, tmp, 0, len(arr) - 1)

# def mergeSortSub(arr, tmp, low, high):
#     # This sorts the array in place, so it saves a bit of space
#     # ... But it's harder to read
#     if low < high:
#         mid = (low + high)//2
#         mergeSortSub(arr, tmp, low, mid)
#         mergeSortSub(arr, tmp, mid + 1, high)
#         merge(arr, tmp, low, mid, high)


# def merge(arr, tmp, low, mid, high):
#     for i in range(low, high + 1):
#         tmp[i] = arr[i]

#     tmp_low = low
#     tmp_high = mid + 1
#     curr = low

#     while(tmp_low <= mid and tmp_high <= high):
#         if tmp[tmp_low] <= tmp[tmp_high]:
#             arr[curr] = tmp[tmp_low]
#             tmp_low += 1
#         else:
#             arr[curr] = tmp[tmp_high]
#             tmp_high += 1
#         curr += 1

#     while(tmp_low <= mid):
#         arr[curr] = tmp[tmp_low]
#         tmp_low += 1
#         curr += 1


# Merge sort splits array into smaller and smaller lists until only a single element remains
# the lists are merged together and sorted as they are merged


def mergeSort(arr):
    # This is less space saving than the above algorithm, but it's easier to read
    # This does not sort in place
    if len(arr) <= 1:
        return arr
    mid_idx = len(arr)//2  # Not (len(arr)-1)//2 because list splicing is not end inclusive
    left, right = arr[:mid_idx], arr[mid_idx:]
    return merge(mergeSort(left), mergeSort(right))

def merge(left, right):
    output = []
    i, j = 0, 0
    while(i < len(left) and j < len(right)):
        # left and right are both sorted already.  Add them in sorted order
        if left[i] < right[j]:
            output.append(left[i])
            i += 1
        else:
            output.append(right[j])
            j += 1

    if i < len(left):
        # right is empty, but left isn't
        output += left[i:]
    elif j < len(right):
        # left is empty, but right isn't
        output += right[j:]
    return output


arr=[6, 5, 73, 81, 84, 80, 41, 73, 92, 4, 85, 45, 0, 98, 34, 65, 35, 41, 45, 48]
print(arr)

result = mergeSort(arr)
print(result)

expected = [0, 4, 5, 6, 34, 35, 41, 41, 45, 45, 48, 65, 73, 73, 80, 81, 84, 85, 92, 98]
assert result == expected

print()
print("Merge Sort Successfully sorted some random ints")
