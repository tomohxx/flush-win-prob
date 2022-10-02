# Flush Win Prob

一人麻雀における一色手の和了確率を計算するツール.

## クローン

```
git clone https://github.com/tomohxx/flush-win-prob.git
```

## ビルド

```
mkdir build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
make
```

## 実行

`prob.csv`が生成される.

```
./main
```

## DB 生成

```
sqlite3 prob.db < init.sql
```
