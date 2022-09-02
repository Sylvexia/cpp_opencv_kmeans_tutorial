# K-means & C++ Tutorial & Opencv

Kmeans和c++的教學

這個教學是提供給擁有一定基礎程式語言的喵喵\
會嘗試把一點點的C++的特色帶進來，讓喵喵們對於實驗室過高的寫程式門檻有一點概念\
不至於說看到實驗室的程式碼覺得：喵的這個到底是在衝三小

## 第一章 如何建置專案

最基本的步驟\
複製專案到你想要的位置並進到專案裡面：

```
git clone git@gitlab.ical.tw:a1085125/basic_tutorial.git
cd basic_tutorial
```
開始編譯：

```
mkdir build
cd build
cmake ..
make -j4
./ch1
```

指令解釋：
- git clone {url} : 利用git複製gitlab/github專案
- cmake: 找到CMakeLists.txt，設置專案，產生出Makefile
- make: 根據Makefile編譯並產生出可以被電腦執行的二進制執行檔, -j4代表使用4個執行序在做編譯這件事情

ch1的程式我暫時不會說在做什麼\
程式照著上面執行 能夠跑出灰色模糊的人臉就好\
ch2開始我才會開始講程式碼\

課後練習：\
上面做完應該會出現灰色的迪亞波羅\
要怎麼召喚貓咪拯救世界呢？\
提示：
環境變數或是更改讀取路徑

## 第二章 Opencv基本操作

- 讀檔（彩色，灰色）imread
- 模糊 blur
- Canny濾波 canny
- 縮放 resize
- hsv二值化

課後練習：\
上網搜尋opencv的api\
嘗試使用GaussianBlur,以hsv濾色後，使用morphology和findcontours找出紅色的物體\
並知道上述這些函式的意義。