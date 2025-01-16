/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfraslin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:05:44 by sfraslin          #+#    #+#             */
/*   Updated: 2025/01/16 10:05:46 by sfraslin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_pile	*ft_find_max(t_pile **pile)
{
	t_pile	*temp;
	t_pile	*first;

	temp = *pile;
	first = *pile;
	while (*pile != NULL)
	{
		if ((*pile)->nb > temp->nb)
			temp = *pile;
		*pile = (*pile)->next;
	}
	*pile = first;
	return (temp);
}

t_pile	*ft_find_min(t_pile **pile)
{
	t_pile	*temp;
	t_pile	*first;

	temp = *pile;
	first = *pile;
	while (*pile != NULL)
	{
		if ((*pile)->nb < temp->nb)
			temp = *pile;
		*pile = (*pile)->next;
	}
	*pile = first;
	return (temp);
}

void	ft_find_next_big(t_pile **pile, t_pile *node)
{
	t_pile	*temp;

	temp = *pile;
	while (*pile != NULL)
	{
		if ((*pile)->nb > node->nb && (*pile)->nb < temp->nb)
			temp = *pile;
		*pile = (*pile)->next;
	}
	node->target = temp;
}
