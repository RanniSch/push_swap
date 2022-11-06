/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 06:53:51 by rschlott          #+#    #+#             */
/*   Updated: 2022/11/06 10:12:35 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* identifies the biggest number in an array. */
int	max(int *length, unsigned int len)
{
	int	max;

	if (!len)
		return (0);
	max = length[--len];
	while (len--)
	{
		if (length[len] > max)
			max = length[len];
	}
	return (max);
}

/* creates an array "length" and fills it with ones. Creates an array 
"subsequence" and fills it with zeroes. Arrays have same length as list. */
void	length_initializer_lis(int *subsequence, int *length, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		subsequence[i] = 0;
		length[i] = 1;
		i++;
	}
}
