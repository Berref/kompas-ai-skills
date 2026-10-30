# BeginEditEx - Войти в режим редактирования эскиза

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Эскиз ](bc2287727.html) > [Интерфейс ISketch ](isketch.html) > [ISketch - методы ](isketch_methods.html) |  Scroll [ [ [ ](isketch_deletewrongprojection.html "К следующему разделу")](isketch_methods.html "На уровень выше")](isketch_beginedit.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](isketch.html)

Синтаксис Automation:

LPDISPATCH BeginEditEx( BOOL ReadOnly );

Синтаксис COM:

HRESULT BeginEditEx( BOOL ReadOnly, IFragmentDocument * * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

ReadOnly | \- = TRUE - для чтения.  
---|---  
  
Подразделы:

(отсутствуют)
