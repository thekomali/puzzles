#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

int reverse_num(int num);
bool is_palindrome(char *str);
int hcf(int num1, int num2);
bool is_armstrong(int num);
void print_divisors(int num);
bool is_prime(int num);


int main() {
  // 1. Reverse a number
  printf("reversed(%d) -> %d\n", 12345, reverse_num(12345));

  // 2. Palindrome check
  printf("is_palindrome(%s) -> %s\n", "mom", is_palindrome("mom") ? "true" : "false");

  // 3. Highest Common Factor
  printf("HCF(%d, %d) = %d\n", 0, 20, hcf(0, 20));

  // 4. Armstrong number
  printf("is_armstrong(%d) = %d\n", 371, is_armstrong(371));

  // 5. Print all divisors
  printf("Divisors of %d = ", 36);
  print_divisors(36);

  // 6. Check from Prime
  printf("is_prime(%d) -> %d\n", 77, is_prime(77));

  return 0;
}


// time complexity  - O(log10 (num))  ; where log10 (num) -> gives no of digis in num 
// space complexity - O(1)
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


// time complexity  - O(N)
// space compelxity - O(1)
bool is_palindrome(char *str) {
  for (int l = 0, r = strlen(str) - 1; l < r; l++, r--) {
    if (str[l] != str[r]) 
      return false;
  }

  return true;
}


// time complexity  - O( log( min(num1, num2) ) )
// space compelxity - O(1)
int hcf(int num1, int num2) {
  /* EUCLIDEAN ALGORITHM
   * Example -> 117, 54
   * 
   * 117  54  |  117 - 54 = 63
   * 63   54  |  63 - 54 = 9
   * 54   9   |  54 - 9 = 45
   * 45   9   |  45 - 9 = 36
   * 36   9   |  36 - 9 = 27
   * 27   9   |  27 - 9 = 18
   * 18   9   |  18 - 9 = 9
   * 9    9   |  0
   * GCD = 9
   * 
   * USING DIVISION
   * 117  54  |  117 = 2 * 54  + 9
   * 54   9   |  54  = 6 * 9   + 0
   * GCD = 9
  */

  int divident, divisor;

  if (num1 == num2) return num1;

  if (num1 > num2) {
    divident = num1;
    divisor = num2;
  } else {
    divident = num2;
    divisor = num1;
  }

  while (divisor) {
    int rem = divident % divisor;

    divident = divisor;
    divisor = rem;
  }

  return divident;
}


// time complexity  - O(log10 (num))  ; where log10 (num) -> gives no of digis in num 
// space complexity - O(1)
bool is_armstrong(int num) {
  /* ARMSTRONG NUMER
  *  Example -> 153
  *  
  *  no of digits n = 3
  * 
  *  1^3 + 5^3 + 3^3 = 153 = number
  */
  int numcp = num;
  int digit, sum;

  while (numcp) {
    digit = numcp % 10;
    
    sum += (digit * digit * digit);
    numcp /= 10;
  }

  return sum == num;
}


// time complexity  - O(sqrt(N))
// space compelxity - O(1)
void print_divisors(int num) {
  int limit = sqrt(num);

  // check all the numbers till the square root value to get the divisors
  // for divisors higher than square root value, num / identified_divisor
  for (int n = 1; n <= limit; n++) {
    if (num % n == 0) {
      printf("%d, %d, ", n, num/n);
    }
  }
  printf("\b\b \n");    // to remove the extra ,
}


// time complexity  - O(sqrt(N))
// space compelxity - O(1)
bool is_prime(int num) {
  // verify if the number is divisible from 2 till the square root of the number
  // if no divisor found, then it's prime
  int limit =  sqrt(num);

  for (int i = 2; i <= limit; i++) {
    if (num % i == 0) return false;
  }

  return true;
}