/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfraslin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:27:21 by sfraslin          #+#    #+#             */
/*   Updated: 2025/01/14 13:27:22 by sfraslin         ###   ########.fr       */
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
	if ((*pile)->nb > second->nb && (*pile)->nb > last->nb)
		*pile = rotate(pile, 'a', 1);
	second = (*pile)->next;
	if ((*pile)->nb > second->nb)
		swap(pile, 'a', 1);
	if ((*pile)->nb < second->nb && second->nb > last->nb)
	{
		if ((*pile)->nb < last->nb)
		{
			swap(pile, 'a', 1);
			*pile = rotate(pile, 'a', 1);
		}
		if ((*pile)->nb > last->nb)
			*pile = reverse_r(pile, 'a', 1);
	}
}

void	ft_sort_4(t_pile **pile_a, t_pile **pile_b)
{
	t_pile	*min;

	min = ft_find_min(pile_a);
	if (min->position == 2)
		swap(pile_a, 'a', 1);
	if (min->position == 4)
		*pile_a = reverse_r(pile_a, 'a', 1);
	if (min->position == 3)
	{
		rotate(pile_a, 'a', 1);
		rotate(pile_a, 'a', 1);
	}
	push(pile_b, pile_a, 'a', 1);
	ft_sort_3(pile_a);
	push(pile_a, pile_b, 'b', 1);
}

void	ft_sort_more(t_pile **pile_a, t_pile **pile_b)
{
	t_pile		*temp; //garder une adresse de pile_a comment ?

	ft_start_push(pile_a, pile_b);
	while (ft_pilesize(*pile_a) > 3)
		push(pile_b, pile_a, 'a', 1);
	ft_sort_3(pile_a);
}

void	ft_start_push(t_pile **pile_a, t_pile **pile_b)
{
	long int	mean;
	int			i;

	mean = ft_mean(pile_a);
	i = 0;
	while (*pile_a != NULL)
	{
		if ((*pile_a)->nb >= mean && (*pile_a)->nb >= mean + (mean / 2))
		{
			if (i == 1)
				rotate(pile_b, 'b', 1);
			push(pile_b, pile_a, 'a', 1);
			i = 0;
		}
		if ((*pile_a)->nb >= mean && (*pile_a)->nb <= mean + (mean / 2))
		{
			if (i == 0)
				rotate(pile_b, 'b', 1);
			push(pile_b, pile_a, 'a', 1);
			i = 1;
		}
		*pile_a = (*pile_a)->next;
	}
}

//calculer cout de deplacement pour chaque entite...