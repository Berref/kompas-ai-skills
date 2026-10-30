# direction - Направление отсечения

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы формообразующих операций ](int_operation.html) > [Сечение плоскостью (Интерфейсы ksCutByPlaneDefinition, ICutByPlaneDefinition) ](kscutbyplanedefinition.html) > [ICutByPlaneDefinition - свойства ](kscutbyplanedefinition_props.html) |  Scroll [ [ [ ](kscutbyplanedefinition_methods.html "К следующему разделу")](kscutbyplanedefinition_props.html "На уровень выше")](kscutbyplanedefinition_choosetype.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kscutbyplanedefinition.html)

Тип данных: BOOL

Значения свойства:

TRUE | \- прямое направление,  
---|---  
FALSE | \- обратное направление.  
  
Синтаксис Automation:

direction = iCutByPlane.direction | Получить свойство([* ](1.html))  
---|---  
iCutByPlane.direction = direction | Установить свойство ([* ](1.html))  
direction = iCutByPlane.GetDirection() | Получить свойство ([**](2.html))  
iCutByPlane.SetDirection(direction) | Установить свойство ([**](2.html))  
  
Подразделы:

(отсутствуют)
