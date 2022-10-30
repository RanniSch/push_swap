/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 18:04:11 by rschlott          #+#    #+#             */
/*   Updated: 2022/10/30 10:22:37 by rschlott         ###   ########.fr       */
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
    //array_ajustment(array_a, len_a);
}

void    shorten_stack_a(struct s_node **a_liste, struct s_node **b_liste)
{
    if (count_of_nodes(a_liste) == 4)
        push_to_b(a_liste, b_liste);
    if (count_of_nodes(a_liste) == 5)
    {
        push_to_b(a_liste, b_liste);
        push_to_b(a_liste, b_liste);
    }
}

void    four_arguments(struct s_node **a_liste, struct s_node **b_liste, int *array_a)
{
    int i;
    struct s_node *ptr_b;
    int biggest_a;

    ptr_b = *b_liste;
    i = 0;
    biggest_a = biggest_in_a(a_liste);
    if (ptr_b->data > array_a[i + 2] && ptr_b->data < array_a[i + 3])
    {
        reverse_rotate_a(a_liste);
        push_to_a(a_liste, b_liste);
        rotate_a(a_liste);
        rotate_a(a_liste);
    }
    else
        push_to_a(a_liste, b_liste);
    if (ptr_b->data > biggest_a)
        rotate_a(a_liste);
    if (ptr_b->data > array_a[i + 1] && ptr_b->data < array_a[i + 2])
        swap_a(a_liste);
}

int    five_arguments(struct s_node **a_liste, struct s_node **b_liste)
{
    int *array_a;
    int *values_b;
    int len_a;
    int smallest;
    int index;
    int checker_a;
    struct s_node *ptr_b;

    ptr_b = *b_liste;
    while (ptr_b != NULL)
    {
        array_a = (int *)malloc((count_of_nodes(a_liste)) * sizeof(int));
        if (!array_a)
            return(0);
        values_b = (int *)malloc((count_of_nodes(b_liste)) * sizeof(int));
        if (!values_b)
            return(0);
        len_a = current_a(a_liste, array_a);
        get_smallest(array_a, len_a, b_liste, values_b);
        smallest = min(b_liste, values_b);
        //printf("smallest val %d\n", smallest);
        index = index_value(values_b, smallest);
        //printf("index %d\n", index);
        checker_a = sorting_position_a(array_a, len_a, b_liste, index);
        //printf("checker_a %d b %d\n", checker_a, ptr_b->data);
        sorting_two_nums(a_liste, b_liste, index, array_a, len_a, checker_a);  // ggf. geht nun auch die andere Funktion!
        //printf("0: %d 1: %d 2: %d 3: %d\n", array_a[0], array_a[1], array_a[2], array_a[3]);
        free(array_a);
        free(values_b);
        ptr_b = *b_liste;
    }
    return(0);
}

void    sorting_two_nums(struct s_node **a_liste, struct s_node **b_liste, unsigned int index, int *array_a, int len_a, int checker_a)
{
    struct s_node *ptr_b;

    ptr_b = *b_liste;
    if (index > 0)
    {
        while (index--)
            rotate_b(b_liste);
    }
    ptr_b = *b_liste;
    //printf("b %d\n", ptr_b->data);
    //now check if rotate or reverse rotate a to push number from b to a!!!   KANN MAN 2 FUNKTIONEN DRAUS MACHEN     
    //Rotate in a and b in the same direction before push = RR or RRR*/
    if (checker_a == 1)
    {
        while(!(ptr_b->data < array_a[0] && ptr_b->data > array_a[len_a - 1]))
        {
            //printf("b_data %d a(i) %d a(len) %d\n", ptr_b->data, array_a[i], array_a[len_a]);
            rotate_a(a_liste);
            rotate_array_a(array_a, len_a);
        }
    }
    if (checker_a == 2)
    {
        //printf("b data %d\n", ptr_b->data);
        while(!(ptr_b->data < array_a[0] && ptr_b->data > array_a[len_a - 1]))
        {
            //printf("b_data %d a(i) %d a(len) %d\n", ptr_b->data, array_a[i], array_a[len_a]);
            //printf("b %d a(i) %d a(len) %d\n", ptr_b->data, array_a[i], array_a[len_a]);
            reverse_rotate_a(a_liste);
            reverse_rotate_array_a(array_a, len_a);
            //printf("b %d a(i) %d a(len) %d\n", ptr_b->data, array_a[i], array_a[len_a]);  // array_a != a_liste --> checken!!!  ggf. Zeile 275 unnötig!!!
        }
    }
    if (checker_a == 3)
    {
        while (!(ptr_b->data < array_a[0] && array_a[len_a - 1] > array_a[0]))
        {
            rotate_a(a_liste);
            rotate_array_a(array_a, len_a);
        }
    }
    if (checker_a == 4)
    {
        while (!(ptr_b->data < array_a[0] && array_a[len_a - 1] > array_a[0]))
        {
            reverse_rotate_a(a_liste);
            reverse_rotate_array_a(array_a, len_a);
        }
    }
    if (checker_a == 5)
    {
        while (!(ptr_b->data > array_a[len_a - 1] && array_a[0] < array_a[len_a - 1]))
        {
            rotate_a(a_liste);
            rotate_array_a(array_a, len_a);
        }
    }
        if (checker_a == 6)
    {
        while (!(ptr_b->data > array_a[len_a - 1] && array_a[0] < array_a[len_a - 1]))
        {
            reverse_rotate_a(a_liste);
            reverse_rotate_array_a(array_a, len_a);
        }
    }
    push_to_a(a_liste, b_liste);
    //print_stack(a_liste);       // muss noch raus
    //print_stack(b_liste);       // muss noch raus
}

int sorted_numbers(struct s_node **a_liste)
{
    int i;
    int sorted;
    struct s_node *ptr_a;

    i = 0;
    sorted = 0;
    ptr_a = *a_liste;
    while (ptr_a->data < ptr_a->link->data && ptr_a->link != NULL)
    {
        ptr_a = ptr_a->link;
        i++;
    }
    i = i + 1;
    if (i == count_of_nodes(a_liste))
        sorted = 1;
    return (sorted);
}

int    little_input(struct s_node **a_liste, struct s_node **b_liste, int smallest_a)
{
    int *array_a;
    int len_a;

    if (count_of_nodes(a_liste) == 2)
        two_arguments(a_liste);
    else
    {
        if (sorted_numbers(a_liste) == 0)
        {
            shorten_stack_a(a_liste, b_liste);
            array_a = (int *)malloc((count_of_nodes(a_liste)) * sizeof(int));
            if (!array_a)
                return(0);
            len_a = current_a(a_liste, array_a);
            three_arguments(a_liste, array_a, len_a);
            free(array_a);
            if (count_of_nodes(b_liste) == 1)
            {
                array_a = (int *)malloc((count_of_nodes(a_liste)) * sizeof(int));
                if (!array_a)
                    return(0);
                len_a = current_a(a_liste, array_a);
                four_arguments(a_liste, b_liste, array_a);
                free(array_a);
            }
            if (count_of_nodes(b_liste) == 2)
            {
                five_arguments(a_liste, b_liste);
            }
        } 
    }        
    array_a = (int *)malloc((count_of_nodes(a_liste)) * sizeof(int));
    if (!array_a)
        return(0);
    len_a = current_a(a_liste, array_a);
    final_order(a_liste, smallest_a, array_a, len_a);
    //print_stack(a_liste);
    free(array_a);
    //print_stack(a_liste);
    return(0);
}
