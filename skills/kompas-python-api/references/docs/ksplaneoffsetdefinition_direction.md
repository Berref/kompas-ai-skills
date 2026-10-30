# direction - Направление смещения от базовой плоскости

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы вспомогательной геометрии ](int_geometry.html) > [Смещенная плоскость (Интерфейсы ksPlaneOffsetDefinition, IPlaneOffsetDefinition) ](ksplaneoffsetdefinition.html) > [IPlaneOffsetDefinition - свойства ](ksplaneoffsetdefinition_props.html) |  Scroll [ [ [ ](ksplaneoffsetdefinition_offset.html "К следующему разделу")](ksplaneoffsetdefinition_props.html "На уровень выше")](ksplaneoffsetdefinition_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksplaneoffsetdefinition.html)

Тип данных: BOOL

Синтаксис Automation:

direction = iPlaneOffset.direction | Получить свойство([* ](1.html))  
---|---  
iPlaneOffset.direction = direction | Установить свойство ([* ](1.html))  
direction = iPlaneOffset.GetDirection() | Получить свойство ([**](2.html))  
iPlaneOffset.SetDirection(direction) | Установить свойство ([**](2.html))  
  
Значения свойства:

TRUE | \- прямое направление,  
---|---  
FALSE | \- обратное направление.  
  
Примечание:

Прямое направление совпадает с направлением нормали к базовой плоскости.

Подразделы:

(отсутствуют)
