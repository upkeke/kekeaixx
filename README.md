# kekeaixx
桌面动态壁纸

## 环境

1. qt ：qt5.15.2  mvsc2019
2. window10



## 原理 

1. 用qt写一个播放器，做到无边框，尺寸和自己显示器分辨率相同(修改resize里面的参数)
2. 找到桌面图标和桌面之间的WorkerW句柄，将播放器窗体设为其子窗口

## 代码说明

###   MainWindow 类

####  成员变量

1. **Ui::MainWindow *ui**

   由于没有使用deigner对窗体编辑，基本没用

2. **QMediaPlayer *player**

   播放器，管理视频播放

3. **QVideoWidget *vid_wid**

   播放窗口

4. QMediaPlaylist *playlist

   播放列表

####  成员函数

1. void down_win()  

   测试用 无实际运用

2. void test()

   测试用 无实际运用

3. void test1()

   测试用 无实际运用

4. void get_file()

   主要获取从playlist.txt里面获取每个视频的文件路径

   使用的QTextStream，这个类专门读取txt文件的，可以保证读取的每一行没有换符

5. void init_video()

   播放器的初始化，包括多媒体与播放设备的连接，播放列表、音量，播放模式的设置

6. void down_win1()

   难点。找到桌面和管理图标的窗口之间的窗口

   a.  需要找到 这个WorkerW窗口的句柄

   ![111.png](https://github.com/upkeke/kekeaixx/blob/main/111.png?raw=true)

   刚开机可能还没有这个002B0958WorkerW窗口，只有上面那个001409E4WorkerW 窗口和program manager，二者连在一起，上面的WorkerW就是显示桌面图标的窗口，下面program manager是桌面壁纸窗口，而插入的这个中间的wokerw窗口就用来显示播放器，掩盖下面的坐面壁纸

   b. 找到这个workw之后将其设为播放器窗口的父窗口即可

##  注意事项

需要安装解码器



