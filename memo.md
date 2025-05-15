## 考えたこと (step1)
制約はやさしいので，賢いことはしないでも通りそう．

local nameとdomain nameで適用すべき規則が異なるので，それぞれ別に処理する．local nameを実際のアドレスに還元する処理は元の関数の処理とは独立して行えるので，関数化したい．

## 時間・空間計算量 (step1)
時間・空間計算量ともにO(emails.length * emails[i].length)．
