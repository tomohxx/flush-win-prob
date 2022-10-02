create table prob (hand text, turn integer, prob real, primary key(hand, turn));

.mode csv
.import prob.csv prob
