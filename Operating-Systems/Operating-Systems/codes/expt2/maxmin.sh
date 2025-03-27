echo "Enter the number"
read n
max=-1
min=10
while [ $n -gt 0 ]
do
	rem=$(($n%10))
	if [ $rem -lt $min ]
	then
		min=$rem
	fi
	if [ $rem -gt $max ]
	then
		max=$rem
	fi
	n=$(($n/10))
done
echo "Maximum digit - $max"
echo "Minimum digit - $min"
