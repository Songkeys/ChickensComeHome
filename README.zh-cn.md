# ChickensComeHome 小鸡回家

[![](https://img.shields.io/github/license/Songkeys/ChickensComeHome.svg)](https://github.com/Songkeys/ChickensComeHome)

[English](README.md) | [简体中文](README.zh-cn.md)

*小鸡回家* 是我在大约三天内为 CPP 课程作业编写的解谜游戏。

游戏目的是帮助一群鸡回到他们的小屋，但你必须收集一个鸡蛋，并避免路上的所有陷阱。

## 截图

![screenshot](https://user-images.githubusercontent.com/22665058/63771984-bf6da280-c90a-11e9-81ff-a970fa8013cb.gif)

## 运行

要求：

- Visual Studio 2017 (+?)

Windows: 只需运行 `CourseworkBase2018.sln` 文件即可.

> 阅读 [README.TXT](README.TXT) 中有关 macOS / linux 安装的更多信息。

## 更多地图

你可以添加游戏中的更多关卡的地图。它位于 `src/resources/maps` 下。添加一个 ascii 格式的`.txt`文件以开始这样做。

字符表示:

- `0` - 空地
- `1` - 墙
- `2` - 陷阱
- `4` - 鸡蛋
- `5` - 家
- `9` - 小鸡

## 版权

所有资源均从互联网上收集，并保证可以被免费使用。

游戏框架由 [Jason Atkin 博士](http://www.cs.nott.ac.uk/~pszja/) 编写，他是该 CPP 课程的老师。
