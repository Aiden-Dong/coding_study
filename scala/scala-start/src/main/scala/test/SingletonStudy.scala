package test

import test.interface.Logger
;

/**
 * <pre>
 * </pre>
 *
 * @author saligia
 * @date 18-4-16
 */
object SingletonStudy {

    def showMsg(msg:String, logger:Logger):Unit = {
        logger.logger(msg)
    }
}
