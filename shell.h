#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

#define BUFFER_SIZE 1024
#define PATH_MAX 4096

extern char **environ;

size_t _strlen(const char *str);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);

bool handle_biultins(char *cmd, char *param);
int _strcmp(char *fstr, char *sstr);
void exit_shell(const char *code);
char **split_cmd(char *command);
void _execute(char **argv, char **envp);
char *_strcat(char *first, char *second);
char *file_check(char *command);
char *_strchr(const char *str, int target);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
int _atoi(const char *str);
char *_strtok(char *str, char *del);
char *search_in_path(char *command);

/* cd functions */
bool change_directory(const char *dir);
bool change_directory_previous(void);
bool change_directory_home(void);
bool change_directory_path(const char *dir);

/* handle prompt */
char *set_prompt();
bool is_pipeline_command(const char *cmd);
void isatty_check(void);

/*biultins functions */
void _setenv(char *variable, char *value);
void remove_comment(char *lineptr);
bool is_empty_line(char *lineptr);
void clean_lineptr(char **ptr);

#endif
