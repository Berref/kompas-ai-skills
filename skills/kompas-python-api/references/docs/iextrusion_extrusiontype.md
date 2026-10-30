# ExtrusionType - Тип выдавливания

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Операции ](bc2279073.html) > [Интерфейс IExtrusion ](iextrusion.html) > [IExtrusion - свойства ](iextrusion_props.html) |  Scroll [ [ [ ](iextrusion_sketch.html "К следующему разделу")](iextrusion_props.html "На уровень выше")](iextrusion_draftvalue.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iextrusion.html)

Тип данных: из перечисления [EndTypeEnum](end_type.html)

Синтаксис Automation:

ExtrusionType = iObject.ExtrusionType( normal ); | Получить свойство ([* ](1.html))  
---|---  
iObject.ExtrusionType( normal ) = ExtrusionType; | Установить свойство ([* ](1.html))  
ExtrusionType = iObject.GetExtrusionType( normal ); | Получить свойство ([**](2.html))  
iObject.SetExtrusionType( normal, ExtrusionType ); | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_ExtrusionType( &ExtrusionType ); | Получить свойство  
---|---  
iObject->put_ExtrusionType( ExtrusionType ); | Установить свойство  
  
Входные параметры:

normal | TRUE - выдавливание в прямом направлении, FALSE - выдавливание в обратном направлении.  
---|---  
  
Примечание:

Свойство позволяет получить и установить тип выдавливания.

Подразделы:

(отсутствуют)
