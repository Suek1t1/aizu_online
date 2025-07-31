def sorting(array, i):
    # 正しいwhile条件
    while i > 0 and array[i] < array[i - 1]:
        # 要素を交換
        array[i - 1], array[i] = array[i], array[i - 1]
        i -= 1
    return array

def insert_sort(array, number):
    for i in range(number):
        # ソートを実施
        sorting(array, i)

        # 現在の配列を表示
        for j in range(number):
            if j < number - 1:
                print(str(array[j]) + " ", end="")
            else:
                print(array[j])  # インデックス修正

# 入力を受け取る
input_number = input()
input_str = input()
number = int(input_number)
array = [int(x.strip()) for x in input_str.split(" ")]

# 挿入ソートを実施
insert_sort(array, number)