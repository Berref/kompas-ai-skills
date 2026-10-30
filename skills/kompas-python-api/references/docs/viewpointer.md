# ViewPointer - Создать стрелку направления взгляда

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Размеры и технологические обозначения ](cm1742473.html) > [Функции построения размеров /обозначений ](dims_signs_fncts_common.html) |  Scroll [ [ [ ](viewpointerw.html "К следующему разделу")](dims_signs_fncts_common.html "На уровень выше")](tolerance.html "К предыдущему разделу")  
---|---  
  
[Пример...](viewpointer_example.html)

Аналог данной функции при использовании Automation - метод [ksDocument2D::ksViewPointer](ksdocument2d_ksviewpointer.html).

Синтаксис:

reference ViewPointer (ViewPointerParam *par);

Выходной параметр:

par | \- указатель на структуру параметров стрелки направления взгляда [ViewPointerParam](structviewpointerparam.html).  
---|---  
  
Возвращаемое значение:

указатель на стрелку взгляда | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание.

При использовании Unicode следует использовать функцию [ViewPointerW](viewpointerw.html).

Подразделы:

(отсутствуют)
