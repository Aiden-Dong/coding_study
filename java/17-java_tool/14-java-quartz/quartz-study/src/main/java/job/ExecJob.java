package job;

import org.joda.time.format.ISODateTimeFormat;
import org.quartz.Job;
import org.quartz.JobExecutionContext;
import org.quartz.JobExecutionException;

/***
 * <pre>
 * </pre>
 * @user : saligia
 * @date : 2018-06-21
 */
public class ExecJob implements Job {
    public void execute(JobExecutionContext jobExecutionContext) throws JobExecutionException {
        System.out.println("JobRunTime : " + ISODateTimeFormat.dateTime().print(jobExecutionContext.getJobRunTime())); // 作业运行的时间量
        System.out.println("FireTime : " + ISODateTimeFormat.dateTime().print(jobExecutionContext.getFireTime().getTime()));   // 触发器的实际时间
        System.out.println("ScheduledFireTime" + ISODateTimeFormat.dateTime().print(jobExecutionContext.getScheduledFireTime().getTime()));    // 触发器的预定时间
        System.out.println("NextFireTime" + ISODateTimeFormat.dateTime().print(jobExecutionContext.getNextFireTime().getTime()));
        if(jobExecutionContext.getPreviousFireTime() != null){
            System.out.println("PreviousFireTime" + ISODateTimeFormat.dateTime().print(jobExecutionContext.getPreviousFireTime().getTime()));
        }
        System.out.println("===================================================================================================================");
    }
}
