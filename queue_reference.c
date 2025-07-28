// AOJ ALDS1_3_B Queue
// 2018.4.30 bal4u

#include <stdio.h>

#define MAX_N 100002

typedef struct { char *p; int tm; } Q;
Q que[(MAX_N<<1)+2]; int top, end;
char name[MAX_N][20];

char buf[20], *p;
int in()
{
	int n = 0;
	while (*p >= '0') n = 10*n + (*p++ & 0xf);
	p++;
	return n;
}

int main()
{
	int  n, q, tm, i;
	Q  t;

	fgets(p=buf, 20, stdin);
	n = in(), q = in();
	for (i = 0; i < n; i++) {
		fgets(p=name[i], 20, stdin);
		while (*p > ' ') p++; *p++ = 0;
		que[i].p = name[i], que[i].tm = in();
	}

	tm = 0, top = 0, end = n;
	while (top != end) {
		t = que[top]; if (++top == MAX_N) top = 0;
		if (t.tm <= q) {
			printf("%s %d\n", t.p, tm+t.tm);
			tm += t.tm;
		} else {
			t.tm -= q;
			que[end] = t; if (++end == MAX_N) end = 0;
			tm += q;
		}
	}
	return 0;
}

