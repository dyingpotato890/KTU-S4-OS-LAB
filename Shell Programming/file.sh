for item in *; do
    if [ -d $item ]; then
        echo "Directory: $item"
    fi

    if [ -f $item ]; then
        echo "File: $item"
    fi
done
