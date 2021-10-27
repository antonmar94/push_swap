/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonmar <antonmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 15:49:44 by antonmar          #+#    #+#             */
/*   Updated: 2021/10/27 14:16:06 by antonmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	create_list(t_plist **a_list, char **argv)
{
	t_plist	*aux_list;
	char	*clean_word;
	char	*aux;

	while (*argv)
	{
		if (**argv == '\0')
		{
			write(2, "Error\n", 6);
			return (-1);
		}
		aux = *argv;
		while (*aux)
		{
			clean_word = *ft_split(aux, ' ');
			aux_list = ft_pslstnew(ft_atoi(clean_word));
			ft_pslstadd_back(a_list, aux_list);
			while (*aux != ' ' && *aux)
				aux++;
			while (*aux == ' ' && *aux)
				aux++;
		}
		argv++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_pslist	*ta_list;
	t_pslist	*tb_list;
	t_plist		*a_list;
	t_plist		*b_list;

	if (argc < 2 || test_error(argv) == 1)
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	argv++;
	if (create_list(&a_list, argv) == -1)
		return (-1);
	if (dup_in_list(a_list))
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
