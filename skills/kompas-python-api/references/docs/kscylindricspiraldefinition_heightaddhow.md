# heightAddHow - Признак дополнительной высоты

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы пространственных кривых ](int_pr_curve.html) > [Цилиндрическая спираль (Интерфейсы ksCylindricSpiralDefinition и CylindricSpiralDefinition ](kscylindricspiraldefinition.html) > [ICylindricSpiralDefinition - свойства ](kscylindricspiraldefinition_props.html) |  Scroll [ [ [ ](kscylindricspiraldefinition_heighttype.html "К следующему разделу")](kscylindricspiraldefinition_props.html "На уровень выше")](kscylindricspiraldefinition_heightadd.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kscylindricspiraldefinition.html)

Тип данных: BOOL

Значения свойства:

TRUE | \- продолжить за объект,  
---|---  
FALSE | \- не доходя до объекта.  
  
Синтаксис Automation:

heightAddHow = iCylindricSpiral.heightAddHow | Получить свойство ([* ](1.html))  
---|---  
iCylindricSpiral.heightAddHow = heightAddHow | Установить свойство ([* ](1.html))  
heightAddHow = iCylindricSpiral.GetHeightAddHow() | Получить свойство ([**](2.html))  
iCylindricSpiral.SetHeightAddHow(heightAddHow) | Установить свойство ([**](2.html))  
  
Примечание

Данное свойство используется только при способе задания высоты "по объекту" ([heightType](kscylindricspiraldefinition_heighttype.html) = 1).

Подразделы:

(отсутствуют)
