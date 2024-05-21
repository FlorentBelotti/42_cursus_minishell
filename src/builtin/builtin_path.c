/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:37:25 by fbelotti          #+#    #+#             */
/*   Updated: 2024/05/21 12:02:36 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	builtin_in_child(t_command *cmd, t_env *env)
{
	(void)env;
	if (cmd->builtin_flag == BUILTIN_ECHO)
		ft_echo(cmd);
	else if (cmd->builtin_flag == BUILTIN_PWD)
		ft_pwd();
	else if (cmd->builtin_flag == BUILTIN_ENV)
		ft_env(env);
}

void	builtin_out_child(int i, t_exec *exec, t_command *cmd, t_env *env)
{
	handle_redir_entering_exec(i, exec);
	if (handle_redirections(cmd->redirections, exec) == 1)
		return ;
	else if (cmd->builtin_flag == BUILTIN_CD)
		ft_cd(cmd, env);
	if (cmd->builtin_flag == BUILTIN_EXPORT)
		ft_export(cmd, env);
	if (cmd->builtin_flag == BUILTIN_UNSET)
		ft_unset(cmd, env);
	if (cmd->builtin_flag == BUILTIN_EXIT)
		ft_exit(cmd);
	handle_redir_leaving_exec(i, exec);
}

int	check_builtin_path(t_command *cmd)
{
	if (cmd->builtin_flag > NOT_A_BUILTIN && cmd->builtin_flag <= BUILTIN_PWD)
		return (0);
	else if (cmd->builtin_flag > BUILTIN_PWD)
		return (1);
	else
		return (-1);
}