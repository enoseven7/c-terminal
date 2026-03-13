#include "eno.h"

// cd, cd [path], cd - (previous dir), cd ~ (home dir), handle non existing dirs, permission issues
int command_cd(char **args, char *init_dir)
{
    (void) init_dir;
    if(args[1] == NULL)
    {
        printf("cd: expected argument \"cd [path]\"\n");
    } else if (chdir(args[1]) == 0 )
    {
        printf("CD worked\n");
    } else
    {
        perror("CD");
    }

    return 0;
}
int command_pwd()
{
    char cwd[MAX_PATH];
    getcwd(cwd, sizeof(cwd));
    printf("%s\n", cwd);
    return 0;
}
int command_echo(char** args, char** env);
int command_env(char **env);
int command_which(char **args, char **env);
