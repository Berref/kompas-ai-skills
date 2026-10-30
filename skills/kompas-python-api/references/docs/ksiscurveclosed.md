# ksIsCurveClosed - Проверить, замкнута ли указанная кривая

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Вспомогательные построения ](cm1726712.html) > [Математические функции ](math_fncts_common.html) |  Scroll [ [ [ ](ksispointinsidecontour.html "К следующему разделу")](math_fncts_common.html "На уровень выше")](ksgetcurvepointprojectionex.html "К предыдущему разделу")  
---|---  
  
[Пример...](ksispointinsidecontour_ksiscurveclosed_example.html)

Аналог данной функции при использовании Automation - метод [ksDocument2D::ksIsCurveClosed](ksdocument2d_ksiscurveclosed.html).

Синтаксис:

int ksIsCurveClosed (reference p);

Входной параметр:

p | \- указатель на кривую.  
---|---  
  
Возвращаемое значение:

1 | \- кривая замкнута,  
---|---  
0 | \- кривая разомкнута,  
-1 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
