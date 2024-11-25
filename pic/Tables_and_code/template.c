#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct record {
  void* cont;
  struct environment* env;
  unsigned char* read;
  unsigned char* write;
  int index;
  unsigned char polarity;
};

struct task {
  void* cont;
  struct environment* env;
  struct task* next;
};

struct environment {
  struct environment* parent;
};

#define ENV_RECORD(env, i) (*(struct record**)(((unsigned char*)env) + sizeof(struct environment) + sizeof(struct record*) * i))

int main() {
  struct record* tmp_session;
  struct environment* env = NULL, * tmp_env;
  void* tmp_cont;
  struct task* next_task = malloc(sizeof(struct task)), * tmp_task;
  next_task->cont = &&end;

  goto run;

  /*... PROCESS DEFINITIONS ...*/

run:
  env = malloc(sizeof(struct environment) +
               sizeof(struct record*) * /*... ENTRY PROCESS RECORD COUNT ...*/);
  goto proc_main;
end:
  return 0;
}
