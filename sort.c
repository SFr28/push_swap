/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfraslin <sfraslin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:27:21 by sfraslin          #+#    #+#             */
/*   Updated: 2025/01/21 13:53:56 by sfraslin         ###   ########.fr       */
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
	t_pile	*max;
	t_pile	*max_b;
	int		size;

	size = ft_pilesize(*pile_a);
	max = ft_find_max(pile_a);
	ft_start_push(pile_a, pile_b, size);
	max_b = ft_find_max(pile_b);
	if (max_b == max)
		max_b = NULL;
	ft_sort_3(pile_a);
	ft_turk(pile_a, pile_b, max_b, size);
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

void ft_turk(t_pile **pile_a, t_pile **pile_b, t_pile *max, int size)
{
	t_pile	*first_b;
	t_pile	*node;
	int		size_b;
	int		size_a;

	first_b = *pile_b;
	size_b = ft_pilesize(*pile_b);
	size_a = ft_pilesize(*pile_a);
	if (ft_pilesize(*pile_a) == size)
		return ;
	ft_position(pile_a, pile_b);
	while (first_b != NULL)
    {
        ft_find_next_big(pile_a, first_b);
        first_b = first_b->next;
    }
	ft_cost(pile_a, pile_b, max);
	node = ft_find_cheapest(pile_b);
	if ((size_a < size_b && node->position <= size_b / 2) || (size_a > size_b && node->target->position <= size_a / 2))
		ft_repush_r(pile_a, pile_b, node);
	else if ((size_a < size_b && node->position > size_b / 2) || (size_a > size_b && node->target->position > size_a / 2))
		ft_repush_rr(pile_a, pile_b, node);
	ft_turk(pile_a, pile_b, max, size);
}
