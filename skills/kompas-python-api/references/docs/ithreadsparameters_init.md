# Init - Инициализация параметров стандартной резьбы

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Операции ](bc2279073.html) > [Интерфейс IThreadsParameters ](ithreadsparameters.html) > [IThreadsParameters - методы ](ithreadsparameters_methods.html) |  Scroll [ [ [ ](ithreaddialogparam.html "К следующему разделу")](ithreadsparameters_methods.html "На уровень выше")](ithreadsparameters_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ithreadsparameters.html)

Синтаксис Automation:

BOOL Init( BSTR StandardFileName, double Diameter, double Pitch );

Синтаксис COM:

HRESULT Init( BSTR StandardFileName, double Diameter, double Pitch, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае удачи.  
---|---  
  
Входные параметры:

StandardFileName | \- имя таблицы стандарта резьбы,  
---|---  
Diameter | \- номинальное значение диаметра,  
Pitch | \- шаг.  
  
Подразделы:

(отсутствуют)
