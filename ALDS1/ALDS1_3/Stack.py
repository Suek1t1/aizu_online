#このプログラムはaizu online jugeのALDS1 3_Aのプログラムである
#逆ポーランド記法で書いた計算式を計算するプログラムを作る
stack = []

def operate(a, b, operator):
    if operator == '+':
        return a + b
    elif operator == '-':
        return a - b
    elif operator == '*':
        return a * b
    else:
        raise ValueError("Unknown operator: " + operator)

#入力
input_str = input()
array = [x.strip() for x in input_str.split(" ")]

#数字文字と記号の識別
for token in array:
    #if '0' <= token <= '9':これだと99とか999が不明なオペランドとして処理されてしまう．
    if token.isdigit() or (token.startswith('-') and token[1:].isdigit()):      #isdigit()は全ての数値文字列が数字であるか確認する．またstartswitchは-を除去するもので，絶対値が整数か判定する．
        stack.append(int(token))
    else:
        b = stack.pop()
        a = stack.pop()

        result = operate(a, b,token)
        stack.append(result)
        #print(stack[-1])        #デバック用．-1はスタックの末尾だけを参照する．（popと違って取り出されるわけではない）

#出力
print(stack[0])