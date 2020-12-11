import tensorflow as tf
from sklearn.datasets import make_classification

"""
MLP 实现多分类问题
"""
if __name__ == '__main__':

    # 加载数据
    # x : [300 , 28, 28]
    # y : [60k]

    x,y  = make_classification(n_samples=30000, n_features=300, n_informative=150, n_classes=10)

    # 转换成 tensor
    x = tf.convert_to_tensor(x, dtype=tf.float32)
    y = tf.one_hot(tf.convert_to_tensor(y, dtype=tf.int32), depth=10)


    # 分批次拆解 batch
    train_db = tf.data.Dataset.from_tensor_slices((x,y)).batch(50)

    # 声明初始化参数 b
    w1 = tf.Variable(tf.random.truncated_normal([300, 256], stddev=0.1))
    b1 = tf.Variable(tf.zeros([256]))

    w2 = tf.Variable(tf.random.truncated_normal([256, 128], stddev=0.1))
    b2 = tf.Variable(tf.random.truncated_normal([128]))

    w3 = tf.Variable(tf.random.truncated_normal([128, 10], stddev=0.1))
    b3 = tf.Variable(tf.random.truncated_normal([10]))

    # 步长原始版
    lr = 1e-3

    # 遍历次数
    for epoch in range(10) :

        # 分批次运算
        for step, (x1, y1) in enumerate(train_db) :
            # x1, y1 为一个小批次 -- 50

            # 计算梯度
            with tf.GradientTape() as  tape :
                # layer1
                h1 = x1 @ w1 + b1
                z1 = tf.nn.sigmoid(h1)

                # layer2
                h2 = z1 @ w2 + b2
                z2 = tf.nn.sigmoid(h2)
                # layer3
                y_hat = z2 @ w3 + b3

                # loss
                mse = tf.math.reduce_mean(tf.math.square(y1 - y_hat), axis=0)
                # print(mse.shape)

            # 梯度监控
            grads = tape.gradient(mse, [w1, b1, w2, b2, w3, b3])

            # 原地更新
            w1.assign_sub(w1 - lr * grads[0])
            b1.assign_sub(b1 - lr * grads[1])
            w2.assign_sub(w2 - lr * grads[2])
            b2.assign_sub(b2 - lr * grads[3])
            w3.assign_sub(w3 - lr * grads[4])
            b3.assign_sub(b3 - lr * grads[5])


            # 打印损失
            if step % 100 == 0 :
                print('loss : ', float(tf.math.reduce_mean(mse)))