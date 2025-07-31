//このプログラムはaizu online jugeのALDS1 4_Cのプログラムである

#include <stdio.h>
#include <string.h> 	//strcmpを使用するために追加している（strcmp(string comparison)は文字と文字を比較する関数）

int  DNA['T' + 1];		//文字を数値に変換するための変換表
char f[33554432];		//辞書の実体となるフラグ配列(チェックシート的なやつ)容量効率は低いけど計算速度が速くなる

//文字列を整数キーに変換する関数
int get_key() {
    int k = 1;
    char DNA_code;
    getchar(); 
    while ((DNA_code = getchar()) != '\n') {    	//文字列の終わり（改行）まで読み込む
        k <<= 2;      								//キーを4倍して次の桁を用意（DNAのパターンはA,C,G,Tの4パターン．これは2ビットで全て表現できるから，kを四倍すると次の桁が用意できる）
        k |= DNA[DNA_code];   						//現在の文字に対応する数値を合成
		/*    1000  (kの値)
			| 0001  (Cの値。桁を合わせるため0を追加)
			------
  			  1001  (ORの結果)	*/
    }
    return k;
}

int main() {
    int n;
    char command[10];

//変換表（A,C，G,Tは2ビットで表現できる）
    DNA['A'] = 0;
	DNA['C'] = 1;
    DNA['G'] = 2;
    DNA['T'] = 3;

//命令数を読み込む
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
//命令（"insert" or "find"）を読み込む
        scanf("%s", command);
        if (strcmp(command, "insert") == 0){		//"insert" の場合
            f[get_key()] = 1;
        } else {            						//"find" の場合
            if (f[get_key()]) {
                puts("yes");
            } else {
                puts("no");
            }
        }
    }

    return 0;
}