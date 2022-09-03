/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading-copy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 13:23:03 by rschlott          #+#    #+#             */
/*   Updated: 2022/09/03 12:57:48 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* converts char to int */
int ft_atoi(const char *str)
{
	int			sign;
	long int	convert;

	sign = 1;
	convert = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = sign * (-1);
		str++;
	}
	while (*str && *str > 47 && *str < 58)
	{
		convert = (convert * 10) + *str - '0';
		str++;
		if (convert > 2147483647 && sign == 1)
			return (-1);
		if (convert > 2147483648 && sign == -1)
			return (0);
	}
	return (convert * sign);
}

/* adds a new node to the list */
void    add_at_end(struct node **a_liste, int data)
{
    struct node *ptr;
    struct node *current;

    ptr = *a_liste;
    current = (struct node *)malloc(sizeof(struct node));
    current->data = data;
    current->link = NULL;
    if (ptr != NULL)
    {
        while(ptr->link != NULL)
        {
            ptr = ptr->link;
        }
        ptr->link = current;
    }
    else
        *a_liste = current;    
}

/* counts the number of nodes */
int    count_of_nodes(struct node **liste)
{
    int count;
    
    count = 0;
    if (*liste == NULL)
        printf("Stack is empty");
    struct node *ptr = NULL;
    ptr = *liste;
    while (ptr != NULL)
    {
        count++;
        ptr = ptr->link;
    }
    return(count);
}

/* print the data of a linked list */
void    print_stack(struct node **liste)
{
    if(*liste == NULL)
        printf("Linked List is empty");
    struct node *ptr = NULL;
    ptr = *liste;
    while(ptr != NULL)
    {
        printf("%d ", ptr->data);       // insert printf function!!!!!!!!!!!
        ptr = ptr->link;
    }
    printf("\nnumber of nodes: %d\n", count_of_nodes(liste));       // insert printf function!!!!!!!!!!!   
}

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

/* swap elements of both functions at the same time */
void    swap_a_b(struct node **a_liste, **b_liste)
{
    swap_elements(&a_liste);
    swap_elements(&b_liste);
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

/*  Take the first argument at the top of one stack and put it at the top of the other stack (from liste to b_liste or the other way round). 
    Do nothing if first stack is empty. For pushing there is a source list and a destination list. 
    When the source list is empty -> error 
    When destination list is empty -> new node
    If it is not empty, adding element to the top. */
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

/* receiving arguments from user input */
void ft_stack_receive(int argc, char **argv, struct node **a_liste)
{
    int i;

    i = 1;
    /* argc zählt den ersten String in argv mit und der ist immer ./a.out */
    while (i < argc)
    {
        add_at_end(a_liste, ft_atoi(argv[i]));
        i++;
    }
}

int main(int argc, char **argv)
{ 
    struct node *a_liste;
    struct node *b_liste;
    
    a_liste = NULL;
    b_liste = NULL;
    /* &a_liste gibt die Adresse des Pointers, der zur Liste zeigt durch = double pointer */
    ft_stack_receive(argc, argv, &a_liste);
    print_stack(&a_liste);
    //swap_elements(&a_liste);
    //print_stack(&a_liste);
    //rotate_elements(&a_liste);
    //print_stack(&a_liste);
    //rotate_rev_elements(&a_liste);
    //print_stack(&a_liste);
    push_first_element(&a_liste, &b_liste);
    print_stack(&a_liste);
    print_stack(&b_liste);
    push_first_element(&a_liste, &b_liste);
    print_stack(&a_liste);
    print_stack(&b_liste);
    return(0);
}
