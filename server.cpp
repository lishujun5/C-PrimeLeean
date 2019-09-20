#pragma GCC diagnostic error "-std=c++11"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <arpa/inet.h>
#include <errno.h>
#include <pthread.h>
#include <signal.h>
#include <ctype.h>
#include <vector>
using namespace std;

void sys_err(const char *str)
{
    perror(str);
    exit(1);
}

int main(int argc, char **argv)
{
    int lfd, cfd;
    socklen_t clt_addr_len;
    struct sockaddr_in srv_addr, clt_addr;
    // 将地址结构清零（按字节），容易出错（后面两个参数容易颠倒）
    // memset(&srv_addr, 0, sizeof(srv_addr));
    // bzero也可以用来清零操作 
    bzero(&srv_addr, 0);
    srv_addr.sin_family = AF_INET;
    srv_addr.sin_port = htons(8080);
    srv_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    int opt = 1;
    // 设置套接字选项
    setsockopt(lfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    // 创建套接字
    lfd = socket(AF_INET, SOCK_STREAM, 0);
    
    // 绑定套接字
    bind(lfd, (struct sockaddr *)&srv_addr, sizeof(srv_addr));
    
    // 监听客户端的连接
    listen(lfd, 128);
    
    fd_set rset, allset; // 读集合，所有描述符集合
    int maxfd = lfd; // 最大描述符
    FD_ZERO(&allset); // 所有描述符清零
    FD_SET(lfd, &allset); // 把listen返回的描述符置1

    char buf[512];
    vector<int> flag;

    while (1)
    {
        rset = allset; // allset是想监听的套接字描述符集合，rset是实际返回的套接字描述符集合
        // select IO多路转接
        // rset是传入传出参数，传入是想监听的文件描述符，返回是实际监听到的文件描述符
		printf("select 阻塞\n");
        int nready = select(maxfd+1, &rset, NULL, NULL, NULL);
		printf("select 释放阻塞\n");
        if (nready < 0)
        {
            sys_err("select");
        }
        if (FD_ISSET(lfd, &rset)) // 判断lfd是否在监听集合中
        {
            clt_addr_len = sizeof(clt_addr);
            // 非阻塞接收客户端的连接
			printf("阻塞它\n");
            cfd = accept(lfd, (struct sockaddr *)&clt_addr, &clt_addr_len);
            memset(buf, 0, 512);
            // 打印已经连接的客户端的信息
            cout << "客户端连接：" << inet_ntop(AF_INET, &clt_addr.sin_addr.s_addr, buf, sizeof(buf)) 
                 << "，" << ntohs(clt_addr.sin_port) << endl;
            // 把cfd加入到想监听的文件描述符集合中
            FD_SET(cfd, &allset);
            flag.push_back(cfd);

            // 更新最大描述符
            if (maxfd < cfd)
                maxfd = cfd;
            if (0 == --nready) // 说明select只返回一个lfd，即没有客户端连接上来，则无须执行后面的内容
                continue;
        }
        // 扫描所有文件描述符，看是否有读操作
        for (int i = 0; i < flag.size(); ++i)
        {
            if (FD_ISSET(flag[i], &rset)) // i所在的文件描述符有读操作
            {
                memset(buf, 0, 512);
                // 接收来自客户端的数据
                recv(flag[i], buf, sizeof(buf), 0);
                int ret = strlen(buf);
                if (ret == 0) // 读套接字返回零表明客户端关闭了
                {
                    close(flag[i]);
                    cout << "客户端关闭：" << inet_ntop(AF_INET, &clt_addr.sin_addr.s_addr, buf, sizeof(buf)) 
                        << "，" << ntohs(clt_addr.sin_port) << endl;
                    FD_CLR(flag[i], &allset); // 解除select对此文件描述符的监听
                }
                for (int i = 0; i < ret; ++i)
                    buf[i] = toupper(buf[i]);
                // 回射到客户端
                send(flag[i] ,buf, ret,0);
                // 客户端写到标准输出
                write(STDOUT_FILENO, buf, ret);
            }
        }
    }
    close(lfd);
    return 0;
}
