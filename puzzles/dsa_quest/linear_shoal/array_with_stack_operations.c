// problem ->

// time complexity  -> O(T)   ; size of target
// space complexity -> O(T)

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** buildArray(int* target, int targetSize, int n, int* returnSize) {
  // array to hold operations name (hold 100 strings each of size 5)
  char **oper = malloc(sizeof(char *) * 200);
  for (int i = 0; i < 200; i++)
    oper[i] = malloc(5 * sizeof(char));

  int t = 0;    // index for looping through target array
  int s = 1;    // series integer
  int op = 0;   // count the operations added

  while (t < targetSize) {
    if (target[t] == s) {
      strcpy(oper[op++], "Push");
      t++;
    }
    else {
      // if the value is not present in target array, so we need to
      // push and pop the element in stack
      strcpy(oper[op++], "Push");
      strcpy(oper[op++], "Pop");
    }

    s++;

  }

  *returnSize = op;
  return oper;
}