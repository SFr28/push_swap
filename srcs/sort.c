/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfraslin <sfraslin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:27:21 by sfraslin          #+#    #+#             */
/*   Updated: 2025/01/21 15:37:11 by sfraslin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sort_3(t_pile **pile)
{
	t_pile	*second;
	t_pile	*last;

	second = (*pile)->next;
	last = ft_pilelast(*pile);
	if ((*pile)->nb < second->nb && second->nb < last->nb)
		return ;
	if ((*pile)->nb < second->nb && second->nb > last->nb)
	{
		if ((*pile)->nb < last->nb)
		{
			swap(pile, 'a', 1);
			*pile = rotate(pile, 'a', 1);
		}
		if ((*pile)->nb > last->nb)
			reverse_r(pile, 'a', 1);
	}
	if ((*pile)->nb > second->nb && (*pile)->nb > last->nb)
		*pile = rotate(pile, 'a', 1);
	second = (*pile)->next;
	if ((*pile)->nb > second->nb)
		swap(pile, 'a', 1);
}

void	ft_sort_4(t_pile **pile_a, t_pile **pile_b)
{
	t_pile	*min;

	min = ft_find_min(pile_a);
	if (min->position == 2)
		swap(pile_a, 'a', 1);
	if (min->position == 4)
		reverse_r(pile_a, 'a', 1);
	if (min->position == 3)
	{
		rotate(pile_a, 'a', 1);
		rotate(pile_a, 'a', 1);
	}
	push(pile_b, pile_a, 'b', 1);
	ft_sort_3(pile_a);
	push(pile_a, pile_b, 'a', 1);
}

void	ft_sort_more(t_pile **pile_a, t_pile **pile_b)
{
	t_pile	*min;
	int		size;

	size = ft_pilesize(*pile_a);
	ft_start_push(pile_a, pile_b, size);
	ft_sort_3(pile_a);
	ft_turk(pile_a, pile_b, size);
	min = ft_find_min(pile_a);
	if (min->position > size / 2)
	{
		while (*pile_a != min)
			reverse_r(pile_a, 'a', 1);
	}
	if (min->position <= size / 2)
	{
		while (*pile_a != min)
			rotate(pile_a, 'a', 1);
	}
}

void	ft_start_push(t_pile **pile_a, t_pile **pile_b, int size)
{
	long int	mean;
	int			i;
	t_pile		*temp;

	i = 1;
	mean = ft_mean(pile_a);
	while (i <= size - 3)
	{
		temp = *pile_a;
		if (temp->nb > mean)
		{
			push(pile_b, pile_a, 'b', 1);
			rotate(pile_b, 'b', 1);
		}
		else
			push(pile_b, pile_a, 'b', 1);
		i++;
	}
}

void ft_turk(t_pile **pile_a, t_pile **pile_b, int size)
{
	t_pile	*first_b;
	t_pile	*node;

	first_b = *pile_b;
	if (ft_pilesize(*pile_a) == size)
		return ;
	ft_position(pile_a, pile_b);
	while (first_b != NULL)
    {
        ft_find_next_big(pile_a, first_b);
        first_b = first_b->next;
    }
	ft_cost(pile_a, pile_b);
	node = ft_find_cheapest(pile_b);
	if (ft_choose(pile_a, pile_b, node) == 1)
		ft_repush_same(pile_a, pile_b, node);
	else if (ft_choose(pile_a, pile_b, node) == 0)
		ft_repush_diff(pile_a, pile_b, node);
	ft_turk(pile_a, pile_b, size);
}
