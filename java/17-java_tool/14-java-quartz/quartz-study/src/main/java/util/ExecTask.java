package util;

import job.ExecJob;
import org.joda.time.DateTime;
import org.quartz.*;
import org.quartz.impl.StdSchedulerFactory;
import org.quartz.simpl.SimpleThreadPool;
import test.Student;

import java.util.Date;

/***
 * <pre>
 * </pre>
 * @user : saligia
 * @date : 2018-06-21
 */
public class ExecTask {
    public static void main(String[] args) throws SchedulerException {

        // 创建调度 -- 从配置文件中获取
        SchedulerFactory factory = new StdSchedulerFactory();
        Scheduler scheduler = factory.getScheduler();

        // 创建作业
        JobDetail jobDetail = JobBuilder.newJob(ExecJob.class)
                .withIdentity("ExecJob", "ExecTask")
                .build();
        // 创建触发
        Trigger trigger = TriggerBuilder.newTrigger()
                .withIdentity("ExecJob", "ExecTask")
                .withSchedule(CronScheduleBuilder.cronSchedule("0 * * * * ?"))
                .startAt(new Date(DateTime.now().withTimeAtStartOfDay().getMillis()))
                .build();

        scheduler.scheduleJob(jobDetail, trigger);
        scheduler.start();



    }
}
