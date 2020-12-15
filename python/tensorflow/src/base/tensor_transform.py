import tensorflow as tf


if __name__ == '__main__':
    a = tf.ones([3, 4, 9])
    b = tf.ones([3, 4, 9])

    # 拼接纬度不变
    print(tf.concat([a,b],  axis=0).shape)

    # 拼接 升高纬度
    print(tf.stack([a, b], axis=0).shape)



    # 数据的扩充填充 pad
    c = tf.fill((1,3), 1)

    print(c)
    print(tf.pad(c, [[0,0], [1,2]]))

    # 数据的复制 tile
    print(tf.tile(c, [1, 2]))