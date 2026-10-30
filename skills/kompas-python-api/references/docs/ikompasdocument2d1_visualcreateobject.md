# VisualCreateObject - Запустить визуальный процесс создания объекта

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Базовые интерфейсы ](ba1711015.html) > [Интерфейс IKompasDocument2D1 ](ikompasdocument2d1.html) > [IKompasDocument2D1 - методы ](ikompasdocument2d1_methods.html) |  Scroll [ [ [ ](ikompasdocument2d1_visualeditobject.html "К следующему разделу")](ikompasdocument2d1_methods.html "На уровень выше")](ikompasdocument2d1_updatevariables.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ikompasdocument2d1.html)

Синтаксис Automation:

LPDISPATCH VisualCreateObject( DrawingObjectTypeEnum ObjectType );

Синтаксис COM:

HRESULT VisualCreateObject( DrawingObjectTypeEnum ObjectType, IDrawingObject * * Result );

Возвращаемое значение:

| \- Указатель на созданный объект [IDrawingObject](idrawingobject.html) \- в случае удачного завершения.  
---|---  
  
Входные параметры:

ObjectType | \- тип объекта из перечисления [DrawingObjectTypeEnum](drawingobjecttypeenum.html).  
---|---  
  
Версия Компас v23

Подразделы:

(отсутствуют)
