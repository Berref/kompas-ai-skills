# buildMode - Способ построения спирали

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы пространственных кривых ](int_pr_curve.html) > [Коническая спираль (Интерфейсы ksConicSpiralDefinition и IConicSpiralDefinition) ](ksconicspiraldefinition.html) > [IConicSpiralDefinition - свойства ](ksconicspiraldefinition_props.html) |  Scroll [ [ [ ](ksconicspiraldefinition_firstangle.html "К следующему разделу")](ksconicspiraldefinition_props.html "На уровень выше")](ksconicspiraldefinition_builddir.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksconicspiraldefinition.html)

Тип данных: short

Значения свойства:

0 | \- по шагу и количеству витков,  
---|---  
1 | \- по шагу и высоте,  
2 | \- по количеству витков и высоте.  
  
Синтаксис Automation:

buildMode = iConicSpiral.buildMode | Получить свойство ([* ](1.html))  
---|---  
iConicSpiral.buildMode = buildMode | Установить свойство ([* ](1.html))  
buildMode = iConicSpiral.GetBuildMode() | Получить свойство ([**](2.html))  
iConicSpiral.SetBuildMode(buildMode) | Установить свойство ([**](2.html))  
  
Подразделы:

(отсутствуют)
