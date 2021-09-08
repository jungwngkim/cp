TEMPLATE=./src/template.cc
FILE=./src/$1.cc

if [ -f $FILE ]; then
    # Create new file? or open the file?
    echo Opening $1.cc
    code $FILE
else
    echo Creating $1.cc in ./src
    cp $TEMPLATE $FILE
    echo Opening $1.cc
    code $FILE
fi