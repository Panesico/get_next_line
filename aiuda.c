#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "stdio.h"


# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

typedef struct s_fd_str
{
	char	*str;
	int 	fd;
}	t_fd_str;


unsigned int	ft_read(t_fd_str *fd);
t_fd_str	*ft_new_fd(int filed);
void	ft_free_fd_struct(t_fd_str	*fd_struct);

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

int main()
{
	int i = 0;
	int fd = open("hola", 0);
	while(i++ != 10)
		printf("%s", ft_get_next_line(fd));
}