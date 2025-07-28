#最大公約数を求める関数
def greatest_common(x,y) :
    while y != 0:
        x,y = y,x % y
    return x

#入力
input_str = input()
array = [int(x.strip()) for x in input_str.split(" ")]
#入力ミスの除去
if len(array) != 2 :
    print("error")

else :
#ｘとｙを設定する(x > yに設定する)
    if array[0] > array[1] :
        x = array[0]
        y = array[1]
    else :
        y = array[0]
        x = array[1]

greatest = greatest_common(x,y)
print(greatest)
