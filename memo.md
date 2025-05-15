## 考えたこと (step1)
制約はやさしいので，賢いことはしないでも通りそう．

local nameとdomain nameで適用すべき規則が異なるので，それぞれ別に処理する．local nameを実際のアドレスに還元する処理は元の関数の処理とは独立して行えるので，関数化したい．

## 時間・空間計算量 (step1)
時間・空間計算量ともにO(emails.length * emails[i].length)．

## 考えたこと (step2)
https://github.com/hayashi-ay/leetcode/pull/25/files
https://github.com/mura0086/arai60/pull/18/files
https://github.com/irohafternoon/LeetCode/pull/16/files
https://github.com/Ryotaro25/leetcode_first60/pull/15/files
https://github.com/colorbox/leetcode/pull/28/files

よく考えると諸々読み取り専用でいいところがあって，std::string_viewでよかった．ただ，使い方が適切なのかは不安．

canonicalという名前がいい，

https://support.google.com/mail/answer/7436150?hl=en
https://support.google.com/mail/thread/228350356/plus-sign-in-gmail-address?hl=en

.とか+のルールはgmailのものみたい．RFCでは@複数個は認められてなさそう．rfindは使わなくていいや．

それはそうとして@あるなしのバリデーションはあってもいい．ライブラリ化するなら，戻り値はoptionにしたいけど，この感覚はどうなんだろう．

## 考えたこと (step3)
2分40秒くらいで解けるようになった．
