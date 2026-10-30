# IsLocalResultExist - Есть ли локальный результат в модели или во вставках

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Компоненты ](bc2609111.html) > [Интерфейс IPart7 ](ipart7.html) > [IPart7 - методы ](ipart7_methods.html) |  Scroll [ [ [ ](ipart7_isvariablenamevalid.html "К следующему разделу")](ipart7_methods.html "На уровень выше")](ipart7_getopendocumentparam.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipart7.html)

Синтаксис Automation :

BOOL IsLocalResultExist( BOOL Reqursive );

Синтаксис COM:

HRESULT IsLocalResultExist( BOOL Reqursive, BOOL * Result );

Возвращаемое значение:

TRUE | \- есть локальный результат,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

Reqursive | \- Проверять наличие локального результата у вставок рекурсивно.  
---|---  
  
Версия: Компас v20

Подразделы:

(отсутствуют)
