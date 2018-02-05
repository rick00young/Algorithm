
def partition(array, low, high):
    pivot_key =  array[low]
    while low < high:
        while low < high and array[high] >= pivot_key:
            high -= 1
        temp = array[low]
        array[low] = array[high]
        array[high] = temp

        while low < high and array[low] <= pivot_key:
            low += 1
        temp = array[low]
        array[low] = array[high]
        array[high] = temp
    return low

def q_sort(array, low, high):
    # pivot = ''
    if low < high:
        pivot = partition(array, low, high)
        q_sort(array, low, pivot-1)
        q_sort(array, pivot+1, high)


def quick_sort(array=None):
    q_sort(array, 0, len(array)-1)


if '__main__' == __name__:
    array = [3,4,2,6,8,5,1]
    quick_sort(array)
    print(array)