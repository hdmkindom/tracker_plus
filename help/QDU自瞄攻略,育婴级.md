# QDU 自瞄调车攻略,育婴级

请先把相机硬件光圈拉到最高,gain给最大

# 编译的时候别忘记 openvino

# 硬件问题排查

### **串口问题** 最严重的问题

25赛季从我开始接手自瞄,开始和下位机软件一块调车开始,截至到我写这篇文章,这个问题一直存在.很严重,希望将 USB转ttl 当成一类消耗品

**问题表现** : 
1. Error creating serial port : 就是没串口,上位机没有连接串口或者串口炸了.如果是一个功能正常的串口,不管有没有连接下位机,当他连上上位机的时候,都会有反应,我们的自制串口一般是亮灯
2. 串口芯片附近带电,能电到手 : 串口线和USB端连接的部分,RX,TX,地,可能有相连短路的,一般是裸露在外的金属丝之类
3. 运行的时候一直报 tracker节点队列满,而且一般detector是正常工作的 : 这个情况一般是串口有问题,接触不良之类的,原因未知,有的时候动动串口就好了
4. 

###  相机问题

先去通读一下说明书
1. 看亮灯情况,具体去看说明书第10章,LED灯
2. 相机型号,去查手册
3. 会用MVS

**问题表现** : 
1. 连上相机,但是查不到相机 : 大部分情况是因为相机得等30s才有反映
2. 程序运行中中断,报 80000007 错误码 : 相机无法采集图像,去MVS看看
3. 
--- 
# 软件问题排查

软件问题主要是 PID 参数,就是头跟不上;此外还有通信问题

**问题表现** : 
1. foxglove 拉 send_pitch,receive_pitch;send_yaw,receive_yaw,发现接受的始终是慢了我们很多,放大看横坐标峰值差多少,这里我们可以去修改bias_time,但是还是建议让软件调硬一点PID,看看是调硬pitch还是yaw

关于 PID ,可以去了解一下 [了解PID](https://zhuanlan.zhihu.com/p/39573490) 基本的就是 三个部分 : 比例控制,积分控制,微分控制
具体去问电控同学了 

---

# 自瞄基本状况排查

## odom2camare

### xyz
这里放上去 相机光圈坐标系到odom (机器人旋转中心)的xyz值
1. 打击向左,向右
2. 打击向上,向下
### rpy
同上是相机正向向量的rpy

--- 
# 识别器问题排查

**问题表现** : 
1. 太暗了,导致看不清装甲板,或者装甲板正对着的时候闪烁 : 适当的调高高光阈值,太高会导致 detector 延迟变大,去foxglove拉/detector/latency 中detecor_latency,看看曲线情况,越低越好
2. 识别目标(敌车)静止情况下,上下左右摇晃本车的云台,发现在三维中看到 xyz 有速度箭头 : foxglove拉 position_x的曲线,观察静止时刻是否稳定,不稳定是预测器的问题;如果本车云台上下左右偏转,发现position_x变化很大,一般是下位机发的imu时间戳与我们的相机时间戳对不上,调整 timestamp_offset 的值,来让上下位机时间戳对齐
3. 自己调整曝光与二值化阈值

--- 

# 预测器问题排查

## EKF 噪声

### u_q 

### u_r

## 跳变问题

旋转 $\frac{1}{4}$ 圈不跳变(跳变频率小于旋转 $\frac{1}{4}$ 圈频率) 或者
旋转 $\frac{1}{4}$ 圈一直跳变(跳变频率大于旋转 $\frac{1}{4}$ 圈频率) : foxglove 拉 info_yaw_diff 曲线,看看每半圈峰值是多少,自己衡量着取合适 max_match_yaw_diff , s.t. 旋转 $\frac{1}{4}$ 圈时也就是切换识别装甲板的时候也就是上一帧装甲板刚刚丢失,这一帧刚识别到的时候,刚好能够跳变
## max_match_distance 问题

---


# 解算器问题排查

## 选板

打击一直超前(尤其表现为一直打坏装甲板的的电线) 选板的时候头摆过去超前导致的,
## 偏置

1. time_bias 超前调小,落后调大

2. s_bias 测量准确尽可能不要动,yaw旋转中心离相机光圈的垂直距离

3. z_bias 测量准确尽可能不要动,如果 odom2camare xyz都正确的话,打的高调低,打的底调高

---

# 通信问题排查

*头*对不对
*包*内容对不对,每一个值类型都对吗
校验*码*一致吗
波特*率*一致吗
## crc 校验

这个我不会,问孙光浩

## auto

请一定要 在 auto.sh 中 **# 等待进程启动** 部分,给充足的时间
如果时间不充足,会导致tracker还没来得及启动就被杀死

---
有任何问题,请联系我 : hdm1300415778@gmail.com
