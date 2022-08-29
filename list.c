/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 22:47:30 by rschlott          #+#    #+#             */
/*   Updated: 2022/06/18 12:40:22 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* Counts the number of nodes in a list. */

int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 0;
	while (lst != NULL)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

#include "libft.h"
/* Create a new element for the list, to continue the
    end of the list. Returns a new node for the list. 
	Creates memory for each new item. */

t_list	*ft_lstnew(void *content)
{
	t_list	*newnode;

	newnode = (t_list *)malloc(sizeof(t_list));
	if (newnode == NULL)
		return (NULL);
	if (content == NULL)
		newnode->content = NULL;
	else
		newnode->content = content;
	newnode->next = NULL;
	return (newnode);
}

#include "libft.h"
/* First checking if list exists. Then checking for the 
last item and adding a new item behind the last. Else check 
if the list is empty. If so: creating the first item. */

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

#include "libft.h"
/* Returns the node for the last item of the list. 
    It's recursive. *lst is my pointer to the list. */

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	if (lst->next == NULL)
		return (lst);
	return (ft_lstlast(lst->next));
}

#include "libft.h"
/* del is the function that delets the content of the node(item).
    In free the memory of one particular node will be freeed. */

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == NULL || del == NULL)
	{
		return ;
	}
	else
	{
		del(lst->content);
		free(lst);
		return ;
	}
}

#include "libft.h"
/* deletes all elements of the list (the whole list). */

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*aux;

	if (!*lst)
		return ;
	while (*lst)
	{
		aux = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = aux;
	}
	*lst = 0;
}

