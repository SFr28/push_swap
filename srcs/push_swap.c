/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfraslin <sfraslin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 18:23:51 by sfraslin          #+#    #+#             */
/*   Updated: 2025/01/21 11:28:38 by sfraslin         ###   ########.fr       */
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
		ft_putstr_fd("Error\n", 2);
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
	if (ft_is_sorted(pile_a) == 1)
		return (0);
	if (size == 3)
		ft_sort_3(pile_a);
	if (size == 4)
		ft_sort_4(pile_a, pile_b);
	if (size > 4)
		ft_sort_more(pile_a, pile_b);
	//ft_print_pile(pile_a);
	ft_free_pile(pile_a);
	return (0);
}
int	ft_is_sorted(t_pile **pile)
{
	t_pile	*first;

	first = *pile;
	while (first->next != NULL)
	{
		if (first->nb > first->next->nb)
			return (0);
		first = first->next;
	}
	return (1);
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
