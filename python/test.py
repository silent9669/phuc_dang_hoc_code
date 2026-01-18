#!/usr/bin/env python3
import sys

def selection_sort(arr):
    n = len(arr)
    for i in range(n):
        min_idx = i
        for j in range(i+1, n):
            if arr[j] < arr[min_idx]:
                min_idx = j
        arr[i], arr[min_idx] = arr[min_idx], arr[i]
    return arr

def insertion_sort(arr):
    n = len(arr)
    for i in range(1, n):
        key = arr[i]
        j = i-1
        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key
    return arr

def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        for j in range(0, n-i-1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
    return arr

def quick_sort(arr):
    if len(arr) <= 1:
        return arr
    pivot = arr[len(arr) // 2]
    left = [x for x in arr if x < pivot]
    middle = [x for x in arr if x == pivot]
    right = [x for x in arr if x > pivot]
    return quick_sort(left) + middle + quick_sort(right)

def merge_sort(arr):
    if len(arr) <= 1:
        return arr
    mid = len(arr) // 2
    left = merge_sort(arr[:mid])
    right = merge_sort(arr[mid:])
    return merge(left, right)

def merge(left, right):
    result = []
    i = j = 0
    while i < len(left) and j < len(right):
        if left[i] < right[j]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1
    result.extend(left[i:])
    result.extend(right[j:])
    return result

if __name__ == "__main__":
    test_array = [64, 34, 25, 12, 22, 11, 90]
    
    print("Original array:", test_array)
    
    sorted_array_bubble = bubble_sort(test_array.copy())
    print("Sorted array using Bubble Sort:", sorted_array_bubble)
    
    sorted_array_quick = quick_sort(test_array.copy())
    print("Sorted array using Quick Sort:", sorted_array_quick)
    
    sorted_array_merge = merge_sort(test_array.copy())
    print("Sorted array using Merge Sort:", sorted_array_merge)

    sorted_array_selection = selection_sort(test_array.copy())
    print("Sorted array using Selection Sort:", sorted_array_selection)

    sorted_array_insertion = insertion_sort(test_array.copy())
    print("Sorted array using Insertion Sort:", sorted_array_insertion)

    sys.exit(0)
