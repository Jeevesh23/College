echo "Enter the number"
read a
sum=0
x=1
while [ $x -le $a ]
	do 
		sum=$(($sum + $x))
		x=$(($x + 1))
	done

avg=$(($sum / $a))
echo "SUM is - $sum"
echo "AVERAGE is - $avg"

