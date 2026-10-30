# GetSideParameters - Получить параметры выдавливания в одном направлении

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Операции ](bc2279073.html) > [Интерфейс IExtrusion ](iextrusion.html) > [IExtrusion - методы ](iextrusion_methods.html) |  Scroll [ [ [ ](iextrusion_setsideparameters.html "К следующему разделу")](iextrusion_methods.html "На уровень выше")](iextrusion_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iextrusion.html)

Синтаксис Automation:

BOOL GetSideParameters( BOOL normal,

End_Type * ExtrusionType,

double * Depth,

double * DraftValue,

BOOL * DraftOutward,

IModelObject * DepthObject );

Синтаксис COM:

HRESULT GetSideParameters( BOOL normal,

End_Type * ExtrusionType,

double * Depth,

double * DraftValue,

BOOL * DraftOutward,

IModelObject * DepthObject );

Входные параметры:

normal | направление, TRUE - в прямом направлении, FALSE - в обратном направлении.  
---|---  
  
Выходные параметры:

ExtrusionType | \- тип выдавливания,  
---|---  
Depth | \- глубина выдавливания,  
DraftValue | \- угол наклона,  
DraftOutward | \- признак уклона внутрь,  
DepthObject | \- указатель на объект, задающий глубину выдавливания.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

1\. Метод позволяет получать параметры операции выдавливание.

2\. Параметр Depth позволяет задать на сколько выдавить за объект, задающий глубину выдавливания, или какое расстояние оставить до объекта, задающего глубину выдавливания - в зависимости от типа построения (для типов построения "до поверхности" и "до вершины" см. перечисление [ksEndTypeEnum](ksendtypeenum.html)).

Подразделы:

(отсутствуют)
