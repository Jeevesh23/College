echo "Enter the number of rows"
read n
m=$n
for ((i=1; i<=$n; i++))
do
	for ((j=1; j <= $m - 1; j++))
	do
		printf " "		
	done
	for ((k=1; k <= i; k++))
	do 
		printf "* "
	done
	m=$(($m-1))
	printf "\n"
done
