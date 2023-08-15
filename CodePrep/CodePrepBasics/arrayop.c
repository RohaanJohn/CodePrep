// Noel John Robert
// lab exp no: 0
// array operations

#include <stdio.h>
#include <stdlib.h>
int max_size = 100; // maximum no. of elements in array
int arr[100];
int n;

int insertion(int item, int pos) {
  int i;
  if (n == max_size || pos > max_size) {
    printf("Insertion not possible");
    return 0;
  } else {
    for (i = n - 1; i >= pos - 1; i--)
      arr[i + 1] = arr[i];
    arr[pos - 1] = item;
    n++;
  }
  return 0;
}

void deletion(int item) {
  int count = 0;

  for (int i = 0; i < n; i++) {
    if (arr[i + count] == item) {
      count++;
      i--;
    }
    arr[i + 1] = arr[i + 1 + count];
  }
  n = n - count;
}

void display() {
  for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);
}

int main() {

  printf("How many elements do you want to input: ");
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  printf("1. Insert element\n");
  printf("2. Delete element\n");
  printf("3. Display array\n");

  char quit;
  do {
    int choice, pos, item;
    printf("Input your choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      printf("Input item to be inserted: ");
      scanf("%d", &item);
      printf("Position to insert item: ");
      scanf("%d", &pos);
      insertion(item, pos);
      break;

    case 2:
      printf("Input item to be deleted: ");
      scanf("%d", &item);
      deletion(item);
      break;

    case 3:
      display();
      break;

    default:
      printf("Wrong choice entered.");
    }
    printf("\nDo you want to continue?[Y/N]");
    scanf("%c", &quit); // this is temporary
    scanf("%c", &quit); // Y/y to continue, N/n to quit
    printf("\n\n");
  } while (quit == 'Y' || quit == 'y');

  return 0;
}
