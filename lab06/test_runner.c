#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define LINE_SIZE 256
#define MAX_ARGS 20

int main(void)
{
  FILE *file;
  char line[LINE_SIZE];
  char *args[MAX_ARGS];
  char *word;

  int count;
  int i;
  int total = 0;
  int passed = 0;
  int failed = 0;
  int status;

  pid_t pid;


  // Test Plan
  file = fopen("tests.txt", "r");

  if (file == NULL)
    {
     perror("fopen");
     return 1;
    }

  // Read Each Command
  while (fgets(line, LINE_SIZE, file) != NULL)
    {

  // Remove New Line
    
    i = 0;
    while (line[i] != '\0')
    {
      if (line[i] == '\n')
        {
          line[i] = '\0';
          break;

        }
      i++;
    } 


  //  Seperate Into Arguments
  word = strtok(line, " \t");

  //  Skip Blank Lines
  if (word == NULL || word[0] == '#')
    {
      continue;
    }

  count = 0; 
  
  while (word != NULL && count < MAX_ARGS - 1)          // Check for More Words
    {
      args[count] = word;
      count++;
      word = strtok(NULL, " \t");       // Next Word
    }

  args[count] = NULL;

  // Display Test Command
  printf("\nTest: ");
  
  for (i = 0; i < count; i++)
    {
      printf("%s ", args[i]);
    }

  printf("\n Starting Test...\n");
  total++;

  // Create Child Process
  pid = fork();

  if (pid < 0)      // Check If this Fails
    {
      perror("fork");
      failed++;
      printf("Result: FAIL\n");
      continue;
    }
  else if (pid == 0) {
      execvp(args[0], args);      //  Execute Test Command
      
      perror("execvp");     // If execvp Fails
      _exit(1);      // Exit with error Status
  }else{ // When succeeds
      if (wait(&status) == -1)                      // Parent waits for Child Process
        {
          perror("wait");         // Run one, then next, not all 5 at once
          failed++;
          printf("Result: FAIL\n");
        }
  else if (WIFEXITED(status) && WEXITSTATUS(status) == 0)        // If BOTH return 0 (Success)
    { 
      passed++;
      printf("Result: PASS\n");
    }
  else
    {
      failed++;
      printf("Result: FAIL\n");
    }
  }
}

// Close Testing file
fclose(file);

// Display Results
printf("\n===========================\n");
printf("TEST SUMMARY\n");
printf("============================\n");
printf("Tests executed: %d\n", total);
printf("Tests passed: %d\n", passed);
printf("Tests Failed: %d\n", failed);

return 0;
}

