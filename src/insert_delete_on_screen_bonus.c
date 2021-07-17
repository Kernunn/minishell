#include <term.h>
#include "libft.h"
#include "ft_putint_bonus.h"
#include <unistd.h>
#include <stdlib.h>

void	backspace_ch_on_screen(void)
{
	char	buf[100];
	char	*buffer;
	char	*cap;
	char	*str;

	buffer = buf;
	if ((cap = tgetstr("le", &buffer)) == NULL)
		exit(1);
	if ((str = tgoto(cap, 0, 0)) == NULL)
		exit(1);
	if ((tputs(str, 1, ft_putint)) == -1)
		exit(1);
	buffer = buf;
	ft_bzero(buffer, 100);
	if ((cap = tgetstr("DC", &buffer)) == NULL)
		exit(1);
	if ((str = tgoto(cap, 0, 1)) == NULL)
		exit(1);
	if ((tputs(str, 1, ft_putint)) == -1)
		exit(1);
}

void	delete_ch_on_screen(void)
{
	char	buf[100];
	char	*buffer;
	char	*cap;
	char	*str;

	buffer = buf;
	if ((cap = tgetstr("DC", &buffer)) == NULL)
		exit(1);
	if ((str = tgoto(cap, 0, 1)) == NULL)
		exit(1);
	if ((tputs(str, 1, ft_putint)) == -1)
		exit(1);
}

void	insert_ch_on_screen(char c)
{
	char	buf[100];
	char	*buffer;
	char	*cap;
	char	*str;

	buffer = buf;
	if ((cap = tgetstr("IC", &buffer)) == NULL)
		exit(1);
	if ((str = tgoto(cap, 0, 1)) == NULL)
		exit(1);
	if ((tputs(str, 1, ft_putint)) == -1)
		exit(1);
	write(2, &c, 1);
}

void	insert_line_on_screen(char *line)
{
	char	buf[100];
	char	*buffer;
	char	*cap;
	char	*str;

	buffer = buf;
	if ((cap = tgetstr("IC", &buffer)) == NULL)
		exit(1);
	if ((str = tgoto(cap, 0, ft_strlen(line))) == NULL)
		exit(1);
	if ((tputs(str, 1, ft_putint)) == -1)
		exit(1);
	ft_putstr_fd(line, 2);
}

void	delete_line_on_screen(int len)
{
	char	buf[100];
	char	*buffer;
	char	*cap;
	char	*str;

	buffer = buf;
	if ((cap = tgetstr("rc", &buffer)) == NULL)
		exit(1);
	if ((str = tgoto(cap, 0, 0)) == NULL)
		exit(1);
	if ((tputs(str, 1, ft_putint)) == -1)
		exit(1);
	buffer = buf;
	ft_bzero(buffer, 100);
	if ((cap = tgetstr("DC", &buffer)) == NULL)
		exit(1);
	if ((str = tgoto(cap, 0, len)) == NULL)
		exit(1);
	if ((tputs(str, 1, ft_putint)) == -1)
		exit(1);
}
