/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 18:04:11 by rschlott          #+#    #+#             */
/*   Updated: 2022/10/23 19:41:13 by rschlott         ###   ########.fr       */
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

void    three_arguments(struct s_node **a_liste)
{
    struct s_node *ptr_a;

    ptr_a = *a_liste;
    if(ptr_a->data > ptr_a->link->data && ptr_a->link->data > ptr_a->link->link->data)
    {
        swap_a(a_liste);
        ptr_a = *a_liste;
        reverse_rotate_a(a_liste);
    }
    else if(ptr_a->data > ptr_a->link->data)
    {
        swap_a(a_liste);
        ptr_a = *a_liste;
        if(ptr_a->link->data > ptr_a->link->link->data)
        {
            reverse_rotate_a(a_liste);
            ptr_a = *a_liste;
            if(ptr_a->data > ptr_a->link->data)
                swap_a(a_liste);
        }
    }
    else if(ptr_a->data < ptr_a->link->data && ptr_a->link->data > ptr_a->link->link->data)
    {
        reverse_rotate_a(a_liste);
        ptr_a = *a_liste;
        if(ptr_a->data > ptr_a->link->data)
            swap_a(a_liste);
    }
}

void    four_arguments(struct s_node **a_liste, struct s_node **b_liste, int smallest_a)
{
    struct s_node *ptr_a;
    struct s_node *ptr_b;

    ptr_a = *a_liste;
    ptr_b = *b_liste;
    if(!(ptr_a->data > ptr_a->link->data && ptr_a->link->data > ptr_a->link->link->data && ptr_a->link->link->data > ptr_a->link->link->link->data))
    {
        if(ptr_a->data != smallest_a)
            push_to_b(a_liste, b_liste);
        else
            swap_a(a_liste);
        push_to_b(a_liste, b_liste);
        three_arguments(a_liste);
        while(!(ptr_b->data < ptr_a->data && ptr_b->data > ptr_a->link->link->data))
            {
                // + if number in b is the biggest
            }
    }
}

void    little_input(struct s_node **a_liste, struct s_node **b_liste, int smallest_a)
{
    //struct s_node *ptr_a;

    //ptr_a = *a_liste;
    if (count_of_nodes(a_liste) == 2)
        two_arguments(a_liste);
    if (count_of_nodes(a_liste) == 3)
        three_arguments(a_liste);
    if (count_of_nodes(a_liste) == 4)
        four_arguments(a_liste, b_liste, smallest_a);
}
