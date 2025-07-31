def insertion_sort(array,number,g):
    swap_count = 0
    for i in range(g,number):
        v = array[i]
        j = i - g
        while j >= 0 and array[j] > v:
            array[j + g] = array[j]
            j -= g
            swap_count += 1
        array[j + g] = v
    return swap_count

def shell_sort(array,number):
    swap_count_total = 0
    gap = []
    h = 1
    while h <= number:
        gap.append(h)
        h = 3 * h + 1
    gap.reverse()

    m = len(gap)
    print(m)
    print(" ".join(map(str, gap)))

    for g in gap:
        swap_count = insertion_sort(array,number,g)
        swap_count_total += swap_count
    print(swap_count_total)
    for a in array:
        print(a)

# 入力処理
number = int(input())
array = [int(input()) for _ in range(number)]

shell_sort(array,number)