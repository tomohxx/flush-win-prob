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
sqlite3 db.sqlite3 < ../init.sql
```

以下のようなコマンドで一色手の巡目ごとの和了確率を検索できる.

```
sqlite> select turn, prob from prob where hand = '1122345577889';
0|0.462711
1|0.434498
2|0.405372
3|0.375423
4|0.344775
5|0.313581
6|0.282036
7|0.250372
8|0.218685
9|0.187287
10|0.15629
11|0.125972
12|0.0968531
13|0.0696154
14|0.0451107
15|0.0244029
16|0.00881679
17|0.0
18|0.0
```
