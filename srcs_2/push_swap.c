/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfraslin <sfraslin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 18:23:51 by sfraslin          #+#    #+#             */
/*   Updated: 2025/01/23 12:37:24 by sfraslin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_pile	**pile_a;
	t_pile	*first;

	if (ac < 2 || (ac > 2 && av[1][0] == '\0'))
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	pile_a = NULL;
	pile_a = &first;
	if (ft_arg_to_pile(ac, av, pile_a) == NULL)
		return (1);
	if (ft_is_sorted(pile_a) == 1)
		return (0);
	ft_choose_sort(pile_a);
	ft_free_pile(pile_a);
	return (0);
}

int	ft_is_sorted(t_pile **pile)
{
	t_pile	*pile_a;

	pile_a = *pile;
	while (pile_a->next != NULL)
	{
		if (pile_a->nb > pile_a->next->nb)
			return (0);
		pile_a = pile_a->next;
	}
	return (1);
}

void	ft_choose_sort(t_pile **pile_a)
{
	t_pile	**pile_b;
	t_pile	*first_b;

	first_b = NULL;
	pile_b = &first_b;
	if (ft_pilesize(*pile_a) == 2)
	{
		if ((*pile_a)->nb > (*pile_a)->next->nb)
			swap(pile_a, 'a', 1);
		return ;
	}
	if (ft_pilesize(*pile_a) == 3)
		ft_sort_3(pile_a);
	if (ft_pilesize(*pile_a) == 4)
		ft_sort_4(pile_a, pile_b);
	if (ft_pilesize(*pile_a) > 4)
		ft_sort_more(pile_a, pile_b);
}

/*void	ft_print_pile(t_pile **pile)
{
	t_pile	*temp;
	int		i;
	int		size;

	temp = *pile;
	size = ft_pilesize(temp);
	i = 0;
	while (temp!= NULL && i < size + 1)
	{
		printf("%li\n", temp->nb);
		(temp) = temp->next;
		i++;
	}
}*/
