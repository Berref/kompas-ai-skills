# VisualEditObject - Запустить визуальный процесс редактирования объекта

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Базовые интерфейсы ](ba1711015.html) > [Интерфейс IKompasDocument2D1 ](ikompasdocument2d1.html) > [IKompasDocument2D1 - методы ](ikompasdocument2d1_methods.html) |  Scroll [ [ [ ](ikompasdocument3d1.html "К следующему разделу")](ikompasdocument2d1_methods.html "На уровень выше")](ikompasdocument2d1_visualcreateobject.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ikompasdocument2d1.html)

Синтаксис Automation:

BOOL VisualEditObject( IDrawingObject * Object );

Синтаксис COM:

HRESULT VisualEditObject( IDrawingObject * Object, BOOL * Result );

Возвращаемое значение:

TRUE | \- если объект отредактирован,  
---|---  
FALSE | \- объект не отредактирован.  
  
Входные параметры:

Object | \- указатель на редактируемый объект [IDrawingObject](idrawingobject.html).  
---|---  
  
Версия Компас v23

Подразделы:

(отсутствуют)
