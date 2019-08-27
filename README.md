# ChickensComeHome

[![](https://img.shields.io/github/license/Songkeys/ChickensComeHome.svg)](https://github.com/Songkeys/ChickensComeHome)

[English](README.md) | [简体中文](README.zh-cn.md)

*ChickensComeHome* is a puzzle game I wrote in about 3 days for a CPP coursework.

The aim of this game is to help a group of chickens to get back to their cabin, but you have to collect an egg and avoid all the traps on the way.

## Screenshot

![screenshot](https://user-images.githubusercontent.com/22665058/63771984-bf6da280-c90a-11e9-81ff-a970fa8013cb.gif)

## Running

Requirements:

- Visual Studio 2017 (+?)

Windows: Just run the `CourseworkBase2018.sln` file.

> Read more in [README.TXT](README.TXT) for macOS / linux installation.

## More Maps

You are free to add maps in the game for more levels. It's under `src/resources/maps`. Add a ascii-format `.txt` file to get start to do so.

Charater representation:

- `0` - empty ground
- `1` - wall
- `2` - trap
- `4` - egg
- `5` - home
- `9` - chick

## Credits

All resources are collected from internet and guaranteed to be free-to-use.

The game framework is written by [Dr Jason Atkin](http://www.cs.nott.ac.uk/~pszja/), who is the teacher for this CPP module.