#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include<QVideoWidget>
#include<QMediaPlaylist>
#include<QDebug>
#include<QFile>
#include<QIODevice>
#include<QTextStream>
#include<Windows.h>

#pragma execution_character_set("utf-8")
#pragma comment  (lib, "User32.lib")
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void get_file();   //获取播放列表
    void init_video();  //初始化播放器
    void down_win();    //窗体嵌入图标下
    void down_win1();    //窗体嵌入图标下
    void test();
    void test1();

private:
    Ui::MainWindow *ui;
    QMediaPlayer *player;  //播放器
    QVideoWidget *vid_wid; //播放窗口
    QMediaPlaylist *playlist; //播放列表

};
#endif // MAINWINDOW_H
