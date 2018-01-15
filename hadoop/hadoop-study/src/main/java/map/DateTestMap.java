package map;

import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.NullWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Mapper;
import org.joda.time.DateTime;
import org.joda.time.DateTimeZone;

import java.io.IOException;

/**
 * Created by saligia on 17-9-12.
 */
public class DateTestMap extends Mapper<LongWritable, Text, NullWritable, NullWritable> {

    @Override
    protected void setup(Context context) throws IOException, InterruptedException {
       // DateTimeZone.setDefault(DateTimeZone.forID("+0800"));
    }

    private enum MapCounter{
        LinesCount
    }

    @Override
    protected void map(LongWritable key, Text value, Context context) throws IOException, InterruptedException {
        context.getCounter(MapCounter.LinesCount).increment(1);
    }
}
