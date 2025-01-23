/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfraslin <sfraslin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:05:44 by sfraslin          #+#    #+#             */
/*   Updated: 2025/01/21 13:18:09 by sfraslin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_pile	*ft_find_max(t_pile **pile)
{
	t_pile	*temp;
	t_pile	*first;

	temp = *pile;
	first = *pile;
	while (first != NULL)
	{
		if (first->nb > temp->nb)
			temp = first;
		first = first->next;
	}
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
	t_pile	*target;

	temp = *pile;
	target = ft_find_max(pile);
	if (node->nb > target->nb)
		target = ft_find_min(pile);
	while (temp != NULL)
	{
		if (temp->nb > node->nb && temp->nb < target->nb)
			target = temp;
		temp = temp->next;
	}
	node->target = target;
}

t_pile	*ft_find_cheapest(t_pile **pile)
{
	t_pile	*temp;
	t_pile	*cheap;

	temp = *pile;
	cheap = *pile;
	while (temp != NULL)
	{
		if (cheap->cost > temp->cost)
			cheap = temp;
		temp = temp->next;
	}
	return (cheap);
}
