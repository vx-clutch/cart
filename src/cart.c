#include "util.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int init();
int run();
int help();

int main(int argc, char **argv) {
  if (argc < 2)
    help();
  if (strcmp(argv[1], "init")) {
    if (argc < 3)
      help();
    init();
  } else if (strcmp(argv[1], "run"))
    run();
  return 0;
}

int help() {
  printf("Usage: cart [verb] [noun]\n\n");
  printf("Options:\n");
  printf("  init\t\tInitialize new project, has argument `name`\n");
  printf("  run\t\tRun the current project, takes no arguments\n");
  exit(0);
}

int init() {
  cprintf(error, "not impl");
  return 0;
}

int run() {
  cprintf(error, "not impl");
  return 0;
}
