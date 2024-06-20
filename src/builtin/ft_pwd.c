/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:05:02 by fbelotti          #+#    #+#             */
/*   Updated: 2024/06/20 11:49:09 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/minishell.h"

int ft_pwd(void)
{
	char *pwd;

	pwd = get_current_working_directory();
	printf("%s\n", pwd);
	free(pwd);
	return (0);
}
