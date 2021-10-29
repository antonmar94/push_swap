/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ordenation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonmar <antonmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 15:20:23 by antonmar          #+#    #+#             */
/*   Updated: 2021/10/29 14:50:23 by antonmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ordenation_short(t_pslist *a_list, t_pslist *b_list)
{
	if (ft_plstsize(a_list->list) < 3)
	{
		if (!is_orden(a_list->list))
			single_movea(a_list, b_list, 's');
		return (0);
	}
	if (ft_plstlast(a_list->list)->content > a_list->list->content)
	{
		single_movea(a_list, b_list, 's');
		if (!is_orden(a_list->list))
			single_movea(a_list, b_list, 'r');
	}
	else
	{
		if (ft_plstlast(a_list->list)->content > a_list->list->next->content)
			single_movea(a_list, b_list, 'r');
		else
		{
			if (a_list->list->content > a_list->list->next->content)
				single_movea(a_list, b_list, 's');
			single_movea(a_list, b_list, 'o');
		}
	}
	return (0);
}

int	push_ordenation_short(t_pslist *a_list, t_pslist *b_list, int len)
{
	if (ft_plstsize(a_list->list) == 3 && len == 3)
	{
		ordenation_short(a_list, b_list);
		return (1);
	}
	if (len == 2)
	{
		if (a_list->list->content > a_list->list->next->content)
			single_movea(a_list, b_list, 's');
		return (1);
	}
	while (len != 3 || !(a_list->list->content < a_list->list->next->content
			&& a_list->list->next->content < a_list->list->next->next->content))
	{
		if (a_list->list->content > a_list->list->next->content)
			single_movea(a_list, b_list, 's');
		else if (a_list->list->content > a_list->list->next->next->content
			|| a_list->list->next->content > a_list->list->next->next->content)
		{
			single_moveb(a_list, b_list, 'p');
			single_movea(a_list, b_list, 's');
			single_movea(a_list, b_list, 'p');
		}
	}
	return (1);
}

int	push_invordenation_short(t_pslist *a_list, t_pslist *b_list, int len)
{
	if (len <= 1)
		single_movea(a_list, b_list, 'p');
	if (len == 2)
	{
		if (b_list->list->content < b_list->list->next->content)
			single_moveb(a_list, b_list, 's');
		single_movea(a_list, b_list, 'p');
		single_movea(a_list, b_list, 'p');
		return (1);
	}
	while (len || !(a_list->list->content < a_list->list->next->content
			&& a_list->list->next->content < a_list->list->next->next->content))
	{
		if (a_list->list->content > a_list->list->next->content)
			single_movea(a_list, b_list, 's');
		if ((len == 1 || (b_list->list->content > b_list->list->next->content)
				|| (a_list->list->content > a_list->list->next->next->content)))
		{
			single_movea(a_list, b_list, 'p');
			len--;
		}
		else
			single_moveb(a_list, b_list, 's');
	}
	return (1);
}

int	ordenation_recura(t_pslist *a_list, t_pslist *b_list, int len)
{
	int	num_elem;
	int	reversed;

	num_elem = len;
	reversed = 0;
	if (is_orden(a_list->list))
		return (0);
	if (len <= 3)
	{
		push_ordenation_short(a_list, b_list, len);
		return (0);
	}
	a_list->pivote = get_pivote(a_list->list, len);
	reversed = divide_alist(a_list, b_list, len);
	while (num_elem / 2 + num_elem % 2 != ft_plstsize(a_list->list)
		&& reversed--)
		single_movea(a_list, b_list, 'o');
	ordenation_recura(a_list, b_list, num_elem / 2 + num_elem % 2);
	ordenation_recurb(a_list, b_list, num_elem / 2);
	return (0);
}

int	ordenation_recurb(t_pslist *a_list, t_pslist *b_list, int len)
{
	int	num_elem;
	int	reversed;

	num_elem = len;
	reversed = 0;
	if (is_invorden(b_list->list))
	{
		while (b_list->list)
			single_movea(a_list, b_list, 'p');
		return (0);
	}
	if (len <= 3)
	{
		push_invordenation_short(a_list, b_list, len);
		return (0);
	}
	b_list->pivote = get_pivote(b_list->list, len);
	reversed = divide_blist(a_list, b_list, len);
	while (num_elem / 2 != ft_plstsize(b_list->list) && reversed--)
		single_moveb(a_list, b_list, 'o');
	ordenation_recura(a_list, b_list, num_elem / 2 + num_elem % 2);
	ordenation_recurb(a_list, b_list, num_elem / 2);
	return (0);
}
