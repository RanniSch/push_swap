/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_args_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 17:20:48 by rschlott          #+#    #+#             */
/*   Updated: 2022/11/06 11:08:03 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* takes first or second arg, depending on which needs less operations. */
void	best_num_b(struct s_node **b_liste, unsigned int index)
{
	if (index > 0)
	{
		while (index--)
			rotate_b(b_liste);
	}
}

/* pushes first two args to stack b and runs "three_arguments" */
void	run_five_arguments(struct s_node **a_liste, struct s_node **b_liste,
		int *array_a, int *values_b)
{
	int	len_a;
	int	index;
	int	smallest;
	int	checker_a;
	int	b_data;

	len_a = current_a(a_liste, array_a);
	get_smallest(array_a, len_a, b_liste, values_b);
	smallest = min(b_liste, values_b);
	index = index_value(values_b, smallest);
	b_data = identifies_best_b(b_liste, index);
	checker_a = sorting_position_a(array_a, len_a, b_data);
	best_num_b(b_liste, index);
	sorting_normal_num(a_liste, b_liste, array_a, checker_a);
	sorting_smallest_num(a_liste, b_liste, array_a, checker_a);
	sorting_biggest_num(a_liste, b_liste, array_a, checker_a);
	push_to_a(a_liste, b_liste);
}
