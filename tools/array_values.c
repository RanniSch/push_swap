/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_values.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 09:44:29 by rschlott          #+#    #+#             */
/*   Updated: 2022/11/06 11:49:31 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* checks if b is neither min/max the amount of opperations to push to a */
int	get_smallest_normal(int b_data, int *array_a, int len_a, int op)
{
	int	i;

	i = 0;
	if (b_data > array_a[i] && b_data < array_a[i + 1])
		op = 1;
	else if (b_data < array_a[i] && b_data > array_a[len_a - 1])
		op = 0;
	else
	{
		while (!(b_data > array_a[i] && b_data < array_a[i + 1]))
			i++;
		if (i != 0 && i < ((len_a) / 2))
			op = i + 1;
		else if (i != 0)
			op = (len_a) - (i + 1);
	}
	return (op);
}

/* checks if b is min the amount of opperations to get pushed to a */
int	get_smallest_min(int b_data, int *array_a, int len_a, int op)
{
	int	i;

	i = 0;
	if (b_data < array_a[i + 1] && array_a[i] > array_a[i + 1])
		op = 1;
	else if (b_data < array_a[i] && array_a[len_a - 1] > array_a[i])
		op = 0;
	else
	{
		while (!(b_data < array_a[i + 1] && array_a[i] > array_a[i + 1]))
			i++;
		if (i != 0 && i < ((len_a) / 2))
			op = i + 1;
		else if (i != 0)
			op = (len_a) - (i + 1);
	}
	return (op);
}

/* checks if b is max the amount of opperations to get pushed to a */
int	get_smallest_max(int b_data, int *array_a, int len_a, int op)
{
	int	i;

	i = 0;
	if (b_data > array_a[i] && array_a[i + 1] < array_a[i])
		op = 1;
	else if (b_data > array_a[len_a - 1] && array_a[i] < array_a[len_a - 1])
		op = 0;
	else
	{
		while (!(b_data > array_a[i] && array_a[i + 1] < array_a[i]))
			i++;
		if (i != 0 && i < ((len_a) / 2))
			op = i + 1;
		else if (i != 0)
			op = (len_a) - (i + 1);
	}
	return (op);
}

/* checks which num from b needs smallest amount of opperations to push to a */
void	get_smallest(int *array_a, int len_a, struct s_node **b_liste,
		int *values_b)
{
	struct s_node	*ptr_b;
	int				op;
	int				b;
	int				j;

	j = 0;
	b = 0;
	ptr_b = *b_liste;
	while (ptr_b != NULL)
	{
		if (!min_limit_checker(array_a, len_a, ptr_b->data)
			&& !max_limit_checker(array_a, len_a, ptr_b->data))
			op = get_smallest_normal(ptr_b->data, array_a, len_a, 0);
		if (min_limit_checker(array_a, len_a, ptr_b->data))
			op = get_smallest_min(ptr_b->data, array_a, len_a, 0);
		if (max_limit_checker(array_a, len_a, ptr_b->data))
			op = get_smallest_max(ptr_b->data, array_a, len_a, 0);
		if (b > (count_of_nodes(b_liste) / 2))
			values_b[j] = op + (count_of_nodes(b_liste) - b) + 1;
		else
			values_b[j] = op + b + 1;
		j++;
		ptr_b = ptr_b->link;
		b++;
	}
}
