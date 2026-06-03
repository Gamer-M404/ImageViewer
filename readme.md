# Linux 图片查看器

## 相关依赖
1. SDL2
```
sudo apt install libsdl2-dev libsdl2-2.0-0 -y
```

2. cmake
```
sudo apt install cmake -y
```

## 实现原理
ppm是一个很简单的图片格式，通常第一行是文件头（P6）， 后面会有一行注释，接着是图片的宽与高，像素的最大值。后面就是8bit的RGB矩阵了

只要读出每个像素RGB的值然后用SDL渲染即可

## 自动化脚本
```
iv.sh in.xxx(各种格式的图片)
```

这里能解析各种格式主要是因为在脚本中使用了
```
ffmpeg -i in.xxx out.ppm
```
从而把各种格式的图片都改成ppm格式的了