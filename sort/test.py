
def merge(l, r):
    i = 0
    j = 0
    merged = []

    while i < len(l) and j < len(r):
        if l[i] <= r[j]:
            merged.append(l[i])
            i += 1
        else:
            merged.append(r[j])
            j += 1
    A = merged

def mergesort(A):
    
    if len(A) < 2:
        return

    mid = len(A) // 2

    left = A[:mid]
    right = A[mid:]

    mergesort(left)
    mergesort(right)
    merge(left, right)

if __name__ == '__main__':

    x = [4, 7, 5, 8, 12, 16, 7, 22, 1, 0, 72]

    print('Unsorted Array: ', end = '')
    for i in x:
        print(str(i) + " ", end = '')
    print()

    mergesort(x)

    print('Sorted Array: ', end = '')
    for i in x:
        print(str(i) + " ", end = '')
    print()