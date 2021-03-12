#!/bin/bash

color1=\\e[38\;5\;50m # light green
color2=\\e[38\;5\;75m # blue
color3=\\e[38\;5\;214m # Orange
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
arg1=$1
max=30 # test count

if [ $# -ne 1 ] ; then
	echo -e "$color1 TEST option plz : -3\t-5\t-100\t-500"
	exit
fi

if [[ $option_3 != $arg1 ]] && [[ $option_5 != $arg1 ]] && [[ $option_100 != $arg1 ]] && [[ $option_500 != $arg1 ]]; then
	echo -e "$color1 TEST option plz : -3\t-5\t-100\t-500"
	exit
fi

if [[ $option_3 == $arg1 ]] ; then
	#################################################
	#####				TEST ARGS=3				#####
	#################################################
	echo -e "\n\n\n\n$color1========================"
	echo -e "      $color2[TEST START]"
	echo -e "[ARGS]     \t   [$color3 3 $color2]"
	echo -e "[MAX]\t$color4...\t   $color2[$color3 3 $color2]"
	echo -e "$color1========================"
	i=0

	while [ $i -le $max ]
	do
		ARG=$(./make_number 3) && ./push_swap $ARG > temp
		var=$(cat ./temp | wc -l)
		RESULT=$(cat temp | ./checker $ARG)
		echo -ne "\r$color3[$i]"
		tput el
		echo -ne "\t"
		for ((j=0; j<$var; j++));
		do
			echo -ne "$color4."
		done
		echo -e "\n$color1========================"
		echo -ne "\r$color2[INPUT ARGS] :$color3 3\n"
		echo -ne "$color2[CMD LINES] :$color3 $var\n"
		echo -ne "$color2[CHECKER] :$color3 $RESULT"
		if [ $i -lt $max ] ; then
			tput cuu1
			tput cuu1
			tput cuu1
		fi
		((i++))
	done
	echo -e "\n$color1========================"
	echo -e "$color2\t[TEST END]"
	echo -e "$color1========================"
fi

if [[ $option_5 = $arg1 ]] ; then
	#################################################
	#####				TEST ARGS=5				#####
	#################################################
	echo -e "\n\n\n\n$color1=========================="
	echo -e "       $color2[TEST START]"
	echo -e "[ARGS]\t              [$color3 5 $color2]"
	echo -e "[MAX]\t$color4............ $color2[$color3 12 $color2]"
	echo -e "$color1=========================="
	i=0
	while [ $i -le $max ]
	do
		ARG=$(./make_number 5) && ./push_swap $ARG > temp
		var=$(cat ./temp | wc -l)
		RESULT=$(cat temp | ./checker $ARG)
		echo -ne "\r$color3[$i]"
		tput el
		echo -ne "\t"
		for ((j=0; j<$var; j++));
		do
			echo -ne "$color4."
		done
		echo -e "\n$color1=========================="
		echo -ne "\r$color2[INPUT ARGS] :$color3 5\n"
		echo -ne "$color2[CMD LINES] :$color3 $var\n"
		echo -ne "$color2[CHECKER] :$color3 $RESULT"

		if [ $i -lt $max ] ; then
		tput cuu1
		tput cuu1
		tput cuu1
		fi
		((i++))
	done
	echo -e "\n$color1=========================="
	echo -e "$color2\t[TEST END]"
	echo -e "\e$color1=========================="
	rm ./temp
fi

if [[ $option_100 = $arg1 ]] ; then
	#################################################
	#####				TEST ARGS=100			#####
	#################################################
	echo -e "\n\n\n\n$color1=========================="
	echo -e "       $color2[TEST START]"
	echo -e "[ARGS]\t              [$color3 100 $color2]"
	i=0
	while [ $i -le $max ]
	do
		ARG=$(./make_number 100) && ./push_swap $ARG > temp
		var=$(cat ./temp | wc -l)
		RESULT=$(cat temp | ./checker $ARG)
		echo -e "$color1=========================="
		echo -ne "$color2[CMD LINES] :$color3 $var\n"
		echo -ne "$color2[CHECKER] :$color3 $RESULT\n"
		((i++))
	done
	echo -e "$color1=========================="
	echo -e "$color2\t[TEST END]"
	echo -e "\e$color1=========================="
	rm ./temp
fi

if [[ $option_500 = $arg1 ]] ; then
	#################################################
	#####				TEST ARGS=500			#####
	#################################################
	echo -e "\n\n\n\n$color1=========================="
	echo -e "       $color2[TEST START]"
	echo -e "[ARGS]\t              [$color3 500 $color2]"
	i=0
	while [ $i -le $max ]
	do
		ARG=$(./make_number 500) && ./push_swap $ARG > temp
		var=$(cat ./temp | wc -l)
		RESULT=$(cat temp | ./checker $ARG)
		echo -e "$color1=========================="
		echo -ne "$color2[CMD LINES] :$color3 $var\n"
		echo -ne "$color2[CHECKER] :$color3 $RESULT\n"
		((i++))
	done
	echo -e "$color1=========================="
	echo -e "$color2\t[TEST END]"
	echo -e "\e$color1=========================="
	rm ./temp
fi
rm ./temp