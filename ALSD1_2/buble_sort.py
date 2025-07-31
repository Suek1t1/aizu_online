def buble_sort(array, number):
    swap_count = 0
    for i in range(number):
        for j in range(0, number - i - 1):
            if array[j] > array[j + 1]: 
                array[j], array[j + 1] = array[j + 1], array[j]  
                swap_count += 1  
    return swap_count

input_number = input()
input_str = input()
number = int(input_number)
array = [int(x.strip()) for x in input_str.split(" ")]

swap_count = buble_sort(array, number)

for i in range(number):
    if i < number - 1 :
        print(str(array[i]) + " ",end="")
    else :
        print(array[i])
print(swap_count)