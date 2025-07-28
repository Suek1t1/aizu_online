#include <stdio.h>
#include <stdlib.h>

struct pointer {
  int key;
  struct pointer *prev, *next;
};
typedef struct pointer* node;

node front, last;

// 要素をリストの先頭に追加
void insert(int data) {
  node target = front->next;
  node v = malloc(sizeof(struct pointer));
  v->key = data;
  front->next = v;
  v->prev = front;
  v->next = target;
  target->prev = v;
}

// 特定の要素を削除
void delete(int data) {
  node target = front->next;
  while (target != last && target->key != data) target = target->next;
  if (target == last) return; // 見つからなければ何もしない
  node left = target->prev, right = target->next;
  left->next = right;
  right->prev = left;
}

// 先頭要素を削除
void delete_front() {
  if (front->next == last) return; // 空リストなら無視
  node target = front->next->next;
  free(front->next);
  front->next = target;
  target->prev = front;
}

// 末尾要素を削除
void delete_last() {
  if (last->prev == front) return; // 空リストなら無視
  node target = last->prev->prev;
  free(last->prev);
  last->prev = target;
  target->next = last;
}

int main(void) {
  int number, data;
  char command[10];

  // 番兵ノードの初期化
  front = malloc(sizeof(struct pointer));
  last = malloc(sizeof(struct pointer));
  front->next = last;
  front->prev = front;
  last->next = last;
  last->prev = front;

  scanf("%d", &number);

  for (int i = 0; i < number; i++) {
    scanf("%s", command);

    if (command[0] == 'i') {
      scanf("%d", &data);
      insert(data);
    } else if (command[6] == 'F') {
      delete_front();
    } else if (command[6] == 'L') {
      delete_last();
    } else {
      scanf("%d", &data);
      delete(data);
    }
  }

  // リストの出力
  node space = front->next;
  while (space != last) {
    if (space != front->next) printf(" ");
    printf("%d", space->key);
    space = space->next;
  }
  printf("\n");

  return 0;
}