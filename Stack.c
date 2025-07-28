#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stacks[MAX];
int top = 0;

// 演算子が入力された際、一つ前と二つ前の値を取り出す関数
int pop() {
    return stacks[--top];
}

// オペランドが入力された際、その値をスタックに積む関数
void push(int value) {
    stacks[top++] = value;
}

int main(void) {
    int a, b;
    char stacks_input[1000];

    // EOFまで入力を受け付ける
    while (scanf("%s", stacks_input) != EOF) {
        // 数値判定
        if ('0' <= stacks_input[0] && stacks_input[0] <= '9') {
            push(atoi(stacks_input));
        } else {
            // 演算子が来た場合
            b = pop();
            a = pop();
            switch (stacks_input[0]) {
                case '+':
                    push(a + b);
                    break;
                case '-':
                    push(a - b);
                    break;
                case '*':
                    push(a * b);
                    break;
                default:
                    printf("無効な演算子: %s\n", stacks_input);
                    return 1;
            }
        }
    }
    // 計算結果を表示
    printf("\n%d", pop());
    return 0;
}