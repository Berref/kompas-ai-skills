# Depth - Глубина выдавливания

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Листовое тело ](bc2753655.html) > [Интерфейс ISheetMetalContainer ](isheetmetalcontainer.html) > [ISheetMetalContainer - свойства ](isheetmetalcontainer_props.html) > [Интерфейс ISheetMetalBody ](isheetmetalbody.html) > [ISheetMetalBody - свойства ](isheetmetalbody_props.html) |  Scroll [ [ [ ](isheetmetalbody_depthobject.html "К следующему разделу")](isheetmetalbody_props.html "На уровень выше")](isheetmetalbody_bendvalue.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](isheetmetalbody.html)

Тип данных: double

Синтаксис Automation:

Depth = iObject.Depth( normal ); | Получить свойство ([* ](1.html))  
---|---  
iObject.Depth( normal ) = Depth; | Установить свойство ([* ](1.html))  
Depth = iObject.GetDepth( normal ); | Получить свойство ([**](2.html))  
iObject.SetDepth( normal, Depth ); | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_Depth( normal, &Depth ); | Получить свойство  
---|---  
iObject->put_Depth( normal, Depth ); | Установить свойство  
  
Входные параметры:

BOOL normal | \- TRUE - глубина выдавливания в прямом направлении, \- FALSE - глубина выдавливания в обратном направлении.  
---|---  
  
Примечание.

Позволяет считывать и устанавливать глубину выдавливания.

Подразделы:

(отсутствуют)
