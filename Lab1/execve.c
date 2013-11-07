#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	char **newargv;
	char *newenviron[] = {NULL};
    char delim[] = " \t";
    pid_t pid;
    int numtokens;

	if (argc != 2) {
		fprintf(stderr, "Usage: %s <file-to-exec>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if ((numtokens = makeargv(argv[1], delim, &newargv)) == -1) {
		fprintf(stderr, "Failed to construct an argument array for %s\n", argv[1]);
		return 1;
	}
	*newargv = argv[1];
    if (pid = fork()){ /* If fork() returns 0, I am the child */
      printf("I am the child process executing %s", newargv[0]);
	  execve(argv[1], newargv, newenviron);
	  perror("execve");	/* no return on error */
	  exit(EXIT_FAILURE);
    } else { /* if fork() didn't return 0, I am the parent */
      wait();
      printf("I am parent process %u; child process %u is running %s\n", getpid(), pid, *newargv);
      exit(EXIT_SUCCESS);
    }
}
