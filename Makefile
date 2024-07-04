# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilastra- <ilastra-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/09 08:55:25 by ilastra-          #+#    #+#              #
#    Updated: 2024/05/23 11:10:31 by ilastra-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
# VARIABLES                                                                    #
# NAME: Define el nombre de la biblioteca que se creará (libft.a).             #
NAME = libft.a
# CC: Especifica el compilador a usar (gcc).                                   #
CC = gcc
# CCFLAGS: Define las opciones del compilador (-Wall -Wextra -Werror).         #
CCFLAGS = -Wall -Wextra -Werror
# RM: Comando para eliminar archivos (rm -rf).                                 #
RM = rm -rf
# AR: La acción @ar crs el comando ar para crear un archivo de biblioteca      #
#     estática (lib.a) con los archivos objeto especificados.                  #
AR = ar crs
# SRCS: Lista los archivos fuente (.c) que forman parte de la biblioteca.      #
SRCS = 	ft_atoi.c\
	ft_bzero.c\
	ft_calloc.c\
	ft_isalnum.c\
	ft_isalpha.c\
	ft_isascii.c\
	ft_isdigit.c\
	ft_isprint.c\
	ft_itoa.c\
	ft_memchr.c\
	ft_memcmp.c\
	ft_memcpy.c\
	ft_memmove.c\
	ft_memset.c\
	ft_putchar_fd.c\
	ft_putendl_fd.c\
	ft_putnbr_fd.c\
	ft_putstr_fd.c\
	ft_split.c\
	ft_strchr.c\
	ft_strdup.c\
	ft_striteri.c\
	ft_strjoin.c\
	ft_strlcat.c\
	ft_strlcpy.c\
	ft_strlen.c\
	ft_strmapi.c\
	ft_strncmp.c\
	ft_strnstr.c\
	ft_strrchr.c\
	ft_strtrim.c\
	ft_substr.c\
	ft_tolower.c\
	ft_toupper.c
# SRCSB: Lista de archivos fuente (.c) para las funciones adicionales (bonus)  #
#       de la biblioteca.		                                               #
SRCSB =	ft_lstadd_back_bonus.c\
	ft_lstadd_front_bonus.c\
	ft_lstclear_bonus.c\
	ft_lstdelone_bonus.c\
	ft_lstiter_bonus.c\
	ft_lstlast_bonus.c\
	ft_lstlast_bonus.c\
	ft_lstmap_bonus.c\
	ft_lstnew_bonus.c\
	ft_lstsize_bonus.c\
# OBJS: Variable que genera una lista de archivos objeto (.o)                  #
#       a partir de los archivos fuente (.c).                                  #
OBJS = $(SRCS:.c=.o)
# OBJSB: Variable que genera una lista de archivos objeto (.o)                 #
#       a partir de los archivos fuente (.c).                                  #
OBJSB = $(SRCSB:.c=.o)
# COLORS: Definen secuencias de escape ANSI para colores en la terminal        #
# DEF_COLOR = \033[0;39m
# GRAY = \033[0;90m
# RED = \033[0;91m
# GREEN = \033[0;92m
# YELLOW = \033[0;93m
# BLUE = \033[0;94m
# MAGENTA = \033[0;95m
# CYAN = \033[0;96m
# WHITE = \033[0;97m
# **************************************************************************** #

# **************************************************************************** #
# REGLAS                                                                       #
# .DEFAULT_GOAL := all
# %.o : %.c: Esta regla indica cómo compilar cada archivo fuente (.c)          #
#            en un archivo objeto (.o).                                        #
#            La acción @$(CC) $(CCFLAGS) -c -o $@ $< utiliza el compilador gcc #
#            con las opciones -Wall -Wextra -Werror para compilar el archivo   #
#            fuente ($<) y generar el archivo objeto ($@).                     #
%.o : %.c
	@$(CC) $(CCFLAGS) -c $^ -o $@
# $(NAME) : $(OBJS): Esta regla indica que para crear la biblioteca (libft.a), #
#           se necesitan los archivos objeto ($(OBJS) y $(OBJSB).              #
$(NAME) : $(OBJS)
	$(AR) $(NAME) $(OBJS)
# all: Esta regla es un alias para la regla $(NAME).                           #
#      Cuando se ejecuta make all, se crea la biblioteca.                      #
all: $(NAME)
# bonus: Compila las funciones adicionales de la biblioteca y las agrega a la  #
#        biblioteca principal ($(NAME)). También crea un archivo bonus para    #
#        indicar la compilación de las funciones adicionales.                  #
bonus: $(NAME) $(OBJSB)
	$(AR) $(NAME) $(OBJSB)
# clean: Esta regla elimina los archivos objeto (.o)                           #
#        generados durante la compilación.                                     #
clean:
	$(RM) -f $(OBJS) $(OBJSB)
# fclean: Esta regla elimina la biblioteca (libft.a)                           #
#         y los archivos objeto (.o).                                          #
fclean: clean
	$(RM) $(NAME) $(bonus)
# re: Esta regla es un alias para la secuencia fclean all.                     #
#     Cuando se ejecuta make re, se limpia la compilación anterior             #
#     y se crea la biblioteca nuevamente.                                      #
re: fclean all
# **************************************************************************** #

# **************************************************************************** #
# PSEUDO-OBJETIVOS                                                             #
# PHONY: Indica que all, clean, fclean y re son pseudo-objetivos,              #
#        no archivos reales.                                                   #
.PHONY: all bonus clean fclean re .c.o
# **************************************************************************** #
