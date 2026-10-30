# SetSideParameters - Установить параметры листового тела в одном направлении

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Листовое тело ](bc2753655.html) > [Интерфейс ISheetMetalContainer ](isheetmetalcontainer.html) > [ISheetMetalContainer - свойства ](isheetmetalcontainer_props.html) > [Интерфейс ISheetMetalBody ](isheetmetalbody.html) > [ISheetMetalBody - методы ](isheetmetalbody_methods.html) |  Scroll [ [ [ ](isheetmetalbend.html "К следующему разделу")](isheetmetalbody_methods.html "На уровень выше")](isheetmetalbody_getsideparameters.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](isheetmetalbody.html)

Синтаксис Automation:

BOOL SetSideParameters( BOOL normal,

End_Type ExtrusionType,

double Depth,

IModelObject * DepthObject );

Синтаксис COM:

HRESULT SetSideParameters( BOOL normal,

End_Type ExtrusionType,

double Depth,

IModelObject * DepthObject );

Входные параметры:

normal | \- направление: TRUE - в прямом направлении, FALSE - в обратном,  
---|---  
ExtrusionType | \- способ построения листового тела,  
Depth | \- глубина выдавливания,  
DepthObject | \- указатель на объект, задающий глубину выдавливания.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание.

Параметр Depth в позволяет задать на сколько выдавить за объект, задающий глубину выдавливания, или какое расстояние оставить до объекта, задающего глубину выдавливания - в зависимости от типа построения (для типов построения "до поверхности" и "до вершины" см. перечисление [ksEndTypeEnum](ksendtypeenum.html)).

Подразделы:

(отсутствуют)
