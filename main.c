#include "eno.h"
// shell loop
// input parsing
// command execution exp, cd, pwd, echo, env, setenv, unsetenv, which, exit
// execute external commands
// manage environment variables
// manage path
// error handling
//
//

void shell_loop(char** env)
{

  char* input = NULL;
  size_t input_size = 0;

  char** args;

  while(1)
  {
    printf("eno>");
    if(getline(&input, &input_size, stdin) == -1) // end of the file, ctrl + d
    {
      perror("getline"); 
      break;
    }
    // printf("Input: %s", input);
    
    args = parse_input(input);
  }
}

int main (int argc, char** argv, char** env)
{

  shell_loop(env);

  return 0;
}
