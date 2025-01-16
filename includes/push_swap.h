/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfraslin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 18:12:03 by sfraslin          #+#    #+#             */
/*   Updated: 2025/01/09 18:33:49 by sfraslin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include "ft_printf.h"
#include <stdio.h>

typedef	struct	s_pile
{
	long int		nb;
	int				position;
	struct s_pile	*next;
	struct s_pile	*target;
}	t_pile;

void	ft_pile_add_back(t_pile **pile, t_pile *new);
void	ft_pile_add_front(t_pile **pile, t_pile *new);
void    ft_create_pile(t_pile **pile, char *str, int p);
t_pile  **ft_arg_to_pile(int ac, char **av, t_pile **pile_a);
t_pile	*ft_pilelast(t_pile *pile);
t_pile	*ft_pilenew(long int content);
int		ft_pilesize(t_pile *pile);
long int    ft_atol(char *str, int sign);
long int	ft_mean(t_pile **pile_a);

void    ft_error(int i);
int 	ft_check_arg(char **tab);
int 	ft_check_doubles(t_pile **pile);
t_pile	**ft_free_pile(t_pile **pile_a);

t_pile	*swap(t_pile **pile, char c, int i);
void	push(t_pile **pile_1, t_pile **pile_2, char c, int i);
t_pile	*rotate(t_pile **pile, char c, int i);
t_pile	*reverse_r(t_pile **pile, char c, int i);

void    ft_sort_3(t_pile **pile);
void    ft_sort_4(t_pile **pile_a, t_pile **pile_b);
void	ft_sort_more(t_pile **pile_a, t_pile **pile_b);
int		ft_is_sorted(t_pile **pile);
void	ft_start_push(t_pile **pile_a, t_pile **pile_b);

t_pile  *ft_find_min(t_pile **pile);
t_pile  *ft_find_max(t_pile **pile);
void    ft_find_next_big(t_pile **pile, t_pile *node);

#endif
