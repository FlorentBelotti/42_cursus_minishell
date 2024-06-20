/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:04:52 by fbelotti          #+#    #+#             */
/*   Updated: 2024/06/20 11:49:09 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/minishell.h"

int ft_env(t_command *cmd, t_env *env)
{
	if (cmd->parts[1] == NULL)
		print_env(env);
	else
		return (1);
	return (0);
}
