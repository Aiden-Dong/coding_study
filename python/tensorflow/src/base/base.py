import tensorflow as tf


if __name__ == '__main__':
    # 正态分布随机值
    a = tf.random.normal([2,2], dtype=tf.float32)
    print(a)

    b = tf.zeros([2,2])
    print(b)

    # 均匀分布初始值
    c = tf.random.uniform([2,2], minval=1, maxval=2, dtype=tf.float32)

    print(c)

    # 普通初始化
    d = tf.constant([1,2,3,5], dtype=tf.int32)

    # 转置
    print(tf.transpose(a))





