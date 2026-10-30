# Add - Создать объект "Эскиз"

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Эскиз ](bc2287727.html) > [Интерфейс ISketchs ](isketchs.html) > [ISketchs - методы ](isketchs_methods.html) |  Scroll [ [ [ ](isketch.html "К следующему разделу")](isketchs_methods.html "На уровень выше")](isketchs_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](isketchs.html)

Синтаксис Automation:

LPDISPATH Add();

Синтаксис COM:

HRESULT Add( ISketch** Result);

Возвращаемое значение:

Указатель на интерфейс эскиза [ISketch](isketch.html) | \- в случае удачного завершения.  
---|---  
  
Примечания:

1\. Метод позволяет создать новый объект "Эскиз".

2\. После получения нового интерфейса нужно задать параметры листового тела и вызвать метод [IModelObject::Update](imodelobject_update.html).

Подразделы:

(отсутствуют)
