#!/usr/bin/env bash

JRE=""

for vfile in $(find ${HADOOP_HOME}/ -name "*.jar" -print);
do
  JRE=${JRE}:${vfile}
done


JRE=lib/hadoop-study-1.0.jar:${JRE}
#echo ${JRE}

java -cp ${JRE} job.HadoopSaligia