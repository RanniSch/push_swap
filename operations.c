/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 13:44:09 by rschlott          #+#    #+#             */
/*   Updated: 2022/09/23 13:27:13 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* swap function: Swap the first two elements at the top of the stack */
void    swap_elements(struct node **liste)
{
    struct node *temp1;
    struct node *temp2;
    struct node *ptr_to_head;

    ptr_to_head = *liste;
    temp1 = ptr_to_head->link;
    temp2 = temp1->link;
    if (*liste != NULL && count_of_nodes(liste) > 1)   // später error handling an eigener Stelle; head = NULL abbruch; count = 1 ausdrucken
    {
        *liste = temp1;
        ptr_to_head->link = temp2;         // 2000 link wird zu 3000 link
        temp1->link = ptr_to_head;           // 3000 link wird zu 1000 link
    }
    else
        printf("error\n");                  // ft_printf function
}

/* swap elements of both stacks at the same time */
void    swap_a_b(struct node **a_liste, struct node **b_liste)
{
    swap_elements(a_liste);
    swap_elements(b_liste);
}

/* rotate function: Shift up all elements of the stack by 1. The first element becomes the last one */
void    rotate_elements(struct node **liste)
{
    struct node *temp1;
    struct node *temp2;
    struct node *ptr_to_head;
    int i;

    ptr_to_head = *liste;
    temp2 = ptr_to_head;
    temp1 = temp2->link;
    i = 1;
    if (*liste != NULL && count_of_nodes(liste) > 1)
    {
        *liste = temp1;
        while (i <= count_of_nodes(liste))        // später error handling an eigener Stelle; head = NULL abbruch; count = 1 ausdrucken
        {
            temp2 = temp2->link;
            i++;
        }
        temp2->link = ptr_to_head;                     // letzter link wird zum ersten Link
        ptr_to_head->link = NULL;                       // erster link wird zu NULL                     
    }
    else
        printf("error\n");                            // ft_printf function    
}

/* rotate elements of both stacks at the same time */
void    rotate_a_b(struct node **a_liste, struct node **b_liste)
{
    rotate_elements(a_liste);
    rotate_elements(b_liste);
}

/* reverse rotate function: Shift down all elements of the stack by 1. The last element becomes the first one */
void    rotate_rev_elements(struct node **liste)
{
    struct node *temp1;
    struct node *temp2;
    struct node *ptr_to_head;
    int i;

    ptr_to_head = *liste;
    temp1 = ptr_to_head;
    temp2 = ptr_to_head;
    i = 1;
    if (*liste != NULL && count_of_nodes(liste) > 1)
    {
        while (i < count_of_nodes(liste))        // später error handling an eigener Stelle; head = NULL abbruch; count = 1 ausdrucken
        {
            if (i < (count_of_nodes(liste) - 1))
            {
                temp1 = temp1->link;                
            }                
            temp2 = temp2->link;
            i++;
        }
        temp2->link = ptr_to_head;                      // letzter link wird zum alten ersten Link (jetzt zweiter Link)
        *liste = temp2;
        temp1->link = NULL;                             // vorletzter link wird zu NULL
    }
    else
        printf("error\n");                            // ft_printf function    
}

/* reverse rotate elements of both stacks at the same time */
void    rotate_rev_a_b(struct node **a_liste, struct node **b_liste)
{
    rotate_rev_elements(a_liste);
    rotate_rev_elements(b_liste);
}

/*  Take the first argument at the top of one stack and put it at the top of the other stack. Do nothing if first stack is empty. 
    For pushing there is a source list and a destination list. When the source list is empty -> error 
    When destination list is empty -> new node; If it is not empty, adding element to the top. */
void    push_first_element(struct node **src, struct node **dest)
{
    struct node *ptr_to_head;
    struct node *ptr_dest;
    struct node *temp;

    ptr_to_head = *src;
    ptr_dest = *dest;
    temp = ptr_to_head;
    //if (ptr_src = NULL)
    //    ft_error();
    *src = ptr_to_head->link;    
    if (ptr_dest != NULL)
    {
        temp->link = ptr_dest;
    }
    else
        temp->link = NULL;
    *dest = temp;    
}
