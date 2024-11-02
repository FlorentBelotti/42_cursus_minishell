<div align="left">

### 42_cursus_minishell![---------------------------------------------------](https://raw.githubusercontent.com/andreasbm/readme/master/assets/lines/rainbow.png)

<div align="left">

![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white)

<nav>
    
### Summary![---------------------------------------------------](https://raw.githubusercontent.com/andreasbm/readme/master/assets/lines/rainbow.png)

<ul>
    <li><a href="#introduction">Introduction</a></li>
    <li><a href="#common-instructions">Common Instructions</a></li>
    <li><a href="#mandatory-part">Mandatory Part</a></li>
    <li><a href="#code-overview">Code Overview</a></li>
    <li><a href="#feedback">Feedback</a></li>
    <li><a href="#organization-and-task-distribution">Organization and Task Distribution</a></li>
    <li><a href="#execution-breakdown">Execution Breakdown</a></li>
    <li><a href="#conclusion">Conclusion</a></li>
    <li><a href="#thanks">Thanks</a></li>
</ul>
</nav>

### Introduction![---------------------------------------------------](https://raw.githubusercontent.com/andreasbm/readme/master/assets/lines/rainbow.png)
<section id="introduction">

<div align="justify">

The Minishell project is about creating a simple shell similar to bash. This project helps in understanding processes, file descriptors, and signal handling by implementing a functional command-line interface.

<div align="left">

### Common Instructions![---------------------------------------------------](https://raw.githubusercontent.com/andreasbm/readme/master/assets/lines/rainbow.png)
<section id="common-instructions">

<ul>
    <li>The project must be written in C and conform to the coding norm.</li>
    <li>Functions must handle errors gracefully without causing unexpected termination (e.g., segmentation faults).</li>
    <li>All allocated memory must be properly freed to avoid leaks.</li>
    <li>A Makefile must be provided to compile the project with the necessary flags: -Wall, -Wextra, and -Werror.</li>
    <li>The Makefile should include at least the rules: <code>$(NAME)</code>, <code>all</code>, <code>clean</code>, <code>fclean</code>, and <code>re</code>.</li>
</ul>
</section>

<div align="left">

### Mandatory Part![---------------------------------------------------](https://raw.githubusercontent.com/andreasbm/readme/master/assets/lines/rainbow.png)
<section id="mandatory-part">

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

<div align="left">

### Code Overview![---------------------------------------------------](https://raw.githubusercontent.com/andreasbm/readme/master/assets/lines/rainbow.png)
<section id="code-overview">

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
    <li><code>ft_cd.c</code>: Implementation of the <code>cd</code> built-in command.</li>
    <li><code>ft_echo.c</code>: Implementation of the <code>echo</code> built-in command.</li>
    <li><code>ft_env.c</code>: Implementation of the <code>env</code> built-in command.</li>
    <li><code>ft_exit.c</code>: Implementation of the <code>exit</code> built-in command.</li>
    <li><code>ft_export.c</code>: Implementation of the <code>export</code> built-in command.</li>
    <li><code>ft_pwd.c</code>: Implementation of the <code>pwd</code> built-in command.</li>
    <li><code>ft_unset.c</code>: Implementation of the <code>unset</code> built-in command.</li>
</ul>
</section>

<div align="left">

### Feedback![---------------------------------------------------](https://raw.githubusercontent.com/andreasbm/readme/master/assets/lines/rainbow.png)
<section id="feedback">

<h3>By Florent Belotti</h3>
<p>Minishell is one of the most daunting projects for 42 students, primarily due to feedback from previous cohorts. It’s our first group project, which means learning to collaborate on developing a program. Finding a good working dynamic with your partner is crucial.</p>
<p>This project is complex and often requires rethinking certain parts to integrate all necessary components. After completing a significant portion of the project, it is essential to redo series of tests whenever there is a change in logic to fix bugs. Therefore, it is important not to overload with tests and to remain reasonable about their number to validate the subject.</p>

<div align="left">

### Organization and Task Distribution![---------------------------------------------------](https://raw.githubusercontent.com/andreasbm/readme/master/assets/lines/rainbow.png)
<section id="organization-and-task-distribution">

<p>In our group, named "the brute and the cunning", ZomDev and I decided to clearly separate our responsibilities: he handled the parsing, and I took care of the execution. ZomDev, being slightly ahead in the curriculum, started before I did. His work on parsing allowed me to quickly develop an execution logic.</p>
</section>

<div align="left">

### Execution Breakdown![---------------------------------------------------](https://raw.githubusercontent.com/andreasbm/readme/master/assets/lines/rainbow.png)
<section id="execution-breakdown">

<p>For this project, I divided the execution into four main parts:</p>
<ol>
    <li>
        <strong>Redirections:</strong>
        <p>It was crucial to define a method that would allow calling the same redirection function regardless of the execution case. This part took a lot of time, especially since I wasn't very comfortable with the concept after the Pipex project. Now, I feel more confident and proficient in this area.</p>
    </li>
    <li>
        <strong>Execution Loop:</strong>
        <p>Coming from Pipex, the execution loop seemed more straightforward, although Minishell required some adjustments, particularly for implementing certain builtins and managing memory leaks.</p>
    </li>
    <li>
        <strong>Implementing Builtins:</strong>
        <p>This part was the simplest, resembling the logic of the piscine and the first projects at the school. It didn't pose much difficulty.</p>
    </li>
    <li>
        <strong>Error Code Management:</strong>
        <p>My inexperience led me to consider this aspect only at the end of the "mechanical" development of the execution. This forced me to rethink part of the organization of my execution and perform tedious tasks, such as changing the return of certain functions. I suggest considering error management from the beginning, systematically researching the possible errors for each part of the execution and implementing them immediately.</p>
    </li>
</ol>
</section>

<div align="left">

### Conclusion![---------------------------------------------------](https://raw.githubusercontent.com/andreasbm/readme/master/assets/lines/rainbow.png)
<section id="conclusion">

<p>Overall, my experience with Minishell was less stressful than some of my peers. Although I felt some pressure as my blackhole approached, being only a month away from the submission date, I benefited from the support of my more experienced partner. We collaborated effectively when I encountered difficulties and stayed focused on the execution.</p>
<p>Even if the project is complex, it significantly contributed to my learning in C. I feel more comfortable with managing processes and file descriptors than before, and I gained a deeper understanding of what a shell is and how it works.</p>
</section>

<div align="left">

### Thanks![---------------------------------------------------](https://raw.githubusercontent.com/andreasbm/readme/master/assets/lines/rainbow.png)
<section id="thanks">

<p>Thanks to ZomDev for his guidance and help throughout this project. Special thanks to 42 for providing this enriching experience.</p>
</section>

</div>
</div>

