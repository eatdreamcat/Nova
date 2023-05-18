# Nova
DX Sample 的学习记录

## 2023.4.18 创建window 
## 2023.4.19 GPU Fence

主要是搭建环境，然后创建基础的流程

1.管线的创建
  1.1 获取device
  1.2 创建QUEUE
  1.3 创建SwapChain
  1.4 HeapDesc

2.资产的创建
  2.1 创建CommandList跟PSO
  2.2 渲染主循环
  2.3 Fence用于CPU 跟 GPU 的同步


这里我想简单的认为，管线创建部分就是GPU的准备部分，一些GPU的对象都在这里创建；资产创建部分，主要是CPU的。
如果后面有更准确的理解，那就再做更正。

对于一些Handle句柄的结构体，实际上是通过结构体来增加健壮性



https://github.com/eatdreamcat/Nova/releases/tag/2023.4.18
https://github.com/eatdreamcat/Nova/releases/tag/2023.4.19

## 2023.4.20 绘制三角形

1.创建的最简单的shader
2.创建RootSignature： 根签应该就是shader访问资源的入口
3.描述，在DX中，创建任何一种东西都需要描述
4.上传顶点数据
5.绘制


https://github.com/eatdreamcat/Nova/releases/tag/2023.4.20

## 2023.4.21 纹理采样

1.创建SRV，用于上传纹理数据给shader
2.shader中添加采样器，并指定寄存器，与CPU中desc一致
3.CPU中创建sampler的desc
4.创建渲染状态
5.绘制


https://github.com/eatdreamcat/Nova/releases/tag/2023.4.21.0

## 2023.5.11 FrameBuffer

这一次主要是每个FrameBuffer对应一个CommandAlloctor以及FenceValue

之前只有一个Alloctor跟FenceValue
也就是说，当所有命令绘制完毕上传之后，或获取当前的fence值判断GPU是否执行完，没有就一直等待，然后才开始处理下一帧的命令录制。
猜测：这里的过程大概是，GPU渲染完back，然后present到显示器，原先的back跟front就做了交换，显示器开始扫描新的渲染结果，但是此时CPU还在等待，但是新的backBuffer已经空闲准备好了。


现在两个FrameBuffer都有各自的FenceValue，就可以实现如下过程
GPU绘制完，做present交换双buffer，此时CPU会判断新的back是否可以用，也就是在显示器扫描当前帧结果的同时，可以开始录制下一帧的命令了。

当然以上也仅是基于目前认知的推论，而且具体的细节和过程我也并不清楚，很不严谨！
希望后面可以真正弄清楚这背后的逻辑吧。


https://github.com/eatdreamcat/Nova/releases/tag/2023.5.11


## 2023.5.17 CommandBundle

这个主要就是介绍了Bundle跟Direct两种CommandList的区别。
Bundle可以把一些绘制过程不会频繁变动的固定命令提前录制成一个bundle，这样只需要初始化的时候录制一次。

https://github.com/eatdreamcat/Nova/releases/tag/2023.5.17