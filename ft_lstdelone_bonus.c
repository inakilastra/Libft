/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilastra- <ilastra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:33:32 by ilastra-          #+#    #+#             */
/*   Updated: 2024/05/17 10:12:39 by ilastra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

/**
Nombre de función
    ft_lstdelone
Prototipo 
    void ft_lstdelone(t_list *lst, void (*del)(void *));
Archivos a entregar
    -
Parámetros 
    lst: el nodo a liberar.
    del: un puntero a la función utilizada para liberar el contenido del nodo.
Valor devuelto 
    Nada
Funciones autorizadas
    free
Descripción 
    Toma como parámetro un nodo ’lst’ y libera la memoria del contenido 
    utilizando la función ’del’ dada como parámetro, además de liberar el nodo.
    La memoria de ’next’ no debe liberarse.
*/

/**
 * EXPLICACION
#include "libft.h"			//	Es necesario para size_t "unistd.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)       //  Si "lst" o "del" son nulos
		return ;            //  Salgo de la función
	del(lst->content);      //  Borro el contenido del nodo
	free(lst);              //  Libero la mem de "lst"
}
*/
