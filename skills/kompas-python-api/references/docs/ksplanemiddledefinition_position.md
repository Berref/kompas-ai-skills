# position - Положение плоскости

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы вспомогательной геометрии ](int_geometry.html) > [Средняя плоскость (Интерфейсы ksPlaneMiddleDefinition, IPlaneMiddleDefinition) ](ksplanemiddledefinition.html) > [IPlaneMiddleDefinition - свойства ](ksplanemiddledefinition_props.html) |  Scroll [ [ [ ](ksplanemiddledefinition_methods.html "К следующему разделу")](ksplanemiddledefinition_props.html "На уровень выше")](ksplanemiddledefinition_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksplanemiddledefinition.html)

Тип данных: BOOL

Значения свойства:

TRUE | \- положение 1: позволяет построить биссекторную плоскость,  
---|---  
FALSE | \- положение 2: позволяет построить плоскость, перпендикулярную биссекторной и проходящую через прямую или точку пересечения опорных объектов.  
  
Синтаксис Automation:

position = iDocument3D.position | Получить свойство([* ](1.html))  
---|---  
iDocument3D.position = position | Установить свойство ([* ](1.html))  
position = iDocument3D.GetPosition() | Получить свойство ([**](2.html))  
iDocument3D.SetPosition (position) | Установить свойство ([**](2.html))  
  
Подразделы:

(отсутствуют)
