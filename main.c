/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilastra- <ilastra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:48:02 by ilastra-          #+#    #+#             */
/*   Updated: 2024/05/27 14:59:46 by ilastra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <fcntl.h>

#define DEF_COLOR "\033[0;39m"
#define GRAY "\033[0;90m"
#define RED "\033[0;91m"
#define GREEN "\033[0;92m"
#define YELLOW "\033[0;93m"
#define BLUE "\033[0;94m"
#define MAGENTA "\033[0;95m"
#define CYAN "\033[0;96m"
#define WHITE "\033[0;97m"

const char* get_color(int value) {
    switch (value) {
        case 0:
            return GRAY;
        case 1:
            return RED;
        case 2:
            return GREEN;
        case 3:
            return YELLOW;
        case 4:
            return BLUE;
        case 5:
            return MAGENTA;
        case 6:
            return CYAN;
        case 7:
            return WHITE;												
        default:
            return DEF_COLOR;
    }
}

int check_norminette(const char *filename) {
    char buffer[128];
    FILE *pipe;
    int error_count = 0;
	const char *color;
	
    // Ejecuta norminette y abre una tubería para leer su salida
    char command[256];
    snprintf(command, sizeof(command), "norminette %s", filename);
    pipe = popen(command, "r");
    if (!pipe) {
        fprintf(stderr, "Error al ejecutar norminette.\n");
        return -1;
    }
	color = get_color(7);
    // Lee la salida de norminette línea por línea
    while (fgets(buffer, sizeof(buffer), pipe) != NULL) {
		if (strstr(buffer, ".c: OK!") != NULL) {
			color = get_color(2);
            printf("%s%s", color, buffer); // Imprime la salida de norminette para depuración
        }
		else
		{
			color = get_color(1);
            printf("%s%s", color, buffer);}
        

        // Cuenta los errores (esto es una simplificación; deberías ajustar esto según la salida real de norminette)
        if (strstr(buffer, "Error") != NULL) {
            error_count++;
        }
    }

    // Cierra la tubería
    if (pclose(pipe) == -1) {
        fprintf(stderr, "Error al cerrar la tubería.\n");
        return -1;
    }
	if (error_count > 1)
		error_count--;
    return error_count;
}

int	main(int argc, char **argv)
{
	char		*c;
	int			i;
	int 		result;
	int 		norminette;
	const char 	*color;
	char		*fn;
	char		bonus;

	
	if (argc < 1 && argc > 4)
	{
		printf("\033[0;91m\nError en el número de argumentos\n");
		printf("\033[0;92mPrueba con: ./main \"Tu Nombre\"\n\n");
		return (0);
	}
	color = get_color(6);
	printf("\033[H\033[J");
	printf("%s******************************************************\n", color);
	printf("%s***************MAIN COMPLETADO************************\n", color);
	printf("%s******************************************************\n", color);
	c = argv[1];
	if (argv[2] != NULL && argv[2][0] == 'n')
		bonus = 'n';
	else
		bonus = 's';		
	(void)bonus;	
	if (argv[3] != NULL)
		fn = argv[3];
	else
		fn = "X";

//ft_lstmap_bonus.c
//ft_lstiter_bonus.c
//ft_lstclear_bonus.c
//ft_lstdelone_bonus.c
//ft_lstadd_back_bonus.c
//ft_lstlast_bonus.c
//ft_lstsize_bonus.c
//ft_lstadd_front_bonus.c
//ft_lstnew_bonus.c
//ft_putnbr_fd.c
//ft_putendl_fd.c
//ft_putstr_fd.c
//ft_putchar_fd.c
//ft_striteri.c
//ft_strmapi.c
//ft_itoa.c
//ft_split.c
//ft_strtrim.c
//ft_strjoin.c
//ft_substr.c
//ft_strdup.c
//ft_calloc.c
//ft_atoi.c
//ft_strnstr.c
//ft_memcmp.c
//ft_memchr.c
//ft_strncmp.c
//ft_strrchr.c
//ft_strchr.c
//ft_tolower.c
//ft_toupper.c
//ft_strlcat.c
//ft_strlcpy.c
//ft_memmove.c
//ft_memcpy.c
	char src1[] = "Copio esta frase.";
	char dst1[30];
	i = 2;
	ft_memcpy(dst1,src1,strlen(src1) +1 );
	if (ft_strncmp(dst1, src1, strlen(src1)) != 0)
		i = 1;
	color = get_color(i);
	printf("%sft_memcpy  vs memcpy\n", color);		
	if (i == 1 || ft_strncmp(fn, "memcpy", 6) == 0)
	{		
		printf("%s\tft_memcpy Copio la memoria src1: \"%s\" en dst1: \"%s\"\n", color, src1, dst1);
		printf("%s\t   memcpy Copio el memoria src1: \"%s\" en dst1: \"%s\"\n", color, src1, dst1);
	}
//fn_bzero(c);
	char 	str10[100] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char 	str11[100] = "                    UVWXYZ";
	i = 2;
	ft_bzero(str10, 20);
	for (int j = 20; j < 100; j++) 
	{
		if (str10[j] != str11[j])
			i = 1;
	}  
	color = get_color(i);
	printf("%sft_bzero   vs bzero\n", color);	
	if (i == 1 || ft_strncmp(fn, "bzero", 5) == 0)
	{
		char str3[100] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		ft_bzero(str3, 20);
		printf("%s\tft_bzero ABCDEFGHIJKLMNOPQRSTUVWXYZ pasa a ser ", color);
		for (int j = 0; j < 100; j++) 
		{
			printf("%s%c", color, str3[j]);
		}
		printf("\n");
		char str4[100] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		ft_bzero(str4, 20);
		printf("%s\t   bzero ABCDEFGHIJKLMNOPQRSTUVWXYZ pasa a ser ", color);
		for (int j = 0; j < 100; j++) 
		{
			printf("%s%c", color, str4[j]);
		}
		printf("\n");
		printf("%s******************************************************\n", color);
	}
//fn_memset(c);	
	char 	str1[10] = "Hola Mundo";
	ft_memset(str1, 'X', 5);
	if (strstr(str1, "XXXXXMundo") == NULL)
		i = 1;
	else
		i = 2;
	color = get_color(i);
	printf("%sft_memset  vs memset\n", color);		
	if (i == 1)
	{
		char strA[10] = "Hola Mundo";
		ft_memset(strA, 'X', 5);
		printf("%s\tft_memset \"Hola Mundo\", 'X', 5 --> %s\n", color, strA);
		char strB[10] = "Hola Mundo";
		memset(strB, 'X', 5);	
		printf("%s\t   memset \"Hola Mundo\", 'X', 5 --> %s\n", color, strB);
		printf("%s******************************************************\n", color);
	}
//fn_strlen(c);	
	i = 1;
	if (ft_strlen("Hola Mundo") == 10)
		i = 2;
	color = get_color(i);
	printf("%sft_strlen  vs strlen\n", color);
	if (i == 1)
	{
		printf("%s\tft_strlen \"Hola Mundo\" --> %ld\n", color, ft_strlen("Hola Mundo"));	
		printf("%s\tstrlen \"Hola Mundo\" --> %ld\n", color, strlen("Hola Mundo"));
		printf("%s******************************************************\n", color);
	}	
//fn_isprint(c);	
	i = 1;
	if (ft_isprint('A') == 1 && ft_isprint('Z') == 1 
		&& ft_isprint('a') == 1 && ft_isprint('z') == 1 
		&& ft_isprint('0') == 1 && ft_isprint('9') == 1
		&& ft_isprint(0) == 0)
		i = 2;
	color = get_color(i);
	printf("%sft_isprint vs isprint\n", color);
	if (i == 1)
	{
		printf("%s\tft_isprint 'A' --> %d\n", color, ft_isprint('A'));	
		printf("%s\tft_isprint 'a' --> %d\n", color, ft_isprint('a'));	
		printf("%s\tft_isprint '0' --> %d\n", color, ft_isprint('0'));	
		printf("%s\tft_isprint NULL --> %d\n", color, ft_isprint(0));	
		printf("%s\tft_isprint '!' --> %d\n", color, ft_isprint('!'));
		printf("%s\tisprint 'A' --> %d\n", color, isprint('A'));	
		printf("%s\tisprint 'a' --> %d\n", color, isprint('a'));	
		printf("%s\tisprint '0' --> %d\n", color, isprint('0'));	
		printf("%s\tisprint NULL --> %d\n", color, isprint(0));	
		printf("%s\tisprint '!' --> %d\n", color, isprint('!'));
		printf("%s******************************************************\n", color);
	}	
//fn_isascii(c);
	i = 1;
	if (ft_isascii('A') == 1 && ft_isascii('Z') == 1 
		&& ft_isascii('a') == 1 && ft_isascii('z') == 1 
		&& ft_isascii('0') == 1 && ft_isascii('9') == 1
		&& ft_isascii(128) == 0)
		i = 2;
	color = get_color(i);
	printf("%sft_isascii vs isascii\n", color);
	if (i == 1 || ft_strncmp(fn, "isascii", 7) == 0)
	{
		printf("%s\tft_isascii 'A' --> %d\n", color, ft_isascii('A'));
		printf("%s\tft_isascii '0' --> %d\n", color, ft_isascii('0'));
		printf("%s\tft_isascii 128 --> %d\n", color, ft_isascii(128));
		printf("%s\tisascii 'A' --> %d\n", color, isascii('A'));
		printf("%s\tisascii '0' --> %d\n", color, isascii('0'));
		printf("%s\tisascii 128 --> %d\n", color, isascii(128));
		printf("%s******************************************************\n", color);
	}
//fn_isalnum(c);	
	i = 1;
	if (ft_isalnum('A') == 1 && ft_isalnum('Z') == 1 
		&& ft_isalnum('a') == 1 && ft_isalnum('z') == 1 
		&& ft_isalnum('0') == 1 && ft_isalnum('9') == 1
		&& ft_isalnum('+') == 0)
		i = 2;
	color = get_color(i);
	printf("%sft_isalnum vs isalnum\n", color);
	if (i == 1 || ft_strncmp(fn, "isalnum", 7) == 0)
	{	
		printf("%s\tft_isalnum 'A' --> %d\n", color, ft_isalnum('A'));	
		printf("%s\tft_isalnum 'Z' --> %d\n", color, ft_isalnum('Z'));
		printf("%s\tft_isalnum 'a' --> %d\n", color, ft_isalnum('a'));	
		printf("%s\tft_isalnum 'z' --> %d\n", color, ft_isalnum('z'));	
		printf("%s\tft_isalnum '0' --> %d\n", color, ft_isalnum('0'));
		printf("%s\tft_isalnum '9' --> %d\n", color, ft_isalnum('9'));
		printf("%s\tft_isalnum '+' --> %d\n", color, ft_isalnum('+'));
		printf("%s\tisalnum 'A' --> %d\n", color, isalnum('A'));	
		printf("%s\tisalnum 'Z' --> %d\n", color, isalnum('Z'));
		printf("%s\tisalnum 'a' --> %d\n", color, isalnum('a'));	
		printf("%s\tisalnum 'z' --> %d\n", color, isalnum('z'));	
		printf("%s\tisalnum '0' --> %d\n", color, isalnum('0'));
		printf("%s\tisalnum '9' --> %d\n", color, isalnum('9'));
		printf("%s\tisalnum '+' --> %d\n", color, isalnum('+'));
		printf("%s******************************************************\n", color);
	}	
//fn_isdigit(c);	
	i = 1;
	if (ft_isdigit('0') == 1 && ft_isdigit('9') == 1 && ft_isdigit('X') == 0)
		i = 2;
	color = get_color(i);
	printf("%sft_isdigit vs isdigit\n", color);
	if (i == 1 || ft_strncmp(fn, "isdigit", 7) == 0)
	{
		printf("%s\tft_isdigit 0 --> %d\n", color, ft_isdigit('0'));
		printf("%s\tft_isdigit 9 --> %d\n", color, ft_isdigit('9'));	
		printf("%s\tft_isdigit X --> %d\n", color, ft_isdigit('X'));	
		printf("%s\tisdigit 0 --> %d\n", color, isdigit('0'));
		printf("%s\tisdigit 9 --> %d\n", color, isdigit('9'));	
		printf("%s\tisdigit X --> %d\n", color, isdigit('X'));
		printf("%s******************************************************\n", color);		
	}
//fn_isalpha(c);
i = 1;
	if (ft_isalpha('A') == 1 && ft_isalpha('Z') == 1 
		&& ft_isalpha('a') == 1 && ft_isalpha('z') == 1 
		&& ft_isalpha('0') == 0)
		i = 2;
	color = get_color(i);
	printf("%sft_isalpha vs isalpha\n", color);
	if (i == 1 || ft_strncmp(fn, "isalpha", 7) == 0)
	{	
		printf("%s\tft_isalpha 'A' --> %d\n", color, ft_isalpha('A'));
		printf("%s\tft_isalpha 'Z' --> %d\n", color, ft_isalpha('Z'));	
		printf("%s\tft_isalpha 'a' --> %d\n", color, ft_isalpha('a'));		
		printf("%s\tft_isalpha 'z' --> %d\n", color, ft_isalpha('z'));
		printf("%s\tft_isalpha '0' %d\n", color, ft_isalpha('0'));	
		printf("%s\tisalpha 'A' --> %d\n", color, isalpha('A'));
		printf("%s\tisalpha 'Z' --> %d\n", color, isalpha('Z'));	
		printf("%s\tisalpha 'a' --> %d\n", color, isalpha('a'));		
		printf("%s\tisalpha 'z' --> %d\n", color, isalpha('z'));
		printf("%s\tisalpha '0' %d\n", color, isalpha('0'));
		printf("%s******************************************************\n", color);
	}
 
    printf("%s\n*********************NORMINETTE***********************\n", WHITE);
	norminette = 0;
	if (bonus == 's')
	{
//ft_lstmap_bonus.c
		result = check_norminette("ft_lstmap_bonus.c");
		if (result == -1)
			printf("%sHubo un error al ejecutar norminette. ft_lstmap_bonus.c\n", RED);
		else
			norminette = norminette + result;
//ft_lstiter_bonus.c
		result = check_norminette("ft_lstiter_bonus.c");
		if (result == -1)
			printf("%sHubo un error al ejecutar norminette. ft_lstiter_bonus.c\n", RED);
		else
			norminette = norminette + result;
//ft_lstclear_bonus.c
		result = check_norminette("ft_lstclear_bonus.c");
		if (result == -1)
			printf("%sHubo un error al ejecutar norminette. ft_lstclear_bonus.c\n", RED);
		else
			norminette = norminette + result;
//ft_lstdelone_bonus.c
		result = check_norminette("ft_lstdelone_bonus.c");
		if (result == -1)
			printf("%sHubo un error al ejecutar norminette. ft_lstdelone_bonus.c\n", RED);
		else
			norminette = norminette + result;
//ft_lstadd_back_bonus.c
		result = check_norminette("ft_lstadd_back_bonus.c");
		if (result == -1)
			printf("%sHubo un error al ejecutar norminette. ft_lstadd_back_bonus.c\n", RED);
		else
			norminette = norminette + result;
//ft_lstlast_bonus.c
		result = check_norminette("ft_lstlast_bonus.c");
		if (result == -1)
			printf("%sHubo un error al ejecutar norminette. ft_lstlast_bonus.c\n", RED);
		else
			norminette = norminette + result;
//ft_lstsize_bonus.c
		result = check_norminette("ft_lstsize_bonus.c");
		if (result == -1)
			printf("%sHubo un error al ejecutar norminette. ft_lstsize_bonus.c\n", RED);
		else
			norminette = norminette + result;
//ft_lstadd_front_bonus.c
		result = check_norminette("ft_lstadd_front_bonus.c");
		if (result == -1)
			printf("%sHubo un error al ejecutar norminette. ft_lstadd_front_bonus.c\n", RED);
		else
			norminette = norminette + result;
//ft_lstnew_bonus.c
		result = check_norminette("ft_lstnew_bonus.c");
		if (result == -1)
			printf("%sHubo un error al ejecutar norminette. ft_lstnew_bonus.c\n", RED);
		else
			norminette = norminette + result;
	}
//ft_putnbr_fd.c
	result = check_norminette("ft_putnbr_fd.c");
	if (result == -1)
		printf("%sHubo un error al ejecutar norminette. ft_putnbr_fd.c\n", RED);
	else
		norminette = norminette + result;
//ft_putendl_fd.c
	result = check_norminette("ft_putendl_fd.c");
	if (result == -1)
		printf("%sHubo un error al ejecutar norminette. ft_putendl_fd.c\n", RED);
	else
		norminette = norminette + result;
//ft_putstr_fd.c
	result = check_norminette("ft_putstr_fd.c");
	if (result == -1)
		printf("%sHubo un error al ejecutar norminette. ft_putstr_fd.c\n", RED);
	else
		norminette = norminette + result;
//ft_putchar_fd.c
	result = check_norminette("ft_putchar_fd.c");
	if (result == -1)
		printf("%sHubo un error al ejecutar norminette. ft_putchar_fd.c\n", RED);
	else
		norminette = norminette + result;
//ft_striteri.c
	result = check_norminette("ft_striteri.c");
	if (result == -1)
		printf("%sHubo un error al ejecutar norminette. ft_striteri.c\n", RED);
	else
		norminette = norminette + result;
//ft_strmapi.c
	result = check_norminette("ft_strmapi.c");
	if (result == -1)
		printf("%sHubo un error al ejecutar norminette. ft_strmapi.c\n", RED);
	else
		norminette = norminette + result;
//ft_itoa.c
	result = check_norminette("ft_itoa.c");
	if (result == -1)
		printf("%sHubo un error al ejecutar norminette. ft_itoa.c\n", RED);
	else
		norminette = norminette + result;
//ft_split.c
	result = check_norminette("ft_split.c");
	if (result == -1)
		printf("%sHubo un error al ejecutar norminette. ft_split.c\n", RED);
	else
		norminette = norminette + result;
//ft_strtrim.c
	result = check_norminette("ft_strtrim.c");
	if (result == -1)
		printf("%sHubo un error al ejecutar norminette. ft_strtrim.c\n", RED);
	else
		norminette = norminette + result;
//ft_strjoin.c
	result = check_norminette("ft_strjoin.c");
	if (result == -1)
		printf("%sHubo un error al ejecutar norminette. ft_strjoin.c\n", RED);
	else
		norminette = norminette + result;
//ft_substr.c
	result = check_norminette("ft_substr.c");
	if (result == -1)
		printf("%sHubo un error al ejecutar norminette. ft_substr.c\n", RED);
	else
		norminette = norminette + result;
//ft_strdup.c
	result = check_norminette("ft_strdup.c");
	if (result == -1)
		printf("%sHubo un error al ejecutar norminette. ft_strdup.c\n", RED);
	else
		norminette = norminette + result;
//ft_calloc.c
	result = check_norminette("ft_calloc.c");
	if (result == -1)
		printf("%sHubo un error al ejecutar norminette. ft_calloc.c\n", RED);
	else
		norminette = norminette + result;
//ft_atoi.c
	result = check_norminette("ft_atoi.c");
	if (result == -1)
		printf("%sHubo un error al ejecutar norminette. ft_atoi.c\n", RED);
	else
		norminette = norminette + result;
//ft_strnstr.c
	result = check_norminette("ft_strnstr.c");
	if (result == -1)
		printf("%sHubo un error al ejecutar norminette. ft_strnstr.c\n", RED);
	else
		norminette = norminette + result;
//ft_memcmp.c
	result = check_norminette("ft_memcmp.c");
	if (result == -1)
		printf("%sHubo un error al ejecutar norminette. ft_memcmp.c\n", RED);
	else
		norminette = norminette + result;
//ft_memchr.c
	result = check_norminette("ft_memchr.c");
	if (result == -1)
		printf("%sHubo un error al ejecutar norminette. ft_memchr.c\n", RED);
	else
		norminette = norminette + result;
//ft_strncmp.c
	result = check_norminette("ft_strncmp.c");
	if (result == -1)
		printf("%sHubo un error al ejecutar norminette. ft_strncmp.c\n", RED);
	else
		norminette = norminette + result;
//ft_strrchr.c
	result = check_norminette("ft_strrchr.c");
	if (result == -1)
		printf("%sHubo un error al ejecutar norminette. ft_strrchr.c\n", RED);
	else
		norminette = norminette + result;
//ft_strchr.c
	result = check_norminette("ft_strchr.c");
	if (result == -1)
		printf("%sHubo un error al ejecutar norminette. ft_strchr.c\n", RED);
	else
		norminette = norminette + result;
//ft_tolower.c
	result = check_norminette("ft_tolower.c");
	if (result == -1)
		printf("%sHubo un error al ejecutar norminette. ft_tolower.c\n", RED);
	else
		norminette = norminette + result;
//ft_toupper.c
	result = check_norminette("ft_toupper.c");
	if (result == -1)
		printf("%sHubo un error al ejecutar norminette. ft_toupper.c\n", RED);
	else
		norminette = norminette + result;
//ft_strlcat.c
	result = check_norminette("ft_strlcat.c");
	if (result == -1)
		printf("%sHubo un error al ejecutar norminette. ft_strlcat.c\n", RED);
	else
		norminette = norminette + result;
//ft_strlcpy.c
	result = check_norminette("ft_strlcpy.c");
	if (result == -1)
		printf("%sHubo un error al ejecutar norminette. ft_strlcpy.c\n", RED);
	else
		norminette = norminette + result;
//ft_memmove.c
	result = check_norminette("ft_memmove.c");
	if (result == -1)
		printf("%sHubo un error al ejecutar norminette. ft_memmove.c\n", RED);
	else
		norminette = norminette + result;
//ft_memcpy.c
	result = check_norminette("ft_memcpy.c");
	if (result == -1)
		printf("%sHubo un error al ejecutar norminette. ft_memcpy.c\n", RED);
	else
		norminette = norminette + result;
//ft_bzero
	result = check_norminette("ft_bzero.c");
	if (result == -1)
		printf("%sHubo un error al ejecutar norminette. ft_bzero.c\n", RED);
	else
		norminette = norminette + result;
//ft_memset		
	result = check_norminette("ft_memset.c");
	if (result == -1)
		printf("%sHubo un error al ejecutar norminette. ft_memset.c\n", RED);
	else
		norminette = norminette + result;
//ft_strlen		
	result = check_norminette("ft_strlen.c");
	if (result == -1)
		printf("%sHubo un error al ejecutar norminette. ft_strlen.c\n", RED);
	else
		norminette = norminette + result;
//ft_isprint		
	result = check_norminette("ft_isprint.c");
	if (result == -1)
		printf("%sHubo un error al ejecutar norminette. ft_isprint.c\n", RED);
	else
		norminette = norminette + result;	
//ft_isascii	
	result = check_norminette("ft_isascii.c");
	if (result == -1)
		printf("%sHubo un error al ejecutar norminette. ft_isascii.c\n", RED);
	else
		norminette = norminette + result;
//ft_isalnum		
	result = check_norminette("ft_isalnum.c");
	if (result == -1)
		printf("%sHubo un error al ejecutar norminette. ft_isalnum.c\n", RED);
	else
		norminette = norminette + result;
//ft_isdigit				
	result = check_norminette("ft_isdigit.c");
	if (result == -1)
		printf("%sHubo un error al ejecutar norminette. ft_isdigit.c\n", RED);
	else
		norminette = norminette + result;
//fn_isalpha(c);		
    result = check_norminette("ft_isalpha.c");
	if (result == -1)
		printf("%sHubo un error al ejecutar norminette. ft_isalpha.c\n", RED);
	else
		norminette = norminette + result;
			
	if (norminette == 0)
        color = get_color(2);
	else
        color = get_color(1);
	if (norminette == 0)
		printf("%s\tNorminette: OK!\n", color);
	else
		printf("%sErrores Norminette: %d\n", color, norminette);
	printf("%s******************************************************\n", color);		
	
	printf("%s\n\tHola %s revisa hacia arriba los resultados\n\n", color, c);
	return (0);
}


/**
 * 	//##############################
	//######### ft_isdigit #########
	//##############################

	printf("\n-----ft_isascii-----");
	printf("\n'a' es %d",ft_isascii('a'));
	printf("\n'A' es %d",ft_isascii('A'));
	printf("\n'1' es %d",ft_isascii('1'));
	printf("\n'Ç' es %d",ft_isascii(128));
	printf("\n-----isascii-----");
	printf("\n'a' es %d",isascii('a'));
	printf("\n'A' es %d",isascii('A'));
	printf("\n'1' es %d",isascii('1'));
	printf("\n'Ç' es %d",isascii(128));
	printf("\n");

	//##############################
	//######### ft_isdigit #########
	//##############################

	printf("\n-----ft_isprint-----");
	printf("\n'NULL' es %d",ft_isprint(0));
	printf("\n'!' es %d",ft_isprint('!'));
	printf("\n'1' es %d",ft_isprint('1'));
	printf("\n'a' es %d",ft_isprint('a'));
	printf("\n'}' es %d",ft_isprint('}'));
	printf("\n'nbsp' es %d",ft_isprint(0));
	printf("\n-----isprint-----");
	printf("\n'NULL' es %d",isprint(0));
	printf("\n'!' es %d",isprint('a'));
	printf("\n'1' es %d",isprint('1'));
	printf("\n'a' es %d",isprint('a'));
	printf("\n'}' es %d",isprint('}'));
	printf("\n'nbsp' es %d",isprint(0));
	printf("\n");

	//##############################
	//######### ft_isdigit #########
	//##############################
	
	printf("\n-----ft_strlen-----");
	printf("\nLongitud de 'Hola' es de %ld", ft_strlen("Hola"));
	printf("\nLongitud de 'HolaHola' es de %ld", ft_strlen("HolaHola"));
	printf("\nLongitud de 'HolaHolaHola' es de %ld", ft_strlen("HolaHolaHola"));
	printf("\nLongitud de 'HolaHolaHolaHola' es de %ld", ft_strlen("HolaHolaHolaHola"));
	printf("\n-----strlen-----");
	printf("\nLongitud de 'Hola' es de %ld", strlen("Hola"));
	printf("\nLongitud de 'HolaHola' es de %ld", strlen("HolaHola"));
	printf("\nLongitud de 'HolaHolaHola' es de %ld", strlen("HolaHolaHola"));
	printf("\nLongitud de 'HolaHolaHolaHola' es de %ld", strlen("HolaHolaHolaHola"));
	printf("\n");

	//##############################
	//######### ft_isdigit #########
	//##############################

	char str1[50];
	printf("\n-----ft_memset-----");
	ft_memset(str1, 'A', 50);
	printf("\n50 veces A: %s", str1);
	printf("\n");
	char str2[50];
	printf("\n-----memset-----");    
	memset(str2, 'A', 50);
	printf("\n50 veces A: %s", str2);
	printf("\n");

	//##############################
	//######### ft_isdigit #########
	//##############################

	char str3[100] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	printf("\n-----ft_bzero-----");
	ft_bzero(str3, 20);
	printf("\nABCDEFGHIJKLMNOPQRSTUVWXYZ pasa a ser ");
	for (int i = 0; i < 100; i++) 
	{
		printf("%c", str3[i]);
	}    
	printf("\n");
	char str4[100] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	printf("\n-----bzero-----");    
	//bzero(str4, 20);
	printf("\nABCDEFGHIJKLMNOPQRSTUVWXYZ pasa a ser ");
	for (int i = 0; i < 100; i++) 
	{
		printf("%c", str4[i]);
	}
	printf("\n");

	//##############################
	//######### ft_isdigit #########
	//##############################

	typedef struct Persona {
		char nombre[50];
		int edad;
	} Persona;

	printf("\n-----ft_memcpy-----");
	char src1_1[] = "Hola a todos";
	char dst1_1[30];
	ft_memcpy(dst1_1,src1_1,strlen(src1_1) +1 );
	printf("\n'Hola a todos' en src1_1 y en dst: %s", dst1_1);
	printf("\n");

	Persona persona1_1 = {"Juan Pérez", 30};
	Persona persona1_2;
	ft_memcpy(&persona1_2, &persona1_1, sizeof(Persona));
	printf("%s, %d\n", persona1_2.nombre, persona1_2.edad);

	printf("\n-----memcpy-----");
	char src2[] = "Hola a todos";
	char dst2[30];
	memcpy(dst2,src2,strlen(src2) +1);
	printf("\n'Hola a todos' en src2 y en dst: %s", dst2);
	printf("\n");

	Persona persona2_1 = {"Juan Pérez", 30};
	Persona persona2_2;
	ft_memcpy(&persona2_2, &persona2_1, sizeof(Persona));
	printf("%s, %d\n", persona2_2.nombre, persona2_2.edad);

	//##############################
	//######### ft_isdigit #########
	//##############################

	printf("\n-----ft_memmove-----");
	char str_memmove1_1[] = "Hola mundo!";
	ft_memmove(str_memmove1_1 + 3, str_memmove1_1, 7);
	printf("\n%s", str_memmove1_1);
	char str_memmove1_2[] = "12345678";
	char str_memmove1_3[] = "hola!";
	ft_memmove(str_memmove1_2,str_memmove1_3,5);
	printf("\n%s", str_memmove1_2);
	printf("\n");    
	
	printf("\n-----memmove-----");
	char str_memmove2_1[] = "Hola mundo!";
	memmove(str_memmove2_1 + 3, str_memmove2_1, 7);
	printf("\n%s", str_memmove2_1);
	char str_memmove2_2[] = "12345678";
	char str_memmove2_3[] = "hola!";
	memmove(str_memmove2_2,str_memmove2_3,5);
	printf("\n%s",str_memmove2_2);
	printf("\n");

	//##############################
	//######### ft_isdigit #########
	//##############################

	printf("\n-----ft_strlcpy-----");
	char ft_strlcpy_src[] = "\nHello, world!";
	char ft_strlcpy_dst[20];
	size_t ft_strlcpy_result = ft_strlcpy(ft_strlcpy_dst, ft_strlcpy_src, sizeof(ft_strlcpy_dst));	
	printf("\nsrc: %s", ft_strlcpy_src);
	printf("\ndst: %s", ft_strlcpy_dst);
	printf("\nResult: %zu", ft_strlcpy_result);
	printf("\n");

	//TODO strlcpy standar
	//printf("\n-----strlcpy-----");
	//char	strlcpy_src[] = "Hello, world!";
	//char	strlcpy_dst[20];
	//
	//size_t strlcpy_result = strlcpy(strlcpy_dst, strlcpy_src, sizeof(strlcpy_dst));	
	//printf("src: %s\n", strlcpy_src);
	//printf("dst: %s\n", strlcpy_dst);
	//printf("Result: %zu\n", strlcpy_result);

	//##############################
	//######### ft_isdigit #########
	//##############################

	printf("\n-----ft_strlcat-----");
	char 	*src_main1 = "abcdef ghijk lmnopqrst aaa";
	char 	dest_main1[30] = "ivan ";
	unsigned int n11 = sizeof(src_main1);
	unsigned int n12 = sizeof(dest_main1);

	//char	*src_main2 = "abcdef ghijk lmnopqrst aaa";  //27caracteres (26 + \0)
	//char	dest_main2[30] = "ivan ";				//5 caracteres (4 + \0)
	//unsigned int n21 = sizeof(src_main2);
	//unsigned int n22 = sizeof(dest_main2);

	printf("\nstrlcat personalizada: %zu", ft_strlcat(dest_main1, src_main1, n12));
	printf("\nsize src %d",n11);
	printf("\nsize dst %d",n12);
	printf("\n%s",src_main1);
	printf("\n%s",dest_main1);
	printf("\n");
	//TODO: strlcat standar
	//printf("\n-----strlcat-----");

	//##############################
	//######### ft_isdigit #########
	//##############################

	printf("\n------ft_toupper----------");
	printf("\n Letra A es: %c", ft_toupper('A'));
	printf("\n Letra b es: %c", ft_toupper('b'));
	printf("\n Letra 1 es: %c", ft_toupper('1'));

	printf("\n");
	printf("\n------toupper----------");
	printf("\n Letra A es: %c", toupper('A'));
	printf("\n Letra b es: %c", toupper('b'));
	printf("\n Letra 1 es: %c", toupper('1'));
	printf("\n");

	//##############################
	//######### ft_isdigit #########
	//##############################

	printf("\n------ft_tolower----------");
	printf("\n Letra A es: %c", ft_tolower('A'));
	printf("\n Letra b es: %c", ft_tolower('b'));
	printf("\n Letra 1 es: %c", ft_tolower('1'));

	printf("\n");
	printf("\n------tolower----------");
	printf("\n Letra A es: %c", tolower('A'));
	printf("\n Letra b es: %c", tolower('b'));
	printf("\n Letra 1 es: %c", tolower('1'));
	printf("\n");    

	//##############################
	//######### ft_isdigit #########
	//##############################

	char frase[] = "Hola que tal";
	char letra = 'a';
	printf("\n------ft_strchr----------");
	printf("\n Letra %c en la frase \"%s\" esta a partir de aqui: %s", letra, frase, ft_strchr(frase, letra));
	printf("\n");

	printf("\n------strchr----------");
	printf("\n Letra %c en la frase \"%s\" esta a partir de aqui: %s", letra, frase, strchr(frase, letra));
	printf("\n");   

	//##############################
	//######### ft_isdigit #########
	//##############################

	char frase_strrchr[] = "Hola que tal";
	char letra_strrchr = 'a';
	printf("\n------ft_strrchr----------");
	printf("\n Letra %c en la frase \"%s\" esta a partir de aqui: %s", letra_strrchr, frase_strrchr, ft_strrchr(frase_strrchr, letra_strrchr));
	printf("\n");
	printf("\n------strrchr----------");
	printf("\n Letra %c en la frase \"%s\" esta a partir de aqui: %s", letra, frase, strrchr(frase, letra));
	printf("\n"); 

	//##############################
	//######### ft_strncmp #########
	//##############################

	int strncmp_num = 5;
	printf("\n------strncmp----------");
	printf("\nft_strncmp: %d", ft_strncmp("12344", "12349", strncmp_num));
	printf("\nstrncmp:    %d", strncmp("12344", "12349", 	strncmp_num));
	printf("\nft_strncmp: %d", ft_strncmp("12345", "12345", strncmp_num));
	printf("\nstrncmp:    %d", strncmp("12345", "12345", 	strncmp_num));
	printf("\nft_strncmp: %d", ft_strncmp("12348", "12343", strncmp_num));
	printf("\nstrncmp:    %d", strncmp("12348", "12343", 	strncmp_num));
	printf("\n"); 


	//##############################
	//######### ft_memchr  #########
	//##############################

    const char *str = "Hello, world!";
    char key = 'w';
    char *result_ft_memchr = ft_memchr(str, key, strlen(str));
    char *result_memchr    = memchr(str, key, strlen(str));
    printf("\n------------- ft_memchr ------------");
    printf("\nLa frase \"%s\" contiene la letra \"%c\" aquí %s", str, key, result_ft_memchr);
    printf("\n-------------- memchr ------------");
    printf("\nLa frase \"%s\" contiene la letra \"%c\" aquí %s", str, key, result_memchr);
	printf("\n"); 

	//##############################
	//######### ft_memcmp  #########
	//##############################

    const char *memcmp_s1  = "Hello, world!";
    const char *memcmp_s2  = "Hello, world";
    const size_t n  = 32;
    int result_ft_memcmp = ft_memcmp(memcmp_s1, memcmp_s2, n);
    int result_memcmp    = memcmp(memcmp_s1, memcmp_s2, n);
    printf("\n------------- ft_memcmp ------------");
    printf("\nLa frase \"%s\" es igual a la frase \"%s\": %i", memcmp_s1, memcmp_s2, result_ft_memcmp);
    printf("\n-------------- memcmp ------------");
    printf("\nLa frase \"%s\" es igual a la frase \"%s\": %i", memcmp_s1, memcmp_s2, result_memcmp);	
	printf("\n");

	//##############################
	//######### ft_strnstr #########
	//##############################

	const char *big_main1 = "abcdef aa aab";
	const char *little_main1 = " aab";
	const char *big_main2 = "abcdef aaab";
	const char *little_main2 = "f aa";
    printf("\n------------- ft_strnstr ------------");
	printf("\n¿La frase \"%s\" esta contenida en la frase \"%s\"? --> Resultado: \"%s\"", big_main1, little_main1, ft_strnstr(big_main1,little_main1,12));
	printf("\n¿La frase \"%s\" esta contenida en la frase \"%s\"? --> Resultado: \"%s\"", big_main2, little_main2, ft_strnstr(big_main2,little_main2,12));
	//TODO: comparacion con la funcion standar
	printf("\n");

	//##############################
	//#########   ft_atoi  #########
	//##############################

	printf("\n-------------ft_atoi----------"); 
	printf("\nCadena de texto \"+12+345_678\" pasada a entero: %d", ft_atoi("+12+345_678"));
	printf("\nCadena de texto \"+12-345_678\" pasada a entero: %d", ft_atoi("+12+345_678"));
	printf("\nCadena de texto \"a12345_678\" pasada a entero: %d", ft_atoi("a12345_678"));
	printf("\nCadena de texto \"12345678\" pasada a entero: %d", ft_atoi("12345678"));
	printf("\nCadena de texto \"1234 5678\" pasada a entero: %d", ft_atoi("1234 5678"));
	printf("\nCadena de texto \"-12345_678\" pasada a entero: %d", ft_atoi("-12345_678"));
	printf("\nCadena de texto \"1-2-345_678\" pasada a entero: %d", ft_atoi("1-2-345_678"));
	printf("\nCadena de texto \"+a2-345_678\" pasada a entero: %d", ft_atoi("+a2-345_678"));
	printf("\n-------------atoi----------"); 
	printf("\nCadena de texto \"+12+345_678\" pasada a entero: %d", atoi("+12+345_678"));
	printf("\nCadena de texto \"+12-345_678\" pasada a entero: %d", atoi("+12-345_678"));
	printf("\nCadena de texto \"a12345_678\" pasada a entero: %d", atoi("a12345_678"));
	printf("\nCadena de texto \"12345678\" pasada a entero: %d", atoi("12345678"));
	printf("\nCadena de texto \"1234 5678\" pasada a entero: %d", atoi("1234 5678"));
	printf("\nCadena de texto \"-12345_678\" pasada a entero: %d", atoi("-12345_678"));
	printf("\nCadena de texto \"1-2-345_678\" pasada a entero: %d", atoi("1-2-345_678"));
	printf("\nCadena de texto \"+a2-345_678\" pasada a entero: %d", atoi("+a2-345_678"));
	printf("\n");
	
	//##############################
	//######### ft_calloc  #########
	//##############################
    
	printf("\n-------------ft_calloc----------\n"); 
    int *array_ft;
    int *array;
    int num_elements = 5;

    array_ft = (int *)ft_calloc(num_elements, sizeof(int));
    array = (int *)calloc(num_elements, sizeof(int));

    if (array_ft == NULL) {
        printf("array_ft: Error al asignar memoria.\n");
        return 1;
    }
    if (array == NULL) {
        printf("array: Error al asignar memoria.\n");
        return 1;
    }
    printf("array_ft -> ");
    for (int i = 0; i < num_elements; i++) {
        printf("%d ", array_ft[i]);
    }
    printf("\n");

    printf("array    -> ");
    for (int i = 0; i < num_elements; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    printf("\n");

    free(array_ft);
    free(array);

    //struct
	typedef struct {
		int edad;
		float altura;
		char *nombre;
	} Persona_ft;

    Persona_ft *p_ft;
	Persona_ft *p_;
    p_ft = (Persona_ft*)ft_calloc(1, sizeof(Persona_ft));
	p_ = (Persona_ft*)calloc(1, sizeof(Persona_ft));
    printf("Persona_ft -> Edad: %d, Altura: %.2f, Nombre: %p\n", p_ft->edad, p_ft->altura, (void*)p_ft->nombre);
 
    printf("Persona    -> Edad: %d, Altura: %.2f, Nombre: %p\n", p_->edad, p_->altura, (void*)p_->nombre);

    free(p_ft);
    free(p_);
    printf("\n");

    //array de punteros
    char **strings_ft;
    char **strings;
    strings_ft = (char**)ft_calloc(num_elements, sizeof(char*));
    strings = (char**)calloc(num_elements, sizeof(char*));

    if (strings_ft == NULL) {
        printf("strings_ft: Error al asignar memoria.\n");
        return 1;
    }

    if (strings == NULL) {
        printf("strings: Error al asignar memoria.\n");
        return 1;
    }

    for (int i = 0; i < num_elements; i++) {
        if (strings_ft[i] == NULL) {
            printf("strings_ft[%d] es NULL\n", i);
        }
    }

    for (int i = 0; i < num_elements; i++) {
        if (strings[i] == NULL) {
            printf("strings[%d] es NULL\n", i);
        }
    }
    free(strings);
    free(strings_ft);
	
	//##############################
	//######### ft_strdup  #########
	//##############################

	char	*originalString = "Hola, este es un ejemplo de strdup";
	char	*strdup_string;
	char	*ft_strdup_string;

	strdup_string = strdup(originalString);
	ft_strdup_string = ft_strdup((originalString));

	printf("Cadena original: %s\n", originalString);

	if (strdup_string != NULL && ft_strdup_string != NULL)
	{
		printf("\n------------ strdup ----------------");
		printf("\nCadena duplicada standar: \"%s\"\n", strdup_string);
		printf("\n------------ ft_strdup ----------------");
		printf("\nCadena duplicada custom: \"%s\"\n", ft_strdup_string);
		free(strdup_string);
		free(ft_strdup_string);
		printf("\n--- Despues de hacer free ---\n");
			printf("------------ strdup ----------------");
		printf("\nCadena duplicada standar: %s\n", strdup_string);
		printf("\n------------ ft_strdup ----------------");		
		printf("\nCadena duplicada custom: %s\n", ft_strdup_string);
	}
	else
	{
		printf("Error al duplicar la cadena. Memoria insuficiente.\n");
	}

	//##############################
	//######### ft_substr #########
	//##############################

    char *texto = "0123456789101112";
    char *substr;
	printf("\n--------ft_substr---------");
    printf("\nTexto original: \"%s\"", texto);   
    substr =  ft_substr(texto, 7, 5);
    printf("\nTexto extraido desde el caracter 7 + 5 caracteres: \"%s\"", substr);
    printf("\n");
    free(substr);
	//TODO: no existe función equivalente.

	//##############################
	//######### ft_strjoin #########
	//##############################

	char *strjoin_aux1 = NULL;
    strjoin_aux1 = ft_strjoin("Palabra 1 - ", "Palabra 2");
	printf("\n--------ft_strjoin---------");
    printf("\nLa cadena \"Palabra 1\" y la cadena \"Palabra 2\" forman: \"%s\"", strjoin_aux1);
    free(strjoin_aux1);
    printf("\n Cadena anterior despues de usar free: \"%s\"", strjoin_aux1);
	printf("\n");      

	//##############################
	//######### ft_strtrim #########
	//##############################

    char *strtrim_aux1 = NULL;
	printf("\n--------ft_strtrim---------");
    strtrim_aux1 = ft_strtrim("EA_Esta es mi casa_EA", "EA");
    printf("\nLa cadena \"EA_Esta es mi casa_EA\" y la cadena a quitar es 'EA'. Cadena sin 'EAs': \"%s\"", strtrim_aux1);
    free(strtrim_aux1);
    printf("\n Cadena anterior despues de usar free: \"%s\"", strtrim_aux1);
	printf("\n");

	//##############################
	//######### ft_strsplit ########
	//##############################

	char *str_split = "Esto,,es,u,prueba,para ver,la separacion,de,caracteres";
    char **result_strsplit = ft_split(str_split, ',');    
	printf("\n--------ft_strsplit---------");
	printf("\nFrase original: \"%s\"", str_split);	
    if (result_strsplit)
    {
        int i = 0;
        while (sizeof(result_strsplit) != i)
			i++;      
            printf("\nWord %d: %s", i - 1, result_strsplit[i]);
        //ft_freesplit(result,sizeof(result));
    }
    else
        printf("\nError: No se pudo dividir la cadena.\n");
	printf("\n");

	//##############################
	//#########  ft_itoa  ##########
	//##############################

	printf("\n--------ft_itoa---------");
    int itoi_numbers[] = {0, -1, 123, -123, 2147483647, -2147483648};
    char *itoi_str;
    
    for (unsigned int i = 0; i < sizeof(itoi_numbers) / sizeof(itoi_numbers[0]); i++) {
        itoi_str = ft_itoa(itoi_numbers[i]);
        if (itoi_str) {
            printf("\nft_itoa(%d) = \"%s\"", itoi_numbers[i], itoi_str);
            if (i != 0)
				free(itoi_str);
        } else {
            printf("Error allocating memory for number %d\n", itoi_numbers[i]);
        }
    }
	printf("\n");   

	//##############################
	//######### ft_strmapi #########
	//##############################

	printf("\n--------ft_strmapi---------");
	char strmapi_str[] = "EnjutoMojamuto!.";
	printf("\nLa palabra a mayusculizar es \"%s\"", strmapi_str);
	char *strmapi_result = ft_strmapi(strmapi_str, ft_strmapi_tocapp);
	printf("\nLa palabra en mayusculas es: \"%s\"", strmapi_result);
	printf("\n");

	//##############################
	//######### ft_striteri ########
	//##############################

	printf("\n--------ft_striteri---------");
	char striteri_str[] = "Marciaaaaal!.";
	printf("\nLa palabra a mayusculizar es \"%s\"", striteri_str);
	ft_striteri(striteri_str, ft_striteri_tocapp);
	printf("\nLa palabra en mayusculas es: \"%s\"", striteri_str);
	printf("\n");

	//##############################
	//######## ft_putchar_fd #######
	//##############################

	printf("\n--------ft_putchar_fd---------");
	// Escribir el carácter 'A' en la salida estándar
	printf("\nSTDOUT_FILENO:\n");
	usleep(5000);
    ft_putchar_fd('A', STDOUT_FILENO); 
    // Escribir un salto de línea en la salida estándar
    ft_putchar_fd('\n', STDOUT_FILENO);
    // Escribir el carácter 'B' en el error estándar
    ft_putchar_fd('B', STDERR_FILENO);

    // Escribir el carácter 'C' en el archivo
    // Abrir un archivo en modo de escritura (crear si no existe)
    int file_descriptor1;
    file_descriptor1 = open("example.txt", O_WRONLY | O_CREAT, 0644);
    if (file_descriptor1 < 0) {
        write(STDERR_FILENO, "Error opening file\n", 19);
        return 1;
    }
    // Escribir el carácter 'C' en el archivo
	printf("\nfile_descriptor = open(\"example.txt, O_WRONLY | O_CREAT, 0644);");
	printf("\nSe escribirá 'C' en el fichero example.txt\n");
	usleep(5000);
    ft_putchar_fd('C', file_descriptor1);
	close(file_descriptor1);		
	printf("\n");

	//##############################
	//######## ft_putstr_fd ########
	//##############################

	printf("\n--------ft_putstr_fd---------");
	// Escribir la palabra  'AVION' en la salida estándar
	printf("\nSTDOUT_FILENO:");
	usleep(5000);	
	ft_putstr_fd("\n\"AVION\"", STDOUT_FILENO); 
	// Escribir la palabra 'BARCO' en el error estándar
	ft_putstr_fd("\n\"BARCO\"", STDERR_FILENO);

	// Escribir la palabra 'CORVETE' en el archivo
	// Abrir un archivo en modo de escritura (crear si no existe)
	int file_descriptor2;
	file_descriptor2 = open("example.txt", O_WRONLY | O_CREAT, 0644);
	if (file_descriptor2 < 0) {
		write(STDERR_FILENO, "Error opening file\n", 19);
		return 1;
	}
	// Escribir la palabra 'CORVETE' en el archivo
	printf("\nfile_descriptor = open(\"example.txt, O_WRONLY | O_CREAT, 0644);");
	printf("\nSe escribirá 'CORVETE' en el fichero example.txt\n");	
	ft_putstr_fd("\"CORVETE\"", file_descriptor2);
	close(file_descriptor2);
	printf("\n");

	//##############################
	//######## ft_putendl_fd #######
	//##############################

	printf("\n--------ft_putendl_fd---------");
	// Escribir la palabra  'AVION' en la salida estándar
	printf("\nSTDOUT_FILENO:");
	usleep(500000);
	ft_putendl_fd("\"AVION\"", STDOUT_FILENO); 
	// Escribir la palabra 'BARCO' en el error estándar
	ft_putendl_fd("\"BARCO\"", STDERR_FILENO);

	// Escribir la palabra 'CORVETE' en el archivo
	// Abrir un archivo en modo de escritura (crear si no existe)
	int file_descriptor3;
	file_descriptor3 = open("example.txt", O_WRONLY | O_CREAT, 0644);
	if (file_descriptor3 < 0) {
		write(STDERR_FILENO, "Error opening file\n", 19);
		return 1;
	}
	// Escribir la palabra 'CORVETE' en el archivo
	printf("\nfile_descriptor = open(\"example.txt, O_WRONLY | O_CREAT, 0644);");
	printf("\nSe escribirá 'CORVETE' en el fichero example.txt\n");	
	ft_putendl_fd("\"CORVETE\"", file_descriptor3);
	close(file_descriptor3);
	printf("\n");

	//##############################
	//######## ft_putnbr_fd ########
	//##############################

	write(1,"\n--------ft_putnbr_fd---------\n",32);
	usleep(5000);
	ft_putnbr_fd(-2147483648, STDERR_FILENO);
	write(1,"\n",1);
	ft_putnbr_fd(350478, STDOUT_FILENO); 
	int file_descriptor4;

	// Abrir un archivo en modo de escritura (crear si no existe)
	file_descriptor4 = open("example.txt", O_WRONLY | O_CREAT, 0644);
	if (file_descriptor4 < 0) {
		write(STDERR_FILENO, "Error opening file\n", 19);
		return 1;
	}
	printf("\nfile_descriptor = open(\"example.txt, O_WRONLY | O_CREAT, 0644);");
	printf("\nSe escribirá '-350478' en el fichero example.txt\n");	
	ft_putnbr_fd(-350478, file_descriptor4);
	close(file_descriptor4);
	printf("\n");

	printf("\n");

	//##############################
	//######### ft_lstnew ##########
	//##############################	
    
	printf("\n--------ft_lstnew---------\n");
	int lstnew_aux = 42;
    t_list *node = ft_lstnew(&lstnew_aux);
    if (node != NULL)
    {
        printf("\nNode content: %d\n", *(int *)node->content);
        free(node);      // Liberar el nodo si ya no es necesario
    }
	printf("\n");

	//##############################
	//####### ft_lstadd_front ######
	//##############################	

	printf("\n--------ft_lstadd_front---------\n");

	// Creamos una lista vacía
	t_list *lst_add_front = NULL;
	// Creamos un nuevo nodo para agregar al frente de la lista
	t_list *new_node_add_front = ft_lstnew("FEO");
	// Agregamos el nuevo nodo al frente de la lista
	ft_lstadd_front(&lst_add_front, new_node_add_front);
	// Imprimimos la lista para verificar
	printf("Contenido de la lista:\n");
	while (lst_add_front != NULL)
	{
		// Suponiendo que el contenido de la lista es una cadena de caracteres
		printf("%s\n", (char *)(lst_add_front->content)); 
		lst_add_front = lst_add_front->next;
	}
	printf("\n");

	//##############################
	//########  ft_lstsize  ########
	//##############################

	printf("\n--------ft_lstsize---------\n");
	// Creamos una lista vacía
	t_list *lstsize = NULL;
	// Creamos un nuevo nodo para agregar al frente de la lista
	t_list *lstsize_node1 = ft_lstnew("FEO");
	t_list *lstsize_node2 = ft_lstnew("FUERTE");    
	t_list *lstsize_node3 = ft_lstnew("FORMAL");    
	// Agregamos el nuevo nodo al frente de la lista
	ft_lstadd_front(&lstsize, lstsize_node1);
	ft_lstadd_front(&lstsize, lstsize_node2);    
	ft_lstadd_front(&lstsize, lstsize_node3);    
	// Imprimimos la lista para verificar
	printf("Numero de elementos en la lista = \"%d\":\n", ft_lstsize(lstsize));
	printf("Contenido de la lista:\n");
	while (lstsize != NULL)
	{
		// Suponiendo que el contenido de la lista es una cadena de caracteres
		printf("%s\n", (char *)(lstsize->content)); 
		lstsize = lstsize->next;
	}
	printf("\n");

	//##############################
	//########  ft_lstlast  ########
	//##############################

	printf("\n--------ft_lstlast---------\n");

	// Creamos una lista vacía
	t_list *lst_src = NULL;
    t_list *last_lst_find = NULL;
	// Creamos un nuevo nodo para agregar al frente de la lista
	t_list *lstlast_node1 = ft_lstnew("FEO");
	t_list *lstlast_node2 = ft_lstnew("FUERTE");    
	t_list *lstlast_node3 = ft_lstnew("FORMAL");    
	// Agregamos el nuevo nodo al frente de la lista
	ft_lstadd_front(&lst_src, lstlast_node3);    
	ft_lstadd_front(&lst_src, lstlast_node2);    
	ft_lstadd_front(&lst_src, lstlast_node1);
    // Ultimo nodo de la lista
	printf("\nNumero de elementos en la lista = \"%d\":", ft_lstsize(lst_src));
    last_lst_find = ft_lstlast(lst_src);
	printf("\nUltimo nodo de la lista:");
    printf("\n\"%s\"", (char *)(last_lst_find->content)); 
	//Toda la lista para ver cual es el ultimo.
    printf("\nNodos de elementos de la lista:");
    while (lst_src != NULL)
	{
		printf("\n * \"%s\"", (char *)(lst_src->content)); 
		lst_src = lst_src->next;
	}	
	printf("\n");

	//##############################
	//####### ft_lstadd_back #######
	//##############################

	printf("\n--------ft_lstdelone---------\n");
	// Creamos una lista vacía

	t_list *lst_src_back = NULL;
	t_list *last_lst_back = NULL;
	// Creamos un nuevo nodo para agregar al frente de la lista
	// Suponiendo q la función ft_lstnew crea un nodo con un contenido dado
	t_list *lstadd_back1 = ft_lstnew("FEO");
	t_list *lstadd_back2 = ft_lstnew("FUERTE");    
	t_list *lstadd_back3 = ft_lstnew("FORMAL");    
	// Agregamos el nuevo nodo al frente de la lista
	ft_lstadd_front(&lst_src_back, lstadd_back3);    
	ft_lstadd_front(&lst_src_back, lstadd_back2);    
	ft_lstadd_front(&lst_src_back, lstadd_back1);
	// Ultimo nodo de la lista
	printf("\nNumero de elementos en la lista = \"%d\":", ft_lstsize(lst_src_back));
	last_lst_back = ft_lstlast(lst_src_back);
	printf("\nUltimo nodo de la lista:");
	printf("\n\"%s\"", (char *)(last_lst_back->content)); 
	// Crear un nuevo ndo
	t_list *new_node4 = ft_lstnew("John_Wayne");
	//Agregar ese nodo al final de la lista
	ft_lstadd_back(&lst_src_back, new_node4);
	//Toda la lista para ver cual es el ultimo.
	printf("\nNodos de la lista despues de añadir un cuarto al final:");
	while (lst_src_back != NULL)
	{
		printf("\n * \"%s\"", (char *)(lst_src_back->content)); 
		lst_src_back = lst_src_back->next;
	}

	//##############################
	//######## ft_lstdelone ########
	//##############################
	
	printf("\n--------ft_lstdelone---------\n");

	// Creamos una lista vacía
	t_list *delone_lst = NULL;

	// Creamos un nuevo nodo para agregar al frente de la lista	
	t_list *delone_node1 = ft_lstnew(ft_strdup("FEO"));
	t_list *delone_node2 = ft_lstnew(ft_strdup("FUERTE"));    
	t_list *delone_node3 = ft_lstnew(ft_strdup("FORMAL"));    
	t_list *delone_node4 = ft_lstnew(ft_strdup("John_Wayne"));
	
	// Agregamos el nuevo nodo al frente de la lista  
    ft_lstadd_front(&delone_lst, delone_node4);    
	ft_lstadd_front(&delone_lst, delone_node3);    
	ft_lstadd_front(&delone_lst, delone_node2);    
	ft_lstadd_front(&delone_lst, delone_node1);
	
	printf("\nLista ANTES de borrado: \n");
	printList(delone_lst);

    // Borrar un nodo intermedio
	printf("\nBorrar nodo 2 de la lista: %s", (char *)delone_node2->content);
	t_list *delone_previous = NULL;
	t_list *delone_temp = delone_lst;
	while (delone_temp && delone_temp->content != delone_node2->content) {
	delone_previous = delone_temp;
	delone_temp = delone_temp->next;
	}

	if (delone_temp)
	{
		if (delone_previous) 
		{
			delone_previous->next = delone_temp->next;
		} else 
		{
			delone_lst = delone_temp->next;
		}
		ft_lstdelone(delone_temp, del);
	} 
	else 
	{
		printf("\nNodo no encontrado.\n");
	}	
	
	printf("\nLista DESPUES de borrado: \n");
	printList(delone_lst);
	free(delone_lst);

	//##############################
	//######## ft_lstclear  ########
	//##############################	

	printf("\n--------ft_lstclear---------\n");

	// Creamos una lista vacía
	t_list *clear_lst = NULL;

	// Creamos un nuevo nodo para agregar al frente de la lista	
	t_list *clear_node1 = ft_lstnew(ft_strdup("FEO"));
	t_list *clear_node2 = ft_lstnew(ft_strdup("FUERTE"));    
	t_list *clear_node3 = ft_lstnew(ft_strdup("FORMAL"));    
	t_list *clear_node4 = ft_lstnew(ft_strdup("John_Wayne"));
	
	// Agregamos el nuevo nodo al frente de la lista  
    ft_lstadd_front(&clear_lst, clear_node4);    
	ft_lstadd_front(&clear_lst, clear_node3);    
	ft_lstadd_front(&clear_lst, clear_node2);    
	ft_lstadd_front(&clear_lst, clear_node1);
	
	printf("\nLista ANTES de borrado: \n");
	printList(clear_lst);

    ft_lstclear(&clear_lst,del);

	printf("\nLista DESPUES de borrado: ");
	printList(clear_lst);
	free(clear_lst);	

	//##############################
	//########  ft_lstiter  ########
	//##############################	

	printf("\n--------ft_lstiter---------\n");

	// Creamos una lista vacía
	t_list *itern_lst = NULL;

	// Creamos un nuevo nodo para agregar al frente de la lista	
	t_list *iter_node1 = ft_lstnew(ft_strdup("FEO"));
	t_list *iter_node2 = ft_lstnew(ft_strdup("FUERTE"));    
	t_list *iter_node3 = ft_lstnew(ft_strdup("FORMAL"));    
	t_list *iter_node4 = ft_lstnew(ft_strdup("John_Wayne"));
	
	// Agregamos el nuevo nodo al frente de la lista  
	ft_lstadd_front(&itern_lst, iter_node4);    
	ft_lstadd_front(&itern_lst, iter_node3);    
	ft_lstadd_front(&itern_lst, iter_node2);    
	ft_lstadd_front(&itern_lst, iter_node1);
	
	printf("\nLista ANTES de lstiter: \n");
	printList(itern_lst);
	
	printf("\nLista DESPUES de lstiter:");
	ft_lstiter(itern_lst, add_42);
	printf("\n");

	free(itern_lst);

	//##############################
	//########   ft_lstmap  ########
	//##############################	

	printf("\n--------ft_lstmap---------\n");

	// Creamos una lista vacía
	t_list *lst_map = NULL;
	t_list *lst_map_copy = NULL;	

	// Creamos un nuevo nodo para agregar al frente de la lista	
	t_list *map_node1 = ft_lstnew(ft_strdup("Feo"));
	t_list *map_node2 = ft_lstnew(ft_strdup("Fuerte"));    
	t_list *map_node3 = ft_lstnew(ft_strdup("Formal"));    
	t_list *map_node4 = ft_lstnew(ft_strdup("John_Wayne"));
	
	// Agregamos el nuevo nodo al frente de la lista  
	ft_lstadd_front(&lst_map, map_node4);    
	ft_lstadd_front(&lst_map, map_node3);    
	ft_lstadd_front(&lst_map, map_node2);    
	ft_lstadd_front(&lst_map, map_node1);
	
	printf("\nLista de t_list *lst_map: \n");
	printList(lst_map);	

	printf("\nLista de t_list *lst_map_copy:\n");
	lst_map_copy = ft_lstmap(lst_map, upper_content, del);
	printList(lst_map_copy);

	free(lst_map);
	free(lst_map_copy);

	return 0;
*/
