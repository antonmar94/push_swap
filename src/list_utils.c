/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonmar <antonmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:30:39 by antonmar          #+#    #+#             */
/*   Updated: 2021/10/26 15:53:02 by antonmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_plstsize(t_plist *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

t_plist	*ft_plstlast(t_plist *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_plist	*ft_pslstnew(long long content)
{
	t_plist	*res;

	res = (t_plist *)malloc(sizeof(t_plist));
	if (!res)
		return (NULL);
	res->content = content;
	res->next = NULL;
	return (res);
}

t_pslist	*ft_pstlstnew(t_plist *list)
{
	t_pslist	*res;

	res = (t_pslist *)malloc(sizeof(t_pslist));
	if (!res)
		return (NULL);
	res->list = list;
	res->cont = 0;
	res->size = ft_plstsize(list);
	res->pivote = get_pivote(list, ft_plstsize(list));
	res->last_orden = ft_plstlast(list);
	return (res);
}

void	ft_pslstadd_back(t_plist **lst, t_plist *new)
{
	t_plist	*aux;

	aux = *lst;
	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	while ((*lst)->next)
		*lst = (*lst)->next;
	(*lst)->next = new;
	*lst = aux;
}
