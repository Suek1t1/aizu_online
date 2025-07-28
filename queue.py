#このプログラムはaizu online jugeのALDS1 3_Bのプログラムである
#ラウンドロビンスケジューリングをシミュレートするプログラム
def all_zeros(process):
    for row in process:
        if row[1] != '0':
            return False
    return True

def queue(data,process):
    processed = []      #処理済みのデータを格納する
    time = 0            #今までにかかった処理時間
    j = 0
    while not all_zeros(process):
        for i in data[0]:            
            process[i][1] -= data[1]
            if process[i][1] <= 0:      #処理が終了した時
                time = time + data[1] + process[i][1]       #経過時間を記録する
                processed[j] = process.pop(i)
            else:       #処理が終了しなかった時



#入力
input_data = input()        #プロセスの処理個数と処理時間を入力する
data = [x.strip() for x in input_data.split(" ")]
process = []
i = 0
while True:
    try:
        line = input()
        if line:
            # 各行をスペース区切りでリストにし、二次元配列として追加
            process.append([x.strip() for x in line.split(" ")])
    except EOFError:
        break

queue(data,process)

#出力
for i in data:
    print(process[i])
