/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:42:07 by truello           #+#    #+#             */
/*   Updated: 2024/06/20 11:49:09 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/minishell.h"

char get_redirection_char(int mode)
{
	if (mode == REDIR_IN || mode == REDIR_HD)
		return ('<');
	else
		return ('>');
}

void print_redirections(t_redirections *redirections)
{
	if (!redirections)
		return;
	printf("\n--- Redirections START ---\n");
	while (redirections)
	{
		printf("%s -> %d\n", redirections->path, redirections->mode);
		redirections = redirections->next;
	}
	printf("--- Redirections END ---\n");
}

void free_redirections(t_redirections *redirections)
{
	if (!redirections)
		return;
	if (redirections->next)
		free_redirections(redirections->next);
	free(redirections->path);
	free(redirections);
}
