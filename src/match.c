char *ft_run_stars(char *str) {
  while (*str == '*')
	str++;
  return (str);
}

void ft_increase_for_one(char **src, char **to_find) {
  *src = *src + 1;
  *to_find = *to_find + 1;
}

void ft_thefirst_element_is_star(char **src, char **to_find) {
  char *last_element_after_star;

  last_element_after_star = *to_find;
  while (**src != '\0' && **to_find != '\0') {
	*to_find = ft_run_stars(*to_find);
	last_element_after_star = *to_find;
	while (**src != **to_find && **src != '\0')
	  *src = *src + 1;
	while (**to_find == **src && **src != '\0')
	  ft_increase_for_one(src, to_find);
	if (**to_find != '*' && **src != '\0') {
	  *to_find = last_element_after_star;
	  while (**src != **to_find && **src != '\0')
		*src = *src + 1;
	}
  }
}

int match(char *src, char *to_find) {
  while (*src != '\0' && *to_find != '\0') {
	if (*to_find == '*')
	  ft_thefirst_element_is_star(&src, &to_find);
	else {
	  while (*to_find == *src && *to_find != '\0' && *to_find != '*')
		ft_increase_for_one(&src, &to_find);
	  if (*to_find != *src && *to_find != '\0' && *to_find != '*')
		return (0);
	}
  }
  to_find = ft_run_stars(to_find);
  if (*src == '\0' && *to_find == '\0')
	return (1);
  return (0);
}
