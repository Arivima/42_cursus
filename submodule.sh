# https://gist.github.com/gitaarik/8735255
# https://git-scm.com/book/en/v2/Git-Tools-Submodules
# https://chrisjean.com/git-submodules-adding-using-removing-and-updating/



echo "git submodule update --init --recursive;"            && git submodule update --init --recursive;
echo "checking out of 01_libft"            && cd 01_libft         && git checkout master && cd ..;
echo "checking out of 02_ftprintf"         && cd 02_ftprintf      && git checkout master && cd ..;
echo "checking out of 03_get_next_line"    && cd 03_get_next_line && git checkout master && cd ..;
echo "checking out of 04_netwhat"          && cd 04_netwhat       && git checkout main && cd ..;
echo "checking out of 06_push_swap"        && cd 06_push_swap     && git checkout master && cd ..;
echo "checking out of 07_fdf"              && cd 07_fdf           && git checkout master && cd ..;
echo "checking out of 08_pipex"            && cd 08_pipex         && git checkout master && cd ..;
echo "checking out of 09_minishell"        && cd 09_minishell     && git checkout master && cd ..;
echo "checking out of 11_philosophers"     && cd 11_philosophers  && git checkout master && cd ..;
echo "checking out of 13_cub3D"            && cd 13_cub3D         && git checkout master && cd ..;
echo "checking out of 14_piscine_CPP"      && cd 14_piscine_CPP   && git checkout master && cd ..;
echo "checking out of 15_netpractice"      && cd 15_netpractice   && git checkout main && cd ..;
echo "checking out of 16_ft_containers"    && cd 16_ft_containers && git checkout master && cd ..;
echo "checking out of 17_inception"        && cd 17_inception     && git checkout main && cd ..;
echo "checking out of ___exams"            && cd ___exams         && git checkout main && cd ..;
echo "adding, commiting, pushing"   && git add . && git commit -m "pointer update" && git push;
