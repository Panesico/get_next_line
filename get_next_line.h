#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

typedef struct s_fd_str
{
	char	*str;
	int 	fd;
}	t_fd_str;


unsigned int	ft_read(t_fd_str *fd);
t_fd_str		*ft_new_fd(int filed);
void			ft_free_fd_struct(t_fd_str	*fd_struct);

#endif
