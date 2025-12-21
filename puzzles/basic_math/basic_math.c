#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int reverse_num(int);
bool is_palindrome(char *);


int main() {
  // 1. Reverse a number
  printf("reversed(%d) -> %d\n", 12345, reverse_num(12345));

  // 2. Palindrome check
  printf("is_palindrome(%s) -> %s\n", "mom", is_palindrome("mom") ? "true" : "false");

  // 3. Highest Common Factor

  // 4. Armstrong number

  // 5. Print all divisors

  // 6. Check from Prime

  return 0;
}


int reverse_num(int num) {
  if (num < 9) return num;

  // take the last digit (reminder operator)
  // remove the last digit (division operator)
  // multiply with 10 to increase the place value every time

  int reversed = 0;
  int tmp;

  while (num) {
    tmp = num % 10;
    reversed = (reversed * 10) + tmp;

    num /= 10;
  }

  return reversed;
} 


bool is_palindrome(char *str) {
  for (int l = 0, r = strlen(str) - 1; l < r; l++, r--) {
    if (str[l] != str[r]) 
      return false;
  }

  return true;
}