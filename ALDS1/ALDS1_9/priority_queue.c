// ALDS1_9_c

#include <stdio.h>
#include <stdlib.h>
#define MAX_Q 2000000

// 入れ替えを行う関数
void swap(int *a,int *b){
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

int priority_queue[MAX_Q];
int priority_queue_size = 1;                            // 最優先の根。一番上位の根

// 命令insertの処理
void insert(int number){
  priority_queue[priority_queue_size] = number;
  priority_queue_size++;
  int nw = priority_queue_size-1;
  while(nw>=2){                                         // 親と子を比較する
    if(priority_queue[nw] > priority_queue[nw/2]){      // 例：3つ目のキーが入力された場合、3/2=1(親)と比較。4つ目のキーが入力された場合は、4/2=2(親と比較)
      swap(&priority_queue[nw],&priority_queue[nw/2]);
      nw /= 2;
    }else{
      break;
    }
  }
}

// 命令extractの処理
int extract(){
  int ret = priority_queue[1];
  priority_queue[1] = priority_queue[priority_queue_size-1];    // ヒープの一番最後にねを移動させる
  priority_queue_size--;

  int nw = 1;                                                   
  while(nw < priority_queue_size){
    int nwx = nw;                                               // nwxは、親と子の中で一番大きい値を持つノードのインデックス
    if(nw*2 < priority_queue_size && priority_queue[nw] < priority_queue[nw*2]){
      nwx = nw*2;
    }
    if(nw*2+1 < priority_queue_size && priority_queue[nw] < priority_queue[nw*2+1] && priority_queue[nw*2] < priority_queue[nw*2+1]){
      nwx = nw*2+1;
    }
    if(nwx == nw)break;
    swap(&priority_queue[nw],&priority_queue[nwx]);
    nw = nwx;
  }


  return ret;
}

// main関数
int main(){
  while(1){
    char command[9];
    scanf("%s",command);
    if(command[0] == 'i'){              // 命令がinsertの時
      int number;
      scanf("%d",&number);
      insert(number);
    }else if(command[1] == 'x'){        // 名声がextractの時
      printf("%d\n",extract());
    }else{
      break;
    }
  }
}

