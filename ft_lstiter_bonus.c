/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilastra- <ilastra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 09:40:53 by ilastra-          #+#    #+#             */
/*   Updated: 2024/05/17 10:12:55 by ilastra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/**
Nombre de función
    ft_lstiter
Prototipo 
    void ft_lstiter(t_list *lst, void (*f)(void *));
Archivos a entregar
    -
Parámetros 
    lst: un puntero al primer nodo.
    f: un puntero a la función que utilizará cada nodo.
Valor devuelto 
    Nada
Funciones autorizadas
    Ninguna
Descripción 
    Itera la lista ’lst’ y aplica la función ’f’ en el contenido de cada nodo.
*/

/**
 * EXPLICACION
#include "libft.h"			//	Es necesario para size_t "unistd.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)			//	Si "lst" o "f" son nulos
		return ;			//	Salgo de la función
	while (lst)				//	Recorro la lista "lst"
	{
		f(lst->content);	//	Aplico la función "f" al nodo
		lst = lst->next;	//	Me muevo al siguiente nodo
	}
}
*/
