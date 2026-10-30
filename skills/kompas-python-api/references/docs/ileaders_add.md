# Add - Создать новый элемент и добавить его в коллекцию

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения и размеры ](obozn_razm.html) > [Обозначения ](bb3219840.html) > [Коллекции обозначений ](bb3219842.html) > [Интерфейс ILeaders ](ileaders.html) > [ILeaders - методы ](ileaders_methods.html) |  Scroll [ [ [ ](iremoteelements.html "К следующему разделу")](ileaders_methods.html "На уровень выше")](ileaders_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ileaders.html)

Синтаксис Automation:

LPDISPATCH Add( DrawingObjectTypeEnum DimType );

Синтаксис COM:

HRESULT Add( DrawingObjectTypeEnum DimType, IBaseLeader ** Result );

Входные параметры:

DimType | \- тип линии-выноски.  
---|---  
  
Типы линий-выносок:

ksDrLeader | 20 | Простая линия-выноска,  
---|---|---  
ksDrPosLeader | 21 | Линия-выноска для обозначения позиции,  
ksDrBrandLeader | 22 | Линия-выноска для обозначения клеймения,  
ksDrMarkerLeader | 23 | Линия-выноска для обозначения маркирования.  
  
Возвращаемое значение:

| \- Указатель на интерфейс линии-выноски [IBaseLeader](ibaseleader.html).  
---|---  
  
Подразделы:

(отсутствуют)
