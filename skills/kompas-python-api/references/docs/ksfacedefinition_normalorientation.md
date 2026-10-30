# normalOrientation - Относительная ориентация (ориентация нормали грани относительно ориентации нормали поверхности)

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы дополнительных элементов ](int_additional.html) > [Грань (Интерфейсы ksFaceDefinition, IFaceDefinition) ](ksfacedefinition.html) > [IFaceDefinition - свойства ](ksfacedefinition_props.html) |  Scroll [ [ [ ](ksfacedefinition_methods.html "К следующему разделу")](ksfacedefinition_props.html "На уровень выше")](ksfacedefinition_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](ksfacedefinition.html)

Тип данных: BOOL

Синтаксис Automation:

normalOrient = iFaceDefinition.normalOrientation | Получить свойство ([* ](1.html))  
---|---  
iFaceDefinition.GetNormalOrientation() | Получить свойство ([**](2.html))  
  
Возвращаемое значение:

TRUE | \- направление нормали совпадает с направлением нормали математической поверхности,  
---|---  
FALSE | \- направление нормали не совпадает с направлением нормали математической поверхности [ksSurface](kssurface.html).  
  
Примечание:

Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
