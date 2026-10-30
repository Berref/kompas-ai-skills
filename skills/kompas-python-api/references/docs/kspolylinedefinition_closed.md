# Closed - Признак замкнутости ломаной

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы пространственных кривых ](int_pr_curve.html) > [Ломаная ( Интерфейсы ksPolyLineDefinition и IPolygonalLineDefinition) ](kspolylinedefinition.html) > [IPolygonalLineDefinition - свойства ](kspolylinedefinition_props.html) |  Scroll [ [ [ ](kspolylinedefinition_vertexvisible.html "К следующему разделу")](kspolylinedefinition_props.html "На уровень выше")](kspolylinedefinition_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kspolylinedefinition.html)

Тип данных: BOOL

Значения свойства:

TRUE | \- замкнутая ломаная,  
---|---  
FALSE | \- разомкнутая ломаная.  
  
Синтаксис Automation:

Closed = iPolyLine.Closed | Получить свойство ([* ](1.html))  
---|---  
iPolyLine.Closed = Closed | Установить свойство([* ](1.html))  
Closed = iPolyLine.GetClosed() | Получить oсвойство ([**](2.html))  
iPolyLine.SetClosed(Closed) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iPolyLine>get_Closed(&closed) | Получить свойство  
---|---  
iPolyLine>put_Closed(closed) | Установить свойство  
  
Подразделы:

(отсутствуют)
