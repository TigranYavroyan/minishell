/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:18:36 by healeksa          #+#    #+#             */
/*   Updated: 2025/01/16 16:18:04 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static char	*option_check(t_command_ptr command)
{
	char	*path;

	if (command->options->head->val[1])
	{
		set_status_unsigned(INV_ARG);
		return (printf("minishell: cd: %c%c: invalid option\n",
				command->options->head->val[0], command->options->head->val[1]),
			NULL);
	}
	path = get_bst(command->minishell->env, "OLDPWD");
	if (!path)
		return (__err_msg_prmt__("cd: ", "OLDPWD not set", 1), NULL);
	else if (path[0] == '\0')
		return (printf("\n"), NULL);
	return (path);
}

char	*path_resolve(t_command_ptr command)
{
	char	*path;

	if (!empty_lt(command->options))
	{
		path = option_check(command);
		if (path)
		{
			ft_putendl_fd(path, STDOUT_FILENO);
			return (path);
		}
		else
			return (NULL);
	}
	else if (empty_lt(command->args))
	{
		path = catch_home(command);
		if (!path)
			return (__err_msg_prmt__("cd: ", "HOME not set", 1), NULL);
		else if (path[0] == '\0')
			return (NULL);
	}
	else
		path = command->args->head->val;
	return (path);
}

bool	cwd_check(t_command_ptr command)
{
	char	*pwd_curr;
	char	*cwd;
	char	*old_pwd;

	cwd = getcwd(NULL, 0);
	if (cwd == NULL)
	{
		pwd_curr = ft_strdup(get_bst(command->minishell->env, "PWD"));
		old_pwd = ft_strdup(get_bst(command->minishell->env, "PWD"));
		ft_append(&pwd_curr, "/..");
		insert_bst(command->minishell->env, "OLDPWD", old_pwd);
		insert_bst(command->minishell->export, "OLDPWD", old_pwd);
		insert_bst(command->minishell->env, "PWD", pwd_curr);
		insert_bst(command->minishell->export, "PWD", pwd_curr);
		__err_msg__("cd: ", CDERR, 0);
		free(pwd_curr);
		free(old_pwd);
		return (false);
	}
	free(cwd);
	return (true);
}

void	ft_cd(t_command_ptr command)
{
	char	*path;
	char	*tmp_pwd;

	path = path_resolve(command);
	if (!path)
		return ;
	tmp_pwd = get_pwd();
	if (!ft_chdir(path, command))
	{
		return (auto_free(&tmp_pwd));
	}
	if (!cwd_check(command))
		return (auto_free(&tmp_pwd));
	set_pwd(tmp_pwd, command);
	free(tmp_pwd);
}
