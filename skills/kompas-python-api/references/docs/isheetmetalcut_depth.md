# Depth - Глубина выреза

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Листовое тело ](bc2753655.html) > [Интерфейс ISheetMetalContainer ](isheetmetalcontainer.html) > [ISheetMetalContainer - свойства ](isheetmetalcontainer_props.html) > [Интерфейс ISheetMetalCut ](isheetmetalcut.html) > [ISheetMetalCut - свойства ](isheetmetalcut_props.html) |  Scroll [ [ [ ](isheetmetalcut_depthobject.html "К следующему разделу")](isheetmetalcut_props.html "На уровень выше")](isheetmetalcut_cuttype.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](isheetmetalcut.html)

Тип данных: double

Синтаксис Automation:

Depth = iObject.Depth; | Получить свойство ([* ](1.html))  
---|---  
iObject.Depth = Depth; | Установить свойство ([* ](1.html))  
Depth = iObject.GetDepth(); | Получить свойство ([**](2.html))  
iObject.SetDepth( Depth ); | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_Depth( &Depth ); | Получить свойство  
---|---  
iObject->put_Depth( Depth ); | Установить свойство  
  
Примечание.

1\. Свойство доступно при типе построения отверстия "на глубину", см.[ksHoleCutTypeEnum](ksholecuttypeenum.html).

2\. Позволяет считывать и устанавливать глубину отверстия.

Подразделы:

(отсутствуют)
