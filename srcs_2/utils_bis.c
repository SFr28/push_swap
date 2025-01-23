/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfraslin <sfraslin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 18:23:51 by sfraslin          #+#    #+#             */
/*   Updated: 2025/01/23 12:26:39 by sfraslin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_error(int i)
{
	if (i == -1)
		ft_putstr_fd("Error\n", 2);
}

t_pile	**ft_free_pile(t_pile **pile_a)
{
	t_pile	*temp;

	while (*pile_a != NULL)
	{
		temp = (*pile_a)->next;
		free(*pile_a);
		*pile_a = temp;
	}
	return (NULL);
}


    // t_pile	*temp;
    // int     size_a;
    // int     size_b;

    // size_a = ft_pilesize(*pile_a);
    // temp = *pile_b;
    // size_b = ft_pilesize(*pile_b);
    // while (temp != NULL)
    // {
    //     if (temp->position <= size_b / 2)
    //     {
    //         temp->cost = temp->position + size_a - temp->target->position;
    //         if (temp->target->position <= size_a / 2 && temp->position <= temp->target->position)
    //             temp->cost = temp->target->position;
    //         if (temp->target->position <= size_a / 2 && temp->position > temp->target->position)
    //             temp->cost = temp->position;
    //     }
    //     if (temp->position > size_b / 2)
    //     {
    //         temp->cost = size_b - temp->position + temp->target->position;
    //         if (temp->target->position > size_a / 2 && temp->position > temp->target->position)
    //             temp->cost = size_a - temp->target->position;
    //         if (temp->target->position > size_a / 2 && temp->position <= temp->target->position)
    //             temp->cost = size_b - temp->position;
    //     }
    //     temp = temp->next;
    // }

/*{
    t_pile	*temp;
    int     size;

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
}*/