import tensorflow as tf


if __name__ == '__main__':
    # 基本运算 : + - * / % //
    a = tf.ones([2,2])
    b = tf.ones([2,2])

    c = a + b

    print(c)

    # 对数, 指数
    print(tf.math.log(a))
    tf.math.log
    print(tf.math.exp(a))

    # 平方与开方
    print(tf.math.pow(c, 2))
    print(tf.math.sqrt(c))

    # 矩阵乘法 @ / matmul
    print(a@b)
    print(tf.matmul(a,b))

    tf.math.reduce_min


    #################################################################################


    # 范数

    f = tf.constant([1,2,3,4,5,6], dtype=tf.float32)
    print(tf.norm(f))

    # 统计计算
    # reduce_min : 最小值
    # reduce_max : 最大值
    # reduce_mean : 均值

    print(tf.math.reduce_mean(a))

    # argmax / argmin  最大值为孩子

    print(tf.math.argmax(f))

    # unique  去重
    print(tf.unique(f))


    # sort
    print(tf.sort(f, direction="DESCENDING"))

    # argsort 返回大小的位置
    print(tf.argsort(f))

    #top_k
    print(tf.math.top_k())


