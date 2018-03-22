#!/bin/bash

CLASSPATH=${CLASSPATH}

MAINCLASS=com.test.Log4JTestMain

for v_file in `find lib -name "*.jar" -print`
do
    CLASSPATH=${CLASSPATH}:${v_file}
done

CLASSPATH=${CLASSPATH}:conf

java -cp ${CLASSPATH} ${MAINCLASS}