## Common Instructions

- [ ] Your project must be written in C.
- [ ] Your project must be written in accordance with the [Norminette](https://github.com/afmyhouse/norminette). If you have bonus files/functions, they are included in the norm check and you will receive a 0 if there is a norm error inside.
- [ ] Your functions should not quit unexpectedly (segmentation fault, bus error, double free, etc) apart from undefined behaviors. If this happens, your project will be considered non functional and will receive a 0 during the evaluation.
- [ ] All heap allocated memory space must be properly freed when necessary. No leaks will be tolerated.
- [ ] If the subject requires it, you must submit a Makefile which will compile your source files to the required output with the flags -Wall, -Wextra and -Werror, use cc, and your Makefile must not relink.
- [ ] Your [Makefile](https://github.com/afmyhouse/4201-makefile) must at least contain the rules **$(NAME)**, **all**, **clean**, **fclean** and **re**.
- [ ] To turn in bonuses to your project, you must include a rule bonus to your Makefile, which will add all the various headers, libraries or functions that are forbidden on the main part of the project. Bonuses must be in a different file \_**bonus.{c/h}** if the subject does not specify anything else. Mandatory and bonus part evaluation is done separately.
- [ ] If your project allows you to use your _**libft**_, you must copy its sources and its associated Makefile in a _**libft folder**_ with its associated _**Makefile**_. Your **project’s Makefile** must compile the library first, by using the **library Makefile**, then compile the whole project using the **project's Makefile**.
- [ ] We encourage you to create test programs for your project even though this work won’t have to be submitted and won’t be graded. It will give you a chance
to easily test your work and your peers’ work. You will find those tests especially useful during your defence. Indeed, during defence, you are free to use your tests and/or the tests of the peer you are evaluating.
- [ ] Submit your work to your assigned git repository. Only the work in the git repository will be graded. If Deepthought is assigned to grade your work, it will be done after your peer-evaluations. If an error happens in any section of your work during **Deepthought**’s grading, the evaluation will stop.
