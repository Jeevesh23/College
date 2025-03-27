echo "Enter the number"
read a
fact=1
x=1
while [ $x -le $a ]
	do 
		fact=$(($fact * $x))
		x=$(($x + 1))
	done


echo "factorial is - $fact"

