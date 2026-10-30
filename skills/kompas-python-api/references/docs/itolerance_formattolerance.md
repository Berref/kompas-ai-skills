# FormatTolerance - Форматировать таблицу допуска формы

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения и размеры ](obozn_razm.html) > [Обозначения ](bb3219840.html) > [Интерфейс ITolerance ](itolerance.html) > [ITolerance - методы ](itolerance_methods.html) |  Scroll [ [ [ ](iviewpointer.html "К следующему разделу")](itolerance_methods.html "На уровень выше")](itolerance_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](itolerance.html)

Синтаксис Automation :

BOOL FormatTolerance();

Синтаксис COM :

HRESULT FormatTolerance( BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Функция выполняет обновление таблицы допуска формы.

Пустые столбцы и строки в начале и в конце таблицы будут удалены.

Границы пустых граничных ячеек в непустых столбцах будут удалены.

Версия: Компас v20

Подразделы:

(отсутствуют)
