# heightAddHow - Признак дополнительной высоты

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы пространственных кривых ](int_pr_curve.html) > [Коническая спираль (Интерфейсы ksConicSpiralDefinition и IConicSpiralDefinition) ](ksconicspiraldefinition.html) > [IConicSpiralDefinition - свойства ](ksconicspiraldefinition_props.html) |  Scroll [ [ [ ](ksconicspiraldefinition_heighttype.html "К следующему разделу")](ksconicspiraldefinition_props.html "На уровень выше")](ksconicspiraldefinition_heightadd.html "К предыдущему разделу")  
---|---  
  
Тип данных: BOOL

Значения свойства:

TRUE | \- продолжить за объект,  
---|---  
FALSE | \- не доходя до объекта.  
  
Синтаксис Automation:

heightAddHow = iConicSpiral.heightAddHow | Получить свойство ([* ](1.html))  
---|---  
iConicSpiral.heightAddHow = heightAddHow | Установить свойство ([* ](1.html))  
heightAddHow = iConicSpiral.GetHeightAddHow() | Получить свойство ([**](2.html))  
iConicSpiral.SetHeightAddHow(heightAddHow) | Установить свойство ([**](2.html))  
  
Примечание:

Данное свойство используется только при способе задания высоты "по объекту" ([heightType](ksconicspiraldefinition_heighttype.html) = 1).

Подразделы:

(отсутствуют)
