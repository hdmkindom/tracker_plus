#!/bin/bash

# 自启动和监控节点
#  莫忘记修改绝对路径

delay_time=3
while true
do
    # 启动节点
    gnome-terminal -- bash -c "/path/to/your/start_rv.sh; exec bash"    echo "RV 启动成功，开始监控进程..."
  
    # 等待进程启动
    sleep 5

    while true
    do
        # 检查目标进程是否存在
        if ! pgrep -f "armor_tracker_node" >/dev/null; then
            echo "检测到armor_tracker_node进程异常退出，重新启动中..."
            break  # 跳出监控循环，返回外层循环重启程序
        fi
        sleep $delay_time  # 检查间隔
    done
done
