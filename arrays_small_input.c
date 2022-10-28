/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrays_small_input.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 12:14:55 by rschlott          #+#    #+#             */
/*   Updated: 2022/10/28 12:50:45 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    s_array_a_small(int *array_a, int len_a)
{
    int temp;
    
    temp = array_a[len_a - 2];
    array_a[len_a - 2] = array_a[len_a - 3];
    array_a[len_a - 3] = temp;
}

void    r_array_a_small(int *array_a, int len_a)
{
    int temp;
    
    temp = array_a[len_a - 3];
    array_a[len_a - 3] = array_a[len_a - 2];
    array_a[len_a - 2] = array_a[len_a - 1];
    array_a[len_a - 1] = temp;
}

void    rr_array_a_small(int *array_a, int len_a)
{
    int temp;
    
    temp = array_a[len_a - 1];
    array_a[len_a - 1] = array_a[len_a - 2];
    array_a[len_a - 2] = array_a[len_a - 3];
    array_a[len_a - 3] = temp;
    //printf("rr null %d eins %d zwei %d drei %d\n", array_a[len_a - 4], array_a[len_a - 3], array_a[len_a - 2], array_a[len_a - 1]);
}
