/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:29:46 by truello           #+#    #+#             */
/*   Updated: 2024/06/04 15:22:40 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	basic_status;

static void	parse_and_execute_line(char *line, t_env *env, t_exec *exec)
{
	t_token		*tlist;
	t_command	*cmds;

	if (line[0] == '\0')
		return ;
	cmds = NULL;
	tlist = tokenize(line, env);
	parse_commands(tlist, &cmds);
	//print_commands(cmds);
	free_token(tlist);
	if (!check_commands(cmds))
		return (free_command(cmds), (void) 0);
	if (is_command_valid(cmds, env) == 1)
		handle_execution(line, cmds, env, exec);
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
	setup_signal_handler();
	line = readline("minishell > ");
	if (line && line[0] != '\0')
		add_history(line);
	exec = make_exec_structure();
	while (line)
	{
		parse_and_execute_line(line, env, exec);
		free(line);
		line = readline("minishell > ");
		if (line && line[0] != '\0')
			add_history(line);
	}
	rl_clear_history();
	return (ft_free(line), free_env(env), 0);
}
