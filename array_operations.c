/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 08:02:14 by rschlott          #+#    #+#             */
/*   Updated: 2022/10/28 12:16:31 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    rotate_array_a(int *array_a, int len_a)
{
    int i;
    int first_num;

    i = 0;
    first_num = array_a[0];
    while(i < (len_a - 1))
    {
        array_a[i] = array_a[i + 1];
        i++;
    }
    array_a[len_a - 1] = first_num;
}

void    reverse_rotate_array_a(int *array_a, int len_a)
{
    int last_num;

    last_num = array_a[len_a - 1];
    while((len_a - 1) > 0)
    {
        array_a[len_a - 1] = array_a[len_a - 2];
        len_a--;
    }
    array_a[0] = last_num;
}
