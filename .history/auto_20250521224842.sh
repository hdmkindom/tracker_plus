#!/bin/bash

# 自启动和监控节点
# 莫忘记修改绝对路径

delay_time=3
TERMINAL_TITLE="RV" # 定义终端标题，方便复用
start_rv_script="/home/hdm/ttttt/tracker_plus/start_rv.sh" # 启动脚本的绝对路径
while true
do
    # 启动节点
    gnome-terminal --title="$TERMINAL_TITLE" -- bash -c "/home/hdm/ttttt/tracker_plus/start_rv.sh; exec bash"
    echo "$TERMINAL_TITLE 启动成功，开始监控进程..."

    # 等待进程启动
    sleep 5

    while true
    do
        # 检查目标进程是否存在
        if ! pgrep -f "armor_tracker_node" >/dev/null; 
            then
            sleep 2 # 等待2秒,避免炸掉

            echo "检测到 armor_tracker_node 进程异常退出。"
            
            # 检查 wmctrl 是否可用
            if command -v wmctrl &> /dev/null; then
                echo "正在尝试关闭名为 '$TERMINAL_TITLE' 的终端窗口..."
                # 获取窗口标题完全为 TERMINAL_TITLE 的终端窗口ID
                # wmctrl -l 输出格式: <ID> <Desktop> <Client Machine> <Window Title>
                # 我们将从第4个字段开始组合成标题，并与 TERMINAL_TITLE 比较
                WINDOW_ID=$(wmctrl -l | awk -v title="$TERMINAL_TITLE" '{
                    current_title=""; 
                    for(f=4;f<=NF;f++){
                        current_title=current_title $f (f==NF?"":" ")
                    }; 
                    if(current_title==title){
                        print $1; 
                        exit # 找到第一个匹配的就退出 awk
                    }
                }')

                if [ ! -z "$WINDOW_ID" ]; then
                    echo "找到 '$TERMINAL_TITLE' 终端窗口 ID: $WINDOW_ID. 正在关闭..."
                    wmctrl -i -c "$WINDOW_ID" # -i 表示通过ID操作，-c 表示关闭窗口
                    sleep 1 # 给窗口一点时间关闭
                else
                    echo "警告: 未能找到名为 '$TERMINAL_TITLE' 的终端窗口来关闭。"
                fi
            else
                echo "警告: wmctrl 命令未找到。无法自动关闭 '$TERMINAL_TITLE' 终端。请考虑安装 wmctrl (sudo apt install wmctrl)。"
            fi
            
            echo "准备重新启动..."
            break  # 跳出监控循环，返回外层循环重启程序
        fi
        sleep $delay_time  # 检查间隔
    done
done