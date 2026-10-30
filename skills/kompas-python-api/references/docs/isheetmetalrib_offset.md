# Offset - Величина смещения вдоль кривой сгиба

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Листовое тело ](bc2753655.html) > [Интерфейс ISheetMetalContainer ](isheetmetalcontainer.html) > [ISheetMetalContainer - свойства ](isheetmetalcontainer_props.html) > [Интерфейс ISheetMetalRib ](isheetmetalrib.html) > [ISheetMetalRib - свойства ](isheetmetalrib_propers.html) |  Scroll [ [ [ ](isheetmetalrib_offsettype.html "К следующему разделу")](isheetmetalrib_propers.html "На уровень выше")](isheetmetalrib_lenght2.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](isheetmetalrib.html)

Тип данных: double

Синтаксис Automation:

Offset = Object.Offset; | Получить свойство ([* ](1.html))  
---|---  
Object.Offset = Offset; | Установить свойство ([* ](1.html))  
Offset = Object.GetOffset(); | Получить свойство ([**](2.html))  
Object.SetOffset( Offset); | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_Offset( &Offset ); | Получить свойство  
---|---  
Object.put_Offset( Offset ); | Установить свойство  
  
Примечание:

1.Для типа смещения ksOffsetByU свойство определяет величину смещения в % от длины кривой (0...100).

2.Для типа смещения ksOffsetByLen свойство определяет длину сегмента.

Подразделы:

(отсутствуют)
