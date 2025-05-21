#!/bin/bash

# 自启动和监控节点

delay_time=3
while true
do
    # 启动跟踪节点
    gnome-terminal -t "tracker" -x bash -c "cd /home/abc/rm/tracker; source install/setup.bash; ros2 launch rm_vision_bringup vision_bringup.launch.py; exec bash"
    echo "Tracker启动成功，开始监控进程..."
  
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
