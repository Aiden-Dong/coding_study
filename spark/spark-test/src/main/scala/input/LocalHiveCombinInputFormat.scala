package input

import org.apache.hadoop.mapreduce.lib.input.CombineTextInputFormat


/**
 * <pre>
 * </pre>
 *
 * @author saligia
 * @date 18-3-23
 *
 */
class LocalHiveCombinInputFormat extends CombineTextInputFormat{
  setMaxSplitSize(512000000);
}
