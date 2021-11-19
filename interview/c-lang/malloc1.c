#include <stdio.h>
#include <stdlib.h>

int main() {
  long long int large = 1099511627776;
  char *buffer = (char *)malloc(large);
  if (buffer == NULL) {
    printf("error!\n");
    return EXIT_FAILURE;
  }
  printf("Memory allocated\n");
  for (size_t i = 0; i < large; i += 4096) {
    buffer[i] = 0;
  }
  free(buffer);
  printf("Done finally\n");
  return EXIT_SUCCESS;
}