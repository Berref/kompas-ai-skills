# FormatTolerance - Форматировать таблицу допуска формы

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Оформление ](bc2273863.html) > [Обозначения ](bc2275772.html) > [Интерфейс ITolerance3D ](itolerance3d.html) > [ITolerance3D - методы ](itolerance3d_methods.html) |  Scroll [ [ [ ](itolerance3d_getposition.html "К следующему разделу")](itolerance3d_methods.html "На уровень выше")](itolerance3d_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](itolerance3d.html)

Синтаксис Automation :

BOOL FormatTolerance();

Синтаксис COM :

HRESULT FormatTolerance( BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае удачного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Функция выполняет обновление таблицы допуска формы.

Пустые столбцы и строки в начале и в конце таблицы будут удалены.

Границы пустых граничных ячеек в непустых столбцах будут удалены.

Версия: Компас v20

Подразделы:

(отсутствуют)
