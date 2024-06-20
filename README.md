<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
</head>
<body>
    <header>
        <h1>42_cursus_minishell</h1>
        <p>A project to create a simple shell.</p>
    </header>
    <nav>
        <h2>Table of Contents</h2>
        <ul>
            <li><a href="#introduction">Introduction</a></li>
            <li><a href="#common-instructions">Common Instructions</a></li>
            <li><a href="#mandatory-part">Mandatory Part</a></li>
            <li><a href="#code-overview">Code Overview</a></li>
        </ul>
    </nav>
    <section id="introduction">
        <h2>Introduction</h2>
        <p>The Minishell project is about creating a simple shell similar to bash. This project helps in understanding processes, file descriptors, and signal handling by implementing a functional command-line interface.</p>
    </section>
    <section id="common-instructions">
        <h2>Common Instructions</h2>
        <ul>
            <li>The project must be written in C and conform to the coding norm.</li>
            <li>Functions must handle errors gracefully without causing unexpected termination (e.g., segmentation faults).</li>
            <li>All allocated memory must be properly freed to avoid leaks.</li>
            <li>A Makefile must be provided to compile the project with the necessary flags: -Wall, -Wextra, and -Werror.</li>
            <li>The Makefile should include at least the rules: <code>$(NAME)</code>, <code>all</code>, <code>clean</code>, <code>fclean</code>, and <code>re</code>.</li>
        </ul>
    </section>
    <section id="mandatory-part">
        <h2>Mandatory Part</h2>
        <p>Your Minishell must implement the following features:</p>
        <ul>
            <li>Display a prompt when waiting for a new command.</li>
            <li>Have a working history feature.</li>
            <li>Search and launch the right executable based on the PATH variable or using a relative or an absolute path.</li>
            <li>Handle single and double quotes, environment variables, and special characters like <code>$</code> and <code>?</code>.</li>
            <li>Implement redirections: <code><</code>, <code>></code>, <code><<</code>, and <code>>></code>.</li>
            <li>Implement pipes <code>|</code>.</li>
            <li>Handle signals: <code>ctrl-C</code>, <code>ctrl-D</code>, and <code>ctrl-\</code>.</li>
            <li>Implement built-in commands: <code>echo</code>, <code>cd</code>, <code>pwd</code>, <code>export</code>, <code>unset</code>, <code>env</code>, and <code>exit</code>.</li>
        </ul>
    </section>
    <section id="code-overview">
        <h2>Code Overview</h2>
        <h3>Parsing</h3>
        <p>(To be filled by partner)</p>
        <h3>Execution</h3>
        <p>The execution part of the Minishell project includes the following files:</p>
        <ul>
            <li><code>cmd_exec_utils.c</code>: Utility functions for command execution.</li>
            <li><code>cmd_exec.c</code>: Main command execution logic.</li>
            <li><code>cmd_path.c</code>: Handles the resolution of executable paths.</li>
            <li><code>cmd_process.c</code>: Manages the creation and handling of child processes.</li>
            <li><code>cmd_utils.c</code>: Additional utility functions for command processing.</li>
            <li><code>handle_pipes.c</code>: Functions to handle piping between commands.</li>
            <li><code>handle_redirections.c</code>: Functions to handle input and output redirections.</li>
            <li><code>builtin_path.c</code>: Functions related to path handling for built-in commands.</li>
            <li><code>builtin_utils.c</code>: Utility functions for built-in command handling.</li>
            <li><code>ft_cd.c</code>: Implementation of the `cd` built-in command.</li>
            <li><code>ft_echo.c</code>: Implementation of the `echo` built-in command.</li>
            <li><code>ft_env.c</code>: Implementation of the `env` built-in command.</li>
            <li><code>ft_exit.c</code>: Implementation of the `exit` built-in command.</li>
            <li><code>ft_export.c</code>: Implementation of the `export` built-in command.</li>
            <li><code>ft_pwd.c</code>: Implementation of the `pwd` built-in command.</li>
            <li><code>ft_unset.c</code>: Implementation of the `unset` built-in command.</li>
        </ul>
</body>
</html>
