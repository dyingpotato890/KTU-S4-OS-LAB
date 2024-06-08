echo "Enter The Height: "
read height

for (( i=1;i<=$height;i++ ));
do
   for (( j=$height;j >= i;j-- ));
   do
   	echo -n " "
   done
   
   for (( c=1;c <= i;c++ ));
   do
   	echo -n " *"
   done
   
	echo ""
done

newHeight=`expr $height - 1`

for (( i=$newHeight;i>=1;i--));
do
   for (( j=i;j<=$newHeight;j++ ));
   do
   	if [ $j == $newHeight ]
   	then
   		echo -n " "
   	fi
   	echo -n " "
   done
   
   for (( c=1;c <= i;c++ ));
   do
   	echo -n " *"
   done
	echo ""
done
