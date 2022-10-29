/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 18:04:11 by rschlott          #+#    #+#             */
/*   Updated: 2022/10/29 15:26:16 by rschlott         ###   ########.fr       */
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
    array_ajustment(array_a, len_a);
}

void    array_ajustment(int *array_a, int len_a)
{
    if (array_a[len_a - 3] > array_a[len_a - 2] && array_a[len_a - 2] > array_a[len_a - 1])
    {
        s_array_a_small(array_a, len_a);
        rr_array_a_small(array_a, len_a);
    }
    if (array_a[len_a - 3] > array_a[len_a - 2] && array_a[len_a - 2] < array_a[len_a - 1])
    {
        if (array_a[len_a - 3] > array_a[len_a - 1])
            r_array_a_small(array_a, len_a);
        else
            s_array_a_small(array_a, len_a);
    }
    if (array_a[len_a - 3] < array_a[len_a - 2] && array_a[len_a - 2] > array_a[len_a - 1])
    {
        rr_array_a_small(array_a, len_a);
        if (array_a[len_a - 3] > array_a[len_a - 2])
            s_array_a_small(array_a, len_a);
    }
}

void    four_arguments(struct s_node **a_liste, struct s_node **b_liste, int *array_a, int len_a)
{
    int i;
    struct s_node *ptr_b;
    int biggest_a;

    i = 0;
    if (sorted_numbers(a_liste, array_a,len_a) == 0)
    {
        biggest_a = biggest_in_a(a_liste);
        push_to_b(a_liste, b_liste);
        ptr_b = *b_liste;
        three_arguments(a_liste, array_a, len_a);
        //printf("null %d eins %d zwei %d drei %d\n", array_a[i], array_a[i + 1], array_a[i + 2], array_a[i + 3]);
        if (ptr_b->data > array_a[i + 2] && ptr_b->data < array_a[i + 3])
        {
            reverse_rotate_a(a_liste);
            push_to_a(a_liste, b_liste);
            rotate_a(a_liste);
            rotate_a(a_liste);
        }
        else
            push_to_a(a_liste, b_liste);
        if (ptr_b->data == biggest_a)
            rotate_a(a_liste);
        if (ptr_b->data > array_a[i + 1] && ptr_b->data < array_a[i + 2])
            swap_a(a_liste);
    }
}

void    five_arguments(struct s_node **a_liste, struct s_node **b_liste, int *array_a, int len_a)
{
    int i;
    struct s_node *ptr_b;

    i = 0;
    if (sorted_numbers(a_liste, array_a,len_a) == 0)
    {
        push_to_b(a_liste, b_liste);
        push_to_b(a_liste, b_liste);
        ptr_b = *b_liste;
        three_arguments(a_liste, array_a, len_a);
        //printf("null %d eins %d zwei %d drei %d\n", array_a[i], array_a[i + 1], array_a[i + 2], array_a[i + 3]);
        if (ptr_b->data > array_a[i + 2] && ptr_b->data < array_a[i + 3])
        {
            reverse_rotate_a(a_liste);
            push_to_a(a_liste, b_liste);
        }
        else
            push_to_a(a_liste, b_liste);
        //if (ptr_b->data > array_a[len - 1])
            //rotate_a(a_liste);
        if (ptr_b->data > array_a[i + 1] && ptr_b->data < array_a[i + 2])
            swap_a(a_liste);
        // erst Am Ende rotieren, bis kleinste Zahl vorne steht!!!
    }
}

void    sorting_final_num(struct s_node **a_liste, struct s_node **b_liste, int *array_a, int len_a)
{
    struct s_node *ptr_b;
    int i;

    ptr_b = *b_liste;
    i = 0;
    if (max_limit_checker(array_a, len_a, ptr_b->data) == 2)
    {
        while (!(ptr_b->data > array_a[len_a - 1] && array_a[i] < array_a[len_a - 1]))
        {
            rotate_a(a_liste);
            r_array_a_small(array_a, len_a);
        }
    }
    if (min_limit_checker(array_a, len_a, ptr_b->data) == 1)
    {
        while (!(ptr_b->data < array_a[i] && array_a[len_a - 1] > array_a[i]))
        {
            rotate_a(a_liste);
            r_array_a_small(array_a, len_a);
        }
    }
    if (!(ptr_b->data < array_a[i] && ptr_b->data > array_a[len_a - 1]))
    {
        while (!(ptr_b->data < array_a[i] && ptr_b->data > array_a[len_a - 1]))
        {
            //printf("b_data %d a(i) %d a(len) %d\n", ptr_b->data, array_a[i], array_a[len_a]);
            rotate_a(a_liste);
            r_array_a_small(array_a, len_a);
        }
    }
    push_to_a(a_liste, b_liste);
}

int sorted_numbers(struct s_node **a_liste, int *array_a, int len_a)
{
    int i;
    int sorted;

    i = 0;
    sorted = 0;
    while (array_a[i] < array_a[i + 1] && len_a > 0)
    {
        len_a--;
        i++;
    }
    i = i + 1;
    if (i == count_of_nodes(a_liste))
        sorted = 1;
    return (sorted);
}

int    little_input(struct s_node **a_liste, struct s_node **b_liste)
{
    int *array_a;
    int len_a;

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
    {
        five_arguments(a_liste, b_liste, array_a, len_a);
        free(array_a);
        array_a = (int *)malloc((count_of_nodes(a_liste)) * sizeof(int));
        if (!array_a)
            return(0);
        len_a = current_a(a_liste, array_a);
        sorting_final_num(a_liste, b_liste, array_a, len_a);
        //smallest number in front
    }
    free(array_a);
    return(0);
}
