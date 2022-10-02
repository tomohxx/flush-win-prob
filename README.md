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
sqlite> select * from prob where hand = '1122345577889';
1122345577889|0|0.462711
1122345577889|1|0.434498
1122345577889|2|0.405372
1122345577889|3|0.375423
1122345577889|4|0.344775
1122345577889|5|0.313581
1122345577889|6|0.282036
1122345577889|7|0.250372
1122345577889|8|0.218685
1122345577889|9|0.187287
1122345577889|10|0.15629
1122345577889|11|0.125972
1122345577889|12|0.0968531
1122345577889|13|0.0696154
1122345577889|14|0.0451107
1122345577889|15|0.0244029
1122345577889|16|0.00881679
1122345577889|17|0.0
1122345577889|18|0.0
```
