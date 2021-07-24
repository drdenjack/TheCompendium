# quick sort
#
# This is used in many real cases as it is pretty darn good: 
#   O(n log n) (avg)
#   O(n) best
#   O(n^2) worst
#
# Find a pivot (use the middle of the list here)
# Make a list of smaller and a list of greater elements
# recursivly sort the smaller list and the greater list
# return the combination of [smallers, pivot, greaters]

def quick_sort(arr):
    if len(arr) < 2:
        return arr
    # pick mid as pivot
    mid_idx = (len(arr)-1)//2   # 1 -> 0, 2 -> 0, 3 -> 1, 4 -> 1, 5 -> 2, 6 -> 2, 11 -> 5
    pivot = arr[mid_idx]
    lessers = []
    greaters = []
    for i, a in enumerate(arr):
        if i != mid_idx:
            if a < pivot:
                lessers.append(a)
            else:
                greaters.append(a)
    left = quick_sort(lessers) 
    right = quick_sort(greaters)
    return left + [pivot] + right


if __name__ == "__main__":
    # 20 random integers
    arr = [11, 71, 62, 86, 29, 33, 65, 38, 50, 39, 33, 62, 47, 38, 87, 17, 53, 22, 97, 52]
    print(arr)
    result = quick_sort(arr)
    print(result)
    expected = [11, 17, 22, 29, 33, 33, 38, 38, 39, 47, 50, 52, 53, 62, 62, 65, 71, 86, 87, 97]
    assert result == expected
    print()
    print('Quick Sorted result matched expected value!')
