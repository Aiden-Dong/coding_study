package job;

import map.DateTestMap;
import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.conf.Configured;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.NullWritable;
import org.apache.hadoop.mapreduce.Job;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;
import org.apache.hadoop.util.Tool;
import org.apache.hadoop.util.ToolRunner;
import org.joda.time.DateTimeZone;

/**
 * Created by saligia on 17-9-12.
 */
public class HadoopSaligia extends Configured  implements Tool{
    @Override
    public int run(String[] args) throws Exception {

        Configuration conf = new Configuration();
        conf.set("mapred.min.split.size", "1");
        conf.set("mapred.max.split.size", "256000000");

        Job job = Job.getInstance(conf, "TestData");
        job.setJarByClass(HadoopSaligia.class);

        job.setMapperClass(DateTestMap.class);

        String inPath = args[0];
        String outPath = args[1];

        FileInputFormat.addInputPath(job, new Path(inPath));
        FileOutputFormat.setOutputPath(job, new Path(outPath));

        job.setMapOutputKeyClass(NullWritable.class);
        job.setMapOutputValueClass(NullWritable.class);
        job.setOutputKeyClass(NullWritable.class);
        job.setOutputValueClass(NullWritable.class);

        job.setNumReduceTasks(0);

        return job.waitForCompletion(true) ? 0 : 1;
    }

    public static void main (String[] args) throws Exception{
        ToolRunner.run(new HadoopSaligia(), args);
    }
}
