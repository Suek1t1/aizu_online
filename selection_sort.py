def select_sort(array, number):
    swap_count = 0
    for i in range(number):
        minj = i
        for j in range(i, number):
            if int(array[minj]) > int(array[j]):
                minj = j
        if i != minj:
            array[i], array[minj] = array[minj], array[i]
            swap_count += 1
    return swap_count

input_number = input()
input_str = input()
number = int(input_number)
array = [int(x.strip()) for x in input_str.split(" ")]

swap_count = select_sort(array, number)

for i in range(number):
    if i < number - 1 :
        print(str(array[i]) + " ",end="")
    else :
        print(array[i])
print(swap_count)
