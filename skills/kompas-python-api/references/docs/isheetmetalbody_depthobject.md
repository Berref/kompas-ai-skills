# DepthObject - Объект, задающий глубину выдавливания

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Листовое тело ](bc2753655.html) > [Интерфейс ISheetMetalContainer ](isheetmetalcontainer.html) > [ISheetMetalContainer - свойства ](isheetmetalcontainer_props.html) > [Интерфейс ISheetMetalBody ](isheetmetalbody.html) > [ISheetMetalBody - свойства ](isheetmetalbody_props.html) |  Scroll [ [ [ ](isheetmetalbody_direction.html "К следующему разделу")](isheetmetalbody_props.html "На уровень выше")](isheetmetalbody_depth.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](isheetmetalbody.html)

Тип данных: указатель на объект [IModelObject](imodelobject.html)

Синтаксис Automation:

DepthObject = iObject.DepthObject( normal ); | Получить свойство ([* ](1.html))  
---|---  
iObject.DepthObject( normal ) = DepthObject; | Установить свойство ([* ](1.html))  
DepthObject = iObject.GetDepthObject( normal ); | Получить свойство ([**](2.html))  
iObject.SetDepthObject( normal, DepthObject ); | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_DepthObject( normal, &DepthObject ); | Получить свойство  
---|---  
iObject->put_DepthObject( normal, DepthObject ); | Установить свойство  
  
Входные параметры:

BOOL normal | \- TRUE - объект выдавливания в прямом направлении, \- FALSE - объект выдавливания в обратном направлении.  
---|---  
  
Примечание.

Позволяет считывать и устанавливать указатель на объект, задающий глубину выдавливания.

Подразделы:

(отсутствуют)
