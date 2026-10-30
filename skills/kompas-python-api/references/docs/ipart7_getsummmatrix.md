# GetSummMatrix - Получить суммарную матрицу преобразование координат

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Компоненты ](bc2609111.html) > [Интерфейс IPart7 ](ipart7.html) > [IPart7 - методы ](ipart7_methods.html) |  Scroll [ [ [ ](ipart7_findobject.html "К следующему разделу")](ipart7_methods.html "На уровень выше")](ipart7_getmaxsag.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipart7.html)

Синтаксис Automation:

VARIANT GetSummMatrix( IPart7 * Part1 );

Синтаксис COM:

HRESULT GetSummMatrix( IPart7 * Part1, VARIANT * Result );

Возвращаемое значение:

  
| \- массив SafeArray типа VT_ARRAY | VT_R8.  
---|---  
  
Входные параметры:

Part1 | \- указатель на интерфейс IPart7 детали из которой нужно сделать пересчет координат.  
---|---  
  
Примечания:

1\. Элементы матрицы возвращаются в виде одномерного массива из шестнадцати элементов.

2\. Матрица имеет размер 4х4.

Подразделы:

(отсутствуют)
