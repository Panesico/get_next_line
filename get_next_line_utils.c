#include "get_next_line.h"

unsigned int	ft_read(t_fd_str *fd)
{
	char	c;
	static int	i;

	i = 0;
	while(i < BUFFER_SIZE && read(fd->fd, &c, 1))
	{
		if(c == '\n')
		{
			fd->str[i++] = c;
			fd->str[i++] = '\0';
			return (1);
		}
		else
			fd->str[i++] = c;
	}
	if(fd->str[0])
		return(fd->str[i] = 0, 1);
	return (0);
}

t_fd_str	*ft_new_fd(int filed)
{
	t_fd_str	*fd_struct;

	fd_struct = (t_fd_str *)malloc(sizeof(t_fd_str));
	fd_struct->fd = filed;
	fd_struct->str = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);

	return (fd_struct);
}

void	ft_free_fd_struct(t_fd_str	*fd_struct)
{
	free(fd_struct);
}
