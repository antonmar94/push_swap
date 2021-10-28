/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonmar <antonmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 15:49:44 by antonmar          #+#    #+#             */
/*   Updated: 2021/10/28 21:11:12 by antonmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_pslist	*ta_list;
	t_pslist	*tb_list;
	t_plist		*a_list;
	t_plist		*b_list;

	if (argc < 1 || test_error(argv) == 1)
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	argv++;
	if (create_list(&a_list, argv) == -1 || dup_in_list(a_list))
	{
		del_function(a_list);
		write(2, "Error\n", 6);
		return (-1);
	}
	b_list = NULL;
	ta_list = ft_pstlstnew(a_list);
	tb_list = ft_pstlstnew(b_list);
	ordenation_recura(ta_list, tb_list, ft_plstsize(ta_list->list));
	return (0);
}
