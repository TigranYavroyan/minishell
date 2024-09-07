#include <minishell.h>

t_minishell_ptr init_minishell (char** env) {
	t_minishell_ptr minishell;

	minishell = (t_minishell_ptr)wrapper_malloc(sizeof(t_minishell));
	minishell->line = init_lt();
	minishell->env = matrix_to_bst(env, '=');

	return minishell;
}