/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_i_subsequence.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 22:45:09 by rschlott          #+#    #+#             */
/*   Updated: 2022/06/18 12:42:45 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

int    *ft_one_calloc(int argc, int size)
{
    int    *ptr;
    int     i;

    /*if ((argc - 1) == 0 || size == 0)
    {
        (argc - 1) = 1;
        size = 4;
    }*/
    /*if ((argc - 1) >= __SIZE_MAX__ || size >= __SIZE_MAX__)
        return (0);*/
    ptr = malloc((argc - 1) * size);
    if (!ptr)
        return (NULL);
    i = 0;
    while (i < (argc - 1))
    {
        ptr[i] = 1;
        i++;
    }
    return (ptr);
}

int	ft_atoi(const char *str)
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

int *ft_l_i_subsequence(int argc, int *pt_ints)
{
    int i;
    int j;
    int    *ptr_len;
    //int length[argc - 1];

    //ptr_len = &length[0];

    j = 0;
    i = 1;
    ptr_len = ft_one_calloc(argc, 4);
    while (i <= argc - 1)
    {
        j = 0;
        while (j < i)
        {
            if (pt_ints[j] < pt_ints[i]) //woher soll die Funktion wissen, wie groß der Nachfolger ist!
        {
            ptr_len[i] = ptr_len[j] + 1;
        }
            j++;
        }
        i++;
        printf("ptr_len: %d\n", ptr_len[i]);
    }
    return (ptr_len);         // hier muss noch was anderes hin! Pointer zu length!
}

// Define structure for the node
struct node
{
    int data;               //Data of the node
    struct node *nextPtr;   //Adress of the next node
}

// declare pointer for the starting node
struct node *startNode;

// Function to create a list
static void createNodeList(int argc - 1)
{
    struct node *newNode;
    struct node *nodeBuffer;
    int nodeData;
    int nodeCounter;

    startNode = (struct node *)malloc(sizeof(struct node));
    it (startNode == NULL)
        return (NULL);
    else
    {
        startNode->data = nodeData; //erster Eintrag muss hier rein
        startNode->nextPtr = NULL;
        nodeBuffer = startNode;
        nodeCounter = 2;
        while (nodeCounter <= argc)
        {
            newNode = (struct node *)malloc(sizeof(struct node));
            if (newNode == NULL)
                break;
            else
            {
                newNode->data = nodeData;
                newNode->nextPtr = NULL;
                nodeBuffer->nextPtr = newNode;  // Links the previous node to the current node
                nodeBuffer = nodeBuffer->nextPtr;   // Copies the address of the current node
            }
            nodeCounter++;
        }
    }
}

typedef struct s_list
{
	void			*pt_ints;
	struct s_list	*next;
}					t_list;

t_list	*ft_lstnew(void *pt_ints)
{
	t_list	*newnode;

	newnode = (t_list *)malloc(sizeof(t_list));
	if (newnode == NULL)
		return (NULL);
	if (pt_ints == NULL)
		newnode->pt_ints = NULL;
	else
		newnode->pt_ints = pt_ints;
	newnode->next = NULL;
	return (newnode);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	if (lst->next == NULL)
		return (lst);
	return (ft_lstlast(lst->next));
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lastitem;

	if (!lst)
		return ;
	if (*lst)
	{
		lastitem = ft_lstlast(*lst);
		lastitem->next = new;
	}
	else
		*lst = new;
}

int *ft_stack_receive(int argc, char **argv)
{
    int *pt_ints;
    int *ptr_len;
    int ints;
    t_list  *newnode;
    int i;

    pt_ints = &ints[0];
    i = 1;
    while (i < argc)        // argc zählt den ersten String in argv mit und der ist immer ./a.out
    {
        ints = ft_atoi(argv[i]);
        if (i == 1)
            newnode = ft_lstnew(ints);
        else
        {
            ft_lstadd_back(newnode, ints);  // oder doch ft_lstnew(ints) als Argument?
        }
        //ints[i - 1] = convert;
        //printf("Zahlen: %d", ints[i - 1]);  INTS AUSDRUCKEN!
        i++;
    }
    ptr_len = ft_l_i_subsequence(argc, pt_ints);
    //printf("loop:%d & len: %ls", ints[i - 1], ptr_len);
    return(pt_ints);
}

int main(int argc, char **argv)
{ 
    printf("sequence of 2, 1, 3, 6, 5, 8 = %d\n", *ft_stack_receive(argc, argv));  
    return(0);
}
