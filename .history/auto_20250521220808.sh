#!/bin/bash

# 自启动和监控节点
#  莫忘记修改绝对路径

delay_time=3
while true
do
    # 启动节点
    gnome-terminal --title="RV" -- bash -c "/home/hdm/ttttt/tracker_plus/start_rv.sh; exec bash"
    echo "RV 启动成功，开始监控进程..."

    # 等待进程启动
    sleep 5

    while true
    do
        # 检查目标进程是否存在
        if ! pgrep -f "armor_tracker_node" >/dev/null; 
            then
            sleep 2 # 等待2秒,避免炸掉
            
            echo "检测到armor_tracker_node进程异常退出，正在尝试关闭旧终端并重新启动..."

            # 尝试关闭名为 "RV" 的终端窗口
            if command -v wmctrl &> /dev/null; then
                # 获取名为 "RV" 的终端窗口ID
                # wmctrl -l 的输出格式通常是: <ID> <Desktop> <Client Machine> <Window Title>
                # 我们假设窗口标题 "RV" 是最后一个字段
                RV_WINDOW_ID=$(wmctrl -l | awk '$NF == "RV" {print $1; exit}')

                if [ ! -z "$RV_WINDOW_ID" ]; then
                    echo "找到 'RV' 终端窗口 ID: $RV_WINDOW_ID. 正在关闭..."
                    wmctrl -i -c "$RV_WINDOW_ID"
                    sleep 1 # 等待片刻让窗口关闭
                else
                    echo "警告: 未能找到名为 'RV' 的终端窗口来关闭。"
                fi
            else
                echo "警告: wmctrl 命令未找到。无法自动关闭 'RV' 终端。请考虑安装 wmctrl (例如: sudo apt install wmctrl)。"
            fi
            
            break  # 跳出监控循环，返回外层循环重启程序
        fi
        sleep $delay_time  # 检查间隔
    done
done