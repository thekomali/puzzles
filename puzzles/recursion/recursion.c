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