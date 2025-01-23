/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfraslin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 18:23:51 by sfraslin          #+#    #+#             */
/*   Updated: 2025/01/10 15:05:55 by sfraslin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_pile	*ft_pilelast(t_pile *pile)
{
	if (pile == NULL)
		return (NULL);
	while (pile->next != NULL)
		pile = pile->next;
	return (pile);
}

void	ft_pile_add_back(t_pile **pile, t_pile *new)
{
	t_pile	*temp;

	if (new == NULL)
		return ;
	if (*pile == NULL)
	{
		*pile = new;
		return ;
	}
	temp = ft_pilelast(*pile);
	temp->next = new;
}

t_pile	*ft_pilenew(long int content)
{
	t_pile	*element;

	element = malloc(sizeof(t_pile));
	if (element == NULL)
		return (NULL);
	element->nb = content;
	element->next = NULL;
	return (element);
}

void	ft_pile_add_front(t_pile **pile, t_pile *new)
{
	if (new == NULL)
		return ;
	if (*pile != NULL)
		new->next = *pile;
	else
		new->next = NULL;
	*pile = new;
}

int	ft_pilesize(t_pile *pile)
{
	int	i;

	if (pile == NULL)
		return (0);
	i = 1;
	while (pile->next != NULL)
	{
		i++;
		pile = pile->next;
	}
	return (i);
}
