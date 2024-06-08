/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:29:46 by truello           #+#    #+#             */
/*   Updated: 2024/06/08 16:09:59 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	parse_and_execute_line(char *line, t_env *env, t_exec *exec)
{
	t_token		*tlist;
	t_command	*cmds;

	if (line[0] == '\0')
	{
		free(exec);
		return ;
	}
	cmds = NULL;
	tlist = tokenize(line, exec);
	parse_commands(tlist, &cmds);
	free_token(tlist);
	if (!check_commands(cmds))
	{
		free(exec);
		return (free_command(cmds), (void) 0);
	}
	if (is_command_valid(cmds, env) == 1)
		handle_execution(line, cmds, env, exec);
	else
		free(exec);
	free_command(cmds);
}

int	main(int ac, char **av, char **envp)
{
	char	*line;
	t_exec	*exec;
	t_env	*env;

	(void)ac;
	(void)av;
	env = make_env(envp);
	exec = NULL;
	setup_signal_handler();
	line = readline("minishell > ");
	if (line && line[0] != '\0')
		add_history(line);
	while (line)
	{
		if (!exec)
			exec = make_exec_structure();
		exec->env = env;
		exec->error_flag = 0;
		parse_and_execute_line(line, env, exec);
		free(line);
		line = readline("minishell > ");
		if (line && line[0] != '\0')
			add_history(line);
	}
	rl_clear_history();
	return (ft_free(line), free_env(env), 0);
}
