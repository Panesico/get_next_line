#include "get_next_line.h"

char *ft_get_next_line(int fd)
{
	char		*str;
	t_fd_str	*fd_struct;

	if(fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	fd_struct = ft_new_fd(fd);
	ft_read(fd_struct);
	str = fd_struct->str;
	return (str);
}