#!/bin/bash

# THREE_PASS=3
# THREE_KUDO=2
# FIVE_PASS=12
# FIVE_KUDO=8
# HUNDRED_5=700
# HUNDRED_4=900
# HUNDRED_3=1100
# HUNDRED_2=1300
# HUNDRED_1=1500
# FIVE_HUNDRED_5=5500
# FIVE_HUNDRED_4=7000
# FIVE_HUNDRED_3=8500
# FIVE_HUNDRED_2=10000
# FIVE_HUNDRED_1=11500

RED='\033[01;31m'
GREEN='\033[01;32m'
YELLOW='\033[01;33m'
GRAY='\033[01;37m'

RESET='\033[00m'

echo "$YELLOW>>>>>>>>>>>>>>>>> COMPILATION <<<<<<<<<<<<<<<<<$RESET"
# rm -f randomizator
# gcc -Wall -Werror -Wextra randomizator.c -o randomizator && echo ">RANDOMIZATOR$GREEN OK$RESET" || (echo ">KO -> RANDOMIZATOR COMPILATION FAILED" && exit 1) 
make && echo ">PUSH_SWAP$GREEN OK$RESET" || (echo ">KO -> PUSH_SWAP COMPILATION FAILED" && exit 1)
# rm -f randomizator

echo "$YELLOW>>>>>>>>>>>>>>>>>    LEAKS   <<<<<<<<<<<<<<<<<$RESET"
leaks -atExit -- ./push_swap 1 2 3 4 10 12 13 15 6

echo "$YELLOW>>>>>>>>>>>>>>>>>    ERRORS   <<<<<<<<<<<<<<<<<$RESET"
echo bad input : no input
RET=`./push_swap 2> /dev/null` 
if [ "$RET" != "" ];
	then
	echo $RED FAIL $RESET
	else
	echo $GREEN OK $RESET
fi
echo "bad input : not just digits"
RET=`./push_swap 1 2 8 7 9 l 6 2> /dev/null`
if [ "$RET" != "" ];
	then
	echo $RED FAIL $RESET
	else
	echo $GREEN OK $RESET
fi
echo "bad input : duplicates"
RET=`./push_swap 2 3 5 6 8 9 4 5 2> /dev/null`
if [ "$RET" != "" ];
	then
	echo $RED FAIL $RESET
	else
	echo $GREEN OK $RESET
fi
echo "bad input : > MAX INT"
RET=`./push_swap 2147483650 2 2> /dev/null`
if [ "$RET" != "" ];
	then
	echo $RED FAIL $RESET
	else
	echo $GREEN OK $RESET
fi
echo "bad input : < MIN INT"
RET=`./push_swap -2147483650 2 2> /dev/null`
if [ "$RET" != "" ];
	then
	echo $RED FAIL $RESET
	else
	echo $GREEN OK $RESET
fi
echo "case_mgt : only one arg"
RET=`./push_swap 1 2> /dev/null`
if [ "$RET" != "" ];
	then
	echo $RED FAIL $RESET
	else
	echo $GREEN OK $RESET
fi
echo "case_mgt : already sorted"
RET=`./push_swap 1 2 3 4 5 6 7 8 9 2> /dev/null`
if [ "$RET" != "" ];
	then
	echo $RED FAIL $RESET
	else
	echo $GREEN OK $RESET
fi

echo "$YELLOW>>>>>>>>>>>>>>>>>    TESTING   <<<<<<<<<<<<<<<<<$RESET"
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrocca <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/18 21:22:55 by lrocca            #+#    #+#              #
#    Updated: 2021/05/18 21:22:55 by lrocca           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C_RESET="\e[0;0m"
C_BOLD="\e[1m"
C_RED="\e[0;31m"
C_GREEN="\e[0;32m"
C_YELLOW="\e[0;33m"
C_GRAY="\e[0;37m"
C_BLUE="\e[0;34m"
C_LGRAY="\e[0;90m"
C_LRED="\e[0;91m"
C_LGREEN="\e[0;92m"
C_LBLUE="\e[0;94m"
C_BGRAY="\e[1;30m"
C_BRED="\e[1;31m"
C_BGREEN="\e[1;32m"
C_BYELLOW="\e[1;33m"
C_BBLUE="\e[1;34m"

CHECKER=./checker
PUSH_SWAP=./push_swap
TMP=./test.tmp

print_stat() {
	printf "   $C_GRAY$1$C_RESET $C_BOLD$2$C_RESET"
}

test() {
	printf "${C_BBLUE}$1${C_RESET}\n"

	fail_ops=0
	ko_ops=0
	all_ops=()

	for i in $( seq 1 $3 )
	do
		ko=0
		echo "" > $TMP

		arg=`ruby -e "puts (1..$1).to_a.shuffle.join(' ')" 2> /dev/null`
		($PUSH_SWAP $arg 1> $TMP 2> /dev/null)
		ops=`wc -l < $TMP`
		checker=`$CHECKER $arg < $TMP 2> /dev/null`

		printf "${C_LGRAY}%-5i" ${i}

		all_ops[i]=$(($ops))

		if [[ $((ops)) -lt $2 ]]; then
			status=${C_LGREEN}
		elif [[ $((ops)) -eq $2 ]]; then
			status=${C_BYELLOW}
		else
			status=${C_BRED}
			fail_ops=$(($fail_ops + 1))
			ko=1
		fi

		printf "${status}%2i$C_RESET " $((ops))

		if [[ $checker == "OK" ]]; then
			status=${C_GREEN}
		else
			status=${C_RED}
			ko_ops=$(($ko_ops + 1))
			ko=1
		fi

		printf "${status}%5s$C_RESET" $checker

		if [[ $ko -eq 1 ]]; then
			echo -en "\t${arg}"
		fi

		echo
	done

	avg=$(IFS='+'; bc<<<"scale=1;(${all_ops[*]})/${#all_ops[@]}")

	if [[ ${avg::1} == "." ]]; then
		avg="0"$avg
	fi

	max=$(IFS=$'\n'; echo "${all_ops[*]}" | sort -nr | head -n1)
	max_times=$(echo ${all_ops[*]} | grep -o ${max} | wc -l | tr -d ' ')

	printf "$C_YELLOW$1$C_RESET"
	print_stat "avg" $avg
	print_stat "max" $max
	echo -n " ($max_times)"
	print_stat "fail" $fail_ops
	print_stat "ko" $ko_ops
	echo
	echo
}

touch $TMP

# test [range] [pass_value] [nb of tests]
test 3 3 10
test 5 12 50
test 100 1500 10
test 500 11500 10

rm $TMP