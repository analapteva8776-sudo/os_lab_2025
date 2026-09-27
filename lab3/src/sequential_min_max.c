#include <stdio.h>
#include <stdlib.h>

#include "find_min_max.h"
#include "utils.h"

int main(int argc, char **argv) {
  if (argc != 3) {
    printf("Usage: %s seed arraysize\n", argv[0]);
    return 1;
  }

  int seed = atoi(argv[1]);
  // Генератор rand() может принимать любые seed, но обычно проверяют на положительность
  // Если seed = 0, rand() будет выдавать одинаковые числа, это допустимо.
  // Проверка seed <= 0 может быть избыточной, если только это не требование задания.
  // Оставим проверку, но уточним, что seed может быть 0.
  if (seed < 0) {
    printf("seed must be non-negative\n");
    return 1;
  }

  int array_size = atoi(argv[2]);
  if (array_size <= 0) {
    printf("array_size is a positive number\n");
    return 1;
  }

  int *array = malloc(array_size * sizeof(int));
  if (array == NULL) {
      printf("Memory allocation failed\n");
      return 1;
  }

  GenerateArray(array, array_size, seed);
  
  // ВЫЗОВ ФУНКЦИИ, КОТОРОЙ НЕ БЫЛО В ИСХОДНИКЕ
  struct MinMax min_max = GetMinMax(array, 0, array_size);
  
  free(array);

  printf("min: %d\n", min_max.min);
  printf("max: %d\n", min_max.max);

  return 0;
}