/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimum_sorting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 06:33:00 by rschlott          #+#    #+#             */
/*   Updated: 2022/10/13 11:08:07 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void get_smallest(struct s_node **a_liste, struct s_node **b_liste)
{
    struct s_node *ptr_a;
    struct s_node *ptr_b;
    int *values_b;
    int   i;
    int j;

    i = 0;
    j = 0;
    ptr_a = *a_liste;
    ptr_b = *b_liste;
    set_index(a_liste);
    values_b = (int *)malloc((count_of_nodes(b_liste)) * sizeof(int));
    //if (!values_b)
        //return(NULL);
    while (ptr_a->index <= (count_of_nodes(a_liste) / 2))   // Konstrukt funktioniert noch nicht!
    {
        if (ptr_b->data < ptr_a->data)
            j++;
        if (j == 1)
        {
            ptr_a = *a_liste;
            while (ptr_b->data > ptr_a->data)
                j++;
        }
        ptr_a = ptr_a->link;
    }
    if (j == 0)
    {
        ptr_a = *a_liste;
        while (ptr_b->data > ptr_a->data)
        {
            ptr_a = ptr_a->link;
        }
        j = count_of_nodes(a_liste) - ptr_a->index + 1;
    }
    values_b[i] = j - 1;
    printf("moves %d", values_b[i]);
}

void    minimum_sorting(struct s_node **a_liste, struct s_node **b_liste)
{
    get_smallest(a_liste, b_liste);
    //printf("Nodes a: %d Nodes b: %d\n", count_of_nodes(a_liste), count_of_nodes(b_liste));
}
