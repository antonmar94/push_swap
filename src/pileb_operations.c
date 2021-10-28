/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pileb_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonmar <antonmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 15:34:24 by antonmar          #+#    #+#             */
/*   Updated: 2021/10/27 19:41:23 by antonmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_b(t_plist **first_elem)
{
	t_plist	*third_elem;
	t_plist	*second_elem;

	if (*first_elem && (*first_elem)->next)
	{
		second_elem = (*first_elem)->next;
		third_elem = (*first_elem)->next->next;
		(*first_elem)->next = third_elem;
		second_elem->next = *first_elem;
		*first_elem = second_elem;
	}
	write(1, "sb\n", 3);
}

void	push_b(t_plist **a_list, t_plist **b_list)
{
	t_plist	*aux;
	t_plist	*aux2;

	if (*b_list)
	{
		aux = *a_list;
		aux2 = *b_list;
		*b_list = (*b_list)->next;
		aux2->next = aux;
		*a_list = aux2;
		write(1, "pb\n", 3);
	}
}

void	rotate_b(t_plist **a_list)
{
	t_plist	*aux;
	t_plist	*sec_elem;

	aux = *a_list;
	sec_elem = (*a_list)->next;
	while (aux->next)
		aux = aux->next;
	aux->next = *a_list;
	(*a_list)->next = NULL;
	*a_list = sec_elem;
	write(1, "rb\n", 3);
}

void	rev_rotate_b(t_plist **a_list)
{
	t_plist	*aux;
	t_plist	*sec_elem;

	aux = *a_list;
	sec_elem = *a_list;
	while (aux->next)
		aux = aux->next;
	aux->next = sec_elem;
	*a_list = aux;
	while (aux->next != *a_list)
		aux = aux->next;
	aux->next = NULL;
	write(1, "rrb\n", 4);
}

void	single_moveb(t_pslist *a_list, t_pslist *b_list, char oper)
{
	if (oper == 's')
	{
		swap_b(&(b_list->list));
		a_list->cont++;
	}
	if (oper == 'r')
	{
		rotate_b(&(b_list->list));
		a_list->cont++;
	}
	if (oper == 'p')
	{
		push_b(&(b_list->list), &(a_list->list));
		a_list->cont++;
	}
	if (oper == 'o')
	{
		rev_rotate_b(&(b_list->list));
		a_list->cont++;
	}
}
