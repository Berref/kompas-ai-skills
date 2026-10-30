# MoveParts - Переместить вставки

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Компоненты ](bc2609111.html) > [Интерфейс IParts7 ](iparts7.html) > [IParts7 - методы ](iparts7_methods.html) |  Scroll [ [ [ ](iparts7_saveasdetail.html "К следующему разделу")](iparts7_methods.html "На уровень выше")](iparts7_findpart.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iparts7.html)

Синтаксис Automation:

BOOL MoveParts( VARIANT Parts );

Синтаксис COM:

HRESULT MoveParts( VARIANT Parts, BOOL * Result );

Возвращаемое значение:

TRUE | \- есть локальный результат,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

Parts | \- Список SafeArray VT_ARRAY | VT_DISPATCH перемещаемых вставок [IPart7](ipart7.html).  
---|---  
  
Примечание

Функция позволяет переместить вставки по дереву сборки. Например, можно переместить вставки одной подсборки в другую подсборку или в верхнюю сборку.

Версия: Компас v20

Подразделы:

(отсутствуют)
