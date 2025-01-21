/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfraslin <sfraslin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 18:23:51 by sfraslin          #+#    #+#             */
/*   Updated: 2025/01/21 15:02:42 by sfraslin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    ft_position(t_pile **pile_a, t_pile **pile_b)
{
    t_pile	*temp;
    int i;

    i = 1;
    temp = *pile_a;
    while (temp != NULL)
    {
        temp->position = i;
        temp = temp->next;
        i++;
    }
    if (pile_b == NULL)
        return ;
    i = 1;
    temp = *pile_b;
    while (temp != NULL)
    {
        temp->position = i;
        temp = temp->next;
        i++;
    }
}

void    ft_cost(t_pile **pile_a, t_pile **pile_b)
{
    t_pile	*temp;
    int     size;

    temp = *pile_a;
    size = ft_pilesize(*pile_a);
    while (temp != NULL)
    {
        if (temp->position <= size / 2)
            temp->cost = temp->position;
        if (temp->position > size / 2)
            temp->cost = size - temp->position;
        temp = temp->next;
    }
    temp = *pile_b;
    size = ft_pilesize(*pile_b);
    while (temp != NULL)
    {
        if (temp->position <= size / 2)
            temp->cost = temp->position + temp->target->position;
        if (temp->position > size / 2)
            temp->cost = size - temp->position + temp->target->position;
        temp = temp->next;
    }
}

void	ft_repush_r(t_pile **pile_a, t_pile **pile_b, t_pile *node)
{
	while (node->position != 1 && node->target->position != 1)
	{
		rotate(pile_a, 'a', 0);
		rotate(pile_b, 'b', 0);
		ft_putstr_fd("rr\n", 1);
	}
	while (node->position != 1)
		rotate(pile_b, 'b', 1);
	while (node->target->position != 1)
		rotate(pile_a, 'a', 1);
    push(pile_a, pile_b, 'a', 1);
}

void    ft_repush_rr(t_pile **pile_a, t_pile **pile_b, t_pile *node)
{
	while (node->position != 1 && node->target->position != 1)
	{
		reverse_r(pile_a, 'a', 0);
		reverse_r(pile_b, 'b', 0);
		ft_putstr_fd("rrr\n", 1);
	}
	while (node->position != 1)
		reverse_r(pile_b, 'b', 1);
	while (node->target->position != 1)
		reverse_r(pile_a, 'a', 1);
	push(pile_a, pile_b, 'a', 1);
}

int ft_choose(t_pile **pile_a, t_pile **pile_b, t_pile *node)
{
    int		size_b;
	int		size_a;

	size_b = ft_pilesize(*pile_b);
	size_a = ft_pilesize(*pile_a);
    node->cost = node->cost - node->target->cost;
    if (node->cost > node->target->cost)
    {
        if (node->position <= size_b / 2)
            return (1);
        else
            return (0);
    }
    if (node->target->position <= size_a / 2)
        return (1);
    return (0);
}
