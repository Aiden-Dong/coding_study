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


    print(tf.math.reduce_mean(a))

