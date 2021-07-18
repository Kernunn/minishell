#	ifndef RUN_EXTERNAL_EXTRA_H
#	define RUN_EXTERNAL_EXTRA_H

int file_is_exist(char *pathname);
void free_array(char **array);
char **find_path_var(void);
char *find_path(char **array, char *name);

#	endif
