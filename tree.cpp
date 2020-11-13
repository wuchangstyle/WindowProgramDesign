#define MaxSize 100
typedef struct node {
	char data;
	struct node *lchild;
	struct node *rchild;
}BTNode;
typedef struct {
	BTNode *data[MaxSize];
	int top;
}SqStack;
void InitStack(SqStack *&t) {
	t = (SqStack*)malloc(sizeof(SqStack));
	t->top = -1;
}
bool Push(SqStack *&t, BTNode *s) {
	if (t->top == MaxSize - 1)
		return false;
	else
	{
		t->top++;
	    t->data[t->top] = s;
		return true;
	}
}
bool StackEmpty(SqStack*t) {
	return(t->top == -1);
}
bool Pop(SqStack *&t, BTNode *&s) {
	if (t->top == -1)
		return false;
	s = t->data[t->top];
	t->top--;
	return true;
}
void DestroyStack(SqStack*&t) {
	free(t);
}
void CreatBTree(BTNode *&t, char *exp) {
	BTNode *St[MaxSize], *p;
	int top = -1;
	int k, j = 0;
	char ch;
	t = NULL;
	ch = exp[j];
	for (j = 0; ch != '0'; j++) {
		switch (ch)
		{
		case'(':p = (BTNode*)malloc(sizeof(BTNode)); top++; St[top] = p; k = 1; break;
		case')':top--; break;
		case',':k = 2; break;
		default:p = (BTNode*)malloc(sizeof(BTNode));
			p->data = ch;
			p->lchild = p->rchild = NULL;
			if (t == NULL)
				t = p;
			else {
				switch (k) {
				case 1:St[top]->lchild = p; break;
				case 2:St[top]->rchild = p; break;
				}
			}
		}
	}
}
void PreOrde(BTNode *t) {
	BTNode *p;
	SqStack *st;
	InitStack(st);
	if (t != NULL) {
		Push(st, t);
		while (!StackEmpty(st)) {
			Pop(st, p);
			printf("%c", p->data);
			if (p->rchild != NULL)
				Push(st, p->rchild);
			if (p->lchild != NULL)
				Push(st, p->lchild);
		}
		printf("\n");
	}
	DestroyStack(st);
	}

int main() {
	BTNode *t;
	SqStack *st;
	char *exp;
	CreatBTree(t, "A(B(C,D),E)");
	printf("\n该二叉树的前缀表达式为：");
	PreOrde(t);
	return 1;
}