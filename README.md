# othello

This is othello repository

[travis-test](https://travis-ci.org/Kose-i/othello/branches)

[comment]: # ()

## File constitution

| class | configure |
----|----
| Game | Othello game class |
| Hand | abstracle class |
| Computer | computer class with using costmap|
| Hyoukakansuu | for computer class |
| Player | player class |
| Point | position class |

[comment]: # (`csvdir`を設置後,簡易的なAIの実装に移動.)

### Computer class

*computer* は他クラスを継承し,継承したクラスが持つ関数**calc_cost**を実行してコストの最小値となるオセロの場所を選択します.

[comment]:# (calc costが最大値となる箇所をオセロの場所として選択する)

## How to Use

`config`内の`detect_hand.txt`ファイルを編集して,`Black` `White`のプレーヤーの名前を決めます.

*format*

`Black [name]`

`White [name]`

### プレーヤー名にcomputerという文字列を指定していた場合,computerが起動します.

`mkdir build`

`cd $_`

`cmake ..`

`make`

実行ファイルができたことを確認して実行します.

`./main`
