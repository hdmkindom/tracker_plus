# record 策略

我们的record策略是从开始tracker一直鹿到结束

具体是在串口中,改为 "start"

最后 crtl + c 关闭

## record 使用方法

录包是以 .db3 数据库存储的

`ros2 bag paly record_2025_5_21_0_20_26` 来回看
`-l` 是重复回看

箭头小键盘调整录哪个节点以及播放速度

同时再新打开一个终端,
`rqt` 用rqt 中的 plugins - visualization - img view 
调整到 我们要看的目标节点 `/image_raw/compressed` 
就可以回放了,这里回放的是不经过任何处理的 压缩原图像
