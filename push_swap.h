/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 09:11:10 by rschlott          #+#    #+#             */
/*   Updated: 2022/09/22 13:50:00 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>

/* defines the data structure; in front needs to be typedef to declare the data type */
typedef struct node
{
    int data;
    int index;
    struct node *link;
}               s_node;

/* operations */
void    swap_elements(struct node **liste);
void    swap_a_b(struct node **a_liste, struct node **b_liste);
void    rotate_elements(struct node **liste);
void    rotate_a_b(struct node **a_liste, struct node **b_liste);
void    rotate_rev_elements(struct node **liste);
void    rotate_rev_a_b(struct node **a_liste, struct node **b_liste);
void    push_first_element(struct node **src, struct node **dest);

#endif