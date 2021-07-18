#ifndef FT_ENV_H
# define FT_ENV_H

void ft_add_env(char *key, char *var);
void ft_change_env(char *key, char *var);
char *ft_var_of_key(char *key);
void ft_add_key_to_export(char *key);

#endif
