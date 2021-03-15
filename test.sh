#!/bin/bash

color1=\\033[38\;5\;50m # light gr03333
color2=\\033[38\;5\;75m # b033ue
color3=\\033[38\;5\;214m # Orange
color4=\\033[1\;31m # red

echo -e "$color1                                                                  _                     "
echo -e "                                                  _ __  _   _ ___| |__    _____      ____ _ _ __   "
echo -e "                                                 |  _ \| | | / __|  _ \  / __\ \ /\ / / _  |  _ \ "
echo -e "                                                 | |_) | |_| \__ \ | | | \__ \\ V  V / (_| | |_) | "
echo -e "                                                 |  __/ \____|___/_| |_| |___/ \_/\_/ \__ _|  __/  "
echo -e "                                                 |_|                                       |_|                			  $color2- hroh\n\n\n"

option_3="-3"
option_5="-5"
option_100="-100"
option_500="-500"
file1=./push_swap
file2=./checker
arg1=$1
max=10 # test count default

if [ $# -ne 1 ] && [ $# -ne 2 ] ; then
	echo -e "$color1 TEST OPTION\n ARG1 : -3, -5, -100, -500\n ARG2 : test count [default : 10]"
	exit
fi

if [[ $option_3 != $arg1 ]] && [[ $option_5 != $arg1 ]] && [[ $option_100 != $arg1 ]] && [[ $option_500 != $arg1 ]]; then
	echo -e "$color1 TEST OPTION ERR\n ARG1 : -3, -5, -100, -500"
	exit
fi

if [ $# -eq 2 ] ; then
	max=$2 # test count = arg2
fi

if [ -f $file1 ] && [ -f $file1 ] ; then
	echo ""
else
	make
fi

gcc ./src/test/make_number.c -L./libft -lft -o make_number
touch temp

if [[ $option_3 == $arg1 ]] ; then
	echo -e "\n\n\n\n$color1========================"
	echo -e "      $color2[TEST START]"
	echo -e "[ARGS]     \t   [$color3 3 $color2]"
	echo -e "[MAX]\t$color4...\t   $color2[$color3 3 $color2]"
	echo -e "$color1========================"
fi
if [[ $option_5 = $arg1 ]] ; then
	echo -e "\n\n\n\n$color1=========================="
	echo -e "       $color2[TEST START]"
	echo -e "[ARGS]\t              [$color3 5 $color2]"
	echo -e "[MAX]\t$color4............ $color2[$color3 12 $color2]"
	echo -e "$color1=========================="
fi

if [[ $option_3 == $arg1 ]] || [[ $option_5 = $arg1 ]] ; then
	i=0
	test_num=$(($arg1 * -1))
	while [ $i -le $max ]
	do
		ARG=$(./make_number $test_num) && ./push_swap $ARG > temp
		var=$(cat ./temp | wc -l)
		RESULT=$(cat temp | ./checker $ARG)
		echo -ne "\r$color3[$i]"
		tput el
		echo -ne "\t"
		for ((j=0; j<$var; j++));
		do
			echo -ne "$color4."
		done
		echo ""
		((i++))
	done
	if [[ $option_3 == $arg1 ]] ; then
	echo -e "\n$color1========================"
	echo -e "$color2\t[TEST END]"
	echo -e "$color1========================"
	fi
	if [[ $option_5 = $arg1 ]] ; then
	echo -e "\n$color1=========================="
	echo -e "$color2\t[TEST END]"
	echo -e "$color1=========================="
	fi
fi

if [[ $option_100 = $arg1 ]] || [[ $option_500 = $arg1 ]] ; then
	test_num=$(($arg1 * -1))
	echo -e "\n\n\n\n$color1=========================="
	echo -e "       $color2[TEST START]"
	echo -e "[ARGS]\t           [$color3 $test_num $color2]"
	i=0
	while [ $i -le $max ]
	do
		ARG=$(./make_number $test_num) && ./push_swap $ARG > temp
		var=$(cat ./temp | wc -l)
		RESULT=$(cat temp | ./checker $ARG)
		echo -e "$color1=========================="
		echo -ne "$color2[CMD LINES] :$color3 $var\n"
		echo -ne "$color2[CHECKER] :$color3 $RESULT\n"
		((i++))
	done
	echo -e "$color1=========================="
	echo -e "$color2\t[TEST END]"
	echo -e "$color1=========================="
fi

rm ./temp
rm ./make_number