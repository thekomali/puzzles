#include <stdio.h>
#include <stdbool.h>
#include <string.h>


void print(char *str, int freq);
void print_2_n(int n);
void print_n_1(int n);
int sum_of_n(int num);
int factorial(int num);
int sum_of_digits(int num);
void reverse_array(int *arr, int left, int right);
bool is_palindrome(char *str, int left, int right);
void base_conversion(int num, int base);
void prime_factorization(int num);
int gcd(int num1, int num2);
void print_fibonacci_terms(int terms, int n1, int n2);
int nth_fibonacci_term(int n);




// EVERYTHING STARTS HERE
int main() {
  // 01. Print n times using recursion
  print("Lakshadweep Kuttan", 5);


  // 02. Print 1 -> N using recursion
  print_2_n(5);
  printf("\n");


  // 03. Print N -> 1 using recursion
  print_n_1(5);
  printf("\n");


  // 04. sum of n numbers
  printf("sum(%d) = %d \n", 5, sum_of_n(5));


  // 05. Find factorial
  printf("%d! = %d \n", 5, factorial(5));


  // 06. Sum of digits
  printf("sum_of_digits(%d) = %d \n", 12345, sum_of_digits(12345));


  // 07. reverse the array
  int arr[] = {1, 2, 3, 4, 5, 6};

  printf("array entries -> ");
  for (int i = 0; i < 6; i++) printf("%d, ", arr[i]);

  reverse_array(arr, 0, 5);

  printf("\nreversed array entries -> ");
  for (int i = 0; i < 6; i++) printf("%d, ", arr[i]);
  printf("\n");


  // 08. is palindrome
  printf("is_palindrome(\"%s\") -> %d \n", "momm", is_palindrome("momm", 0, 3));


  // 09. Base conversion :: convert decimal number -> hex, octal or binary
  printf("%d to base(%d) = ", 999, 16);
  base_conversion(999, 16);
  printf("\n");


  // 10. Prime factorization
  printf("prime factors of %d => ", 84);
  prime_factorization(84);
  printf("\n");


  // 11. Greatest common divisor
  printf("GCD of %d, %d -> %d\n", 117, 54, gcd(117, 54));


  // 12. Print Fibonacci series for n terms
  printf("Fibonacci series (%d terms) -> 1, ", 10);
  print_fibonacci_terms(10, 1, 1);
  printf("\n");


  // 13. Nth Fibonacci term
  printf("%dth fibonacci term = %d \n", 5, nth_fibonacci_term(5));


  // 14. Tower of Hanoi


  return 0;
}




/* --------- 01 ------------- */
void print(char *str, int freq) {
  // base condition
  if (freq == 0)
    return;
  
  printf("%s \n", str);

  print(str, freq-1);
}


/* --------- 02 ------------- */
void print_2_n(int n) {
  if (n == 0)
    return;
  
  // recursive call
  print_2_n(n - 1);

  // printing will happen in unwinding phase
  printf("%d, ", n);
}


/* --------- 03 ------------- */
void print_n_1(int n) {
  if (n == 0)
    return;

  // printing will happen in winding phase
  printf("%d, ", n);
  
  // recursive call
  print_n_1(n - 1);
}


/* --------- 04 ------------- */
int sum_of_n(int num) {
  // base condition
  if (num == 1)
    return 1;
  
  return sum_of_n(num - 1) + num;
}


/* --------- 05 ------------- */
int factorial(int num) {
  // base condition
  if (num == 1) 
    return num;

  return factorial(num - 1) * num;
}


/* --------- 06 ------------- */
int sum_of_digits(int num) {
  // base condition
  if (num == 0)
    return num;

  // get the last digit and do recursive call by 
  // passing num with last digit removed
  return (num % 10) + sum_of_digits(num / 10);
}


/* --------- 07 ------------- */
void reverse_array(int *arr, int left, int right) {
  if (left >= right)
    return;

  // let's swap the elements (happens at winding phase)
  int tmp    = arr[left];
  arr[left]  = arr[right];
  arr[right] = tmp;

  reverse_array(arr, left + 1, right - 1);
}



/* --------- 08 ------------- */
bool is_palindrome(char *str, int left, int right) {
  // base condition -> if left becomes greater, then the string is same
  if (left >= right)
    return true;

  // check happens are winding phase
  if (str[left] != str[right])
    return false;

  return is_palindrome(str, left + 1, right - 1);
}



/* --------- 09 ------------- */
// to convert a decimal to any base system, divide the decimal number with the 
// base value until the decimal value reaches zero, then print the reminder
// backwards
void base_conversion(int num, int base) {
  if (num == 0)
    return;

  int rem = num % base;
  base_conversion(num/base, base);

  // printing happens at unwinding phase
  // as we want to print from the last reminder towards first reminder
  if (rem > 9)
    printf("%c", 'A' + (rem - 10));
  else
    printf("%d", rem);
}



/* --------- 10 ------------- */
// find prime factors of - 84
// 84 % 2 == 0, num = 84/2 :: factor = 2
// 42 % 2 == 0, num = 42/2 :: factor = 2
// 21 % 2 != 0
// 21 % 3 == 0, num = 21/3 :: factor = 3
// 7 % 2 != 0
// 7 % 3 != 0
// 7 % 7 == 0, num = 7/7  :: factor = 7
// num == 1 <--- base condition reached, end of recursion
void prime_factorization(int num) {
  if (num == 1)
    return;
  
  // let's start with the first prime number
  int factor = 2;

  // loop until found the factor that divides the num
  while (num % factor != 0)
    factor++;
 
  printf("%d, ", factor);
  
  // on finding the factor, the problem reduces by reducing the num
  prime_factorization(num / factor);
}



/* --------- 11 ------------- */
// Euclid's Remainder Algorithm
int gcd(int num1, int num2) {
  if (num2 == 0)
    return num1;
  
  return gcd(num2, num1 % num2);
}



/* --------- 12 ------------- */
void print_fibonacci_terms(int terms, int n1, int n2) {
  if (terms == 1)
    return;
  
  printf("%d, ", n1);

  print_fibonacci_terms(--terms, n1 + n2, n1);
}



/* --------- 13 ------------- */
int nth_fibonacci_term(int n) {
  if (n == 1 || n == 0)
    return 1;
  
  return nth_fibonacci_term(n - 1) + nth_fibonacci_term(n - 2);
}