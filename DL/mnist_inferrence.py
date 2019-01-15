import tensorflow as tf

INPUT_NODE=784
OUPIT_NODE=10

IMG_SIZE=28
NUM_CHANNEL=1
NUM_LABEL=10

FILTER_SIZE=5
CONV1_DEEP=32
CONV2_DEEP=64
FC_SIZE=512


def inference(input,train,regularizer):
    with tf.variable_scope("conv1"):
        conv1_w=tf.get_variable(
            'weight1',[FILTER_SIZE,FILTER_SIZE,NUM_CHANNEL,CONV1_DEEP],
            initializer=tf.truncated_normal_initializer(stddev=.1)
        )
        conv1_b=tf.get_variable(
            'bias1',[CONV1_DEEP],initializer=tf.constant(0.0)
        )
        conv1=tf.nn.conv2d(input,conv1_w,strides=[1,1,1,1,],padding='SAME')
        relu_conv1=tf.nn.relu(conv1+conv1_b)
    with tf.name_scope("pool1"):
        pool1=tf.nn.max_pool(relu_conv1,strides=[1,2,2,1],ksize=[1,2,2,1],padding='SAME')

    with tf.variable_scope('conv2'):
        conv2_w=tf.get_variable(
            'weight2',[FILTER_SIZE,FILTER_SIZE,CONV1_DEEP,CONV2_DEEP],
            initializer=tf.truncated_normal_initializer(stddev=0.1))
        conv2_b=tf.get_variable('bias2',[CONV2_DEEP],initializer=tf.constant(0.0))
        conv2=tf.nn.conv2d(pool1,conv2_b,strides=[1,1,1,1],padding='SAME')


