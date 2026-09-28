#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char **argv) {
  // Проверяем, что переданы два аргумента: seed и array_size
  if (argc != 3) {
    printf("Usage: %s seed array_size\n", argv[0]);
    printf("Example: %s 42 1000\n", argv[0]);
    return 1;
  }

  pid_t pid = fork();

  if (pid < 0) {
    // Ошибка fork
    perror("fork failed");
    return 1;
  }

  if (pid == 0) {
    // Дочерний процесс
    // Заменяем себя на sequential_min_max
    // Аргументы: argv[0] — имя программы, argv[1] — seed, argv[2] — array_size
    execl("./sequential_min_max", "sequential_min_max", argv[1], argv[2], NULL);

    // Если execl вернул управление — значит, произошла ошибка
    perror("execl failed");
    exit(1);
  } else {
    // Родительский процесс
    int status;
    wait(&status);

    if (WIFEXITED(status)) {
      int exit_code = WEXITSTATUS(status);
      printf("Дочерний процесс завершился с кодом: %d\n", exit_code);
      return exit_code;
    } else {
      printf("Дочерний процесс завершился аварийно\n");
      return 1;
    }
  }

  return 0;
}
