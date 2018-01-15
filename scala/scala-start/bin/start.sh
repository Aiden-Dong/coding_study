#!/usr/bin/env bash
JAR=""
for v_jar in $(find -name "*.jar" -print);
do
   JAR=${JAR}:${v_jar}
done

java -cp ${JAR} HelloScala