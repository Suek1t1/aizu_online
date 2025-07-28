#include <stdio.h>
#include <ctype.h>  // isdigit を使うため

#define MAX_N 100002       // 最大プロセス数（入力制限）
#define NAME_LEN 20        // プロセス名の最大長

// プロセス構造体：名前のポインタと残り時間
typedef struct {
    char *pointer;         // プロセス名（name[i] へのポインタ）
    int time_left;         // 残りの実行時間
} Q;

// キューの配列とキュー管理変数（リングバッファ方式）
Q que[(MAX_N << 1) + 2];   // 安全のために2倍＋αのサイズ確保
int top, end;              // キューの先頭と末尾

// プロセス名を保持する配列
char name[MAX_N][NAME_LEN];    

// 入力バッファとポインタ
char buffer[100];          // 入力用バッファ（1行分）
char *pointer;             // 現在読み取り中の位置を示すポインタ

// 文字列から整数を読み取る補助関数（atoiの代わり）
int in(char **p) {
    int n = 0;
    while (isdigit(**p)) {
        n = 10 * n + (**p & 0xf);
        (*p)++;
    }
    return n;
}

int main(void) {
    int number, quantum, time_elapsed;  // プロセス数、クォンタム、経過時間
    Q tmp;                              // 一時的なプロセスデータ

    // --- 初期入力の読み込み（1行目：プロセス数とクォンタム） ---
    fgets(buffer, sizeof(buffer), stdin);
    pointer = buffer;
	number = in(&pointer);
    quantum = in(&pointer);

    // --- 各プロセスの名前と実行時間を読み込む ---
    for (int i = 0; i < number; i++) {
        fgets(pointer = name[i], sizeof(name[i]), stdin);  // 1行読み取り
        while (*pointer > ' ') pointer++;                  // スペースまで進む
        *pointer++ = 0;                                 // プロセス名の後ろを文字列終端に

        que[i].pointer = name[i];                          // ポインタ設定
        que[i].time_left = in(&pointer);                           // 実行時間の取得
    }

    // --- ラウンドロビン処理 ---
    time_elapsed = 0;
    top = 0;
    end = number;

    while (top != end) {
        tmp = que[top];                     // 先頭のプロセスを取り出す
        if (++top == MAX_N) top = 0;        // リングバッファ処理

        if (tmp.time_left <= quantum) {
            time_elapsed += tmp.time_left;  // 実行時間を加算
            printf("%s %d\n", tmp.pointer, time_elapsed);
        } else {
            tmp.time_left -= quantum;       // 残り時間を減らす
            time_elapsed += quantum;
            que[end] = tmp;                 // キューの末尾に再追加
            if (++end == MAX_N) end = 0;    // リングバッファ処理
        }
    }

    return 0;
}