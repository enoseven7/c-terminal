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
    char* cwd = NULL;

    //use dynamic allocation
    cwd = getcwd(NULL, 0);
    if(cwd != NULL)
    {
        printf("%s\n", cwd);
        free(cwd);
    } else {
        perror("getcwd");
    }
    return 0;
}

//echo Hello World, echo -n Hello,echo $PATH
int command_echo(char** args, char** env)
{
    (void) env;
    int newline = 1; // default echo has newline
    size_t i = 1; //skipping the -n

    if(args[1] != NULL && my_strcmp(args[i], "-n") == 0 )
    {
        newline = 0;
        i++;
    }

    // process remaining args

    for(; args[i]; i++)
    {
        if(args[i][0] == '$')
        {
            char* value = getenv(args[i] + 1); //skip the $ and get var
            if (value)
            {
                printf("%s", value);
            } else {
                printf("");
            }
        } else {
            printf("%s", args[i]);
        }

        if(args[i + 1] != NULL)
        {
            printf(" ");
        }

    }

    if(newline == 1)
    {
        printf("\n");
    }
    return 0;
}
int command_env(char **env);
int command_which(char **args, char **env);
