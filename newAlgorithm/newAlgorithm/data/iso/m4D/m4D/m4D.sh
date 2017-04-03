#! /bin/bash

preA="m4D_A"
preB="m4D_B"
w="_"
for ((s=0;s<6;s=s+1))
	do
	for((num=1100;num<2800;num=num+100))
		do 
			filenameA=${preA}${num}${w}${s}
			filenameB=${preB}${num}${w}${s}
			./genm4D $num 0 $filenameA $filenameB
		done
done

