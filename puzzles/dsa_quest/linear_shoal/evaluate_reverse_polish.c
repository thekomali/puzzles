// problem -> https://leetcode.com/problems/evaluate-reverse-polish-notation/description/

// time complexity -> O(N)
// space complexity -> O(N)

// DEFINING STACK
typedef struct {
  int info[10000];
  int top;
} stack_t;


stack_t* sinit() {
  stack_t *s = malloc(sizeof(stack_t));
  if (!s) return NULL;

  s->top = -1;
  return s;
}


void spush(stack_t *s, int val) {
  // overflow
  if (s->top >= 10000) return;

  s->info[++s->top] = val;
}


int spop(stack_t *s) {
  // underflow
  if (s->top <= -1) return -1;

  return s->info[s->top--];
}


int operation(int v1, int v2, char *oper) {
  switch(oper[0]) {
    case '+': return v1 + v2;
    case '-': return v1 - v2;
    case '*': return v1 * v2;
    case '/': return v1 / v2;
  }
  return -1;
}


bool is_oper(char *oper) {
  // strlen is verified to handle the negative numbers which will considered as operators
  return (strlen(oper) == 1 && (oper[0] == '+' || oper[0] == '-' || oper[0] == '*' || oper[0] == '/'));
}








int evalRPN(char** tokens, int tokensSize) {
  // initialize the stack
  stack_t *s = sinit();
  if (!s) return -1;

  for (int t = 0; t < tokensSize; t++) {
    // if not a operator, then push the value to stack
    if (!is_oper(tokens[t])) {
      spush(s, atoi(tokens[t]));
    }
    else {
      // if operator, then do the evaluation
      int oper2 = spop(s);
      int oper1 = spop(s);
      spush(s, operation(oper1, oper2, tokens[t]));
    }
  }

  return spop(s);    
}