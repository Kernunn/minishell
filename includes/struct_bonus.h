#	ifndef STRUCT_BONUS_H
#	define STRUCT_BONUS_H

typedef struct	s_buf
{
	char	*buffer;
	int		available_char;
	int		length;
	int		cur_pos;
	char	*history_str;
}				t_buf;

t_buf			*new_buffer(void);

#	endif
