#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
int main()
{
  int *a = NULL, i = 0, elem;
  char c;
  do {
    printf("a[%d]= ", i);
    scanf("%d", &elem);
    a = (int*)realloc(a, (i + 1) * sizeof(int));
    a[i] = elem;
    i++;
    getchar();
    printf("Next (y/n)? ");
    c = getchar();
  } while (c == 'y');
  for (int j = 0; j < i; j++)
    printf("%d ", a[j]);
  if (i>2) i -= 2;
  printf("\n");
  a = (int*)realloc(a, i * sizeof(int)); // уменьшение размера массива на 2
  for (int j = 0; j < i; j++)
    printf("%d ", a[j]);
  getchar(); getchar();
  return 0;
}