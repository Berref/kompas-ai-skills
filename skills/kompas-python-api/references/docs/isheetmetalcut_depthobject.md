# DepthObject - Объект, задающий глубину вырезания

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Листовое тело ](bc2753655.html) > [Интерфейс ISheetMetalContainer ](isheetmetalcontainer.html) > [ISheetMetalContainer - свойства ](isheetmetalcontainer_props.html) > [Интерфейс ISheetMetalCut ](isheetmetalcut.html) > [ISheetMetalCut - свойства ](isheetmetalcut_props.html) |  Scroll [ [ [ ](isheetmetalcut_profile.html "К следующему разделу")](isheetmetalcut_props.html "На уровень выше")](isheetmetalcut_depth.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](isheetmetalcut.html)

Тип данных: указатель на интерфейс [IModelObject](imodelobject.html)

Синтаксис Automation:

DepthObject = iObject.DepthObject; | Получить свойство ([* ](1.html))  
---|---  
iObject.DepthObject = DepthObject; | Установить свойство ([* ](1.html))  
DepthObject = iObject.GetDepthObject(); | Получить свойство ([**](2.html))  
iObject.SetDepthObject( DepthObject ); | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_DepthObject( &DepthObject ); | Получить свойство  
---|---  
iObject->put_DepthObject( DepthObject ); | Установить свойство  
  
Примечание.

1\. Свойство доступно при типе построения отверстия "до грани", см.[ksHoleCutTypeEnum](ksholecuttypeenum.html).

2\. Позволяет получать указатель на интерфейс объекта и устанавливать грань, задающую глубину выдавливания.

Подразделы:

(отсутствуют)
