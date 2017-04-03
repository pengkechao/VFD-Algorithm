#! /bin/bash

preA="m4Dr4_A"
preB="m4Dr4_B"
w="_"
r=4
for ((s=0;s<6;s=s+1))
	do
	for((num=1100;num<2800;num=num+100))
		do 
			filenameA=${preA}${num}${w}${s}
			filenameB=${preB}${num}${w}${s}
			edges=$[$num*$r/10]
			./genm4D $num $edges $filenameA $filenameB
		done
done

