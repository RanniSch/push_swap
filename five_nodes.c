/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 18:04:11 by rschlott          #+#    #+#             */
/*   Updated: 2022/10/27 08:50:20 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    two_arguments(struct s_node **a_liste)
{
    struct s_node *ptr_a;

    ptr_a = *a_liste;
    if(ptr_a->data > ptr_a->link->data)
      swap_a(a_liste);
}

void    three_arguments(struct s_node **a_liste, int *array_a, int len_a)
{
    if (array_a[len_a - 3] > array_a[len_a - 2] && array_a[len_a - 2] > array_a[len_a - 1])
    {
        swap_a(a_liste);
        reverse_rotate_a(a_liste);
    }
    if (array_a[len_a - 3] > array_a[len_a - 2] && array_a[len_a - 2] < array_a[len_a - 1])
    {
        if (array_a[len_a - 3] > array_a[len_a - 1])
            rotate_a(a_liste);
        else
            swap_a(a_liste);
    }
    if (array_a[len_a - 3] < array_a[len_a - 2] && array_a[len_a - 2] > array_a[len_a - 1])
    {
        reverse_rotate_a(a_liste);
        if (array_a[len_a - 3] < array_a[len_a - 1])
            swap_a(a_liste);
    }
}

void    four_arguments(struct s_node **a_liste, struct s_node **b_liste, int *array_a, int len_a)
{
    int i;
    struct s_node *ptr_b;
    int biggest_a;

    i = 0;
    if (!(array_a[i] < array_a[i + 1] && array_a[i + 1] < array_a[i + 2] && array_a[i + 2] < array_a[i + 3]))
    {
        biggest_a = biggest_in_a(a_liste);
        push_to_b(a_liste, b_liste);
        ptr_b = *b_liste;
        three_arguments(a_liste, array_a, len_a);
        push_to_a(a_liste, b_liste);
        // hier braucht es eigentlich den sortierten array mit 3 Inhalten, oder mit der Liste_a arbeiten!!!
        if (ptr_b->data == biggest_a)
            rotate_a(a_liste);
        if (ptr_b->data > array_a[i + 1] && ptr_b->data < array_a[i + 2])
            swap_a(a_liste);
        if (ptr_b->data > array_a[i + 2] && ptr_b->data < array_a[i + 3])
        {
            reverse_rotate_a(a_liste);
            swap_a(a_liste);
            rotate_a(a_liste);
            rotate_a(a_liste);
        }
    }
}

int    little_input(struct s_node **a_liste, struct s_node **b_liste)
{
    int *array_a;
    int len_a;
    //struct s_node *ptr_a;

    //ptr_a = *a_liste;
    array_a = (int *)malloc((count_of_nodes(a_liste)) * sizeof(int));
    if (!array_a)
        return(0);
    len_a = current_a(a_liste, array_a);
    if (len_a == 2)
        two_arguments(a_liste);
    if (len_a == 3)
        three_arguments(a_liste, array_a, len_a);
    if (count_of_nodes(a_liste) == 4)
        four_arguments(a_liste, b_liste, array_a, len_a);
    if (count_of_nodes(a_liste) == 5)
        four_arguments(a_liste, b_liste, array_a, len_a);
    //final_order(a_liste, smallest_a, array_a, len_a);
    free(array_a);
    return(0);
}
