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

int	main(int ac, char **av)
{
	t_pile	**pile_a;
	t_pile	**pile_b;
	t_pile	*first;
	t_pile	*test;
	t_pile	*first_b;
	int		i;
	int		size;

	if (ac < 2 || (ac > 2 && av[1][0] == '\0'))
	{
		printf("Error\n");
		return (1);
	}
	i = 0;
	test = NULL;
	first = NULL;
	first_b = NULL;
	pile_a = &first;
	pile_b = &first_b;
	if (ft_arg_to_pile(ac, av, pile_a) == NULL)
		return (1);
	size = ft_pilesize(first);
	test = first;
	pile_a = &test;
	if (ft_is_sorted(pile_a) == 1)
	{
		printf("Is sorted.\n");
		return (0);
	}
	pile_a = &test;
	if (size == 3)
		ft_sort_3(pile_a);
	if (size == 4)
		ft_sort_4(pile_a, pile_b);
	if (size > 4)
		ft_sort_more(pile_a, pile_b);
	pile_a = &test;
	while (*pile_a!= NULL && i < size + 1)
	{
		printf("%li\n", (*pile_a)->nb);
		(*pile_a) = (*pile_a)->next;
		i++;
	}
	ft_free_pile(pile_a);
	return (0);
}
int	ft_is_sorted(t_pile **pile)
{
	t_pile	*temp;

	temp = *pile;
	while (temp->next != NULL)
	{
		if (temp->nb > temp->next->nb)
			return (0);
		temp = temp->next;
	}
	return (1);
}