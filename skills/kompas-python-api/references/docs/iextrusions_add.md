# Add - Создать операцию выдавливание

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Операции ](bc2279073.html) > [Интерфейс IExtrusions ](iextrusions.html) > [IExtrusions - методы ](iextrusions_methods.html) |  Scroll [ [ [ ](irotateds.html "К следующему разделу")](iextrusions_methods.html "На уровень выше")](iextrusions_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iextrusions.html)

Синтаксис Automation:

LPDISPATH Add(ksObj3dTypeEnum ExtrusionType);

Синтаксис COM:

HRESULT Add( ksObj3dTypeEnum ExtrusionType, IExtrusion ** Result);

Возвращаемое значение:

Указатель на интерфейс операции выдавливание [IExtrusion](iextrusion.html) | \- в случае удачного завершения.  
---|---  
  
Примечания:

1\. Метод позволяет создать новый интерфейс операции выдавливания.

2\. Допустимыми значениями ExtrusionType являются o3d_bossExtrusion, o3d_cutExtrusion.

3\. После получения нового интерфейса нужно задать параметры операции выдавливание и вызвать метод [IModelObject::Update](imodelobject_update.html).

Подразделы:

(отсутствуют)
