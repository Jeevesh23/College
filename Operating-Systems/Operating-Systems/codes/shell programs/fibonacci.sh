echo "Enter the number"
read n
a=0
b=1
e=$(($a + $b))
echo "$a"
echo "$b"

while [ $n -gt 0 ]
do
	echo "$e"
	a=$b
	b=$e
	e=$(($a + $b))
	n=$(($n - 1))
done	



