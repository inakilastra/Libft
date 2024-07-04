/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilastra- <ilastra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 09:57:29 by ilastra-          #+#    #+#             */
/*   Updated: 2024/05/17 10:13:20 by ilastra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*tmp;
	void	*maped_content;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		maped_content = f(lst->content);
		tmp = ft_lstnew(maped_content);
		if (!tmp)
		{
			del(maped_content);
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, tmp);
		lst = lst->next;
	}
	return (new_lst);
}
/**
Nombre de función
    ft_lstmap
Prototipo 
    t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
Archivos a entregar
    -
Parámetros 
    lst: un puntero a un nodo.
    f: la dirección de un puntero a una función usada en la iteración de cada 
    elemento de la lista.
    del: un puntero a función utilizado para eliminar el contenido de un nodo, 
    si es necesario.
Valor devuelto 
    La nueva lista.
    NULL si falla la reserva de memoria.
Funciones autorizadas
    malloc, free
Descripción 
    Itera la lista ’lst’ y aplica la función ’f’ al contenido de cada nodo. 
    Crea una lista resultante de la aplicación correcta y sucesiva de la 
    función ’f’ sobre cada nodo. La función ’del’ se utiliza para eliminar el 
    contenido de un nodo, si hace falta.
*/

/**
 * EXPLICACION
#include "libft.h"			//	Es necesario para size_t "unistd.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;       //  Inicio puntero a new list
	t_list	*tmp;           //  Inicio puntero temporal

	if (!lst || !f)         //  Si "lst" o "f" son nulos
		return ;            //  Salgo de la función      
	new_lst = NULL;         //  Asigno NULL a "new_lst" para head vacio
	while (lst)             //  Recorro "lst"
	{
		//  Asigno a lsita "tmp" el nodo de "lst" aplicado la función
        tmp = ft_lstnew((*f)(lst->content));
		if (!tmp)           //  Si "tmp" es nulo
		{
			//  Borro la lista "new_lst"
            ft_lstclear(&new_lst, del);
			return (NULL);  //  Salgo de la función
		}
		//  Agrego el nodo de "tmp" al final de la lista "new_lst"
        ft_lstadd_back(&new_lst, tmp);
		tmp = tmp->next;    //  Me muevo al siguiente nodo de "tmp"
		lst = lst->next;    //  Me muevo al siguiente nodo de "lst"
	}
	return (new_lst);       //  Devuelvo la nueva lista "new_lst"
}
*/
