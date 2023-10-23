![Banner](https://github.com/byaliego/42-project-badges/blob/main/covers/cover-get_next_line-bonus.png?raw=true)

## About

> A simple function that returns the next line of a file.

### How to include

> Inside your makefile include the following rule:

```
GET_NEXT_LINE_SRC	= get_next_line.c get_next_line_utils.c
GET_NEXT_LINE_OBJ	= ${GET_NEXT_LINE_SRC:.c=.o}

$(DO_GNL): $(GET_NEXT_LINE_OBJ)
	@ar -rcs get_next_line.a $(GET_NEXT_LINE_OBJ)
  
```

Then, include the compiled library into the compiler line.

example: gcc main.c get_next_line.a

## Usage

```
int fd = open("./File_Path");

char *string = get_next_line(fd);
  
```
