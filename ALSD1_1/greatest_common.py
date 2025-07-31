#このプログラムはaizu online jugeのALDS1 1_Cのプログラムである

prime_dp_list = []
#すでに出てきている素数を記憶する（動的計画）
def prime_dp(j):
    prime_dp_list.append(j)

#素数判定とカウント
def prime_juge(array):
    count = 0  #ローカル変数として初期化
    for i in array:
        if i not in prime_dp_list:  # 既に素数リストにないか確認（not in）
            j = 2
            while j * j <= i:
                if i % j == 0:
                    break
                j += 1
            if j * j > i and i > 1:  #素数である場合
                prime_dp(i)
                count += 1
        else:
            count += 1
    return count

#入力処理
array = []
while True:
    try:
        line = input().strip()
        if line:  #空行でない場合
            array.append(int(line))
    except EOFError:  #終了（Ctrl + D / Ctrl + Z）
        break

print(prime_juge(array))