TEMPLATE=./content/template.cpp
FILE=./src/$1.cpp

if [ -f $FILE ]; then
    echo "[WARN] '$1.cpp' exists in './src'"
else
    echo "[INFO] creating '$1.cpp' in './src'"
    cp $TEMPLATE $FILE
fi

echo "[INFO] opening '$1.cpp'"
code $FILE