#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    resize(1000,600);
    move(0,0);
    //无边框
    setWindowFlags(Qt::FramelessWindowHint);
    init_video();
    down_win1();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::get_file()
{
    playlist =new QMediaPlaylist(this);
    QFile file(":/new/prefix1/playlist.txt");
    if (!file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        qDebug()<<"打开失败";
    }
    QTextStream listfile(&file);
    QString line = listfile.readLine();
    while(!line.isNull())
    {
        playlist->addMedia(QUrl::fromLocalFile(line));
        qDebug()<<line;
        line=listfile.readLine();
    }
}
//初始化 播放器
void MainWindow::init_video()
{
    //设置播放器
    player=new QMediaPlayer(this);
    vid_wid=new QVideoWidget(this);  //视频显示的窗体
    setCentralWidget(vid_wid);
    player->setVideoOutput(vid_wid);  //输出的设备
    get_file(); // 添加播放列表
    playlist->setPlaybackMode(QMediaPlaylist::Loop); //循环播放
    player->setPlaylist(playlist);  //设置播放列表
    player->setVolume(5); //设置音量
    player->play();
}

//下沉窗体到图标之后 不可行，窗体会遮挡图标
void MainWindow::down_win()
{
    qDebug()<<"hello";
    //桌面窗口的句柄  //前面是类名 后面是标题
    HWND Progman =::FindWindow(L"Progman",L"Program Manager");
    SendMessageTimeout(Progman, 0x052c, 0 ,0, SMTO_NORMAL, 0x3e8,0);

    qDebug()<<"桌面的句柄:"<<Progman;

    //worker 父窗体
    HWND WorkerW=nullptr;
    //显示图标的  //目标
    HWND DefView =nullptr;
    while(true)
    {
        WorkerW=FindWindowEx(nullptr,WorkerW,L"WorkerW",L"");
        DefView =FindWindowEx(WorkerW,nullptr,L"SHELLDLL_DefView",L"");
        if (DefView) break;
    }
    qDebug()<<"WorkerW的句柄:"<<WorkerW;
    qDebug()<<"DefView的句柄:"<<DefView;
    //管理图标的顺序
    HWND FolderView =FindWindowEx(DefView,nullptr,L"SysListView32",L"FolderView");
    qDebug()<<"FolderView的句柄:"<<FolderView;
    //打印当前窗口的句柄
    qDebug()<<"主窗口的句柄:"<<QString().sprintf("%04X",winId());
    SetParent(reinterpret_cast<HWND>(winId()),Progman); //下成窗口
}
//把窗体放到workw的下一个workw后，可行
void MainWindow::down_win1()
{
    qDebug()<<"hello";
    //桌面窗口的句柄  //前面是类名 后面是标题
    HWND Progman =FindWindow(L"Progman",L"Program Manager");
    SendMessageTimeout(Progman, 0x052c, 0 ,0, SMTO_NORMAL, 0x3e8,0);

    qDebug()<<"桌面的句柄:"<<Progman;

    //worker 父窗体  //第一目标
    HWND WorkerW=nullptr;
    //显示图标的
    HWND DefView =nullptr;
    while(true)
    {
        WorkerW=FindWindowEx(nullptr,WorkerW,L"WorkerW",L"");
        DefView =FindWindowEx(WorkerW,nullptr,L"SHELLDLL_DefView",L"");
        if (DefView) break;
    }
    qDebug()<<"WorkerW0的句柄:"<<WorkerW;
    qDebug()<<"DefView的句柄:"<<DefView;
    //找到下一个workerw 第二目标
    HWND WorkerW1=FindWindowEx(nullptr,WorkerW,L"WorkerW",L"");
    //打印当前窗口的句柄
    qDebug()<<"主窗口的句柄:"<<QString().sprintf("%04X",winId());
    SetParent(reinterpret_cast<HWND>(winId()),WorkerW1); //下成窗口
}

void MainWindow::test()
{
    qDebug()<<typeid(winId()).name()<<QString().sprintf("%04X",winId()); //unsigned __int64
    HWND Progman =::FindWindow(L"Progman",L"Program Manager");
    qDebug()<<typeid(Progman).name()<<"1"<<Progman;
    //HWND QQMusic = FindWindow(L"TXGuiFoundation",L"七剑战歌 - 川井宪次 (かわい けんじ) ");
    HWND m_hd =reinterpret_cast<HWND>(winId());
    //HWND m_hd =(HWND)(winId());
    SetParent(m_hd,Progman);
    qDebug()<<QString().sprintf("%04X",m_hd);
}

void MainWindow::test1()
{
    QFile file(":/new/prefix1/playlist.txt");
    if (!file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        qDebug()<<"打开失败";
    }
    while(!file.atEnd())
    {
        QString line =file.readLine();
        //QString str(line);
        qDebug()<<line;
        //playlist->addMedia(QUrl::fromLocalFile(str));
    }
}




