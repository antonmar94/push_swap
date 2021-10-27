/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonmar <antonmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 13:43:28 by antonmar          #+#    #+#             */
/*   Updated: 2021/10/27 17:39:47 by antonmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H
# include <stdio.h>
# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct ps_list
{
	int				content;
	struct ps_list	*next;

}				t_plist;
typedef struct pas_list
{
	struct ps_list	*list;
	struct ps_list	*pivote;
	int				cont;
	int				size;
	struct ps_list	*last_orden;
}				t_pslist;
void		swap_a(t_plist **stack);
void		swap_b(t_plist **stack);
void		swap_ss(t_plist **a_list, t_plist **b_list);
void		push_a(t_plist **a_list, t_plist **b_list);
void		push_b(t_plist **a_list, t_plist **b_list);
void		rotate_a(t_plist **a_list);
void		rotate_b(t_plist **a_list);
void		rotate_rr(t_plist **a_list, t_plist **b_list);
void		rev_rotate_a(t_plist **a_list);
void		rev_rotate_b(t_plist **a_list);
void		rotate_rrr(t_plist **a_list, t_plist **b_list);
void		single_movea(t_pslist *a_list, t_pslist *b_list, char oper);
void		single_moveb(t_pslist *a_list, t_pslist *b_list, char oper);
void		both_move(t_pslist *a_list, t_pslist *b_list, char oper);
int			test_error(char **arg_list);
int			check_null(char **argv, char *clean_word);
int			create_list(t_plist **a_list, char **argv);
t_plist		*ft_plstlast(t_plist *lst);
int			ft_plstsize(t_plist *lst);
int			is_orden(t_plist *list);
int			is_invorden(t_plist *list);
int			dup_in_list(t_plist *list);
void		del_function(t_plist *a_list);
t_plist		*get_pivote(t_plist *list, int len);
//int			is_thelowest(t_plist *list, t_plist *elemen);
//int			is_thebigger(t_plist *list, t_plist *elemen);
void		ft_pslstadd_back(t_plist **lst, t_plist *new_list);
int			is_in_list(t_plist *list, t_plist *elemen);
t_plist		*ft_pslstnew(long long content);
t_pslist	*ft_pstlstnew(t_plist *list);
void		print_list(t_plist *a_list, t_plist *b_list);
int			divide_alist(t_pslist *a_list, t_pslist *b_list, int len);
int			divide_blist(t_pslist *a_list, t_pslist *b_list, int len);
int			ordenation_short(t_pslist *a_list, t_pslist *b_list);
int			ordenation_recurb(t_pslist *a_list, t_pslist *b_list, int len);
int			ordenation_recura(t_pslist *a_list, t_pslist *b_list, int len);

#endif
