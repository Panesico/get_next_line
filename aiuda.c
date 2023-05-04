# include <unistd.h>
# include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 6
# endif

unsigned int	ft_read(int fd);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_buffer(char *str, int boole);
char			*ft_strdup(const char *s);
size_t			ft_strlen(const char *str);
char			*ft_strchr(const char *str, int c);
void			*ft_calloc(size_t count, size_t size);

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	while (i < count * size)
	{
		((char *)ptr)[i] = 0;
		i++;
	}
	return (ptr);
}

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*str;

	str = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!str)
		return (0);
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	size_t	i;

	if(!str)
		return (0);
	i = -1;
	while (str[++i])
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
	}
	if (str[i] == (char)c)
		return ((char *)&str[i]);
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	s1_len;
	size_t	s2_len;
	char	*str;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!str)
		return (0);
	i = 0;
	j = 0;
	while (j < s1_len && s1[j])
		str[i++] = s1[j++];
	j = 0;
	while (j < (s1_len + s2_len) && s2[j] && s2[j] != '\n')
		str[i++] = s2[j++];
	if (s2[j] == '\n')
		str[i++] = s2[j++];
	str[i] = 0;
	return (str);
}
char	*ft_buffer(char *str, int boole)
{
	static char	*str2;
	char		*temp;
	static int	boolea;

	if (!boole)
		return (0);
	if (boole == 2)
	{
		str2 = ft_strdup(str);
		boolea = 1;
		return (0);
	}
	if (boole == 1)
		return (str2);
	if(boolea--)
	{
		temp = ft_strjoin(str2, str);
		free(str2);
		return(str2 = temp);
	}
	str2 = ft_strjoin(str2, str);
	return (str2);
}

unsigned int	ft_read(int fd)
{
	char		*str;
	static int	i;

	str = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	i = 0;
	while(!ft_strchr(ft_buffer(str, i), '\n'))
	{
		if(!(read(fd, str, BUFFER_SIZE)))
			break ;
		str[BUFFER_SIZE] = 0;
		if(!i)
		{
			ft_buffer(str, 2);
			i++;
		}
		else
			ft_buffer(str, 3);
	}
	if(str[0])
		return(1);
	return (0);
}

char *ft_get_next_line(int fd)
{
	char		*str;

	if(fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if(!ft_read(fd))
		return (0);
	str = ft_buffer(0, 1);
	return (str);
}

int main()
{
	int i = open("hola", 0);
	int j = 3;
	while(j--)
		printf(ft_get_next_line(i));
}