#include <stdio.h>
#include <time.h>

#define REPEAT 2             /*タイピング練習回数*/
#define TEHON_LINE_MAX_NUM 2 /*手本文字列の個数*/
#define GOOD_TIME 20         /*入力時間(GOOD)*/
#define NG_TIME 40           /*入力時間(NG)*/

main()
{
  char first_line[] = "I have some good news";
  char second_line[] = "Let`s do something fun";
  int input_char,  /*キーボードからの入力データ(一文字)*/
      count,       /*タイピング回数の計算用*/
      line,        /*使用する手本文字列の計算用*/
      begin_input, /*入力の開始時刻*/
      end_input,   /*入力の終了時刻*/
      input_time,  /*入力時間*/
      index,       /*文字配列の添字用*/
      error_cnt;   /*エラー文字列*/
  time_t t;        /*time関数用*/

  printf("<タイピングゲーム開始>\n");
  for (count = 0; count < REPEAT; count++)
  {
    for (line = 0; line < TEHON_LINE_MAX_NUM; line++)
    {
      /*手本文字列の出力結果*/
      if (line == 0)
      {
        printf("%s\n", first_line);
      }
      else
      {
        printf("%s\n", second_line);
      }
      begin_input = time(&t);

      /*入力エラー分析処理*/
      index = 0;
      error_cnt = 0;
      if (line == 0)
      {
        while ((input_char = getchar()) != '\n')
        {
          if (first_line[index] != '\0')
          {
            if (input_char != first_line[index])
            {
              error_cnt++;
            }
            index++;
          }
        }
      }
      else
      {
        while ((input_char = getchar()) != '\n')
        {
          if (second_line[index] != '\0')
          {
            if (input_char != second_line[index])
            {
              error_cnt++;
            }
            index++;
          }
        }
      }
      end_input = time(&t);
      /*入力時間による該当メッセージの表示処理*/
      input_time = end_input - begin_input;
      printf("time=%d ", input_time);
      printf("error count =%d\n", error_cnt);

      if (error_cnt == 0)
      {
        if (input_time <= GOOD_TIME)
        {
          printf("素晴らしい！\n");
        }
        else
        {
          if (input_time >= NG_TIME)
          {
            printf("頑張って！\n");
          }
          else
          {
            printf("その調子！\n");
          }
        }
      }
      else
      {
        printf("タイプミスがあります。\n");
      }
    }
  }
}
