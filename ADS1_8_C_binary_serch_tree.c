#include<stdio.h>
#include<stdlib.h>
#define MAX 500001      // 命令数の最大値

typedef struct cell{
  int id;               // キー
  struct cell *right;   // 右子孫
  struct cell *left;    // 左子孫
}cell;
 
// 先行巡回関数
void preorder_traversal(cell *root){
  cell *p=root;
  printf(" %d",p->id);
 
  if(p->left!=NULL){
    preorder_traversal(p->left);
  }
  if(p->right!=NULL){
    preorder_traversal(p->right);
  }
  return;
}

// 中間巡回関数
void inorder_traversal(cell *root){
  cell *p=root;
  if(p->left!=NULL){
    inorder_traversal(p->left);
  }
  printf(" %d",p->id);
  if(p->right!=NULL){
    inorder_traversal(p->right);
  }
  return;
}
 
// --- makecell ---
cell* makecell(int target){
  cell *new=malloc(sizeof(cell));   // mallocは動的メモリ確保関数。
  new->id=target;
  new->left=NULL;                   // 最初は子を持たないのでleft,rightともにNULL
  new->right=NULL;
  return new;
}

// キーの挿入をする関数
void insert(cell **p, cell *new){
    if (*p == NULL) {               // ペースケース。現在の探索1がNULLであり、新しい接点を挿入するべき場所が見つかった場合。
        *p = new;
        return;
    }

    if (new->id < (*p)->id) {       // 再帰ステップ。現在の場所がNULLではない場合で、ルートより、子孫の方が大きい時
        insert(&(*p)->left, new);
    } else {                        // 再帰ステップ。現在の場所がNULLではない場合で、ルートより、子孫の方が小さい時
        insert(&(*p)->right, new);
    }
}
 
// 指定されたキーを探し有無を判定する関数
int find(cell *root,int x){
  cell *p=root;
 
  while(p!=NULL){
    if(p->id==x){
      return 1;
    }else if(p->id <x){
      p=p->right;
    }else{
      p=p->left;
    }
  }
  return 0;
}
 
// 二分探索木から特定のノードを削除する関数
cell* off(cell *q) {
    if(q == NULL){ // 削除対象がNULLなら何もしない (エラーハンドリング)
      return NULL;
    }

    if(q->left == NULL){          // 左の子がない場合 (ケース1:子なし, ケース2:右の子のみ)
      cell *temp = q->right;
      free(q);                    // qのメモリを解放
      return temp;                // 右の子を返す (NULLならNULL, あればその子)
    }else if(q->right == NULL){   // 右の子がない場合 (ケース2:左の子のみ)
      cell *temp = q->left;
      free(q);                    // qのメモリを解放
      return temp;                // 左の子を返す
    }else{                        // 両方の子がある場合 (ケース3:2つの子)
        
      // 次節点を見つける
      cell *successor_parent = q;
      cell *successor = q->right;

      while(successor->left != NULL){
        successor_parent = successor;
        successor = successor->left;
      }

      // 次節点の値を現在のノードにコピー
      q->id = successor->id;

        // 次節点を削除
        if (successor_parent == q) {                 // 次節点がqの直下の右の子の場合
            q->right = off(successor);               // qの右の子を更新
        } else {                                     // 次節点がqの右部分木のさらに奥にある場合
            successor_parent->left = off(successor); // 次節点の親の左の子を更新
        }
        return q;
    }
}

// 指定されたキーを消す関数
void delete(cell **p,int target){
  cell **r=p;
  cell *q=*r;

  while(q!=NULL){
    if(q->id==target){
      *r=off(q);
      return;
    }else if(q->id <target){
      r=&(q->right);
    }else{
      r=&(q->left);
    }
  q=*r;
  }
  return;
}

// main関数
int main(){
  int number,target,k;      // number=命令数、target=対象のキー
  char com[7];              // insert,find,delete,printの各種命令を格納するための配列
  cell *root=NULL;          // 二分探索木のルート
  cell *new;                // 新しい接点を作成する際に使用する
  int Find[MAX]={0};        // findの結果を一時的に保存する
 
  // 命令数入力
  scanf("%d",&number);
 
  // 命令入力
  for(int i=0;i<number;i++){
  scanf("%s",com);
 
    switch(com[0]){
      case 'i':                 // command == insert
        scanf("%d",&target);
        new=makecell(target);   // 新しい接点を作成
        insert(&root,new);
        break;
 
      case 'p':                 // command = print
        inorder_traversal(root);
        printf("\n");
        preorder_traversal(root);
        printf("\n");
        break;
 
      case 'f':                 // command = find
        scanf("%d",&target);
        Find[i]=find(root,target);
        if(Find[i]==1){
          printf("yes\n");
        }else if(Find[i]==0){
          printf("no\n");
        }
        break;

      case 'd':                 // command = delete
        scanf("%d",&target);
        delete(&root,target);
        break;
    }
  }
  return 0;
}

