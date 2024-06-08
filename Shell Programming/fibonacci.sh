echo -n "Enter The Maximum Numbers in Series: "
read n

a=0
b=1

((n=n-2))

echo "Fibonacci Series:"
echo $a
echo $b

for((i=1;i<=n;i++))
do
    ((c=a+b))
    echo $c
    a=$b
    b=$c
done